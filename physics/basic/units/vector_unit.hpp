#ifndef VECTORIAL_UNIT_HPP_INCLUDED
#define VECTORIAL_UNIT_HPP_INCLUDED

#include "dimension_container.hpp"
#include "unit.hpp"
#include "scalar_unit.hpp"
#include "math/number/angle_number.hpp"
#include "math/topology/topology.hpp"
#include "math/topology/coordinates/hyper_spherical_coordinates.hpp"
#include "math/topology/coordinates/coordinates_2d.hpp"
#include "informatics/types/is_number.hpp"

#include "boost/algorithm/string.hpp"
#include "boost/variant.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace math::topology;

namespace physics::units
{
	typedef tuple<unit, boost::variant<list<angle_type>,direction_symbol>> vector_unit_tuple;

	class custom_vector;

	template<typename T>
	class vector_unit : public unit_crtp<T>, public hyper_spherical_coordinates
	{
		public:
			/*vector_unit() : unit_crtp<T>(),hyper_spherical_coordinates()
			{
			}*/

			vector_unit(unit new_value) : unit_crtp<T>(new_value), hyper_spherical_coordinates(lambda_value())
			{
			}

			vector_unit(unit new_value, direction_symbol new_direction) : unit_crtp<T>(new_value), hyper_spherical_coordinates(lambda_value(), new_direction)
			{
			}

			vector_unit(unit new_value, angle_type new_angle1) : unit_crtp<T>(new_value), hyper_spherical_coordinates(lambda_value(), new_angle1)
			{
			}

			vector_unit(unit new_value, angle_type new_angle1, angle_type new_angle2) : unit_crtp<T>(new_value), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
			{
			}

			vector_unit(unit new_value, list<angle_type> new_angles) : unit_crtp<T>(new_value), hyper_spherical_coordinates(lambda_value(), new_angles)
			{
			}

			explicit vector_unit(string init_value) : unit_crtp<T>(init_value), hyper_spherical_coordinates(lambda_value())
			{
			}

			vector_unit(string init_value, angle_type new_angle1) : unit_crtp<T>(init_value), hyper_spherical_coordinates(lambda_value(), new_angle1)
			{
			}

			vector_unit(string init_value, angle_type new_angle1, angle_type new_angle2) : unit_crtp<T>(init_value), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
			{
			}

			vector_unit(string init_value, list<angle_type> new_angles) : unit_crtp<T>(init_value), hyper_spherical_coordinates(lambda_value(), new_angles)
			{
			}

			/*vector_unit(vector_unit_tuple new_tuple) : unit_crtp<T>(move(get<0>(new_tuple))), hyper_spherical_coordinates(lambda_value(), move(boost::apply_visitor(
      [](auto val){ return hyper_spherical_coordinates(lambda_value(),val); },
		get<1>(new_tuple)
    )))
			{
			}*/

			vector_unit(vector_unit_tuple new_tuple) : unit_crtp<T>(move(get<0>(new_tuple))), hyper_spherical_coordinates(lambda_value(), get<1>(new_tuple))
			{
			}

			vector_unit(const vector_unit<T>& x)
			{
				*this = x;
			}

			void point_to(direction_symbol x)
			{
				if (is_1d())
				{
					if (x == direction_symbol::left)
					{
						directions.direction.go_left();
					}
					else if(x == direction_symbol::right)
					{
						directions.direction.go_right();
					}
				}
				else if (is_2d())
				{
					if (x == direction_symbol::left)
					{
						directions.angles[0] = 180;
					}
					else if(x == direction_symbol::right)
					{
						directions.angles[0] = 0;
					}
					else if(x == top)
					{
						directions.angles[0] = 90;
					}
					else if(x == bottom)
					{
						directions.angles[0] = 270;
					}
					else if(x == left_top)
					{
						directions.angles[0] = 135;
					}
					else if(x == right_top)
					{
						directions.angles[0] = 45;
					}
					else if(x == right_bottom)
					{
						directions.angles[0] = 315;
					}
					else if(x == left_bottom)
					{
						directions.angles[0] = 225;
					}
				}
				else if (is_3d())
				{
					if (x == direction_symbol::left)
					{
						directions.angles[0] = 270;
						directions.angles[1] = 90;
					}
					else if(x == direction_symbol::right)
					{
						directions.angles[0] = 90;
						directions.angles[1] = 90;
					}
					else if(x == top)
					{
						directions.angles[0] = 0;
						directions.angles[1] = 0;
					}
					else if(x == bottom)
					{
						directions.angles[0] = 0;
						directions.angles[1] = 180;
					}
					else if(x == left_top)
					{
						directions.angles[0] = 270;
						directions.angles[1] = 45;
					}
					else if(x == right_top)
					{
						directions.angles[0] = 90;
						directions.angles[1] = 45;
					}
					else if(x == right_bottom)
					{
						directions.angles[0] = 90;
						directions.angles[1] = 135;
					}
					else if(x == left_bottom)
					{
						directions.angles[0] = 270;
						directions.angles[1] = 135;
					}
					else if(x == front)
					{
						directions.angles[0] = 0;
						directions.angles[1] = 90;
					}
					else if(x == back)
					{
						directions.angles[0] = 180;
						directions.angles[1] = 90;
					}
					else if(x == left_front)
					{
						directions.angles[0] = 315;
						directions.angles[1] = 90;
					}
					else if(x == right_front)
					{
						directions.angles[0] = 45;
						directions.angles[1] = 90;
					}
					else if(x == top_front)
					{
						directions.angles[0] = 0;
						directions.angles[1] = 45;
					}
					else if(x == bottom_front)
					{
						directions.angles[0] = 0;
						directions.angles[1] = 135;
					}
					else if(x == left_back)
					{
						directions.angles[0] = 225;
						directions.angles[1] = 90;
					}
					else if(x == right_back)
					{
						directions.angles[0] = 135;
						directions.angles[1] = 90;
					}
					else if(x == top_back)
					{
						directions.angles[0] = 180;
						directions.angles[1] = 45;
					}
					else if(x == bottom_back)
					{
						directions.angles[0] = 180;
						directions.angles[1] = 135;
					}
					else if(x == left_top_front)
					{
						directions.angles[0] = 315;
						directions.angles[1] = 45;
					}
					else if(x == right_top_front)
					{
						directions.angles[0] = 45;
						directions.angles[1] = 45;
					}
					else if(x == left_bottom_front)
					{
						directions.angles[0] = 315;
						directions.angles[1] = 135;
					}
					else if(x == right_bottom_front)
					{
						directions.angles[0] = 45;
						directions.angles[1] = 135;
					}
					else if(x == left_top_back)
					{
						directions.angles[0] = 225;
						directions.angles[1] = 45;
					}
					else if(x == right_top_back)
					{
						directions.angles[0] = 135;
						directions.angles[1] = 45;
					}
					else if(x == left_bottom_back)
					{
						directions.angles[0] = 225;
						directions.angles[1] = 135;
					}
					else if(x == right_bottom_back)
					{
						directions.angles[0] = 135;
						directions.angles[1] = 135;
					}
				}
			}

			void operator =(const vector_unit<T>& x)
			{
				if(x.is_defined())
				{
					if(x.equal_dimensions(unit_crtp<T>::get_dimensions_match()))
					{
						unit::value = x.unit::get_value();
						r = lambda_value();
						unit::actual_dimensions = x.get_actual_dimensions();
						unit::real_dimensions = x.get_real_dimensions();
						if (x.is_1d())
						{
							directions.direction = x.get_direction();
							unidimensional = true;
						}
						else
						{
							directions.angles = x.get_angles();
						}
					}
					else
					{
						unit::invalidate(7);
					}
				}
				else
				{
					unit::invalidate(1);
				}
			}

			/*virtual unit* clone() const
			{
				return new T(static_cast<const T&>(*this));
			}*/

			template<typename U>
			T operator +(const vector_unit<U>& y)
			{
				T z = *unit_crtp<T>::clone();
				z += y;
				return z;
			}

			template<typename U>
			T operator -(const vector_unit<U>& y)
			{
				T z = *unit_crtp<T>::clone();
				z -= y;
				return z;
			}

			template<typename U>
			vector_unit_tuple operator *(const vector_unit<U>& y)
			{
				if(unit::is_defined() and y.is_defined() and is_3d() and y.is_3d())
				{
					space_type new_value;
					angle_type angle1;
					angle_type angle2;
					if(y.get_angle(1) == get_angle(1) and y.get_angle(2) == get_angle(2))
					{
						new_value = 0;
						angle1 = 0;
						angle2 = 0;
					}
					else
					{
						space_type new_x = y_projection() * y.z_projection() - z_projection() * y.y_projection();
						space_type new_y = z_projection() * y.x_projection() - x_projection() * y.z_projection();
						space_type new_z = x_projection() * y.y_projection() - y_projection() * y.x_projection();
						new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
						angle1 = cartesian_3d_to_spherical_angle1(new_x, new_y, new_z);
						angle2 = cartesian_3d_to_spherical_angle2(new_x, new_y, new_z);
					}
					unit_real_dimensions new_real_dimensions = multiply_real_dimensions(unit::get_real_dimensions(), y.get_real_dimensions());
					unit_actual_dimensions new_actual_dimensions = multiply_actual_dimensions(unit::get_actual_dimensions(), y.get_actual_dimensions());
					unit new_unit = unit(new_value, new_real_dimensions, new_actual_dimensions);
					list<angle_type> angles;
					angles.push_back(angle1);
					angles.push_back(angle2);
					return vector_unit_tuple(new_unit, angles);
				}
				else
				{
					unit z = 0;
					z.invalidate(13);
					return vector_unit_tuple(z, {});
				}
			}

			template<typename U>
			void operator +=(const vector_unit<U>& y)
			{
				if(equal_dimensions(*this, y) and unit::is_defined() and y.is_defined())
				{
					if(is_1d())
					{
						if(get_direction() == y.get_direction())
						{
							unit::value += y.unit::get_value();
						}
						else
						{
							unit::value -= y.unit::get_value();
							if(unit::value < 0)
							{
								directions.direction.invert();
								unit::value = math::number::abs(unit::value);
							}
						}
					}
					else if(is_2d())
					{
						space_type new_x = x_projection() + y.x_projection();
						space_type new_y = y_projection() + y.y_projection();
						unit::value = cartesian_2d_to_polar_r(new_x, new_y);
						directions.angles[0] = cartesian_2d_to_polar_angle(new_x, new_y);
					}
					else if(is_3d())
					{
						space_type new_x = x_projection() + y.x_projection();
						space_type new_y = y_projection() + y.y_projection();
						space_type new_z = z_projection() + y.z_projection();
						unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
						directions.angles[0] = cartesian_3d_to_spherical_angle1(new_x, new_y, new_z);
						directions.angles[1] = cartesian_3d_to_spherical_angle2(new_x, new_y, new_z);
					}
				}
				else
				{
					unit::invalidate(8);
				}
			}

			template<typename U>
			void operator -=(const vector_unit<U>& y)
			{
				if(equal_dimensions(*this, y) and unit::is_defined() and y.is_defined())
				{
					U z = *y.clone();
					z.invert();
					*this += z;
				}
				else
				{
					unit::invalidate(9);
				}
			}

			template<typename U>
			vector_unit_tuple operator *(const scalar_unit<U>& x)
			{
				space_type new_value = unit::value.get_value() * x.get_value().get_value();
				unit_real_dimensions new_real_dimensions = multiply_real_dimensions(unit::get_real_dimensions(), x.get_real_dimensions());
				unit_actual_dimensions new_actual_dimensions = multiply_actual_dimensions(unit::get_actual_dimensions(), x.get_actual_dimensions());
				unit new_unit = unit(new_value, new_real_dimensions, new_actual_dimensions);
				if(is_1d())
				{
					return vector_unit_tuple(new_unit, directions.direction.get_direction());
				}
				else if(is_2d())
				{
					return vector_unit_tuple(new_unit, {directions.angles[0]});
				}
				else if(is_3d())
				{
					return vector_unit_tuple(new_unit, {directions.angles[0], directions.angles[1]});
				}
			}

			template<typename U>
			vector_unit_tuple operator /(const scalar_unit<U>& x)
			{
				space_type new_value = unit::value.get_value() / x.get_value().get_value();
				unit_real_dimensions new_real_dimensions = divide_real_dimensions(unit::get_real_dimensions(), x.get_real_dimensions());
				unit_actual_dimensions new_actual_dimensions = divide_actual_dimensions(unit::get_actual_dimensions(), x.get_actual_dimensions());
				unit new_unit = unit(new_value, new_real_dimensions, new_actual_dimensions);
				if(is_1d())
				{
					return vector_unit_tuple(new_unit, directions.direction.get_direction());
				}
				else if(is_2d())
				{
					return vector_unit_tuple(new_unit, {directions.angles[0]});
				}
				else if(is_3d())
				{
					return vector_unit_tuple(new_unit, {directions.angles[0], directions.angles[1]});
				}
			}

			template<typename U>
			vector_unit_tuple operator ^(const scalar_unit<U>& x)
			{
				if(x.empty_dimensions())
				{
					unit new_unit = unit::operator^(*this, x);
					if(is_1d())
					{
						return vector_unit_tuple(new_unit, directions.direction.get_direction());
					}
					else if(is_2d())
					{
						return vector_unit_tuple(new_unit, {directions.angles[0]});
					}
					else if(is_3d())
					{
						return vector_unit_tuple(new_unit, {directions.angles[0], directions.angles[1]});
					}
				}
				else
				{
					return vector_unit_tuple(0, {});
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator =(U y)
			{
				unit::value = y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator +(U y)
			{
				T z = *unit_crtp<T>::clone();
				z += y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator -(U y)
			{
				T z = *unit_crtp<T>::clone();
				z -= y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator *(U y)
			{
				T z = *unit_crtp<T>::clone();
				z *= y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator /(U y)
			{
				T z = *unit_crtp<T>::clone();
				z /= y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_tuple operator ^(U y)
			{
				unit new_value = float(unit::value ^ y);
				if (is_1d())
				{
					return vector_unit_tuple(new_value, get_direction());
				}
				else
				{
					list<angle_type> new_angles = list<angle_type>();
					new_angles.push_back(float(directions.angles[0]));
					new_angles.push_back(float(directions.angles[1]));
					return vector_unit_tuple(new_value, new_angles);
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				unit::value += y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				unit::value -= y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				unit::value *= y;
				if(y < 0)
				{
					for(math::number::angle_number& angle : directions.angles)
					{
						angle *= -1;
					}
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				unit::value /= y;
				if(y < 0)
				{
					for(math::number::angle_number& angle : directions.angles)
					{
						angle *= -1;
					}
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				unit::value ^= y;
			}

		private:
			inline function<space_type()> lambda_value()
			{
				return [this]()
				{
					return unit::value.get_value();
				};
			}
	};

	class auto_vector : public vector_unit<auto_vector>
	{
		public:
			auto_vector();

			static const string dimensions_match;
	};

	template<typename T, typename = typename enable_if<is_base_of<vector_unit<T>, T>::value>::type>
	typename vector_unit<T>::custom_vector sqrt(const T& x)
	{
		unit new_value = physics::units::sqrt(x.get_value());
		return vector_unit<T>::custom_vector(new_value, x.get_angles());
	}

	template<typename T, typename = typename enable_if<is_base_of<vector_unit<T>, T>::value>::type>
	typename vector_unit<T>::custom_vector sqrt_nth(const T& x, int y)
	{
		unit new_value = physics::units::sqrt_nth(x.get_value(), y);
		return vector_unit<T>::custom_vector(new_value, x.get_angles());
	}

	template<typename T, typename U, typename V>
	scalar_unit<T> dot_product(const vector_unit<U>& x, const vector_unit<V>& y)
	{
	}

	template<typename T, typename = typename enable_if<is_base_of<vector_unit<T>, T>::value>::type, typename U, typename = typename enable_if<is_base_of<vector_unit<U>, U>::value>::type>
	bool same_dimensions(const T& x, const U& y)
	{
		if(x.get_angles().size() == y.get_angles().size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename T, typename = typename enable_if<is_base_of<vector_unit<T>, T>::value>::type, typename U, typename = typename enable_if<is_base_of<vector_unit<U>, U>::value>::type>
	bool same_direction(const T& x, const U& y)
	{
		math::topology::angle_container compare_angles = x.get_angles();
		math::topology::angle_container other_angles = y.get_angles();
		for(int i = 0; i < compare_angles.size(); i++)
		{
			if(compare_angles[i] != other_angles[i])
			{
				return false;
			}
		}
		return true;
	}

	template<typename T, typename = typename enable_if<is_base_of<vector_unit<T>, T>::value>::type, typename U, typename = typename enable_if<is_base_of<vector_unit<U>, U>::value>::type>
	bool parallel(const T& x, const U& y)
	{
		math::topology::angle_container compare_angles = x.get_angles();
		math::topology::angle_container other_angles = y.get_angles();
		for(int i = 0; i < compare_angles.size(); i++)
		{
			if(!math::number::parallel(compare_angles[i], other_angles[i]))
			{
				return false;
			}
		}
		return true;
	}

	template<typename T, typename = typename enable_if<is_base_of<vector_unit<T>, T>::value>::type, typename U, typename = typename enable_if<is_base_of<vector_unit<U>, U>::value>::type>
	bool orthogonal(const T& x, const U& y)
	{
		math::topology::angle_container compare_angles = x.get_angles();
		math::topology::angle_container other_angles = y.get_angles();
		for(int i = 0; i < compare_angles.size(); i++)
		{
			if(math::number::orthogonal(compare_angles[i], other_angles[i]))
			{
				return true;
			}
		}
		return false;
	}
}

template<typename T, typename = typename enable_if<is_base_of<physics::units::vector_unit<T>, T>::value>::type, typename U, typename = typename enable_if<is_base_of<physics::units::vector_unit<U>, U>::value>::type>
bool operator ==(const T& x, const U& y)
{
	if(physics::units::same_dimensions(x, y))
	{
		if(x.get_value() == y.get_value() and physics::units::same_direction(x, y))
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
		throw invalid_argument("Cannot compare vectors of different dimensions");
	}
}

template<typename T, typename = typename enable_if<is_base_of<physics::units::vector_unit<T>, T>::value>::type, typename U, typename = typename enable_if<is_base_of<physics::units::vector_unit<U>, U>::value>::type>
bool operator !=(const T& x, const U& y)
{
	return !(x == y);
}

template<typename T>
void operator +=(wstring& x, const physics::units::vector_unit<T>& y)
{
	wostringstream output;
	output << y;
	x += output.str();
}

template<typename T>
wstring operator +(const wstring& x, const physics::units::vector_unit<T>& y)
{
	wostringstream output;
	output << x;
	output << y;
	return output.str();
}

template<typename T>
wstring operator +(const physics::units::vector_unit<T>& y, const wstring& x)
{
	wostringstream output;
	output << y;
	output << x;
	return output.str();
}

template<typename T>
wostream& operator <<(wostream& os, const physics::units::vector_unit<T>& x)
{
	wostringstream angles_text;
	if (x.is_1d())
	{
		if (x.get_direction() == direction_symbol::left)
		{
			angles_text << "(l)";
		}
		else if (x.get_direction() == direction_symbol::right)
		{
			angles_text << "(r)";
		}
	}
	else
	{
		int i = 0;
		for(const auto& angle : x.get_angles())
		{
			//angles_text << angle << L"θ" << i << L" ";
			angles_text << "angle" << (i + 1) << ": " << angle << " ";
			i++;
		}
	}
	return os << x.physics::units::unit::get_value() << " " << angles_text.str();
}

template<typename T>
istream& operator >>(istream& is, physics::units::vector_unit<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	physics::units::vector_unit<T> c(b);
	x = c;
	return is;
}

#endif // VECTORIAL_UNIT_HPP_INCLUDED
