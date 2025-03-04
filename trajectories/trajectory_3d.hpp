#ifndef SCIFIR_UNITS_TRAJECTORIES_TRAJECTORY_3D_HPP_INCLUDED
#define SCIFIR_UNITS_TRAJECTORIES_TRAJECTORY_3D_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/base_units.hpp"
#include "../meca_number/angle.hpp"
#include "../coordinates/coordinates_3d.hpp"
#include "../coordinates/coordinates_3dr.hpp"

#include <functional>

using namespace std;

namespace scifir
{
    template<typename T = length>
    class trajectory_3d
    {
        public:
            trajectory_3d() : equation()
            {}
            
            trajectory_3d(const trajectory_3d<T>& x) : equation(x.equation)
            {}
            
            trajectory_3d(trajectory_3d<T>&& x) : equation(std::move(x.equation))
            {}
            
            explicit trajectory_3d(const function<coordinates_3d<T>(float)>& x) : equation(x)
            {}

            trajectory_3d<T>& operator =(const trajectory_3d<T>& x)
            {
                equation = x.equation;
                return *this;
            }
            
            trajectory_3d<T>& operator =(trajectory_3d<T>&& x)
            {
                equation = std::move(x.equation);
                return *this;
            }

            coordinates_3d<T> operator() (float t) const
            {
                return equation(t);
            }

            function<coordinates_3d<T>(float)> equation;
    };
}

#endif // SCIFIR_UNITS_TRAJECTORIES_TRAJECTORY_3D_HPP_INCLUDED
