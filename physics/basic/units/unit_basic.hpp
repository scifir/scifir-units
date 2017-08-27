#ifndef PHYSICS_BASIC_UNITS_UNIT_BASIC_HPP
#define PHYSICS_BASIC_UNITS_UNIT_BASIC_HPP

#include "prefix.hpp"
#include "scalar_unit.hpp"
#include "auto_scalar.hpp"
#include "unit.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <sstream>

namespace physics::units
{
	enum display_mode {unit_display,time_display};

	SCALAR_UNIT_HPP(length);

	SCALAR_UNIT_HPP_BEGIN(time);
		public:
			explicit operator std::chrono::seconds() const;

			void change_display(physics::units::display_mode);

			inline const physics::units::display_mode& get_display_mode() const
			{
				return display_mode;
			}

		private:
			physics::units::display_mode display_mode;
	SCALAR_UNIT_HPP_END();

	SCALAR_UNIT_HPP(mass);
	SCALAR_UNIT_HPP(charge);

	SCALAR_UNIT_HPP_BEGIN(temperature);
		private:
			void add_prefix(shared_ptr<prefix>);
	SCALAR_UNIT_HPP_END();

	SCALAR_UNIT_HPP_BEGIN(mole);
		public:
			int number_of_particles() const;
	SCALAR_UNIT_HPP_END();

	SCALAR_UNIT_HPP(light);
	SCALAR_UNIT_HPP(data);
}

wostream& operator <<(wostream&, const physics::units::time&);

physics::units::length operator"" _Ym(unsigned long long int);
physics::units::length operator"" _Zm(unsigned long long int);
physics::units::length operator"" _Em(unsigned long long int);
physics::units::length operator"" _Pm(unsigned long long int);
physics::units::length operator"" _Tm(unsigned long long int);
physics::units::length operator"" _Gm(unsigned long long int);
physics::units::length operator"" _Mm(unsigned long long int);
physics::units::length operator"" _km(unsigned long long int);
physics::units::length operator"" _hm(unsigned long long int);
physics::units::length operator"" _dam(unsigned long long int);
physics::units::length operator"" _m(unsigned long long int);
physics::units::length operator"" _dm(unsigned long long int);
physics::units::length operator"" _cm(unsigned long long int);
physics::units::length operator"" _mm(unsigned long long int);
physics::units::length operator"" _um(unsigned long long int);
physics::units::length operator"" _nm(unsigned long long int);
physics::units::length operator"" _pm(unsigned long long int);
physics::units::length operator"" _fm(unsigned long long int);
physics::units::length operator"" _am(unsigned long long int);
physics::units::length operator"" _zm(unsigned long long int);
physics::units::length operator"" _ym(unsigned long long int);

physics::units::time operator"" _s(unsigned long long int);
physics::units::time operator"" _ms(unsigned long long int);
physics::units::time operator"" _us(unsigned long long int);
physics::units::time operator"" _ns(unsigned long long int);
physics::units::time operator"" _ps(unsigned long long int);
physics::units::time operator"" _fs(unsigned long long int);
physics::units::time operator"" _as(unsigned long long int);
physics::units::time operator"" _zs(unsigned long long int);
physics::units::time operator"" _ys(unsigned long long int);

physics::units::mass operator"" _Yg(unsigned long long int);
physics::units::mass operator"" _Zg(unsigned long long int);
physics::units::mass operator"" _Eg(unsigned long long int);
physics::units::mass operator"" _Pg(unsigned long long int);
physics::units::mass operator"" _Tg(unsigned long long int);
physics::units::mass operator"" _Gg(unsigned long long int);
physics::units::mass operator"" _Mg(unsigned long long int);
physics::units::mass operator"" _kg(unsigned long long int);
physics::units::mass operator"" _hg(unsigned long long int);
physics::units::mass operator"" _dag(unsigned long long int);
physics::units::mass operator"" _g(unsigned long long int);
physics::units::mass operator"" _dg(unsigned long long int);
physics::units::mass operator"" _cg(unsigned long long int);
physics::units::mass operator"" _mg(unsigned long long int);
physics::units::mass operator"" _ug(unsigned long long int);
physics::units::mass operator"" _ng(unsigned long long int);
physics::units::mass operator"" _pg(unsigned long long int);
physics::units::mass operator"" _fg(unsigned long long int);
physics::units::mass operator"" _ag(unsigned long long int);
physics::units::mass operator"" _zg(unsigned long long int);
physics::units::mass operator"" _yg(unsigned long long int);

physics::units::charge operator"" _YC(unsigned long long int);
physics::units::charge operator"" _ZC(unsigned long long int);
physics::units::charge operator"" _EC(unsigned long long int);
physics::units::charge operator"" _PC(unsigned long long int);
physics::units::charge operator"" _TC(unsigned long long int);
physics::units::charge operator"" _GC(unsigned long long int);
physics::units::charge operator"" _MC(unsigned long long int);
physics::units::charge operator"" _kC(unsigned long long int);
physics::units::charge operator"" _hC(unsigned long long int);
physics::units::charge operator"" _daC(unsigned long long int);
physics::units::charge operator"" _C(unsigned long long int);
physics::units::charge operator"" _dC(unsigned long long int);
physics::units::charge operator"" _cC(unsigned long long int);
physics::units::charge operator"" _mC(unsigned long long int);
physics::units::charge operator"" _uC(unsigned long long int);
physics::units::charge operator"" _nC(unsigned long long int);
physics::units::charge operator"" _pC(unsigned long long int);
physics::units::charge operator"" _fC(unsigned long long int);
physics::units::charge operator"" _aC(unsigned long long int);
physics::units::charge operator"" _zC(unsigned long long int);
physics::units::charge operator"" _yC(unsigned long long int);

physics::units::temperature operator"" _YK(unsigned long long int);
physics::units::temperature operator"" _ZK(unsigned long long int);
physics::units::temperature operator"" _EK(unsigned long long int);
physics::units::temperature operator"" _PK(unsigned long long int);
physics::units::temperature operator"" _TK(unsigned long long int);
physics::units::temperature operator"" _GK(unsigned long long int);
physics::units::temperature operator"" _MK(unsigned long long int);
physics::units::temperature operator"" _kK(unsigned long long int);
physics::units::temperature operator"" _hK(unsigned long long int);
physics::units::temperature operator"" _daK(unsigned long long int);
physics::units::temperature operator"" _K(unsigned long long int);
physics::units::temperature operator"" _dK(unsigned long long int);
physics::units::temperature operator"" _cK(unsigned long long int);
physics::units::temperature operator"" _mK(unsigned long long int);
physics::units::temperature operator"" _uK(unsigned long long int);
physics::units::temperature operator"" _nK(unsigned long long int);
physics::units::temperature operator"" _pK(unsigned long long int);
physics::units::temperature operator"" _fK(unsigned long long int);
physics::units::temperature operator"" _aK(unsigned long long int);
physics::units::temperature operator"" _zK(unsigned long long int);
physics::units::temperature operator"" _yK(unsigned long long int);

physics::units::mole operator"" _Ymol(unsigned long long int);
physics::units::mole operator"" _Zmol(unsigned long long int);
physics::units::mole operator"" _Emol(unsigned long long int);
physics::units::mole operator"" _Pmol(unsigned long long int);
physics::units::mole operator"" _Tmol(unsigned long long int);
physics::units::mole operator"" _Gmol(unsigned long long int);
physics::units::mole operator"" _Mmol(unsigned long long int);
physics::units::mole operator"" _kmol(unsigned long long int);
physics::units::mole operator"" _hmol(unsigned long long int);
physics::units::mole operator"" _damol(unsigned long long int);
physics::units::mole operator"" _mol(unsigned long long int);
physics::units::mole operator"" _dmol(unsigned long long int);
physics::units::mole operator"" _cmol(unsigned long long int);
physics::units::mole operator"" _mmol(unsigned long long int);
physics::units::mole operator"" _umol(unsigned long long int);
physics::units::mole operator"" _nmol(unsigned long long int);
physics::units::mole operator"" _pmol(unsigned long long int);
physics::units::mole operator"" _fmol(unsigned long long int);
physics::units::mole operator"" _amol(unsigned long long int);
physics::units::mole operator"" _zmol(unsigned long long int);
physics::units::mole operator"" _ymol(unsigned long long int);

physics::units::light operator"" _Ycd(unsigned long long int);
physics::units::light operator"" _Zcd(unsigned long long int);
physics::units::light operator"" _Ecd(unsigned long long int);
physics::units::light operator"" _Pcd(unsigned long long int);
physics::units::light operator"" _Tcd(unsigned long long int);
physics::units::light operator"" _Gcd(unsigned long long int);
physics::units::light operator"" _Mcd(unsigned long long int);
physics::units::light operator"" _kcd(unsigned long long int);
physics::units::light operator"" _hcd(unsigned long long int);
physics::units::light operator"" _dacd(unsigned long long int);
physics::units::light operator"" _cd(unsigned long long int);
physics::units::light operator"" _dcd(unsigned long long int);
physics::units::light operator"" _ccd(unsigned long long int);
physics::units::light operator"" _mcd(unsigned long long int);
physics::units::light operator"" _ucd(unsigned long long int);
physics::units::light operator"" _ncd(unsigned long long int);
physics::units::light operator"" _pcd(unsigned long long int);
physics::units::light operator"" _fcd(unsigned long long int);
physics::units::light operator"" _acd(unsigned long long int);
physics::units::light operator"" _zcd(unsigned long long int);
physics::units::light operator"" _ycd(unsigned long long int);

physics::units::auto_unit operator"" _angle(unsigned long long int);

physics::units::auto_unit operator"" _solid_angle(unsigned long long int);

physics::units::data operator"" _YB(unsigned long long int);
physics::units::data operator"" _ZB(unsigned long long int);
physics::units::data operator"" _EB(unsigned long long int);
physics::units::data operator"" _PB(unsigned long long int);
physics::units::data operator"" _TB(unsigned long long int);
physics::units::data operator"" _GB(unsigned long long int);
physics::units::data operator"" _MB(unsigned long long int);
physics::units::data operator"" _kB(unsigned long long int);
physics::units::data operator"" _B(unsigned long long int);

physics::units::length operator"" _Ym(long double);
physics::units::length operator"" _Zm(long double);
physics::units::length operator"" _Em(long double);
physics::units::length operator"" _Pm(long double);
physics::units::length operator"" _Tm(long double);
physics::units::length operator"" _Gm(long double);
physics::units::length operator"" _Mm(long double);
physics::units::length operator"" _km(long double);
physics::units::length operator"" _hm(long double);
physics::units::length operator"" _dam(long double);
physics::units::length operator"" _m(long double);
physics::units::length operator"" _dm(long double);
physics::units::length operator"" _cm(long double);
physics::units::length operator"" _mm(long double);
physics::units::length operator"" _um(long double);
physics::units::length operator"" _nm(long double);
physics::units::length operator"" _pm(long double);
physics::units::length operator"" _fm(long double);
physics::units::length operator"" _am(long double);
physics::units::length operator"" _zm(long double);
physics::units::length operator"" _ym(long double);

physics::units::time operator"" _s(long double);
physics::units::time operator"" _ms(long double);
physics::units::time operator"" _us(long double);
physics::units::time operator"" _ns(long double);
physics::units::time operator"" _ps(long double);
physics::units::time operator"" _fs(long double);
physics::units::time operator"" _as(long double);
physics::units::time operator"" _zs(long double);
physics::units::time operator"" _ys(long double);

physics::units::mass operator"" _Yg(long double);
physics::units::mass operator"" _Zg(long double);
physics::units::mass operator"" _Eg(long double);
physics::units::mass operator"" _Pg(long double);
physics::units::mass operator"" _Tg(long double);
physics::units::mass operator"" _Gg(long double);
physics::units::mass operator"" _Mg(long double);
physics::units::mass operator"" _kg(long double);
physics::units::mass operator"" _hg(long double);
physics::units::mass operator"" _dag(long double);
physics::units::mass operator"" _g(long double);
physics::units::mass operator"" _dg(long double);
physics::units::mass operator"" _cg(long double);
physics::units::mass operator"" _mg(long double);
physics::units::mass operator"" _ug(long double);
physics::units::mass operator"" _ng(long double);
physics::units::mass operator"" _pg(long double);
physics::units::mass operator"" _fg(long double);
physics::units::mass operator"" _ag(long double);
physics::units::mass operator"" _zg(long double);
physics::units::mass operator"" _yg(long double);

physics::units::charge operator"" _YC(long double);
physics::units::charge operator"" _ZC(long double);
physics::units::charge operator"" _EC(long double);
physics::units::charge operator"" _PC(long double);
physics::units::charge operator"" _TC(long double);
physics::units::charge operator"" _GC(long double);
physics::units::charge operator"" _MC(long double);
physics::units::charge operator"" _kC(long double);
physics::units::charge operator"" _hC(long double);
physics::units::charge operator"" _daC(long double);
physics::units::charge operator"" _C(long double);
physics::units::charge operator"" _dC(long double);
physics::units::charge operator"" _cC(long double);
physics::units::charge operator"" _mC(long double);
physics::units::charge operator"" _uC(long double);
physics::units::charge operator"" _nC(long double);
physics::units::charge operator"" _pC(long double);
physics::units::charge operator"" _fC(long double);
physics::units::charge operator"" _aC(long double);
physics::units::charge operator"" _zC(long double);
physics::units::charge operator"" _yC(long double);

physics::units::temperature operator"" _YK(long double);
physics::units::temperature operator"" _ZK(long double);
physics::units::temperature operator"" _EK(long double);
physics::units::temperature operator"" _PK(long double);
physics::units::temperature operator"" _TK(long double);
physics::units::temperature operator"" _GK(long double);
physics::units::temperature operator"" _MK(long double);
physics::units::temperature operator"" _kK(long double);
physics::units::temperature operator"" _hK(long double);
physics::units::temperature operator"" _daK(long double);
physics::units::temperature operator"" _K(long double);
physics::units::temperature operator"" _dK(long double);
physics::units::temperature operator"" _cK(long double);
physics::units::temperature operator"" _mK(long double);
physics::units::temperature operator"" _uK(long double);
physics::units::temperature operator"" _nK(long double);
physics::units::temperature operator"" _pK(long double);
physics::units::temperature operator"" _fK(long double);
physics::units::temperature operator"" _aK(long double);
physics::units::temperature operator"" _zK(long double);
physics::units::temperature operator"" _yK(long double);

physics::units::mole operator"" _Ymol(long double);
physics::units::mole operator"" _Zmol(long double);
physics::units::mole operator"" _Emol(long double);
physics::units::mole operator"" _Pmol(long double);
physics::units::mole operator"" _Tmol(long double);
physics::units::mole operator"" _Gmol(long double);
physics::units::mole operator"" _Mmol(long double);
physics::units::mole operator"" _kmol(long double);
physics::units::mole operator"" _hmol(long double);
physics::units::mole operator"" _damol(long double);
physics::units::mole operator"" _mol(long double);
physics::units::mole operator"" _dmol(long double);
physics::units::mole operator"" _cmol(long double);
physics::units::mole operator"" _mmol(long double);
physics::units::mole operator"" _umol(long double);
physics::units::mole operator"" _nmol(long double);
physics::units::mole operator"" _pmol(long double);
physics::units::mole operator"" _fmol(long double);
physics::units::mole operator"" _amol(long double);
physics::units::mole operator"" _zmol(long double);
physics::units::mole operator"" _ymol(long double);

physics::units::light operator"" _Ycd(long double);
physics::units::light operator"" _Zcd(long double);
physics::units::light operator"" _Ecd(long double);
physics::units::light operator"" _Pcd(long double);
physics::units::light operator"" _Tcd(long double);
physics::units::light operator"" _Gcd(long double);
physics::units::light operator"" _Mcd(long double);
physics::units::light operator"" _kcd(long double);
physics::units::light operator"" _hcd(long double);
physics::units::light operator"" _dacd(long double);
physics::units::light operator"" _cd(long double);
physics::units::light operator"" _dcd(long double);
physics::units::light operator"" _ccd(long double);
physics::units::light operator"" _mcd(long double);
physics::units::light operator"" _ucd(long double);
physics::units::light operator"" _ncd(long double);
physics::units::light operator"" _pcd(long double);
physics::units::light operator"" _fcd(long double);
physics::units::light operator"" _acd(long double);
physics::units::light operator"" _zcd(long double);
physics::units::light operator"" _ycd(long double);

physics::units::auto_unit operator"" _angle(long double);

physics::units::auto_unit operator"" _solid_angle(long double);

physics::units::data operator"" _YB(long double);
physics::units::data operator"" _ZB(long double);
physics::units::data operator"" _EB(long double);
physics::units::data operator"" _PB(long double);
physics::units::data operator"" _TB(long double);
physics::units::data operator"" _GB(long double);
physics::units::data operator"" _MB(long double);
physics::units::data operator"" _kB(long double);
physics::units::data operator"" _B(long double);

#endif
