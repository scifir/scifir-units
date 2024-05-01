#ifndef SCIFIR_UNITS_SPECIAL_UNITS_BODY_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_BODY_HPP_INCLUDED

using namespace std;

namespace scifir
{
    enum class movement { STILL, WALK, RUN, SWIM, CLIMB, FLY };

    enum class movement_state { STILL, ACTIVE };

    enum class body_health { HEALTHY, DAMAGED, SICK, SICK_AND_DAMAGED };
}

#endif // SCIFIR_UNITS_SPECIAL_UNITS_BODY_HPP_INCLUDED