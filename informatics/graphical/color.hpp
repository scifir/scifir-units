#ifndef COLOR_HPP_INCLUDED
#define COLOR_HPP_INCLUDED

#include <iostream>
#include <sstream>

using namespace std;

namespace informatics
{
	class color
	{
		public:
			color(int,int,int,int = 255);

			inline const int& get_red() const
			{
				return red;
			}

			inline const int& get_green() const
			{
				return green;
			}

			inline const int& get_blue() const
			{
				return blue;
			}

			inline const int& get_alpha() const
			{
				return alpha;
			}

			inline bool is_opaque() const
			{
				return (alpha == 255);
			}

			inline bool is_transparent() const
			{
				return (alpha < 255);
			}

			inline bool is_full_transparent() const
			{
				return (alpha == 0);
			}

			inline void print() const
			{
				wcout << *this;
			}

		private:
			int red;
			int blue;
			int green;
			int alpha;
	};
}

wostream& operator <<(wostream&, const color&);

#endif // COLOR_HPP_INCLUDED
