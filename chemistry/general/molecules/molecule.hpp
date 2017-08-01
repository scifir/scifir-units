#ifndef MOLECULE_HPP_INCLUDED
#define MOLECULE_HPP_INCLUDED

// TODO: 3D display of molecules
// TODO: 2D display of molecules by printing inside 2D a 3D molecule
// TODO: XML format extension for .sm files for molecules including atoms number and bonds graph
// TODO: Constructor by opening an .sm file
// TODO: Chemistry Creator program for creating molecules with .sm extension
// TODO: Constructor of molecules by passing a formated string

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "physics/units.hpp"
#include "chemistry/general/atoms/atom.hpp"
#include "chemistry/general/molecules/atomic_bond.hpp"

using namespace std;

namespace chemistry
{
	enum class functional_group {carbonyl};

	class molecule
	{
		public:
			molecule(string); // it can be a file path or the contents of a file of a molecule, two cases

			virtual vector<shared_ptr<atom>> get_atoms() const = 0;
			virtual vector<shared_ptr<atomic_bond>> get_bonds() const = 0;
			virtual vector<vector<bool>> get_bonds_graph() const = 0;
			virtual int get_total_atoms() const = 0;

			mass get_standard_atomic_mass() const;
			mass get_real_mass() const;
			mass get_real_mass_simplified() const;
			mass get_electrons_mass() const;

			inline mass get_total_mass() const
            {
            	return get_real_mass() + get_electrons_mass();
            }

			wstring get_formula() const; //TODO: pending function
			wstring get_canonical_formula() const; //TODO: pending function

			int get_ionic_charge() const; //TODO: pending function
            bool is_ion() const; //TODO: pending function
            bool is_anion() const; //TODO: pending function
            bool is_cation() const; //TODO: pending function
            bool is_neutral() const; //TODO: pending function

            inline bool is_very_big_molecule() const
            {
            	return (get_total_atoms() <= 500);
            }

            //dipole get_dipole() const; //TODO: pending function

            bool has_atom(atom_symbol) const;
            bool has_bond(string) const;
            bool has_functional_group(functional_group) const; //TODO: pending function

            bool is_cyclical() const; //TODO: pending function
            bool is_acyclical() const; //TODO: pending function
            bool is_polar() const; //TODO: pending function
            bool is_apolar() const; //TODO: pending function
            bool is_chiral() const;
            bool is_achiral() const;
            bool is_protic() const;
            bool is_aprotic() const;

            inline bool is_organic() const
			{
				return has_bond("C-H");
			}

			inline bool is_inorganic() const
			{
				return !is_organic();
			}

            bool is_biochemical() const; //TODO: pending function

            int number_of_chiral_atoms() const;
            int number_of_enantiomers() const;

            bool is_eter(); //TODO: create all the headers of those functions. pending function

            //c_canvas_t get_image_2d() const; //TODO: pending function
            //GLObject get_image_3d() const; //TODO: pending function
            void print() const; //TODO: pending function
            void print_image_2d() const; //TODO: pending function
            void print_image_3d() const; //TODO: pending function
		private:
			<tuple<shared_ptr<atom>,point>> get_image_3d_calculate_atom_position(shared_ptr<atom>,tuple<shared_ptr<atom>,point>) const; //TODO: pending function
			void get_atoms_image_3d(vector<tuple<shared_ptr<atom>,point>>) const; //TODO: pending function
			//void get_unpaired_electrons_image_3d(vector<tuple<point,math_vector>>) const; //TODO: pending function
			void get_bonds_image_3d(vector<tuple<shared_ptr<atom>,point>>) const; //TODO: pending function
	};

	bool are_isomers(const molecule&,const molecule&); //TODO: pending function
	bool are_conformational_isomers(const molecule&,const molecule&); //TODO: pending function
	bool are_enantiomers(const molecule&,const molecule&); //TODO: pending function
	bool are_miscible(const molecule&,const molecule&); //TODO: pending function
	bool are_inmiscible(const molecule&,const molecule&); //TODO: pending function
}

wostream& operator <<(wostream&,const chemistry::molecule&); //TODO: pending function
bool operator ==(const chemistry::molecule&,const chemistry::molecule&); //TODO: pending function
bool operator !=(const chemistry::molecule&,const chemistry::molecule&); //TODO: pending function

#endif // MOLECULE_HPP_INCLUDED
