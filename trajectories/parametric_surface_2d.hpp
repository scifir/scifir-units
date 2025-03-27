#ifndef SCIFIR_UNITS_TRAJECTORIES_PARAMETRIC_SURFACE_2D_HPP_INCLUDED
#define SCIFIR_UNITS_TRAJECTORIES_PARAMETRIC_SURFACE_2D_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/base_units.hpp"
#include "../meca_number/angle.hpp"
#include "../coordinates/coordinates_2d.hpp"

#include <functional>

using namespace std;

namespace scifir
{
    template<typename T = length>
    class parametric_surface_2d
    {
        public:
            parametric_surface_2d() : equation()
            {}
            
            parametric_surface_2d(const parametric_surface_2d<T>& x) : equation(x.equation)
            {}
            
            parametric_surface_2d(parametric_surface_2d<T>&& x) : equation(std::move(x.equation))
            {}
            
            explicit parametric_surface_2d(const function<coordinates_2d<T>(float,float)>& x) : equation(x)
            {}

            parametric_surface_2d<T>& operator =(const parametric_surface_2d<T>& x)
            {
                equation = x.equation;
                return *this;
            }
            
            parametric_surface_2d<T>& operator =(parametric_surface_2d<T>&& x)
            {
                equation = std::move(x.equation);
                return *this;
            }

            coordinates_2d<T> operator() (float t) const
            {
                return equation(t);
            }

            function<coordinates_2d<T>(float,float)> equation;
    };
}

#endif // SCIFIR_UNITS_TRAJECTORIES_PARAMETRIC_SURFACE_2D_HPP_INCLUDED
