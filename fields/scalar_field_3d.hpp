#ifndef SCIFIR_UNITS_FIELDS_SCALAR_FIELD_3D_HPP_INCLUDED
#define SCIFIR_UNITS_FIELDS_SCALAR_FIELD_3D_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/base_units.hpp"
#include "../meca_number/angle.hpp"
#include "../coordinates/coordinates_3d.hpp"
#include "../coordinates/coordinates_3dr.hpp"
#include "../topology/point_3d.hpp"

#include <functional>

using namespace std;

namespace scifir
{
    template<typename T,typename U = length>
    class scalar_field_3d
    {
        public:
            scalar_field_3d() : equation()
            {}
            
            scalar_field_3d(const scalar_field_3d<T,U>& x) : equation(x.equation)
            {}
            
            scalar_field_3d(scalar_field_3d<T,U>&& x) : equation(std::move(x.equation))
            {}
            
            explicit scalar_field_3d(const function<T(const U&,const U&,const U&)>& x) : equation(x)
            {}

            explicit scalar_field_3d(string init_scalar_field_3d) : equation()
            {
                /*init_scalar_field_3d.erase(" ");
                vector<string> symbols;
                boost::split(symbols,init_scalar_field_3d,boost::is_any_of("+,-,*,/"));*/
            }

            scalar_field_3d<T,U>& operator = (const scalar_field_3d<T,U>& x)
            {
                equation = x.equation;
                return *this;
            }
            
            scalar_field_3d<T,U>& operator = (scalar_field_3d<T,U>&& x)
            {
                equation = std::move(x.equation);
                return *this;
            }

            T operator() (const U& x, const U& y, const U& z) const
            {
                return equation(x,y,z);
            }

            T operator() (const U& new_p, const angle& new_theta, U new_z) const
            {
                new_z.change_dimensions(new_p);
                T x = T(new_p * scifir::cos(new_theta));
                T y = T(new_p * scifir::sin(new_theta));
                return operator()(x,y,new_z);
            }
            
            T operator() (const U& new_r, const angle& new_theta, const angle& new_phi) const
            {
                T x = T(new_r * scifir::cos(new_theta) * scifir::sin(new_phi));
                T y = T(new_r * scifir::sin(new_theta) * scifir::sin(new_phi));
                T z = T(new_r * scifir::cos(new_phi));
                return operator()(x,y,z);
            }

            T operator() (const angle& new_latitude, const angle& new_longitude, const U& new_altitude) const
            {
                T x = T(new_altitude * scifir::cos(new_latitude) * scifir::cos(new_longitude));
                T y = T(new_altitude * scifir::cos(new_latitude) * scifir::sin(new_longitude));
                T z = T(new_altitude * scifir::sin(new_latitude));
                return operator()(x,y,z);
            }
            
            T operator() (const coordinates_3d<U>& x) const
            {
                return equation(x.x,x.y,x.z);
            }

            T operator() (const coordinates_3dr<U>& x) const
            {
                return equation(x.x,x.y,x.z);
            }

            T operator() (const point_3d<U>& x) const
            {
                return equation(x.x,x.y,x.z);
            }

            scalar_field_3d<T,U> operator +(const scalar_field_3d<T,U>& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) + x.equation(new_x,new_y,new_z); });
            }
            
            scalar_field_3d<T,U> operator -(const scalar_field_3d<T,U>& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) - x.equation(new_x,new_y,new_z); });
            }
            
            scalar_field_3d<T,U> operator *(const scalar_field_3d<T,U>& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) * x.equation(new_x,new_y,new_z); });
            }
            
            scalar_field_3d<T,U> operator /(const scalar_field_3d<T,U>& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) / x.equation(new_x,new_y,new_z); });
            }

            scalar_field_3d<T,U> operator +(const scalar_unit& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) + x; });
            }
            
            scalar_field_3d<T,U> operator -(const scalar_unit& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) - x; });
            }
            
            scalar_field_3d<T,U> operator *(const scalar_unit& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) * x; });
            }
            
            scalar_field_3d<T,U> operator /(const scalar_unit& x) const
            {
                return scalar_field_3d<T,U>([this,x](const U& new_x,const U& new_y,const U& new_z) -> T { return equation(new_x,new_y,new_z) / x; });
            }

            function<T(const U&,const U&,const U&)> equation;
    };

    template<typename T,typename U>
    scalar_field_3d<T,U> operator +(const scalar_unit& x,const scalar_field_3d<T,U>& y)
    {
        return scalar_field_3d<T,U>([x,y](const U& new_x,const U& new_y,const U& new_z) -> T { return x + y.equation(new_x,new_y,new_z); });
    }

    template<typename T,typename U>
    scalar_field_3d<T,U> operator -(const scalar_unit& x,const scalar_field_3d<T,U>& y)
    {
        return scalar_field_3d<T,U>([x,y](const U& new_x,const U& new_y,const U& new_z) -> T { return x - y.equation(new_x,new_y,new_z); });
    }

    template<typename T,typename U>
    scalar_field_3d<T,U> operator *(const scalar_unit& x,const scalar_field_3d<T,U>& y)
    {
        return scalar_field_3d<T,U>([x,y](const U& new_x,const U& new_y,const U& new_z) -> T { return x * y.equation(new_x,new_y,new_z); });
    }

    template<typename T,typename U>
    scalar_field_3d<T,U> operator /(const scalar_unit& x,const scalar_field_3d<T,U>& y)
    {
        return scalar_field_3d<T,U>([x,y](const U& new_x,const U& new_y,const U& new_z) -> T { return x / y.equation(new_x,new_y,new_z); });
    }
}

#endif // SCIFIR_UNITS_FIELDS_SCALAR_FIELD_3D_HPP_INCLUDED
