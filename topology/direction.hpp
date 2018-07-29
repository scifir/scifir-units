#ifndef DIRECTION_HPP_INCLUDED
#define DIRECTION_HPP_INCLUDED

using namespace std;

namespace msci
{
	enum direction_symbol {left, right, top, bottom, front, back, left_top, left_bottom, right_top, right_bottom, left_front, left_back, right_front, right_back, top_front, top_back, bottom_front, bottom_back, left_top_front, left_top_back, left_bottom_front, left_bottom_back, right_top_front, right_top_back, right_bottom_front, right_bottom_back};

	direction_symbol opposite_direction(direction_symbol);

	class direction
	{
		public:
			direction();
			direction(direction_symbol);

			inline const direction_symbol& get_direction() const
			{
				return direction_value;
			}

			inline void invert()
			{
				direction_value = opposite_direction(direction_value);
			}

			void operator =(direction_symbol);

		protected:
			direction_symbol direction_value;
	};

	class direction_lr : public direction
	{
		public:
			direction_lr();
			direction_lr(direction_symbol);

			void operator =(direction_symbol);

			inline bool goes_left()
			{
				return (direction_value == left);
			}

			inline bool goes_right()
			{
				return (direction_value == right);
			}

			inline void go_left()
			{
				direction_value = left;
			}

			inline void go_right()
			{
				direction_value = right;
			}
	};
}

bool operator ==(const msci::direction& x, const msci::direction& y);
bool operator !=(const msci::direction& x, const msci::direction& y);
bool operator ==(const msci::direction& x, msci::direction_symbol y);
bool operator !=(const msci::direction& x, msci::direction_symbol y);
bool operator ==(msci::direction_symbol y, const msci::direction& x);
bool operator !=(msci::direction_symbol y, const msci::direction& x);
bool operator ==(const msci::direction_lr& x, const msci::direction_lr& y);
bool operator !=(const msci::direction_lr& x, const msci::direction_lr& y);
bool operator ==(const msci::direction_lr& x, msci::direction_symbol y);
bool operator !=(const msci::direction_lr& x, msci::direction_symbol y);
bool operator ==(msci::direction_symbol y, const msci::direction_lr& x);
bool operator !=(msci::direction_symbol y, const msci::direction_lr& x);

#endif // DIRECTION_HPP_INCLUDED
