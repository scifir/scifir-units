#ifndef MOLECULE_HPP_INCLUDED
#define MOLECULE_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "units.hpp"
#include "chemistry/general/atoms/atom.hpp"
#include "chemistry/general/molecules/atomic_bond.hpp"
#include "math/topology/point_3d.hpp"

using namespace std;

namespace chemistry
{
	enum class functional_group {carbonyl};

	class molecule
	{
		public:
			molecule();

			virtual vector<shared_ptr<atom>> get_atoms() const = 0;
			virtual vector<shared_ptr<atomic_bond>> get_bonds() const = 0;
			virtual int get_total_atoms() const = 0;

			bool is_factible() const;

			mass get_standard_atomic_mass() const;
			mass get_real_mass() const;
			mass get_real_mass_simplified() const;
			mass get_electrons_mass() const;

			inline mass get_total_mass() const
            {
            	return get_real_mass() + get_electrons_mass();
            }

			wstring get_formula() const;
			wstring get_canonical_formula() const;

			int get_ionic_charge() const;
            bool is_ion() const;
            bool is_anion() const;
            bool is_cation() const;
            bool is_neutral() const;

            inline bool is_very_big_molecule() const
            {
            	return (get_total_atoms() <= 500);
            }

            //dipole get_dipole() const;

            bool has_atom(atom_symbol) const;
            bool has_bond(string) const;
            bool has_bond_group(string) const;
            bool has_functional_group(functional_group) const;

            bool is_cyclical() const;
            bool is_acyclical() const;
            bool is_polar() const;
            bool is_apolar() const;
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

            bool is_biochemical() const;

            int number_of_chiral_atoms() const;
            int number_of_enantiomers() const;

            bool is_eter() const;

            //c_canvas_t get_image_2d() const;
            //GLObject get_image_3d() const;
            void print() const;
            void print_image_2d() const;
            void print_image_3d() const;

            virtual void save(string,string) const = 0;

		private:
			tuple<shared_ptr<atom>,math::point_3d> get_image_3d_calculate_atom_position(shared_ptr<atom>,tuple<shared_ptr<atom>,math::point_3d>,tuple<shared_ptr<atom>,math::point_3d>) const;
			void get_atoms_image_3d(vector<tuple<shared_ptr<atom>,math::point_3d>>) const;
			//void get_unpaired_electrons_image_3d(vector<tuple<math::point_3d,math_vector>>) const;
			void get_bonds_image_3d(vector<tuple<shared_ptr<atom>,math::point_3d>>) const;
	};

	bool are_isomers(const molecule&,const molecule&);
	bool are_conformational_isomers(const molecule&,const molecule&);
	bool are_enantiomers(const molecule&,const molecule&);
	bool are_miscible(const molecule&,const molecule&);
	bool are_inmiscible(const molecule&,const molecule&);
}

wostream& operator <<(wostream&,const chemistry::molecule&);
bool operator ==(const chemistry::molecule&,const chemistry::molecule&);
bool operator !=(const chemistry::molecule&,const chemistry::molecule&);

#endif // MOLECULE_HPP_INCLUDED
