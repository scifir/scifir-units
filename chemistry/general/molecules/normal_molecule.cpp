#include "normal_molecule.hpp"
#include "chemistry/general/atoms/atoms.hpp"

#include "boost/algorithm/string.hpp"
#include "rapidxml/rapidxml.hpp"

#include <iostream>
#include <fstream>

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
				atoms[atom1_index]->add_bond(new_atomic_bond);
				atoms[atom2_index]->add_bond(new_atomic_bond);
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
}
