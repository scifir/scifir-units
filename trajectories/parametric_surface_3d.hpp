#ifndef SCIFIR_UNITS_TRAJECTORIES_PARAMETRIC_SURFACE_3D_HPP_INCLUDED
#define SCIFIR_UNITS_TRAJECTORIES_PARAMETRIC_SURFACE_3D_HPP_INCLUDED

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
    class parametric_surface_3d
    {
        public:
            parametric_surface_3d() : equation()
            {}
            
            parametric_surface_3d(const parametric_surface_3d<T>& x) : equation(x.equation)
            {}
            
            parametric_surface_3d(parametric_surface_3d<T>&& x) : equation(std::move(x.equation))
            {}
            
            explicit parametric_surface_3d(const function<coordinates_3d<T>(float,float)>& x) : equation(x)
            {}

            parametric_surface_3d<T>& operator =(const parametric_surface_3d<T>& x)
            {
                equation = x.equation;
                return *this;
            }
            
            parametric_surface_3d<T>& operator =(parametric_surface_3d<T>&& x)
            {
                equation = std::move(x.equation);
                return *this;
            }

            coordinates_3d<T> operator() (float t) const
            {
                return equation(t);
            }

            function<coordinates_3d<T>(float,float)> equation;
    };
}

#endif // SCIFIR_UNITS_TRAJECTORIES_PARAMETRIC_SURFACE_3D_HPP_INCLUDED
