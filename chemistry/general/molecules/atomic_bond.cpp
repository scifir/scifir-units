#include "atomic_bond.hpp"

using namespace std;

namespace chemistry
{
	atomic_bond::atomic_bond(const shared_ptr<atom>& x,const shared_ptr<atom>& y,atomic_bond_weight new_atomic_bond_weight) : weight(new_atomic_bond_weight)
	{
		atom1 = weak_ptr<atom>(x);
		atom2 = weak_ptr<atom>(y);
	}

	int atomic_bond::get_total_electrons() const
	{
		switch(weight)
		{
		case atomic_bond_weight::single:
			return 2;
		case atomic_bond_weight::dual:
			return 4;
		case atomic_bond_weight::triple:
			return 6;
		}
	}

	bool atomic_bond::is_bond(string x) const
	{
		if (x.size() != 3)
		{
			return false;
		}
		shared_ptr<atom> atom1_lock = atom1.lock();
		shared_ptr<atom> atom2_lock = atom2.lock();
		/*if ((x[0] == atom1_lock->get_symbol() and x[2] == atom2_lock->get_symbol()) or (x[2] == atom1_lock->get_symbol() and x[0] == atom2_lock->get_symbol()))
		{
			if((x[1] == '-' and weight == atomic_bond_weight::single) or (x[1] == '=' and weight == atomic_bond_weight::dual) or (x[1] == '≡' and weight == atomic_bond_weight::triple))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}*/
	}
}
