#ifndef UNIT_NUMBER_HPP_INCLUDED
#define UNIT_NUMBER_HPP_INCLUDED

#include "undefined_number.hpp"

#include "math/topology/topology.hpp"
#include "informatics/types/is_number.hpp"

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace math
{
	class unit_number : public virtual undefined_number<unit_number>
	{
		public:
			unit_number();
			unit_number(math::space_type);

			void operator =(const unit_number&);

			virtual wstring print(int = 2) const;
	};
}

wostream& operator <<(wostream&, const math::unit_number&);

#endif // UNIT_NUMBER_HPP_INCLUDED
