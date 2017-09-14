#include "normal_molecule.hpp"
#include "chemistry/general/atoms/atoms.hpp"

#include "boost/algorithm/string.hpp"
#include "rapidxml/rapidxml.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace rapidxml;
using namespace std;

namespace chemistry
{
	normal_molecule::normal_molecule(string new_file) : molecule(),atoms(),bonds()
	{
		xml_document<> doc;
		if (new_file.substr(0,10) == "<molecule>")
		{
			string cstr;
			doc.parse<0>(&new_file[0]);
		}
		else
		{
			ifstream theFile (new_file);
			stringstream buffer;
			buffer << theFile.rdbuf();
			theFile.close();
			string file_content (buffer.str());
			vector<char> file_content_vector (file_content.begin(),file_content.end());
			file_content_vector.push_back('\0');
			doc.parse<0>(&file_content_vector[0]);
		}
		xml_node<> * root_node;
		root_node = doc.first_node("molecule");
		xml_node<> * atoms_node = root_node->first_node("atoms");
		vector<string> file_atoms = vector<string>();
		string atoms_content = atoms_node->value();
		boost::split(file_atoms,atoms_content,boost::is_any_of(" "));
		for (const string& atom_symbol : file_atoms)
		{
			atoms.push_back(shared_ptr<atom>(create_atom(atom_symbol)));
		}
		xml_node<> * bonds_node = root_node->first_node("bonds");
		vector<string> file_bonds = vector<string>();
		string bonds_content = bonds_node->value();
		boost::split(file_bonds,bonds_content,boost::is_any_of(";"));
		unsigned int atom1_index = 0;
		for (const string& bond_list : file_bonds)
		{
			vector<string> file_atom_bonds = vector<string>();
			boost::split(file_atom_bonds,bond_list,boost::is_any_of(" "));
			for (const string& atom2 : file_atom_bonds)
			{
				unsigned int atom2_index;
				atomic_bond_weight weight;
				size_t is_double_bond = atom2.find("d");
				if (is_double_bond != std::string::npos)
				{
					weight = atomic_bond_weight::dual;
					atom2_index = stoi(atom2.substr(0,1)) - 1;
				}
				else
				{
					size_t is_triple_bond = atom2.find("t");
					if (is_triple_bond != std::string::npos)
					{
						weight = atomic_bond_weight::triple;
						atom2_index = stoi(atom2.substr(0,1)) - 1;
					}
					else
					{
						weight = atomic_bond_weight::single;
						atom2_index = stoi(atom2) - 1;
					}
				}
				if (!atoms[atom1_index]->bonded_to(*atoms[atom2_index]))
				{
					shared_ptr<atomic_bond> new_atomic_bond = make_shared<atomic_bond>(atoms[atom1_index],atoms[atom2_index],weight);
					bonds.push_back(new_atomic_bond);
					atoms[atom1_index]->add_bond(new_atomic_bond);
					atoms[atom2_index]->add_bond(new_atomic_bond);
				}
				atom2_index++;
			}
			atom1_index++;
		}
	}

	normal_molecule::normal_molecule(vector<shared_ptr<atom>> new_atoms,vector<shared_ptr<atomic_bond>> new_bonds) : molecule(),atoms(new_atoms),bonds(new_bonds)
	{
	}

	vector<shared_ptr<atom>> normal_molecule::get_atoms() const
	{
		return atoms;
	}

	vector<shared_ptr<atomic_bond>> normal_molecule::get_bonds() const
	{
		return bonds;
	}

	int normal_molecule::get_total_atoms() const
	{
		return atoms.size();
	}

	void normal_molecule::save(string file_path,string file_name) const
	{
		ostringstream file_content;
		file_content << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
		file_content << "\n<molecule>";
		file_content << "\n\t<atoms>";
		unsigned int atoms_count = 0;
		for (const auto& atom : atoms)
		{
			file_content << atom->get_file_format();
			atoms_count++;
			if (atoms_count < atoms.size())
			{
				file_content << " ";
			}
		}
		file_content << "<atoms>";
		file_content << "\n\t<bonds>";
		unsigned int atom1_index = 0;
		for (const auto& atom1 : atoms)
		{
			int atom2_index = 0;
			int bonds_count = 0;
			for (const auto& atom2 : atoms)
			{
				if (atom1->bonded_to(*atom2))
				{
					file_content << (atom2_index + 1);
					shared_ptr<atomic_bond> atom_bond = atom1->get_bond_of(*atom2);
					if (atom_bond->is_double())
					{
						file_content << "d";
					}
					else if (atom_bond->is_triple())
					{
						file_content << "t";
					}
					bonds_count++;
					if (bonds_count < atom1->get_bonds_number())
					{
						file_content << " ";
					}
				}
				atom2_index++;
			}
			atom1_index++;
			if (atom1_index != atoms.size())
			{
				file_content << ";";
			}
		}
		file_content << "</bonds>";
		file_content << "\n</molecule>";
		FILE* new_file = fopen(file_name.c_str(),"w");
		fputs(file_content.str().c_str(),new_file);
		fclose(new_file);
	}
}
