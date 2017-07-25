#include "vector_unit.hpp"

using namespace math::topology;

namespace physics::units
{
    auto_vector::auto_vector() : vector_unit("1 N")
    {
    }

    const string auto_vector::dimensions_match = "";
}
