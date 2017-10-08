#include "atomic_orbital.hpp"

#include "../../../physics/quantical/particles/electron.hpp"

#include <sstream>
#include <vector>

using namespace std;

namespace msci
{
	orbital::orbital(orbital_symbol new_orbital_specie, int new_period, int electron_number)
	{
		orbital_specie = new_orbital_specie;
		period = new_period;
		electrons = vector<msci::electron>();
		if(electron_number >= 1)
		{
			msci::electron electron1 = msci::electron(-0.5);
			electrons.push_back(electron1);
			if(electron_number == 2)
			{
				msci::electron electron2 = msci::electron(0.5);
				electrons.push_back(electron2);
			}
		}
	}

	orbital_s::orbital_s(int new_period, int electron_number) : orbital(orbital_symbol::s, new_period, electron_number)
	{
		name = "s";
	}

	orbital_p::orbital_p(int new_period, int electron_number) : orbital(orbital_symbol::p, new_period, electron_number)
	{
		name = "p";
	}

	orbital_d::orbital_d(int new_period, int electron_number) : orbital(orbital_symbol::d, new_period, electron_number)
	{
		name = "d";
	}

	orbital_f::orbital_f(int new_period, int electron_number) : orbital(orbital_symbol::f, new_period, electron_number)
	{
		name = "f";
	}

	orbital create_orbital(orbital_symbol orbital_specie, int period, int electron_number)
	{
		switch(orbital_specie)
		{
			case orbital_symbol::s:
				return orbital_s(period, electron_number);
			case orbital_symbol::p:
				return orbital_p(period, electron_number);
			case orbital_symbol::d:
				return orbital_d(period, electron_number);
			case orbital_symbol::f:
				return orbital_f(period, electron_number);
			default:
				return orbital_s(period, electron_number);
		}
	}

	orbital_group::orbital_group(orbital_symbol new_orbital_specie)
	{
		orbitals = vector<orbital>();
		orbital_specie = new_orbital_specie;
		switch(orbital_specie)
		{
			case orbital_symbol::s:
				orbital_max = 1;
				break;
			case orbital_symbol::p:
				orbital_max = 3;
				break;
			case orbital_symbol::d:
				orbital_max = 5;
				break;
			case orbital_symbol::f:
				orbital_max = 7;
				break;
		}
	}

	void orbital_group::add(orbital new_orbital)
	{
		orbitals.push_back(new_orbital);
	}

	vector<orbital>::size_type orbital_group::total_orbitals()
	{
		return orbitals.size();
	}

	bool orbital_group::is_full()
	{
		if(orbital_specie == orbital_symbol::s and total_orbitals() == orbital_max)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string orbital_group::name()
	{
		return orbitals[0].name;
	}

	int orbital_group::period()
	{
		return orbitals[0].period;
	}

	int orbital_group::total_electrons()
	{
		int total_electrons = 0;
		for(auto& orbital : orbitals)
		{
			total_electrons += orbital.electrons.size();
		}
		return total_electrons;
	}

	string orbital_group::display_orbitals()
	{
		ostringstream output;
		for(auto& orbital : orbitals)
		{
			output << orbital;
		}
		return output.str();
	}

	orbital orbital_group::operator [](int number)
	{
		return orbitals[number];
	}
}

ostream& operator <<(ostream& os, const msci::orbital& orbital)
{
	ostringstream output;
	output << orbital.period << orbital.name << orbital.electrons.size();
	return os << output.str();
}

ostream& operator <<(ostream& os, msci::orbital_group orbital_group)
{
	ostringstream output;
	output << orbital_group.period() << orbital_group.name() << orbital_group.total_electrons();
	return os << output.str();
}
