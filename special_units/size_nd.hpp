#ifndef SCIFIR_UNITS_SPECIAL_UNITS_SIZE_ND_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_SIZE_ND_HPP_INCLUDED

#include "../derived_units/space_units.hpp"
#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	template<typename T = length>
	class size_nd
	{
		public:
			size_nd() : widths()
			{}

			size_nd(const size_nd<T>& x) : widths(x.widths)
			{}

			size_nd(size_nd<T>&& x) : widths(std::move(x.widths))
			{}

			template<typename U>
			explicit size_nd(const vector<U>& new_widths) : widths()
			{
				for(const U& new_width : new_widths)
				{
					widths.push_back(T(new_width));
				}
			}

			explicit size_nd(const vector<string>& new_widths) : widths()
			{
				for (const string& new_width : new_widths)
				{
					widths.push_back(T(new_width));
				}
			}

			explicit size_nd(const string& init_size_nd) : size_nd()
			{
				initialize_from_string(init_size_nd);
			}

			size_nd<T>& operator =(const size_nd<T>& x)
			{
				widths = x.widths;
				return *this;
			}

			size_nd<T>& operator =(size_nd<T>&& x)
			{
				widths = std::move(x.widths);
				return *this;
			}

			size_nd<T>& operator =(const string& init_size_nd)
			{
				initialize_from_string(init_size_nd);
				return *this;
			}

			bool is_nd(int i) const
			{
				return widths.size() == i;
			}

			int get_nd() const
			{
				return widths.size();
			}

			template<typename U>
			size_nd<T> operator +(const size_nd<U>& x) const
			{
				if (get_nd() == x.get_nd())
				{
					vector<T> new_widths = vector<T>();
					for (unsigned int i = 0; i < widths.size(); i++)
					{
						new_widths.push_back(widths[i]);
						new_widths[i] += T(x.widths[i]);
					}
					return size_nd<T>(new_widths);
				}
				else
				{
					return size_nd<T>();
				}
			}

			template<typename U>
			size_nd<T> operator -(const size_nd<U>& x) const
			{
				if (get_nd() == x.get_nd())
				{
					vector<T> new_widths = vector<T>();
					for (unsigned int i = 0; i < widths.size(); i++)
					{
						new_widths.push_back(widths[i]);
						new_widths[i] -= T(x.widths[i]);
					}
					return size_nd<T>(new_widths);
				}
				else
				{
					return size_nd<T>();
				}
			}

			template<typename U>
			void operator +=(const size_nd<U>& x)
			{
				if (get_nd() == x.get_nd())
				{
					for (unsigned int i = 0; i < widths.size(); i++)
					{
						widths[i] += T(x.widths[i]);
					}
				}
			}

			template<typename U>
			void operator -=(const size_nd<U>& x)
			{
				if (get_nd() == x.get_nd())
				{
					for (unsigned int i = 0; i < widths.size(); i++)
					{
						widths[i] -= T(x.widths[i]);
					}
				}
			}

			scalar_unit get_volume_nd() const
			{
				vector<dimension> new_dimensions = create_dimensions(widths[0].get_dimensions()[0].get_symbol() + std::to_string(get_nd()));
				float new_value = 1;
				for (unsigned int i = 0; i < widths.size(); i++)
				{
					new_value *= widths[i].get_value();
				}
				return scalar_unit(new_value,new_dimensions);
			}

			string display() const
			{
				if (widths.size() > 0)
				{
					ostringstream output;
					output << widths[0];
					if (widths.size() > 1)
					{
						for (unsigned int i = 1; i < widths.size(); i++)
						{
							output << " * " << widths[i];
						}
					}
					return output.str();
				}
				else
				{
					return "[empty]";
				}
			}

			vector<T> widths;

		private:
			void initialize_from_string(const string& init_size_nd)
			{
				widths.clear();
				vector<string> new_widths;
				boost::split(new_widths,init_size_nd,boost::is_any_of("*"));
				for (string& new_width : new_widths)
				{
					boost::trim(new_width);
					widths.push_back(T(new_width));
				}
			}
	};

	template<>
	class size_nd<float>
	{
		public:
			size_nd() : widths()
			{}

			size_nd(const size_nd<float>& x) : widths(x.widths)
			{}

			size_nd(size_nd<float>&& x) : widths(std::move(x.widths))
			{}

			explicit size_nd(const vector<float>& new_widths) : widths(new_widths)
			{}

			explicit size_nd(const vector<string>& new_widths) : widths()
			{
				for (const string& new_width : new_widths)
				{
					widths.push_back(stof(new_width));
				}
			}

			explicit size_nd(const string& init_size_nd) : size_nd()
			{
				initialize_from_string(init_size_nd);
			}

			size_nd<float>& operator =(const size_nd<float>& x)
			{
				widths = x.widths;
				return *this;
			}

			size_nd<float>& operator =(size_nd<float>&& x)
			{
				widths = std::move(x.widths);
				return *this;
			}

			size_nd<float>& operator =(const string& init_size_nd)
			{
				initialize_from_string(init_size_nd);
				return *this;
			}

			bool is_nd(unsigned int i) const
			{
				return widths.size() == i;
			}

			int get_nd() const
			{
				return int(widths.size());
			}

			size_nd<float> operator +(const size_nd<float>& x) const
			{
				if (get_nd() == x.get_nd())
				{
					vector<float> new_widths = widths;
					for (unsigned int i = 0; i < new_widths.size(); i++)
					{
						new_widths[i] += x.widths[i];
					}
					return size_nd<float>(new_widths);
				}
				else
				{
					return size_nd<float>();
				}
			}

			size_nd<float> operator -(const size_nd<float>& x) const
			{
				if (get_nd() == x.get_nd())
				{
					vector<float> new_widths = widths;
					for (unsigned int i = 0; i < new_widths.size(); i++)
					{
						new_widths[i] -= x.widths[i];
					}
					return size_nd<float>(new_widths);
				}
				else
				{
					return size_nd<float>();
				}
			}

			void operator +=(const size_nd<float>& x)
			{
				if (get_nd() == x.get_nd())
				{
					for (unsigned int i = 0; i < widths.size(); i++)
					{
						widths[i] += x.widths[i];
					}
				}
			}

			void operator -=(const size_nd<float>& x)
			{
				if (get_nd() == x.get_nd())
				{
					for (unsigned int i = 0; i < widths.size(); i++)
					{
						widths[i] -= x.widths[i];
					}
				}
			}

			float get_volume_nd() const
			{
				float new_value = 1;
				for (unsigned int i = 0; i < widths.size(); i++)
				{
					new_value *= widths[i];
				}
				return new_value;
			}

			string display() const
			{
				if (widths.size() > 0)
				{
					ostringstream output;
					output << display_float(widths[0],2);
					if (widths.size() > 1)
					{
						for (unsigned int i = 1; i < widths.size(); i++)
						{
							output << " * " << display_float(widths[i],2);
						}
					}
					return output.str();
				}
				else
				{
					return "[empty]";
				}
			}

			vector<float> widths;

		private:
			void initialize_from_string(const string& init_size_nd)
			{
				widths.clear();
				vector<string> new_widths;
				boost::split(new_widths,init_size_nd,boost::is_any_of("*"));
				for (string& new_width : new_widths)
				{
					boost::trim(new_width);
					widths.push_back(stof(new_width));
				}
			}
	};

	template<typename T>
	string to_string(const size_nd<T>& x)
	{
		return x.display();
	}

	string to_string(const size_nd<float>& x);
}

template<typename T>
bool operator ==(const scifir::size_nd<T>& x, const scifir::size_nd<T>& y)
{
	if (x.get_nd() == y.get_nd())
	{
		for (int i = 0; i < x.widths.size(); i++)
		{
			if (x.widths[i] != y.widths[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const scifir::size_nd<T>& x, const scifir::size_nd<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const scifir::size_nd<T>& x, const string& init_size_nd)
{
	scifir::size_nd<T> y(init_size_nd);
	return (x == y);
}

template<typename T>
bool operator !=(const scifir::size_nd<T>& x, const string& init_size_nd)
{
	return !(x == init_size_nd);
}

template<typename T>
bool operator ==(const string& init_size_nd, const scifir::size_nd<T>& x)
{
	scifir::size_nd<T> y(init_size_nd);
	return (x == y);
}

template<typename T>
bool operator !=(const string& init_size_nd, const scifir::size_nd<T>& x)
{
	return !(init_size_nd == x);
}

template<typename T>
void operator +=(string& x, const scifir::size_nd<T>& y)
{
	x += to_string(y);
}

template<typename T>
string operator +(const string& x, const scifir::size_nd<T>& y)
{
	return x + to_string(y);
}

template<typename T>
string operator +(const scifir::size_nd<T>& x, const string& y)
{
	return to_string(x) + y;
}

template<typename T>
ostream& operator <<(ostream& os, const scifir::size_nd<T>& x)
{
	return os << to_string(x);
}

template<typename T>
istream& operator >>(istream& is, scifir::size_nd<T>& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	x = scifir::size_nd<T>(b);
	return is;
}

#endif // SCIFIR_UNITS_SPECIAL_UNITS_SIZE_ND_HPP_INCLUDED

