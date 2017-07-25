#ifndef BOUND_HPP_INCLUDED
#define BOUND_HPP_INCLUDED

#include "math/number/angle_number.hpp"
#include "physics/units.hpp"

using namespace std;
using namespace math::number;
using namespace physics::units;

namespace chemistry
{
	enum bound_kind {ionic, covalent, metallic};
	enum class bound_weight {simple, double, triple};

	class bound
	{
		public:
			bound(bound_weight);

			const bound_kind& kind() const; // Algorithmically
			const bound_weight& weight() const; // Stored!
			const length& size() const;
			const angle_number& get_angle() const; // This is the only one stored, the other can be retrieved from other classes
			int total_electrons() const;

		private:
			angle_number angle;
			bound weight weight;
			weak_ptr<atom> atom1;
			weak_ptr<atom> atom2;
	};
}

#endif // BOUND_HPP_INCLUDED
