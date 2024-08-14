#include "./body.hpp"

using namespace std;

namespace scifir
{
	string to_string(const movement& x)
    {
		if (x == movement::STILL)
		{
			return "STILL";
		}
		else if (x == movement::WALK)
		{
			return "WALK";
		}
		else if (x == movement::RUN)
		{
			return "RUN";
		}
		else if (x == movement::SWIM)
		{
			return "SWIM";
		}
		else if (x == movement::CLIMB)
		{
			return "CLIMB";
		}
		else if (x == movement::FLY)
		{
			return "FLY";
		}
	}
	
	string to_string(const movement_state& x)
    {
		if (x == movement_state::STILL)
		{
			return "STILL";
		}
		else if (x == movement_state::ACTIVE)
		{
			return "ACTIVE";
		}
	}
	
	string to_string(const body_health& x)
	{
		if (x == body_health::HEALTHY)
		{
			return "HEALTHY";
		}
		else if (x == body_health::DAMAGED)
		{
			return "DAMAGED";
		}
		else if (x == body_health::SICK)
		{
			return "SICK";
		}
		else if (x == body_health::SICK_AND_DAMAGED)
		{
			return "SICK_AND_DAMAGED";
		}
	}
}