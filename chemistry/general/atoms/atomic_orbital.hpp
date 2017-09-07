#ifndef ATOMIC_ORBITAL_HPP_INCLUDED
#define ATOMIC_ORBITAL_HPP_INCLUDED

using namespace std;

#include "../../../physics/quantical/particles/electron.hpp"

#include <string>
#include <vector>
using namespace std;

namespace chemistry
{
	enum class orbital_symbol {s, p, d, f};

	class orbital
	{
		public:
			orbital_symbol orbital_specie;
			string name;
			vector<physics::electron> electrons;
			int period;

			orbital(orbital_symbol, int, int);
	};

	class orbital_s : public orbital
	{
		public:
			orbital_s(int, int);
	};

	class orbital_p : public orbital
	{
		public:
			orbital_p(int, int);
	};

	class orbital_d : public orbital
	{
		public:
			orbital_d(int, int);
	};

	class orbital_f : public orbital
	{
		public:
			orbital_f(int, int);
	};

	orbital create_orbital(orbital_symbol, int, int);

	class orbital_group
	{
		public:
			vector<orbital> orbitals;
			orbital_symbol orbital_specie;
			int orbital_max;

			orbital_group(orbital_symbol);
			void add(orbital);
			vector<orbital>::size_type total_orbitals();
			bool is_full();
			string name();
			int period();
			int total_electrons();
			string display_orbitals();

			orbital operator [](int);
	};
}

ostream& operator <<(ostream&, const chemistry::orbital&);
ostream& operator <<(ostream&, chemistry::orbital_group);

#endif // ATOMIC_ORBITAL_HPP_INCLUDED
