#ifndef COORDINATES_1D_HPP_INCLUDED
#define COORDINATES_1D_HPP_INCLUDED

using namespace std;

namespace msci
{
	class coordinates_1d
	{
		public:
			coordinates_1d();

			virtual const float x_projection() const = 0;
			virtual float get_value() const = 0;
	};
}

#endif // COORDINATES_1D_HPP_INCLUDED
