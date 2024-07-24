#include "./unit_abbreviation.hpp"

using namespace std;

scifir::frequency operator"" _QHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _RHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

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

scifir::frequency operator"" _µHz(unsigned long long int x)
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

scifir::frequency operator"" _rHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _qHz(unsigned long long int x)
{
	return scifir::frequency((long double)x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _QN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _RN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::force operator"" _µN(unsigned long long int x)
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

scifir::force operator"" _rN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _qN(unsigned long long int x)
{
	return scifir::force((long double)x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _QPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _RPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::pressure operator"" _µPa(unsigned long long int x)
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

scifir::pressure operator"" _rPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _qPa(unsigned long long int x)
{
	return scifir::pressure((long double)x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _QJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _RJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::energy operator"" _µJ(unsigned long long int x)
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

scifir::energy operator"" _rJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _qJ(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _QW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _RW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::power operator"" _µW(unsigned long long int x)
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

scifir::power operator"" _rW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _qW(unsigned long long int x)
{
	return scifir::power((long double)x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _QA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _RA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::electric_current operator"" _µA(unsigned long long int x)
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

scifir::electric_current operator"" _rA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _qA(unsigned long long int x)
{
	return scifir::electric_current((long double)x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _QV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _RV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::voltage operator"" _µV(unsigned long long int x)
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

scifir::voltage operator"" _rV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _qV(unsigned long long int x)
{
	return scifir::voltage((long double)x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _QF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _RF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::capacitance operator"" _µF(unsigned long long int x)
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

scifir::capacitance operator"" _rF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _qF(unsigned long long int x)
{
	return scifir::capacitance((long double)x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _QΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _RΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _YΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _ZΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _EΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _PΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _TΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _GΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _MΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _kΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _hΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _daΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _Ω(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _dΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _cΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _mΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _µΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _nΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _pΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _fΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _aΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _zΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _yΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _rΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _qΩ(unsigned long long int x)
{
	return scifir::resistance((long double)x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _QS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _RS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::electric_conductance operator"" _µS(unsigned long long int x)
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

scifir::electric_conductance operator"" _rS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _qS(unsigned long long int x)
{
	return scifir::electric_conductance((long double)x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _QWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _RWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::magnetic_flux operator"" _µWb(unsigned long long int x)
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

scifir::magnetic_flux operator"" _rWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _qWb(unsigned long long int x)
{
	return scifir::magnetic_flux((long double)x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _QT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _RT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::magnetic_strength operator"" _µT(unsigned long long int x)
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

scifir::magnetic_strength operator"" _rT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _qT(unsigned long long int x)
{
	return scifir::magnetic_strength((long double)x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _QH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _RH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::inductance operator"" _µH(unsigned long long int x)
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

scifir::inductance operator"" _rH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _qH(unsigned long long int x)
{
	return scifir::inductance((long double)x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Qlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Rlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::luminous_flux operator"" _µlm(unsigned long long int x)
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

scifir::luminous_flux operator"" _rlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _qlm(unsigned long long int x)
{
	return scifir::luminous_flux((long double)x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Qlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Rlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::illuminance operator"" _µlx(unsigned long long int x)
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

scifir::illuminance operator"" _rlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _qlx(unsigned long long int x)
{
	return scifir::illuminance((long double)x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _QBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _RBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::radioactivity operator"" _µBq(unsigned long long int x)
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

scifir::radioactivity operator"" _rBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _qBq(unsigned long long int x)
{
	return scifir::radioactivity((long double)x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _QGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _RGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::ionizing_radiation operator"" _µGy(unsigned long long int x)
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

scifir::ionizing_radiation operator"" _rGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _qGy(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _QSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _RSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::ionizing_radiation operator"" _µSv(unsigned long long int x)
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

scifir::ionizing_radiation operator"" _rSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _qSv(unsigned long long int x)
{
	return scifir::ionizing_radiation((long double)x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Qkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Rkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::catalytic_activity operator"" _µkat(unsigned long long int x)
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

scifir::catalytic_activity operator"" _rkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _qkat(unsigned long long int x)
{
	return scifir::catalytic_activity((long double)x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Å(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ANGSTROM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _QL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _RL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _YL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _ZL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _EL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _PL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _TL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _GL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _ML(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _kL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _hL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _daL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _L(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _dL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _cL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _mL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _µL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _nL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _pL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _fL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _aL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _zL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _yL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _rL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _qL(unsigned long long int x)
{
	return scifir::volume((long double)x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
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

scifir::length operator"" _QAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _RAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::length operator"" _µAU(unsigned long long int x)
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

scifir::length operator"" _rAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _qAU(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Qpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Rpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::length operator"" _µpc(unsigned long long int x)
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

scifir::length operator"" _rpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _qpc(unsigned long long int x)
{
	return scifir::length((long double)x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _QeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ReV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::energy operator"" _µeV(unsigned long long int x)
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

scifir::energy operator"" _reV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _qeV(unsigned long long int x)
{
	return scifir::energy((long double)x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Da(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::DALTON,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _amu(unsigned long long int x)
{
	return scifir::mass((long double)x, { scifir::dimension(scifir::dimension::ATOMIC_MASS_UNIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Qbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Rbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::area operator"" _µbarn(unsigned long long int x)
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

scifir::area operator"" _rbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _qbarn(unsigned long long int x)
{
	return scifir::area((long double)x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _QM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _RM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::molarity operator"" _µM(unsigned long long int x)
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

scifir::molarity operator"" _rM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _qM(unsigned long long int x)
{
	return scifir::molarity((long double)x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::mole operator"" _particles(unsigned long long int x)
{
	return scifir::mole((long double)x, { scifir::dimension(scifir::dimension::PARTICLES,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::scalar_unit operator"" _memo(unsigned long long int x)
{
	return scifir::scalar_unit((long double)x, { scifir::dimension(scifir::dimension::MEMO,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::angle operator"" _degree(unsigned long long int x)
{
	return scifir::angle((long double)x, scifir::angle::DEGREE);
}

scifir::angle operator"" _rad(unsigned long long int x)
{
	return scifir::angle((long double)x, scifir::angle::RADIAN);
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

scifir::pixel operator"" _px(unsigned long long int x)
{
	return scifir::pixel((long double)x);
}

scifir::frequency operator"" _QHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _RHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

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

scifir::frequency operator"" _µHz(long double x)
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

scifir::frequency operator"" _rHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::frequency operator"" _qHz(long double x)
{
	return scifir::frequency(x, { scifir::dimension(scifir::dimension::HERTZ,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _QN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _RN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::force operator"" _µN(long double x)
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

scifir::force operator"" _rN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::force operator"" _qN(long double x)
{
	return scifir::force(x, { scifir::dimension(scifir::dimension::NEWTON,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _QPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _RPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::pressure operator"" _µPa(long double x)
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

scifir::pressure operator"" _rPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::pressure operator"" _qPa(long double x)
{
	return scifir::pressure(x, { scifir::dimension(scifir::dimension::PASCAL,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _QJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _RJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::energy operator"" _µJ(long double x)
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

scifir::energy operator"" _rJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _qJ(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::JOULE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _QW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _RW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::power operator"" _µW(long double x)
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

scifir::power operator"" _rW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::power operator"" _qW(long double x)
{
	return scifir::power(x, { scifir::dimension(scifir::dimension::WATT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _QA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _RA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::electric_current operator"" _µA(long double x)
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

scifir::electric_current operator"" _rA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_current operator"" _qA(long double x)
{
	return scifir::electric_current(x, { scifir::dimension(scifir::dimension::AMPERE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _QV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _RV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::voltage operator"" _µV(long double x)
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

scifir::voltage operator"" _rV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::voltage operator"" _qV(long double x)
{
	return scifir::voltage(x, { scifir::dimension(scifir::dimension::VOLT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _QF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _RF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::capacitance operator"" _µF(long double x)
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

scifir::capacitance operator"" _rF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::capacitance operator"" _qF(long double x)
{
	return scifir::capacitance(x, { scifir::dimension(scifir::dimension::FARADAY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _QΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _RΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _YΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _ZΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _EΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _PΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _TΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _GΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _MΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _kΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _hΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _daΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _Ω(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _dΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _cΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _mΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _µΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _nΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _pΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _fΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _aΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _zΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _yΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _rΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::resistance operator"" _qΩ(long double x)
{
	return scifir::resistance(x, { scifir::dimension(scifir::dimension::OHM,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _QS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _RS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::electric_conductance operator"" _µS(long double x)
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

scifir::electric_conductance operator"" _rS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::electric_conductance operator"" _qS(long double x)
{
	return scifir::electric_conductance(x, { scifir::dimension(scifir::dimension::SIEMENS,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _QWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _RWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::magnetic_flux operator"" _µWb(long double x)
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

scifir::magnetic_flux operator"" _rWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_flux operator"" _qWb(long double x)
{
	return scifir::magnetic_flux(x, { scifir::dimension(scifir::dimension::WEBER,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _QT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _RT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::magnetic_strength operator"" _µT(long double x)
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

scifir::magnetic_strength operator"" _rT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::magnetic_strength operator"" _qT(long double x)
{
	return scifir::magnetic_strength(x, { scifir::dimension(scifir::dimension::TESLA,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _QH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _RH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::inductance operator"" _µH(long double x)
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

scifir::inductance operator"" _rH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::inductance operator"" _qH(long double x)
{
	return scifir::inductance(x, { scifir::dimension(scifir::dimension::HENRY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Qlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _Rlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::luminous_flux operator"" _µlm(long double x)
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

scifir::luminous_flux operator"" _rlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::luminous_flux operator"" _qlm(long double x)
{
	return scifir::luminous_flux(x, { scifir::dimension(scifir::dimension::LUMEN,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Qlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _Rlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::illuminance operator"" _µlx(long double x)
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

scifir::illuminance operator"" _rlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::illuminance operator"" _qlx(long double x)
{
	return scifir::illuminance(x, { scifir::dimension(scifir::dimension::LUX,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _QBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _RBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::radioactivity operator"" _µBq(long double x)
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

scifir::radioactivity operator"" _rBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::radioactivity operator"" _qBq(long double x)
{
	return scifir::radioactivity(x, { scifir::dimension(scifir::dimension::BECQUEREL,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _QGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _RGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::ionizing_radiation operator"" _µGy(long double x)
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

scifir::ionizing_radiation operator"" _rGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _qGy(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::GRAY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _QSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _RSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::ionizing_radiation operator"" _µSv(long double x)
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

scifir::ionizing_radiation operator"" _rSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::ionizing_radiation operator"" _qSv(long double x)
{
	return scifir::ionizing_radiation(x, { scifir::dimension(scifir::dimension::SIEVERT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Qkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _Rkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::catalytic_activity operator"" _µkat(long double x)
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

scifir::catalytic_activity operator"" _rkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::catalytic_activity operator"" _qkat(long double x)
{
	return scifir::catalytic_activity(x, { scifir::dimension(scifir::dimension::KATAL,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Å(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ANGSTROM,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _QL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _RL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _YL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::YOTTA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _ZL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::ZETTA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _EL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::EXA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _PL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::PETA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _TL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::TERA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _GL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::GIGA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _ML(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MEGA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _kL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::KILO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _hL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::HECTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _daL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::DECA,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _L(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _dL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::DECI,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _cL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::CENTI,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _mL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MILLI,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _µL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::MICRO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _nL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::NANO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _pL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::PICO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _fL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::FEMTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _aL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::ATTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _zL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::ZEPTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _yL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::YOCTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _rL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::volume operator"" _qL(long double x)
{
	return scifir::volume(x, { scifir::dimension(scifir::dimension::LITRE,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
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

scifir::length operator"" _QAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _RAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::length operator"" _µAU(long double x)
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

scifir::length operator"" _rAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _qAU(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::ASTRONOMICAL_UNIT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Qpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _Rpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::length operator"" _µpc(long double x)
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

scifir::length operator"" _rpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::length operator"" _qpc(long double x)
{
	return scifir::length(x, { scifir::dimension(scifir::dimension::PARSEC,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _QeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _ReV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::energy operator"" _µeV(long double x)
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

scifir::energy operator"" _reV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::energy operator"" _qeV(long double x)
{
	return scifir::energy(x, { scifir::dimension(scifir::dimension::ELECTRON_VOLT,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _Da(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::DALTON,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::mass operator"" _amu(long double x)
{
	return scifir::mass(x, { scifir::dimension(scifir::dimension::ATOMIC_MASS_UNIT,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Qbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _Rbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::area operator"" _µbarn(long double x)
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

scifir::area operator"" _rbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::area operator"" _qbarn(long double x)
{
	return scifir::area(x, { scifir::dimension(scifir::dimension::BARN,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _QM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::QUETTA,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _RM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::RONNA,scifir::dimension::NUMERATOR) });
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

scifir::molarity operator"" _µM(long double x)
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

scifir::molarity operator"" _rM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::RONTO,scifir::dimension::NUMERATOR) });
}

scifir::molarity operator"" _qM(long double x)
{
	return scifir::molarity(x, { scifir::dimension(scifir::dimension::MOLARITY,scifir::prefix::QUECTO,scifir::dimension::NUMERATOR) });
}

scifir::scalar_unit operator"" _memo(long double x)
{
	return scifir::scalar_unit(x, { scifir::dimension(scifir::dimension::MEMO,scifir::prefix::NONE,scifir::dimension::NUMERATOR) });
}

scifir::angle operator"" _degree(long double x)
{
	return scifir::angle(x, scifir::angle::DEGREE);
}

scifir::angle operator"" _rad(long double x)
{
	return scifir::angle(x, scifir::angle::RADIAN);
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

scifir::pixel operator"" _px(long double x)
{
	return scifir::pixel(x);
}