#ifndef DIRECTION_HPP_INCLUDED
#define DIRECTION_HPP_INCLUDED

using namespace std;

namespace math::topology
{
	enum direction_symbol {left, right, top, bottom, front, back, left_top, left_bottom, right_top, right_bottom, left_front, left_back, right_front, right_back, top_front, top_back, bottom_front, bottom_back, left_top_front, left_top_back, left_bottom_front, left_bottom_back, right_top_front, right_top_back, right_bottom_front, right_bottom_back};

	class direction
	{
		public:
			direction(direction_symbol);

			const direction_symbol& get_direction() const;

			void invert();

			void operator =(direction_symbol);

		protected:
			direction_symbol direction_value;
	};

	class direction_lr : public direction
	{
		public:
			direction_lr(direction_symbol);

			void operator =(direction_symbol);

			bool goes_left();
			bool goes_right();

			void go_left();
			void go_right();
	};

	direction_symbol opposite_direction(direction_symbol);
}

bool operator ==(const math::topology::direction& x, const math::topology::direction& y);
bool operator !=(const math::topology::direction& x, const math::topology::direction& y);
bool operator ==(const math::topology::direction& x, math::topology::direction_symbol y);
bool operator !=(const math::topology::direction& x, math::topology::direction_symbol y);
bool operator ==(math::topology::direction_symbol y, const math::topology::direction& x);
bool operator !=(math::topology::direction_symbol y, const math::topology::direction& x);
bool operator ==(const math::topology::direction_lr& x, const math::topology::direction_lr& y);
bool operator !=(const math::topology::direction_lr& x, const math::topology::direction_lr& y);
bool operator ==(const math::topology::direction_lr& x, math::topology::direction_symbol y);
bool operator !=(const math::topology::direction_lr& x, math::topology::direction_symbol y);
bool operator ==(math::topology::direction_symbol y, const math::topology::direction_lr& x);
bool operator !=(math::topology::direction_symbol y, const math::topology::direction_lr& x);

#endif // DIRECTION_HPP_INCLUDED
