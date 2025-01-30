#include "./mind.hpp"

using namespace std;

namespace scifir
{
	string to_string(const alert_state& x)
	{
		if (x == alert_state::VIGIL)
		{
			return "VIGIL";
		}
		else if (x == alert_state::SLEEP)
		{
			return "SLEEP";
		}
		else if (x == alert_state::MEDITATION)
		{
			return "MEDITATION";
		}
		return "";
	}

    string to_string(const feeling& x)
	{
		if (x == feeling::SADNESS)
		{
			return "SADNESS";
		}
		else if (x == feeling::RANCOR)
		{
			return "RANCOR";
		}
		else if (x == feeling::LOVE)
		{
			return "LOVE";
		}
		return "";
	}

	string to_string(const emotion& x)
	{
		if (x == emotion::HAPPY)
		{
			return "HAPPY";
		}
		else if (x == emotion::EXCITED)
		{
			return "EXCITED";
		}
		else if (x == emotion::TENDER)
		{
			return "TENDER";
		}
		else if (x == emotion::SCARED)
		{
			return "SCARED";
		}
		else if (x == emotion::ANGRY)
		{
			return "ANGRY";
		}
		else if (x == emotion::SAD)
		{
			return "SAD";
		}
		return "";
	}

	string to_string(const sensation& x)
	{
		if (x == sensation::LIGHT)
		{
			return "LIGHT";
		}
		else if (x == sensation::SOUND)
		{
			return "SOUND";
		}
		else if (x == sensation::ACCELERATION)
		{
			return "ACCELERATION";
		}
		else if (x == sensation::ODOR)
		{
			return "ODOR";
		}
		else if (x == sensation::TASTE)
		{
			return "TASTE";
		}
		else if (x == sensation::TOUCH)
		{
			return "TOUCH";
		}
		else if (x == sensation::TEMPERATURE)
		{
			return "TEMPERATURE";
		}
		return "";
	}

	string to_string(const sense& x)
	{
		if (x == sense::SIGHT)
		{
			return "SIGHT";
		}
		else if (x == sense::HEARING)
		{
			return "HEARING";
		}
		else if (x == sense::SMELL)
		{
			return "SMELL";
		}
		else if (x == sense::TOUCH)
		{
			return "TOUCH";
		}
		else if (x == sense::TASTE)
		{
			return "TASTE";
		}
		else if (x == sense::THERMOCEPTION)
		{
			return "THERMOCEPTION";
		}
		else if (x == sense::PROPRIOCEPTION)
		{
			return "PROPRIOCEPTION";
		}
		return "";
	}

	string to_string(const conscience_state& x)
	{
		if (x == conscience_state::NORMAL)
		{
			return "NORMAL";
		}
		else if (x == conscience_state::ALTERED)
		{
			return "ALTERED";
		}
		return "";
	}
}