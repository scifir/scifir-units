#ifndef SCIFIR_UNITS_TRAJECTORIES_TRAJECTORY_2D_HPP_INCLUDED
#define SCIFIR_UNITS_TRAJECTORIES_TRAJECTORY_2D_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/base_units.hpp"
#include "../meca_number/angle.hpp"
#include "../coordinates/coordinates_2d.hpp"

#include <functional>

using namespace std;

namespace scifir
{
    template<typename T = length>
    class trajectory_2d
    {
        public:
            trajectory_2d() : equation()
            {}
            
            trajectory_2d(const trajectory_2d<T>& x) : equation(x.equation)
            {}
            
            trajectory_2d(trajectory_2d<T>&& x) : equation(std::move(x.equation))
            {}
            
            explicit trajectory_2d(const function<coordinates_2d<T>(float)>& x) : equation(x)
            {}

            trajectory_2d<T>& operator =(const trajectory_2d<T>& x)
            {
                equation = x.equation;
                return *this;
            }
            
            trajectory_2d<T>& operator =(trajectory_2d<T>&& x)
            {
                equation = std::move(x.equation);
                return *this;
            }

            coordinates_2d<T> operator() (float t) const
            {
                return equation(t);
            }

            function<coordinates_2d<T>(float)> equation;
    };
}

#endif // SCIFIR_UNITS_TRAJECTORIES_TRAJECTORY_2D_HPP_INCLUDED
