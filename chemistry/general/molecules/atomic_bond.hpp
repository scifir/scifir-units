#ifndef ATOMIC_BOND_HPP_INCLUDED
#define ATOMIC_BOND_HPP_INCLUDED

#include <memory>

#include "chemistry/general/atoms/atom.hpp"
#include "units.hpp"

using namespace std;
using namespace physics::units;

namespace chemistry
{
	class atomic_bond
	{
		public:
			atomic_bond(const shared_ptr<atom>&,const shared_ptr<atom>&,atomic_bond_weight);

			inline const weak_ptr<atom>& get_atom1() const
			{
				return atom1;
			}

			inline const weak_ptr<atom>& get_atom2() const
			{
				return atom2;
			}

			inline const length& get_bond_length() const
			{
				return bond_length;
			}

			inline const atomic_bond_weight& get_atomic_bond_weight() const
			{
				return weight;
			}

			/*inline enthalpy get_bond_enthalpy()
			{
				//return bond_enthalpy;
			}*/

			inline bool is_covalent() const
			{
				return (is_covalent_polar() or is_covalent_apolar());
			}

			inline bool is_covalent_polar() const
			{
				return !is_covalent_apolar();
			}

			inline bool is_covalent_apolar() const
			{
				shared_ptr<atom> atom1_lock = atom1.lock();
				shared_ptr<atom> atom2_lock = atom2.lock();
				return (atom1_lock->get_electronegativity() == atom2_lock->get_electronegativity());
			}

			inline bool is_ionic() const
			{
				shared_ptr<atom> atom1_lock = atom1.lock();
				shared_ptr<atom> atom2_lock = atom2.lock();
				return ((atom1_lock->get_electronegativity() - atom2_lock->get_electronegativity()) >= 2);
			}

			inline atomic_bond_type get_atomic_bond_type()
			{
				if (atom1.lock()->is_non_metal() and atom2.lock()->is_metallic())
				{
					return atomic_bond_type::ionic;
				}
				else if(atom1.lock()->is_non_metal() and atom2.lock()->is_non_metal())
				{
					return atomic_bond_type::covalent;
				}
				else if(atom1.lock()->is_metallic() and atom2.lock()->is_metallic())
				{
					return atomic_bond_type::metallic;
				}
			}

			inline bool is_flexible() const
			{
				return (weight == atomic_bond_weight::single);
			}

			inline bool is_rigid() const
			{
				return !is_flexible();
			}

			inline bool is_single() const
			{
				return (weight == atomic_bond_weight::single);
			}

			inline bool is_double() const
			{
				return (weight == atomic_bond_weight::dual);
			}

			inline bool is_triple() const
			{
				return (weight == atomic_bond_weight::triple);
			}

			int get_total_electrons() const;
			bool is_bond(const string&) const;

		private:
			weak_ptr<atom> atom1;
			weak_ptr<atom> atom2;
			atomic_bond_weight weight;
			length bond_length;
			//enthalpy bond_enthalpy;
	};
}

#endif // ATOMIC_BOND_HPP_INCLUDED
