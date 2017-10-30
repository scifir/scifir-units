#ifndef UNIT_NUMBER_HPP_INCLUDED
#define UNIT_NUMBER_HPP_INCLUDED

#include "undefined_number.hpp"

#include "math/topology/topology.hpp"
#include "informatics/types/is_number.hpp"

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace msci
{
	class unit_number : public virtual undefined_number<unit_number>
	{
		public:
			unit_number();
			unit_number(msci::space_type);

			void operator =(const unit_number&);

			virtual string print(int = 2) const;
	};
}

ostream& operator <<(ostream&, const msci::unit_number&);

#endif // UNIT_NUMBER_HPP_INCLUDED
