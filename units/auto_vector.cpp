#include "msci/units/units/auto_vector.hpp"

#include "msci/units/units/conversion.hpp"

#include "boost/algorithm/string/erase.hpp"

using namespace std;

namespace msci
{
	auto_vector::auto_vector() : vector_unit()
	{
	}

	auto_vector::auto_vector(const auto_vector& x) : vector_unit(x)
	{
	}

	auto_vector::auto_vector(auto_vector&& x) : vector_unit(move(x))
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,direction_symbol new_direction) : vector_unit(new_value,new_direction)
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,angle_type new_angle1) : vector_unit(new_value,new_angle1)
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,angle_type new_angle1,angle_type new_angle2) : vector_unit(new_value,new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,msci::angle_container new_angles) : vector_unit(new_value,new_angles)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,direction_symbol new_direction) : vector_unit(move(new_value),new_direction)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,angle_type new_angle1) : vector_unit(move(new_value),new_angle1)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,angle_type new_angle1,angle_type new_angle2) : vector_unit(move(new_value),new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,msci::angle_container new_angles) : vector_unit(move(new_value),new_angles)
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,direction_symbol new_direction, const string& init_value) : vector_unit(new_value,new_direction,init_value)
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,angle_type new_angle1, const string& init_value) : vector_unit(new_value,new_angle1,init_value)
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : vector_unit(new_value,new_angle1,new_angle2,init_value)
	{
	}

	auto_vector::auto_vector(const scalar_unit& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit(new_value,new_angles,init_value)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,direction_symbol new_direction, const string& init_value) : vector_unit(move(new_value),new_direction,init_value)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,angle_type new_angle1, const string& init_value) : vector_unit(move(new_value),new_angle1,init_value)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : vector_unit(move(new_value),new_angle1,new_angle2,init_value)
	{
	}

	auto_vector::auto_vector(scalar_unit&& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit(move(new_value),new_angles,init_value)
	{
	}

	auto_vector::auto_vector(const string& init_value,direction_symbol new_direction) : vector_unit(init_value,new_direction)
	{
	}

	auto_vector::auto_vector(const string& init_value,angle_type new_angle1) : vector_unit(init_value,new_angle1)
	{
	}

	auto_vector::auto_vector(const string& init_value,angle_type new_angle1,angle_type new_angle2) : vector_unit(init_value,new_angle1,new_angle2)
	{
	}

	auto_vector::auto_vector(const string& init_value,msci::angle_container new_angles) : vector_unit(init_value,new_angles)
	{
	}

	auto_vector::auto_vector(const vector_unit& x) : vector_unit(x)
	{
	}

	auto_vector::auto_vector(vector_unit&& x) : vector_unit(move(x))
	{
	}

	/*auto_vector& auto_vector::operator =(const auto_vector& x)
	{
		vector_unit::operator=(x);
		return *this;
	}

	auto_vector& auto_vector::operator =(auto_vector&& x)
	{
		vector_unit::operator=(move(x));
		return *this;
	}

	auto_vector& auto_vector::operator =(const vector_unit& x)
	{
		vector_unit::operator=(x);
		return *this;
	}

	auto_vector& auto_vector::operator =(vector_unit&& x)
	{
		vector_unit::operator=(move(x));
		return *this;
	}

	auto_vector& auto_vector::operator =(const unit& x)
	{
		unit::operator=(x);
		return *this;
	}

	auto_vector& auto_vector::operator =(unit&& x)
	{
		unit::operator=(move(x));
		return *this;
	}

	auto_vector auto_vector::operator +(const vector_unit& x) const
	{
		return vector_unit::operator+(x);
	}

	auto_vector auto_vector::operator -(const vector_unit& x) const
	{
		return vector_unit::operator-(x);
	}

	void auto_vector::operator +=(const vector_unit& x)
	{
		vector_unit::operator+=(x);
	}

	void auto_vector::operator -=(const vector_unit& x)
	{
		vector_unit::operator-=(x);
	}

	auto_vector auto_vector::operator *(const scalar_unit& x) const
	{
		return vector_unit::operator*(x);
	}

	auto_vector auto_vector::operator /(const scalar_unit& x) const
	{
		return vector_unit::operator/(x);
	}

	auto_vector auto_vector::operator ^(const scalar_unit& x) const
	{
		return vector_unit::operator^(x);
	}*/

	void auto_vector::initialize_real_dimensions(string init_value)
	{
		int new_start = 0;
		int j = new_start;
		boost::algorithm::erase_all(init_value, " ");
		bool numerator = true;
		string new_dimension;
		int new_scale = 1;
		int new_size = 1;
		vector_real_dimensions new_real_dimensions = vector_real_dimensions();
		while(isalnum(init_value[j]) or init_value[j] == '*' or init_value[j] == '/' or init_value[j] == '_')
		{
			if(isdigit(init_value[j]))
			{
				new_dimension = init_value.substr(new_start, new_size - 1);
				new_scale = stoi(init_value.substr(j, 1));
			}
			else if(!(isalnum(init_value[j + 1]) or init_value[j + 1] == '_'))
			{
				new_dimension = init_value.substr(new_start, new_size);
			}
			if(init_value[j] == '*')
			{
				new_start = j + 1;
				new_size = 0;
			}
			else if(init_value[j] == '/')
			{
				numerator = false;
				new_start = j + 1;
				new_size = 0;
			}
			if(!new_dimension.empty())
			{
				dimension* new_dimension_real = create_dimension(new_dimension);
				abbreviation* new_abbreviation_actual;
				if(new_dimension_real != nullptr)
				{
					shared_ptr<dimension> real_dimension (new_dimension_real);
					if(new_scale > 1)
					{
						*real_dimension ^= new_scale;
					}
					if(numerator == false)
					{
						*real_dimension ^= -1;
					}
					new_real_dimensions[real_dimension->get_enum_type()] = real_dimension;

					new_abbreviation_actual = nullptr;
				}
				else
				{
					new_abbreviation_actual = create_abbreviation(new_dimension);
				}
				if(new_abbreviation_actual != nullptr)
				{
					shared_ptr<abbreviation> add_abbreviation (new_abbreviation_actual);
					if(new_scale > 1)
					{
						*add_abbreviation ^= new_scale;
					}
					if(numerator == false)
					{
						*add_abbreviation ^= -1;
					}
					vector_real_dimensions abbreviation_dimensions = create_real_dimensions(add_abbreviation->get_dimensions_match());
					for(const auto& map_value : abbreviation_dimensions)
					{
						/*for(int i = 0; i < abs(new_scale); i++)
						{
							if(new_real_dimensions.count(map_value.first) > 0)
							{
								if(numerator == true)
								{
									*new_real_dimensions[map_value.first] *= *map_value.second;
								}
								else
								{
									*new_real_dimensions[map_value.first] /= *map_value.second;
								}
							}
							else
							{
								new_real_dimensions[map_value.first] = map_value.second;
							}
						}*/
					}
				}
				else if(get_conversion.count(new_dimension) > 0)
				{
					conversion new_conversion = get_conversion[new_dimension];
					if(numerator == true)
					{
						scalar_unit::value *= new_conversion.get_factor() * new_scale;
					}
					else
					{
						scalar_unit::value /= new_conversion.get_factor() * new_scale;
					}
					dimension* new_dimension_real = create_dimension(new_conversion.get_unit_to());
					abbreviation* new_abbreviation_actual;
					if(new_dimension_real != nullptr)
					{
						shared_ptr<dimension> real_dimension (new_dimension_real);
						if(new_scale > 1)
						{
							*real_dimension ^= new_scale;
						}
						if(numerator == false)
						{
							*real_dimension ^= -1;
						}
						new_real_dimensions[real_dimension->get_enum_type()] = real_dimension;

						new_abbreviation_actual = nullptr;
					}
					else
					{
						new_abbreviation_actual = create_abbreviation(new_conversion.get_unit_to());
					}
					if(new_abbreviation_actual != nullptr)
					{
						shared_ptr<abbreviation> add_abbreviation (new_abbreviation_actual);
						if(new_scale > 1)
						{
							*add_abbreviation ^= new_scale;
						}
						if(numerator == false)
						{
							*add_abbreviation ^= -1;
						}
						actual_dimensions[add_abbreviation->get_enum_type()] = add_abbreviation;
						vector_real_dimensions abbreviation_dimensions = create_real_dimensions(add_abbreviation->get_dimensions_match());
						for(const auto& map_value : abbreviation_dimensions)
						{
							/*for(int i = 0; i < abs(new_scale); i++)
							{
								if(new_real_dimensions.count(map_value.first) > 0)
								{
									if(numerator == true)
									{
										*new_real_dimensions[map_value.first] *= *map_value.second;
									}
									else
									{
										*new_real_dimensions[map_value.first] /= *map_value.second;
									}
								}
								else
								{
									new_real_dimensions[map_value.first] = map_value.second;
								}
							}*/
						}
					}
				}
				new_dimension.clear();
				new_scale = 1;
				new_size = 0;
			}
			j++;
			new_size++;
		}
	}

	string auto_vector::get_dimensions_match() const
	{
		return get_dimension_structure(real_dimensions);
	}

	vector_real_dimensions auto_vector::get_real_dimensions() const
	{
		return real_dimensions;
	}
}

/*msci::auto_vector operator +(const msci::scalar_unit& x,const msci::vector_unit& y)
{
	msci::auto_vector z = msci::auto_vector(x,y.get_coordinates().get_angles());
	return z + y;
}

msci::auto_vector operator -(const msci::scalar_unit& x,const msci::vector_unit& y)
{
	msci::auto_vector z = msci::auto_vector(x,y.get_coordinates().get_angles());
	return z - y;
}

msci::auto_vector operator *(const msci::scalar_unit& x,const msci::vector_unit& y)
{
	return y * x;
}

msci::auto_vector operator +(const msci::scalar_unit& x,const msci::auto_unit& y)
{
	return x + dynamic_cast<const msci::vector_unit&>(y);
}

msci::auto_vector operator -(const msci::scalar_unit& x,const msci::auto_unit& y)
{
	return x - dynamic_cast<const msci::vector_unit&>(y);
}

msci::auto_vector operator *(const msci::scalar_unit& x,const msci::auto_unit& y)
{
	return x * dynamic_cast<const msci::vector_unit&>(y);
}

template<typename T>
msci::auto_vector operator +(const msci::scalar_unit& x,const msci::vector_unit_crtp<T>& y)
{
	return x + dynamic_cast<const msci::vector_unit&>(y);
}

template<typename T>
msci::auto_vector operator -(const msci::scalar_unit& x,const msci::vector_unit_crtp<T>& y)
{
	return x - dynamic_cast<const msci::vector_unit&>(y);
}

template<typename T>
msci::auto_vector operator *(const msci::scalar_unit& x,const msci::vector_unit_crtp<T>& y)
{
	return x * dynamic_cast<const msci::vector_unit&>(y);
}*/
