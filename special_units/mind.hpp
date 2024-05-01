#ifndef SCIFIR_UNITS_SPECIAL_UNITS_MIND_HPP_INCLUDED
#define SCIFIR_UNITS_SPECIAL_UNITS_MIND_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
    enum class alert_state { VIGIL, SLEEP, MEDITATION };

    enum class feeling { SADNESS, RANCOR, LOVE };

    enum class emotion { HAPPY, EXCITED, TENDER, SCARED, ANGRY, SAD };

    enum class sensation { LIGHT, SOUND, ACCELERATION, ODOR, TASTE, TOUCH, TEMPERATURE };

    enum class conscience_state { NORMAL, ALTERED };

    string to_string(const feeling&);
    string to_string(const emotion&);
    string to_string(const sensation&);
}

#endif // SCIFIR_UNITS_SPECIAL_UNITS_MIND_HPP_INCLUDED