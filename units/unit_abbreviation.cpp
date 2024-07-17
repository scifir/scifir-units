#include "./unit_abbreviation.hpp"

using namespace std;

scifir::frequency operator"" _YHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _ZHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _EHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _PHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _THz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _GHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _MHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _kHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _hHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _daHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _Hz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _dHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _cHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _mHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _uHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _nHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _pHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _fHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _aHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _zHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _yHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _YN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _ZN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _EN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _PN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _TN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _GN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _MN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _kN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _hN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _daN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _N(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _dN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _cN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _mN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _uN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _nN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _pN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _fN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _aN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _zN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _yN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _YPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _ZPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _EPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _PPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _TPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _GPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _MPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _kPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _hPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _daPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _Pa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _dPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _cPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _mPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _uPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _nPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _pPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _fPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _aPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _zPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _yPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _YJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ZJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _EJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _PJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _TJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _GJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _MJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _kJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _hJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _daJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _J(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _dJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _cJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _mJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _uJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _nJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _pJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _fJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _aJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _zJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _yJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _YW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _ZW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _EW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _PW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _TW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _GW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _MW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _kW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _hW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _daW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _W(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _dW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _cW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _mW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _uW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _nW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _pW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _fW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _aW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _zW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _yW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _YA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _ZA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _EA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _PA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _TA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _GA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _MA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _kA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _hA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _daA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _A(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _dA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _cA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _mA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _uA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _nA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _pA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _fA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _aA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _zA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _yA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _YV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _ZV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _EV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _PV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _TV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _GV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _MV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _kV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _hV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _daV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _V(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _dV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _cV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _mV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _uV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _nV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _pV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _fV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _aV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _zV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _yV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _YF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _ZF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _EF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _PF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _TF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _GF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _MF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _kF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _hF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _daF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _F(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _dF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _cF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _mF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _uF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _nF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _pF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _fF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _aF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _zF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _yF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _YOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _ZOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _EOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _POhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _TOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _GOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _MOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _kOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _hOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _daOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _Ohm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _dOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _cOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _mOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _uOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _nOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _pOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _fOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _aOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _zOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _yOhm(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _YS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _ZS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _ES(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _PS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _TS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _GS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _MS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _kS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _hS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _daS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _S(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _dS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _cS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _mS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x,{ scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _uS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _nS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _pS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _fS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _aS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _zS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _yS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _YWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _ZWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _EWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _PWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _TWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _GWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _MWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _kWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _hWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _daWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _Wb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _dWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _cWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _mWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _uWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _nWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _pWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _fWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _aWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _zWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _yWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _YT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _ZT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _ET(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _PT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _TT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _GT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

/*scifir::magnetic_strength operator"" _MT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}*/

scifir::magnetic_strength operator"" _kT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _hT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _daT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _T(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _dT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _cT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _mT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _uT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _nT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _pT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _fT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _aT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _zT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _yT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _YH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _ZH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _EH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _PH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _TH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _GH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _MH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _kH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _hH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _daH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _H(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _dH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _cH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _mH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _uH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _nH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _pH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _fH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _aH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _zH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _yH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Ylm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Zlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Elm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Plm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Tlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Glm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Mlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _klm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _hlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _dalm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _lm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _dlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _clm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _mlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _ulm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _nlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _plm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _flm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _alm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _zlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _ylm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Ylx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Zlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Elx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Plx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Tlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Glx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Mlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _klx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _hlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _dalx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _lx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _dlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _clx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _mlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _ulx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _nlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _plx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _flx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _alx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _zlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _ylx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _YBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _ZBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _EBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _PBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _TBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _GBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _MBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _kBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _hBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _daBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _Bq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _dBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _cBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _mBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _uBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _nBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _pBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _fBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _aBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _zBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _yBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _YGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ZGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _EGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _PGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _TGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _GGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _MGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _kGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _hGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _daGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _Gy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _dGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _cGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _mGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _uGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _nGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _pGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _fGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _aGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _zGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _yGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _YSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ZSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ESv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _PSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _TSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _GSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _MSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _kSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _hSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _daSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _Sv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _dSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _cSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _mSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _uSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _nSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _pSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _fSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _aSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _zSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ySv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Ykat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Zkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Ekat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Pkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Tkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Gkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Mkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _kkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _hkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _dakat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _kat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _dkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _ckat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _mkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _ukat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _nkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _pkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _fkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _akat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _zkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _ykat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _angstrom(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ANGSTROM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _L(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _mL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _min(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::MINUTE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _hour(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::HOUR,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _day(unsigned long long int x)
{
	return scifir::time_duration((long double)x, { scifir::dimension(scifir::dimension::DAY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _YAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ZAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _EAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _PAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _TAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _GAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _MAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _kAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _hAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _daAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _AU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _cAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _mAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _uAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _nAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _pAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _fAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _aAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _zAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _yAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Ypc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Zpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Epc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Ppc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Tpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Gpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Mpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _kpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _hpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dapc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _pc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _cpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _mpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _upc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _npc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ppc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _fpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _apc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _zpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ypc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _YeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ZeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _EeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _PeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _TeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _GeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _MeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _keV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _heV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _daeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _eV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _deV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ceV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _meV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ueV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _neV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _peV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _feV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _aeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _zeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _yeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Da(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::DALTON,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _amu(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::ATOMIC_MASS_UNIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Ybarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Zbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Ebarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Pbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Tbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Gbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Mbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _kbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _hbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _dabarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _barn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _dbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _cbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _mbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _ubarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _nbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _pbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _fbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _abarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _zbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _ybarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _YM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _ZM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _EM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _PM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _TM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _GM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _MM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _kM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _hM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _daM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _M(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _dM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _cM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _mM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _uM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _nM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _pM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _fM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _aM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _zM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _yM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _particles(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::PARTICLES,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::percentage operator"" _ppm(unsigned long long int x)
{
	return scifir::percentage((long double)x, scifir::percentage::PARTS_PER_MILLION);
}

/*scifir::percentage operator"" _ppb(unsigned long long int x)
{
	return scifir::percentage((long double)x, scifir::percentage::PARTS_PER_BILLION);
}

scifir::percentage operator"" _ppt(unsigned long long int x)
{
	return scifir::percentage((long double)x, scifir::percentage::PARTS_PER_TRILLION);
}

scifir::percentage operator"" _ppq(unsigned long long int x)
{
	return scifir::percentage((long double)x, scifir::percentage::PARTS_PER_QUATRILLION);
}*/

scifir::frequency operator"" _YHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _ZHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _EHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _PHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _THz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _GHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _MHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _kHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _hHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _daHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _Hz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _dHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _cHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _mHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _uHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _nHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _pHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _fHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _aHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _zHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _yHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _YN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _ZN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _EN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _PN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _TN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _GN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _MN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _kN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _hN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _daN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _N(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _dN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _cN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _mN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _uN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _nN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _pN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _fN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _aN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _zN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _yN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _YPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _ZPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _EPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _PPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _TPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _GPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _MPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _kPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _hPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _daPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _Pa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _dPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _cPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _mPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _uPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _nPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _pPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _fPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _aPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _zPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _yPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _YJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ZJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _EJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _PJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _TJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _GJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _MJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _kJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _hJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _daJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _J(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _dJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _cJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _mJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _uJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _nJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _pJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _fJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _aJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _zJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _yJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _YW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _ZW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _EW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _PW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _TW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _GW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _MW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _kW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _hW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _daW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _W(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _dW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _cW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _mW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _uW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _nW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _pW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _fW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _aW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _zW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _yW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _YA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _ZA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _EA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _PA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _TA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _GA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _MA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _kA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _hA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _daA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _A(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _dA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _cA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _mA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _uA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _nA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _pA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _fA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _aA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _zA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _yA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _YV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _ZV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _EV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _PV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _TV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _GV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _MV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _kV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _hV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _daV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _V(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _dV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _cV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _mV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _uV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _nV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _pV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _fV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _aV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _zV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _yV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _YF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _ZF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _EF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _PF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _TF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _GF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _MF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _kF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _hF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _daF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _F(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _dF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _cF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _mF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _uF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _nF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _pF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _fF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _aF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _zF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _yF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _YOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _ZOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _EOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _POhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _TOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _GOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _MOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _kOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _hOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _daOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _Ohm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _dOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _cOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _mOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _uOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _nOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _pOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _fOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _aOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _zOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _yOhm(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _YS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _ZS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _ES(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _PS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _TS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _GS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _MS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _kS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _hS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _daS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _S(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _dS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _cS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _mS(long double x)
{
	return scifir::electric_conductance(x,{ scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _uS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _nS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _pS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _fS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _aS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _zS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _yS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _YWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _ZWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _EWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _PWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _TWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _GWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _MWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _kWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _hWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _daWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _Wb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _dWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _cWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _mWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _uWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _nWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _pWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _fWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _aWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _zWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _yWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _YT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _ZT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _ET(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _PT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _TT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _GT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

/*scifir::magnetic_strength operator"" _MT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}*/

scifir::magnetic_strength operator"" _kT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _hT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _daT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _T(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _dT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _cT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _mT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _uT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _nT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _pT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _fT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _aT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _zT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _yT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _YH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _ZH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _EH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _PH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _TH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _GH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _MH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _kH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _hH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _daH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _H(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _dH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _cH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _mH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _uH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _nH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _pH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _fH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _aH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _zH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _yH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Ylm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Zlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Elm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Plm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Tlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Glm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Mlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _klm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _hlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _dalm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _lm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _dlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _clm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _mlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _ulm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _nlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _plm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _flm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _alm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _zlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _ylm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Ylx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Zlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Elx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Plx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Tlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Glx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Mlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _klx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _hlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _dalx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _lx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _dlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _clx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _mlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _ulx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _nlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _plx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _flx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _alx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _zlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _ylx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _YBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _ZBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _EBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _PBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _TBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _GBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _MBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _kBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _hBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _daBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _Bq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _dBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _cBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _mBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _uBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _nBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _pBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _fBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _aBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _zBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _yBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _YGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ZGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _EGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _PGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _TGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _GGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _MGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _kGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _hGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _daGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _Gy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _dGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _cGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _mGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _uGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _nGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _pGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _fGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _aGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _zGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _yGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _YSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ZSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ESv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _PSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _TSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _GSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _MSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _kSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _hSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _daSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _Sv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _dSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _cSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _mSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _uSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _nSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _pSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _fSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _aSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _zSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _ySv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Ykat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Zkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Ekat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Pkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Tkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Gkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Mkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _kkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _hkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _dakat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _kat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _dkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _ckat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _mkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _ukat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _nkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _pkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _fkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _akat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _zkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _ykat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _angstrom(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ANGSTROM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _L(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _mL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _min(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::MINUTE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _hour(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::HOUR,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::time_duration operator"" _day(long double x)
{
	return scifir::time_duration(x, { scifir::dimension(scifir::dimension::DAY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _YAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ZAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _EAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _PAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _TAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _GAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _MAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _kAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _hAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _daAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _AU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _cAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _mAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _uAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _nAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _pAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _fAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _aAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _zAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _yAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Ypc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Zpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Epc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Ppc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Tpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Gpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Mpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _kpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _hpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dapc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _pc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _dpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _cpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _mpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _upc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _npc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ppc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _fpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _apc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _zpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _ypc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _YeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ZeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _EeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _PeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _TeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _GeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _MeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _keV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _heV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _daeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _eV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _deV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ceV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _meV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ueV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _neV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _peV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _feV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _aeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _zeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _yeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Da(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::DALTON,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _amu(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::ATOMIC_MASS_UNIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Ybarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Zbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Ebarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Pbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Tbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Gbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Mbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _kbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _hbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _dabarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _barn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _dbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _cbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _mbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _ubarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _nbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _pbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _fbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _abarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _zbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _ybarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _YM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _ZM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _EM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _PM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _TM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _GM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _MM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _kM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _hM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _daM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _M(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _dM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _cM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _mM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _uM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _nM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _pM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _fM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _aM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _zM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _yM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::percentage operator"" _ppm(long double x)
{
	return scifir::percentage(x, scifir::percentage::PARTS_PER_MILLION);
}

/*scifir::percentage operator"" _ppb(long double x)
{
	return scifir::percentage(x, scifir::percentage::PARTS_PER_BILLION);
}

scifir::percentage operator"" _ppt(long double x)
{
	return scifir::percentage(x, scifir::percentage::PARTS_PER_TRILLION);
}

scifir::percentage operator"" _ppq(long double x)
{
	return scifir::percentage(x, scifir::percentage::PARTS_PER_QUATRILLION);
}*/
