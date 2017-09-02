#ifndef CHEMISTRY_GENERAL_ATOMS_NORMAL_ATOM_HPP
#define CHEMISTRY_GENERAL_ATOMS_NORMAL_ATOM_HPP

#include "atom.hpp"

#include "units.hpp"
#include "physics/particles.hpp"

#include <cstdint>

using namespace chemistry;

namespace chemistry
{
	template<typename T>
	class normal_atom : public atom_crtp<T>
	{
		public:
			normal_atom(int new_ionic_charge = 0,int new_neutrons_number = T::mass_number) : mass_number(new_neutrons_number),ionic_charge(new_ionic_charge),atom_crtp<T>()
			{
				if (new_ionic_charge > atom_crtp<T>::get_z())
				{
					throw "ionic charge is greater than z";
				}
			}

			virtual int get_ionic_charge() const
			{
				return ionic_charge;
			}

			virtual int get_electrons_number() const
            {
            	return (atom_crtp<T>::get_z() - get_ionic_charge());
            }

            virtual const unsigned int get_mass_number() const
            {
            	return mass_number;
            }

            virtual string get_electronic_configuration() const // TODO: finish function
            {
            	int remaining_electrons = get_electrons_number();
            	if (remaining_electrons == 0)
				{
					return "empty configuration";
				}
            }

            virtual int get_lone_pairs() const
            {
            	int unpaired_electrons = get_electrons_number();
            	for (const auto& bond : atom::get_bonds())
				{
					shared_ptr<atomic_bond> bond_lock = bond.lock();
					//unpaired_electrons -= bond_lock->get_total_electrons();
				}
				return unpaired_electrons / 2;
            }

            virtual mass get_real_mass() const
            {
            	return mass(atom_crtp<T>::get_z() * physics::proton::common_mass,"amu");
            }

            virtual mass get_electrons_mass() const
            {
            	return mass(get_electrons_number() * physics::electron::common_mass,"amu");
            }

			virtual void print_image_2d() const // TODO: finish function
			{
			}

			virtual void print_image_3d() const // TODO: finish function
			{
			}

		private:
			uint8_t mass_number;
			uint8_t ionic_charge;
	};
}

#endif // CHEMISTRY_GENERAL_ATOMS_NORMAL_ATOM_HPP
