#include "./unit_abbreviation.hpp"

using namespace std;

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