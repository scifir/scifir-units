#ifndef SCIFIR_UNITS_UNITS_UNIT_ABBREVIATION_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_UNIT_ABBREVIATION_HPP_INCLUDED

#include "./scalar_unit.hpp"
#include "./base_units.hpp"

#include "../derived_units/electronics_units.hpp"
#include "../derived_units/physics_units.hpp"
#include "../derived_units/radiometry_units.hpp"
#include "../derived_units/space_units.hpp"
#include "../derived_units/chemistry_units.hpp"

#include "../special_units/percentage.hpp"
#include "../special_units/pixel.hpp"

#include "../nutrition/abv.hpp"

scifir::length operator"" _Å(unsigned long long int);

scifir::volume operator"" _QL(unsigned long long int);
scifir::volume operator"" _RL(unsigned long long int);
scifir::volume operator"" _YL(unsigned long long int);
scifir::volume operator"" _ZL(unsigned long long int);
scifir::volume operator"" _EL(unsigned long long int);
scifir::volume operator"" _PL(unsigned long long int);
scifir::volume operator"" _TL(unsigned long long int);
scifir::volume operator"" _GL(unsigned long long int);
scifir::volume operator"" _ML(unsigned long long int);
scifir::volume operator"" _kL(unsigned long long int);
scifir::volume operator"" _hL(unsigned long long int);
scifir::volume operator"" _daL(unsigned long long int);
scifir::volume operator"" _L(unsigned long long int);
scifir::volume operator"" _dL(unsigned long long int);
scifir::volume operator"" _cL(unsigned long long int);
scifir::volume operator"" _mL(unsigned long long int);
scifir::volume operator"" _µL(unsigned long long int);
scifir::volume operator"" _nL(unsigned long long int);
scifir::volume operator"" _pL(unsigned long long int);
scifir::volume operator"" _fL(unsigned long long int);
scifir::volume operator"" _aL(unsigned long long int);
scifir::volume operator"" _zL(unsigned long long int);
scifir::volume operator"" _yL(unsigned long long int);
scifir::volume operator"" _rL(unsigned long long int);
scifir::volume operator"" _qL(unsigned long long int);

scifir::time_duration operator"" _min(unsigned long long int);
scifir::time_duration operator"" _hour(unsigned long long int);
scifir::time_duration operator"" _day(unsigned long long int);

scifir::length operator"" _QAU(unsigned long long int);
scifir::length operator"" _RAU(unsigned long long int);
scifir::length operator"" _YAU(unsigned long long int);
scifir::length operator"" _ZAU(unsigned long long int);
scifir::length operator"" _EAU(unsigned long long int);
scifir::length operator"" _PAU(unsigned long long int);
scifir::length operator"" _TAU(unsigned long long int);
scifir::length operator"" _GAU(unsigned long long int);
scifir::length operator"" _MAU(unsigned long long int);
scifir::length operator"" _kAU(unsigned long long int);
scifir::length operator"" _hAU(unsigned long long int);
scifir::length operator"" _daAU(unsigned long long int);
scifir::length operator"" _AU(unsigned long long int);
scifir::length operator"" _dAU(unsigned long long int);
scifir::length operator"" _cAU(unsigned long long int);
scifir::length operator"" _mAU(unsigned long long int);
scifir::length operator"" _µAU(unsigned long long int);
scifir::length operator"" _nAU(unsigned long long int);
scifir::length operator"" _pAU(unsigned long long int);
scifir::length operator"" _fAU(unsigned long long int);
scifir::length operator"" _aAU(unsigned long long int);
scifir::length operator"" _zAU(unsigned long long int);
scifir::length operator"" _yAU(unsigned long long int);
scifir::length operator"" _rAU(unsigned long long int);
scifir::length operator"" _qAU(unsigned long long int);

scifir::length operator"" _Qpc(unsigned long long int);
scifir::length operator"" _Rpc(unsigned long long int);
scifir::length operator"" _Ypc(unsigned long long int);
scifir::length operator"" _Zpc(unsigned long long int);
scifir::length operator"" _Epc(unsigned long long int);
scifir::length operator"" _Ppc(unsigned long long int);
scifir::length operator"" _Tpc(unsigned long long int);
scifir::length operator"" _Gpc(unsigned long long int);
scifir::length operator"" _Mpc(unsigned long long int);
scifir::length operator"" _kpc(unsigned long long int);
scifir::length operator"" _hpc(unsigned long long int);
scifir::length operator"" _dapc(unsigned long long int);
scifir::length operator"" _pc(unsigned long long int);
scifir::length operator"" _dpc(unsigned long long int);
scifir::length operator"" _cpc(unsigned long long int);
scifir::length operator"" _mpc(unsigned long long int);
scifir::length operator"" _µpc(unsigned long long int);
scifir::length operator"" _npc(unsigned long long int);
scifir::length operator"" _ppc(unsigned long long int);
scifir::length operator"" _fpc(unsigned long long int);
scifir::length operator"" _apc(unsigned long long int);
scifir::length operator"" _zpc(unsigned long long int);
scifir::length operator"" _ypc(unsigned long long int);
scifir::length operator"" _rpc(unsigned long long int);
scifir::length operator"" _qpc(unsigned long long int);

scifir::energy operator"" _QeV(unsigned long long int);
scifir::energy operator"" _ReV(unsigned long long int);
scifir::energy operator"" _YeV(unsigned long long int);
scifir::energy operator"" _ZeV(unsigned long long int);
scifir::energy operator"" _EeV(unsigned long long int);
scifir::energy operator"" _PeV(unsigned long long int);
scifir::energy operator"" _TeV(unsigned long long int);
scifir::energy operator"" _GeV(unsigned long long int);
scifir::energy operator"" _MeV(unsigned long long int);
scifir::energy operator"" _keV(unsigned long long int);
scifir::energy operator"" _heV(unsigned long long int);
scifir::energy operator"" _daeV(unsigned long long int);
scifir::energy operator"" _eV(unsigned long long int);
scifir::energy operator"" _deV(unsigned long long int);
scifir::energy operator"" _ceV(unsigned long long int);
scifir::energy operator"" _meV(unsigned long long int);
scifir::energy operator"" _µeV(unsigned long long int);
scifir::energy operator"" _neV(unsigned long long int);
scifir::energy operator"" _peV(unsigned long long int);
scifir::energy operator"" _feV(unsigned long long int);
scifir::energy operator"" _aeV(unsigned long long int);
scifir::energy operator"" _zeV(unsigned long long int);
scifir::energy operator"" _yeV(unsigned long long int);
scifir::energy operator"" _reV(unsigned long long int);
scifir::energy operator"" _qeV(unsigned long long int);

scifir::mass operator"" _Da(unsigned long long int);

scifir::mass operator"" _amu(unsigned long long int);

scifir::area operator"" _Qbarn(unsigned long long int);
scifir::area operator"" _Rbarn(unsigned long long int);
scifir::area operator"" _Ybarn(unsigned long long int);
scifir::area operator"" _Zbarn(unsigned long long int);
scifir::area operator"" _Ebarn(unsigned long long int);
scifir::area operator"" _Pbarn(unsigned long long int);
scifir::area operator"" _Tbarn(unsigned long long int);
scifir::area operator"" _Gbarn(unsigned long long int);
scifir::area operator"" _Mbarn(unsigned long long int);
scifir::area operator"" _kbarn(unsigned long long int);
scifir::area operator"" _hbarn(unsigned long long int);
scifir::area operator"" _dabarn(unsigned long long int);
scifir::area operator"" _barn(unsigned long long int);
scifir::area operator"" _dbarn(unsigned long long int);
scifir::area operator"" _cbarn(unsigned long long int);
scifir::area operator"" _mbarn(unsigned long long int);
scifir::area operator"" _µbarn(unsigned long long int);
scifir::area operator"" _nbarn(unsigned long long int);
scifir::area operator"" _pbarn(unsigned long long int);
scifir::area operator"" _fbarn(unsigned long long int);
scifir::area operator"" _abarn(unsigned long long int);
scifir::area operator"" _zbarn(unsigned long long int);
scifir::area operator"" _ybarn(unsigned long long int);
scifir::area operator"" _rbarn(unsigned long long int);
scifir::area operator"" _qbarn(unsigned long long int);

scifir::molarity operator"" _QM(unsigned long long int);
scifir::molarity operator"" _RM(unsigned long long int);
scifir::molarity operator"" _YM(unsigned long long int);
scifir::molarity operator"" _ZM(unsigned long long int);
scifir::molarity operator"" _EM(unsigned long long int);
scifir::molarity operator"" _PM(unsigned long long int);
scifir::molarity operator"" _TM(unsigned long long int);
scifir::molarity operator"" _GM(unsigned long long int);
scifir::molarity operator"" _MM(unsigned long long int);
scifir::molarity operator"" _kM(unsigned long long int);
scifir::molarity operator"" _hM(unsigned long long int);
scifir::molarity operator"" _daM(unsigned long long int);
scifir::molarity operator"" _M(unsigned long long int);
scifir::molarity operator"" _dM(unsigned long long int);
scifir::molarity operator"" _cM(unsigned long long int);
scifir::molarity operator"" _mM(unsigned long long int);
scifir::molarity operator"" _µM(unsigned long long int);
scifir::molarity operator"" _nM(unsigned long long int);
scifir::molarity operator"" _pM(unsigned long long int);
scifir::molarity operator"" _fM(unsigned long long int);
scifir::molarity operator"" _aM(unsigned long long int);
scifir::molarity operator"" _zM(unsigned long long int);
scifir::molarity operator"" _yM(unsigned long long int);
scifir::molarity operator"" _rM(unsigned long long int);
scifir::molarity operator"" _qM(unsigned long long int);

scifir::amount_of_effect operator"" _QIU(unsigned long long int);
scifir::amount_of_effect operator"" _RIU(unsigned long long int);
scifir::amount_of_effect operator"" _YIU(unsigned long long int);
scifir::amount_of_effect operator"" _ZIU(unsigned long long int);
scifir::amount_of_effect operator"" _EIU(unsigned long long int);
scifir::amount_of_effect operator"" _PIU(unsigned long long int);
scifir::amount_of_effect operator"" _TIU(unsigned long long int);
scifir::amount_of_effect operator"" _GIU(unsigned long long int);
scifir::amount_of_effect operator"" _MIU(unsigned long long int);
scifir::amount_of_effect operator"" _kIU(unsigned long long int);
scifir::amount_of_effect operator"" _hIU(unsigned long long int);
scifir::amount_of_effect operator"" _daIU(unsigned long long int);
scifir::amount_of_effect operator"" _IU(unsigned long long int);
scifir::amount_of_effect operator"" _dIU(unsigned long long int);
scifir::amount_of_effect operator"" _cIU(unsigned long long int);
scifir::amount_of_effect operator"" _mIU(unsigned long long int);
scifir::amount_of_effect operator"" _µIU(unsigned long long int);
scifir::amount_of_effect operator"" _nIU(unsigned long long int);
scifir::amount_of_effect operator"" _pIU(unsigned long long int);
scifir::amount_of_effect operator"" _fIU(unsigned long long int);
scifir::amount_of_effect operator"" _aIU(unsigned long long int);
scifir::amount_of_effect operator"" _zIU(unsigned long long int);
scifir::amount_of_effect operator"" _yIU(unsigned long long int);
scifir::amount_of_effect operator"" _rIU(unsigned long long int);
scifir::amount_of_effect operator"" _qIU(unsigned long long int);

scifir::scalar_unit operator"" _mEq(unsigned long long int);

scifir::mole operator"" _particles(unsigned long long int);
scifir::scalar_unit operator"" _memo(unsigned long long int);
scifir::angle operator"" _degree(unsigned long long int);
scifir::angle operator"" _rad(unsigned long long int);
scifir::percentage operator"" _percentage(unsigned long long int);
scifir::percentage operator"" _ppm(unsigned long long int);
/*scifir::percentage operator"" _ppb(unsigned long long int);
scifir::percentage operator"" _ppt(unsigned long long int);
scifir::percentage operator"" _ppq(unsigned long long int);*/
scifir::pixel operator"" _px(unsigned long long int);
scifir::abv operator"" _abv(unsigned long long int);

scifir::length operator"" _Å(long double);

scifir::volume operator"" _QL(long double);
scifir::volume operator"" _RL(long double);
scifir::volume operator"" _YL(long double);
scifir::volume operator"" _ZL(long double);
scifir::volume operator"" _EL(long double);
scifir::volume operator"" _PL(long double);
scifir::volume operator"" _TL(long double);
scifir::volume operator"" _GL(long double);
scifir::volume operator"" _ML(long double);
scifir::volume operator"" _kL(long double);
scifir::volume operator"" _hL(long double);
scifir::volume operator"" _daL(long double);
scifir::volume operator"" _L(long double);
scifir::volume operator"" _dL(long double);
scifir::volume operator"" _cL(long double);
scifir::volume operator"" _mL(long double);
scifir::volume operator"" _µL(long double);
scifir::volume operator"" _nL(long double);
scifir::volume operator"" _pL(long double);
scifir::volume operator"" _fL(long double);
scifir::volume operator"" _aL(long double);
scifir::volume operator"" _zL(long double);
scifir::volume operator"" _yL(long double);
scifir::volume operator"" _rL(long double);
scifir::volume operator"" _qL(long double);

scifir::time_duration operator"" _min(long double);

scifir::time_duration operator"" _hour(long double);

scifir::time_duration operator"" _day(long double);

scifir::length operator"" _QAU(long double);
scifir::length operator"" _RAU(long double);
scifir::length operator"" _YAU(long double);
scifir::length operator"" _ZAU(long double);
scifir::length operator"" _EAU(long double);
scifir::length operator"" _PAU(long double);
scifir::length operator"" _TAU(long double);
scifir::length operator"" _GAU(long double);
scifir::length operator"" _MAU(long double);
scifir::length operator"" _kAU(long double);
scifir::length operator"" _hAU(long double);
scifir::length operator"" _daAU(long double);
scifir::length operator"" _AU(long double);
scifir::length operator"" _dAU(long double);
scifir::length operator"" _cAU(long double);
scifir::length operator"" _mAU(long double);
scifir::length operator"" _µAU(long double);
scifir::length operator"" _nAU(long double);
scifir::length operator"" _pAU(long double);
scifir::length operator"" _fAU(long double);
scifir::length operator"" _aAU(long double);
scifir::length operator"" _zAU(long double);
scifir::length operator"" _yAU(long double);
scifir::length operator"" _rAU(long double);
scifir::length operator"" _qAU(long double);

scifir::length operator"" _Qpc(long double);
scifir::length operator"" _Rpc(long double);
scifir::length operator"" _Ypc(long double);
scifir::length operator"" _Zpc(long double);
scifir::length operator"" _Epc(long double);
scifir::length operator"" _Ppc(long double);
scifir::length operator"" _Tpc(long double);
scifir::length operator"" _Gpc(long double);
scifir::length operator"" _Mpc(long double);
scifir::length operator"" _kpc(long double);
scifir::length operator"" _hpc(long double);
scifir::length operator"" _dapc(long double);
scifir::length operator"" _pc(long double);
scifir::length operator"" _dpc(long double);
scifir::length operator"" _cpc(long double);
scifir::length operator"" _mpc(long double);
scifir::length operator"" _µpc(long double);
scifir::length operator"" _npc(long double);
scifir::length operator"" _ppc(long double);
scifir::length operator"" _fpc(long double);
scifir::length operator"" _apc(long double);
scifir::length operator"" _zpc(long double);
scifir::length operator"" _ypc(long double);
scifir::length operator"" _rpc(long double);
scifir::length operator"" _qpc(long double);

scifir::energy operator"" _QeV(long double);
scifir::energy operator"" _ReV(long double);
scifir::energy operator"" _YeV(long double);
scifir::energy operator"" _ZeV(long double);
scifir::energy operator"" _EeV(long double);
scifir::energy operator"" _PeV(long double);
scifir::energy operator"" _TeV(long double);
scifir::energy operator"" _GeV(long double);
scifir::energy operator"" _MeV(long double);
scifir::energy operator"" _keV(long double);
scifir::energy operator"" _heV(long double);
scifir::energy operator"" _daeV(long double);
scifir::energy operator"" _eV(long double);
scifir::energy operator"" _deV(long double);
scifir::energy operator"" _ceV(long double);
scifir::energy operator"" _meV(long double);
scifir::energy operator"" _µeV(long double);
scifir::energy operator"" _neV(long double);
scifir::energy operator"" _peV(long double);
scifir::energy operator"" _feV(long double);
scifir::energy operator"" _aeV(long double);
scifir::energy operator"" _zeV(long double);
scifir::energy operator"" _yeV(long double);
scifir::energy operator"" _reV(long double);
scifir::energy operator"" _qeV(long double);

scifir::mass operator"" _Da(long double);

scifir::mass operator"" _amu(long double);

scifir::area operator"" _Qbarn(long double);
scifir::area operator"" _Rbarn(long double);
scifir::area operator"" _Ybarn(long double);
scifir::area operator"" _Zbarn(long double);
scifir::area operator"" _Ebarn(long double);
scifir::area operator"" _Pbarn(long double);
scifir::area operator"" _Tbarn(long double);
scifir::area operator"" _Gbarn(long double);
scifir::area operator"" _Mbarn(long double);
scifir::area operator"" _kbarn(long double);
scifir::area operator"" _hbarn(long double);
scifir::area operator"" _dabarn(long double);
scifir::area operator"" _barn(long double);
scifir::area operator"" _dbarn(long double);
scifir::area operator"" _cbarn(long double);
scifir::area operator"" _mbarn(long double);
scifir::area operator"" _µbarn(long double);
scifir::area operator"" _nbarn(long double);
scifir::area operator"" _pbarn(long double);
scifir::area operator"" _fbarn(long double);
scifir::area operator"" _abarn(long double);
scifir::area operator"" _zbarn(long double);
scifir::area operator"" _ybarn(long double);
scifir::area operator"" _rbarn(long double);
scifir::area operator"" _qbarn(long double);

scifir::molarity operator"" _QM(long double);
scifir::molarity operator"" _RM(long double);
scifir::molarity operator"" _YM(long double);
scifir::molarity operator"" _ZM(long double);
scifir::molarity operator"" _EM(long double);
scifir::molarity operator"" _PM(long double);
scifir::molarity operator"" _TM(long double);
scifir::molarity operator"" _GM(long double);
scifir::molarity operator"" _MM(long double);
scifir::molarity operator"" _kM(long double);
scifir::molarity operator"" _hM(long double);
scifir::molarity operator"" _daM(long double);
scifir::molarity operator"" _M(long double);
scifir::molarity operator"" _dM(long double);
scifir::molarity operator"" _cM(long double);
scifir::molarity operator"" _mM(long double);
scifir::molarity operator"" _µM(long double);
scifir::molarity operator"" _nM(long double);
scifir::molarity operator"" _pM(long double);
scifir::molarity operator"" _fM(long double);
scifir::molarity operator"" _aM(long double);
scifir::molarity operator"" _zM(long double);
scifir::molarity operator"" _yM(long double);
scifir::molarity operator"" _rM(long double);
scifir::molarity operator"" _qM(long double);

scifir::amount_of_effect operator"" _QIU(long double);
scifir::amount_of_effect operator"" _RIU(long double);
scifir::amount_of_effect operator"" _YIU(long double);
scifir::amount_of_effect operator"" _ZIU(long double);
scifir::amount_of_effect operator"" _EIU(long double);
scifir::amount_of_effect operator"" _PIU(long double);
scifir::amount_of_effect operator"" _TIU(long double);
scifir::amount_of_effect operator"" _GIU(long double);
scifir::amount_of_effect operator"" _MIU(long double);
scifir::amount_of_effect operator"" _kIU(long double);
scifir::amount_of_effect operator"" _hIU(long double);
scifir::amount_of_effect operator"" _daIU(long double);
scifir::amount_of_effect operator"" _IU(long double);
scifir::amount_of_effect operator"" _dIU(long double);
scifir::amount_of_effect operator"" _cIU(long double);
scifir::amount_of_effect operator"" _mIU(long double);
scifir::amount_of_effect operator"" _µIU(long double);
scifir::amount_of_effect operator"" _nIU(long double);
scifir::amount_of_effect operator"" _pIU(long double);
scifir::amount_of_effect operator"" _fIU(long double);
scifir::amount_of_effect operator"" _aIU(long double);
scifir::amount_of_effect operator"" _zIU(long double);
scifir::amount_of_effect operator"" _yIU(long double);
scifir::amount_of_effect operator"" _rIU(long double);
scifir::amount_of_effect operator"" _qIU(long double);

scifir::scalar_unit operator"" _mEq(long double);

scifir::scalar_unit operator"" _memo(long double);
scifir::angle operator"" _degree(long double);
scifir::angle operator"" _rad(long double);
scifir::percentage operator"" _percentage(long double);
scifir::percentage operator"" _ppm(long double);
/*scifir::percentage operator"" _ppb(long double);
scifir::percentage operator"" _ppt(long double);
scifir::percentage operator"" _ppq(long double);*/
scifir::pixel operator"" _px(long double);
scifir::abv operator"" _abv(long double);

#endif // SCIFIR_UNITS_UNITS_UNIT_ABBREVIATION_HPP_INCLUDED
