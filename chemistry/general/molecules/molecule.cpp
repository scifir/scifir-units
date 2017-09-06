#include "molecule.hpp"

using namespace std;

namespace chemistry
{
	mass molecule::get_standard_atomic_mass() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_standard_atomic_mass();
		}
		return atoms_mass;
	}

	mass molecule::get_real_mass() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_real_mass();
		}
		return atoms_mass;
	}

	mass molecule::get_real_mass_simplified() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_real_mass_simplified();
		}
		return atoms_mass;
	}

	mass molecule::get_electrons_mass() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_electrons_mass();
		}
		return atoms_mass;
	}

	wstring molecule::get_formula() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		wostringstream formula_text;
		return formula_text.str();
	}

	wstring molecule::get_canonical_formula() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		wostringstream formula_text;
		for (const auto& atom : atoms)
		{
			int atom_number = 0;
			for (const auto& atom2 : atoms)
			{
				if (atom == atom2)
				{
					continue;
				}
				if (same_specimen(*atom,*atom2))
				{
					atom_number++;
				}
			}
			formula_text << atom->get_symbol().c_str() << atom_number;
		}
		return formula_text.str();
	}

	int molecule::get_ionic_charge() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		int ionic_charge = 0;
		for (const auto& atom : atoms)
		{
			ionic_charge += atom->get_ionic_charge();
		}
		return ionic_charge;
	}

	bool molecule::is_ion() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_ion())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::is_anion() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_anion())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::is_cation() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_cation())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::is_neutral() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_neutral())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::has_atom(atom_symbol x) const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom: atoms)
		{
			if (atom->is_atom_specimen(x))
			{
				return true;
			}
		}
		return false;
	}

	bool molecule::has_bond(string x) const
	{
		vector<shared_ptr<atomic_bond>> bonds = get_bonds();
		for (const auto& bond : bonds)
		{
			if (bond->is_bond(x))
			{
				return true;
			}
		}
		return false;
	}

	bool molecule::has_functional_group(functional_group x) const
	{

	}

	bool molecule::is_cyclical() const
    {

    }

    bool molecule::is_acyclical() const
    {

    }

    bool molecule::is_polar() const
    {

    }

    bool molecule::is_apolar() const
	{

	}

	bool molecule::is_chiral() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom: atoms)
		{
			if (atom->is_chiral())
			{
				return true;
			}
		}
		return false;
	}

    bool molecule::is_achiral() const
    {
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom: atoms)
		{
			if (atom->is_achiral())
			{
				return true;
			}
		}
		return false;
    }

    bool molecule::is_protic() const
    {
    	return (has_bond("O-H") or has_bond("N-H"));
    }

    bool molecule::is_aprotic() const
    {
		return !is_protic();
    }

    int molecule::number_of_chiral_atoms() const
    {
    	vector<shared_ptr<atom>> atoms = get_atoms();
    	int i = 0;
		for (const auto& atom: atoms)
		{
			if (atom->is_chiral())
			{
				i++;
			}
		}
		return i;
    }

    int molecule::number_of_enantiomers() const
    {
		return 2^number_of_chiral_atoms();
    }

    /*void molecule::get_image_3d() const
    {

    }*/

    void molecule::print_image_3d() const
    {

    }

	tuple<shared_ptr<atom>,math::point_3d> molecule::get_image_3d_calculate_atom_position(shared_ptr<atom> new_atom,tuple<shared_ptr<atom>,math::point_3d> previous_atom,tuple<shared_ptr<atom>,math::point_3d> previous_atom2) const
    {
		// Calculate the position based on the geometry of the previous_atom, each geometry gives a different position to calculate of, based on the angle of the two bonds (the new and the previous one)
		vector<weak_ptr<atomic_bond>> bonds = new_atom->get_bonds();
		for (const auto& bond : bonds)
		{
			tuple<shared_ptr<atom>,math::point_3d> get_image_3d_calculate_atom_position();
		}
    }

    void molecule::get_atoms_image_3d(vector<tuple<shared_ptr<atom>,math::point_3d>> atom_positions) const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			// get atom 3d image calling atom.get_image_3d() or similar
			// use the vector<math::point_3d> to position the image related to the full image
		}
	}

	/*void molecule::get_unpaired_electrons_image_3d(vector<tuple<math::point_3d,math_vector>> electron_positions) const
	{
		// the math_vector is for directions
	}*/

	void molecule::get_bonds_image_3d(vector<tuple<shared_ptr<atom>,math::point_3d>> atom_positions) const
	{
		vector<shared_ptr<atomic_bond>> bonds = get_bonds();
		for (const auto& bond: bonds)
		{
			// get atomic bond 3d image by creating a cillinder and connecting it between the two centers of the atoms
		}
	}
}
