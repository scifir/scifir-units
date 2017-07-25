#include "normal_atom.hpp"

//#include "physics/units.hpp"

namespace chemistry
{
	class atom_H : public normal_atom<atom_H>
	{
		public:
			using normal_atom::normal_atom;

			static const string name;
			static const string symbol;

			static const atomic_group group = IA;
			static const int period = 1;

			static const int z = 1;
			static const int neutrons_number = 0;
			static const int valence_number = 1;

			//static const length atomic_radius;
			//static const mass standard_atomic_mass;

			static constexpr float electronegativity = 2.1;
			static const bool radioactive = false;
	};
}
