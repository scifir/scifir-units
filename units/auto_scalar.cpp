#include "msci/units/units/auto_scalar.hpp"

#include "msci/units/units/conversion.hpp"

#include "boost/algorithm/string/erase.hpp"

#include <iostream>

using namespace std;

namespace msci
{
	auto_scalar::auto_scalar() : scalar_unit()
	{
	}

	auto_scalar::auto_scalar(const auto_scalar& x) : scalar_unit(x)
	{
	}

	auto_scalar::auto_scalar(auto_scalar&& x) : scalar_unit(move(x))
	{
	}

	auto_scalar::auto_scalar(msci::space_type new_value, const string& dimension_structure) : scalar_unit(new_value,dimension_structure)
	{
	}

	auto_scalar::auto_scalar(msci::unit_number new_value, const vector_real_dimensions& new_real_dimensions, const vector_actual_dimensions& new_actual_dimensions) : scalar_unit(new_value,new_actual_dimensions)
	{
	}

	auto_scalar::auto_scalar(const scalar_unit& new_value,const string& init_value) : scalar_unit(new_value,init_value)
	{
	}

	auto_scalar::auto_scalar(scalar_unit&& new_value,const string& init_value) : scalar_unit(move(new_value),init_value)
	{
	}

	auto_scalar::auto_scalar(const string& init_value) : scalar_unit(init_value)
	{
	}

	auto_scalar::auto_scalar(const scalar_unit& x) : scalar_unit(x)
	{
	}

	auto_scalar::auto_scalar(scalar_unit&& x) : scalar_unit(move(x))
	{
	}

	void auto_scalar::initialize_real_dimensions(string init_value)
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
						value *= new_conversion.get_factor() * new_scale;
					}
					else
					{
						value /= new_conversion.get_factor() * new_scale;
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

	string auto_scalar::get_dimensions_match() const
	{
		return get_dimension_structure(real_dimensions);
	}

	vector_real_dimensions auto_scalar::get_real_dimensions() const
	{
		return real_dimensions;
	}
}
