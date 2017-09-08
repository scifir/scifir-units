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
	normal_molecule::normal_molecule(string new_file) : atoms(),bonds(),bonds_graph(),molecule()
	{
		xml_document<> doc;
		xml_node<> * root_node;
		ifstream theFile (new_file);
		vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
		buffer.push_back('\0');
		doc.parse<0>(&buffer[0]);
		root_node = doc.first_node("molecule");
		xml_node<> * atoms_node = root_node->first_node("atoms");
		vector<string> file_atoms = vector<string>();
		string atoms_content = atoms_node->value();
		boost::split(file_atoms,atoms_content,boost::is_any_of(" "));
		for (const auto& atom_symbol : file_atoms)
		{
			atoms.push_back(shared_ptr<atom>(create_atom(atom_symbol)));
		}
		xml_node<> * bonds_node = root_node->first_node("bonds");
		vector<string> file_bonds = vector<string>();
		string bonds_content = bonds_node->value();
		boost::split(file_bonds,bonds_content,boost::is_any_of(";"));
		int atom1_index = 0;
		for (const auto& bond_list : file_bonds)
		{
			vector<string> file_atom_bonds = vector<string>();
			boost::split(file_atom_bonds,bond_list,boost::is_any_of(" "));
			for (const auto& atom2 : file_atom_bonds)
			{
				int atom2_index = stoi(atom2) - 1;
				shared_ptr<atomic_bond> new_atomic_bond = make_shared<atomic_bond>(atoms[atom1_index],atoms[atom2_index],atomic_bond_weight::single);
				bonds.push_back(new_atomic_bond);
				if (!atoms[atom1_index]->bonded_to(*atoms[atom2_index]))
				{
					atoms[atom1_index]->add_bond(new_atomic_bond);
					atoms[atom2_index]->add_bond(new_atomic_bond);
				}
			}
			// detect if the bond is double or triple to get the weight
			atom1_index++;
		}
	}

	vector<shared_ptr<atom>> normal_molecule::get_atoms() const
	{
		return atoms;
	}

	vector<shared_ptr<atomic_bond>> normal_molecule::get_bonds() const
	{
		return bonds;
	}

	vector<vector<bool>> normal_molecule::get_bonds_graph() const
	{
		return bonds_graph;
	}

	int normal_molecule::get_total_atoms() const
	{
		return atoms.size();
	}

	void normal_molecule::save(string file_path,string file_name) const
	{
		ostringstream file_content;
		file_content << "<molecule>";
		file_content << "\n\t<atoms>";
		int atoms_count = 0;
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
		int atom1_index = 0;
		for (const auto& atom1 : atoms)
		{
			int atom2_index = 0;
			int bonds_count = 0;
			for (const auto& atom2 : atoms)
			{
				if (atom1->bonded_to(*atom2))
				{
					file_content << (atom2_index + 1);
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
