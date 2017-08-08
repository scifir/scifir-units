#ifndef UNIT_HPP_
#define UNIT_HPP_

#include "prefix.hpp"
#include "scalar_unit.hpp"
#include "auto_scalar.hpp"
#include "unit.hpp"

#include <iostream>
#include <memory>
#include <sstream>

namespace physics::units
{
	enum display_mode {unit_display,time_display,particles_display};

	class length: public scalar_unit_crtp<length>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class time: public scalar_unit_crtp<time>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;

			void change_display(physics::units::display_mode);

			inline const physics::units::display_mode& get_display_mode() const
			{
				return display_mode;
			}

		private:
			physics::units::display_mode display_mode;
	};

	class mass: public scalar_unit_crtp<mass>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class charge: public scalar_unit_crtp<charge>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class temperature: public scalar_unit_crtp<temperature>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;
			temperature(string);

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;

		private:
			void add_prefix(shared_ptr<prefix>);
	};

	class mole: public scalar_unit_crtp<mole>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class light: public scalar_unit_crtp<light>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

	class data: public scalar_unit_crtp<data>
	{
		public:
			using scalar_unit_crtp::scalar_unit_crtp;

			static const string dimensions_match;
			static const vector_real_dimensions real_dimensions;
	};

}

wostream& operator <<(wostream&, const physics::units::time&);

physics::units::auto_unit operator"" _Ym(unsigned long long int);
physics::units::auto_unit operator"" _Zm(unsigned long long int);
physics::units::auto_unit operator"" _Em(unsigned long long int);
physics::units::auto_unit operator"" _Pm(unsigned long long int);
physics::units::auto_unit operator"" _Tm(unsigned long long int);
physics::units::auto_unit operator"" _Gm(unsigned long long int);
physics::units::auto_unit operator"" _Mm(unsigned long long int);
physics::units::auto_unit operator"" _km(unsigned long long int);
physics::units::auto_unit operator"" _hm(unsigned long long int);
physics::units::auto_unit operator"" _dam(unsigned long long int);
physics::units::auto_unit operator"" _m(unsigned long long int);
physics::units::auto_unit operator"" _dm(unsigned long long int);
physics::units::auto_unit operator"" _cm(unsigned long long int);
physics::units::auto_unit operator"" _mm(unsigned long long int);
physics::units::auto_unit operator"" _um(unsigned long long int);
physics::units::auto_unit operator"" _nm(unsigned long long int);
physics::units::auto_unit operator"" _pm(unsigned long long int);
physics::units::auto_unit operator"" _fm(unsigned long long int);
physics::units::auto_unit operator"" _am(unsigned long long int);
physics::units::auto_unit operator"" _zm(unsigned long long int);
physics::units::auto_unit operator"" _ym(unsigned long long int);

physics::units::auto_unit operator"" _s(unsigned long long int);
physics::units::auto_unit operator"" _ms(unsigned long long int);
physics::units::auto_unit operator"" _us(unsigned long long int);
physics::units::auto_unit operator"" _ns(unsigned long long int);
physics::units::auto_unit operator"" _ps(unsigned long long int);
physics::units::auto_unit operator"" _fs(unsigned long long int);
physics::units::auto_unit operator"" _as(unsigned long long int);
physics::units::auto_unit operator"" _zs(unsigned long long int);
physics::units::auto_unit operator"" _ys(unsigned long long int);

physics::units::auto_unit operator"" _Yg(unsigned long long int);
physics::units::auto_unit operator"" _Zg(unsigned long long int);
physics::units::auto_unit operator"" _Eg(unsigned long long int);
physics::units::auto_unit operator"" _Pg(unsigned long long int);
physics::units::auto_unit operator"" _Tg(unsigned long long int);
physics::units::auto_unit operator"" _Gg(unsigned long long int);
physics::units::auto_unit operator"" _Mg(unsigned long long int);
physics::units::auto_unit operator"" _kg(unsigned long long int);
physics::units::auto_unit operator"" _hg(unsigned long long int);
physics::units::auto_unit operator"" _dag(unsigned long long int);
physics::units::auto_unit operator"" _g(unsigned long long int);
physics::units::auto_unit operator"" _dg(unsigned long long int);
physics::units::auto_unit operator"" _cg(unsigned long long int);
physics::units::auto_unit operator"" _mg(unsigned long long int);
physics::units::auto_unit operator"" _ug(unsigned long long int);
physics::units::auto_unit operator"" _ng(unsigned long long int);
physics::units::auto_unit operator"" _pg(unsigned long long int);
physics::units::auto_unit operator"" _fg(unsigned long long int);
physics::units::auto_unit operator"" _ag(unsigned long long int);
physics::units::auto_unit operator"" _zg(unsigned long long int);
physics::units::auto_unit operator"" _yg(unsigned long long int);

physics::units::auto_unit operator"" _YC(unsigned long long int);
physics::units::auto_unit operator"" _ZC(unsigned long long int);
physics::units::auto_unit operator"" _EC(unsigned long long int);
physics::units::auto_unit operator"" _PC(unsigned long long int);
physics::units::auto_unit operator"" _TC(unsigned long long int);
physics::units::auto_unit operator"" _GC(unsigned long long int);
physics::units::auto_unit operator"" _MC(unsigned long long int);
physics::units::auto_unit operator"" _kC(unsigned long long int);
physics::units::auto_unit operator"" _hC(unsigned long long int);
physics::units::auto_unit operator"" _daC(unsigned long long int);
physics::units::auto_unit operator"" _C(unsigned long long int);
physics::units::auto_unit operator"" _dC(unsigned long long int);
physics::units::auto_unit operator"" _cC(unsigned long long int);
physics::units::auto_unit operator"" _mC(unsigned long long int);
physics::units::auto_unit operator"" _uC(unsigned long long int);
physics::units::auto_unit operator"" _nC(unsigned long long int);
physics::units::auto_unit operator"" _pC(unsigned long long int);
physics::units::auto_unit operator"" _fC(unsigned long long int);
physics::units::auto_unit operator"" _aC(unsigned long long int);
physics::units::auto_unit operator"" _zC(unsigned long long int);
physics::units::auto_unit operator"" _yC(unsigned long long int);

physics::units::auto_unit operator"" _YK(unsigned long long int);
physics::units::auto_unit operator"" _ZK(unsigned long long int);
physics::units::auto_unit operator"" _EK(unsigned long long int);
physics::units::auto_unit operator"" _PK(unsigned long long int);
physics::units::auto_unit operator"" _TK(unsigned long long int);
physics::units::auto_unit operator"" _GK(unsigned long long int);
physics::units::auto_unit operator"" _MK(unsigned long long int);
physics::units::auto_unit operator"" _kK(unsigned long long int);
physics::units::auto_unit operator"" _hK(unsigned long long int);
physics::units::auto_unit operator"" _daK(unsigned long long int);
physics::units::auto_unit operator"" _K(unsigned long long int);
physics::units::auto_unit operator"" _dK(unsigned long long int);
physics::units::auto_unit operator"" _cK(unsigned long long int);
physics::units::auto_unit operator"" _mK(unsigned long long int);
physics::units::auto_unit operator"" _uK(unsigned long long int);
physics::units::auto_unit operator"" _nK(unsigned long long int);
physics::units::auto_unit operator"" _pK(unsigned long long int);
physics::units::auto_unit operator"" _fK(unsigned long long int);
physics::units::auto_unit operator"" _aK(unsigned long long int);
physics::units::auto_unit operator"" _zK(unsigned long long int);
physics::units::auto_unit operator"" _yK(unsigned long long int);

physics::units::auto_unit operator"" _Ymol(unsigned long long int);
physics::units::auto_unit operator"" _Zmol(unsigned long long int);
physics::units::auto_unit operator"" _Emol(unsigned long long int);
physics::units::auto_unit operator"" _Pmol(unsigned long long int);
physics::units::auto_unit operator"" _Tmol(unsigned long long int);
physics::units::auto_unit operator"" _Gmol(unsigned long long int);
physics::units::auto_unit operator"" _Mmol(unsigned long long int);
physics::units::auto_unit operator"" _kmol(unsigned long long int);
physics::units::auto_unit operator"" _hmol(unsigned long long int);
physics::units::auto_unit operator"" _damol(unsigned long long int);
physics::units::auto_unit operator"" _mol(unsigned long long int);
physics::units::auto_unit operator"" _dmol(unsigned long long int);
physics::units::auto_unit operator"" _cmol(unsigned long long int);
physics::units::auto_unit operator"" _mmol(unsigned long long int);
physics::units::auto_unit operator"" _umol(unsigned long long int);
physics::units::auto_unit operator"" _nmol(unsigned long long int);
physics::units::auto_unit operator"" _pmol(unsigned long long int);
physics::units::auto_unit operator"" _fmol(unsigned long long int);
physics::units::auto_unit operator"" _amol(unsigned long long int);
physics::units::auto_unit operator"" _zmol(unsigned long long int);
physics::units::auto_unit operator"" _ymol(unsigned long long int);

physics::units::auto_unit operator"" _Ycd(unsigned long long int);
physics::units::auto_unit operator"" _Zcd(unsigned long long int);
physics::units::auto_unit operator"" _Ecd(unsigned long long int);
physics::units::auto_unit operator"" _Pcd(unsigned long long int);
physics::units::auto_unit operator"" _Tcd(unsigned long long int);
physics::units::auto_unit operator"" _Gcd(unsigned long long int);
physics::units::auto_unit operator"" _Mcd(unsigned long long int);
physics::units::auto_unit operator"" _kcd(unsigned long long int);
physics::units::auto_unit operator"" _hcd(unsigned long long int);
physics::units::auto_unit operator"" _dacd(unsigned long long int);
physics::units::auto_unit operator"" _cd(unsigned long long int);
physics::units::auto_unit operator"" _dcd(unsigned long long int);
physics::units::auto_unit operator"" _ccd(unsigned long long int);
physics::units::auto_unit operator"" _mcd(unsigned long long int);
physics::units::auto_unit operator"" _ucd(unsigned long long int);
physics::units::auto_unit operator"" _ncd(unsigned long long int);
physics::units::auto_unit operator"" _pcd(unsigned long long int);
physics::units::auto_unit operator"" _fcd(unsigned long long int);
physics::units::auto_unit operator"" _acd(unsigned long long int);
physics::units::auto_unit operator"" _zcd(unsigned long long int);
physics::units::auto_unit operator"" _ycd(unsigned long long int);

physics::units::auto_unit operator"" _angle(unsigned long long int);

physics::units::auto_unit operator"" _solid_angle(unsigned long long int);

physics::units::auto_unit operator"" _YB(unsigned long long int);
physics::units::auto_unit operator"" _ZB(unsigned long long int);
physics::units::auto_unit operator"" _EB(unsigned long long int);
physics::units::auto_unit operator"" _PB(unsigned long long int);
physics::units::auto_unit operator"" _TB(unsigned long long int);
physics::units::auto_unit operator"" _GB(unsigned long long int);
physics::units::auto_unit operator"" _MB(unsigned long long int);
physics::units::auto_unit operator"" _kB(unsigned long long int);
physics::units::auto_unit operator"" _B(unsigned long long int);

physics::units::auto_unit operator"" _Ym(long double);
physics::units::auto_unit operator"" _Zm(long double);
physics::units::auto_unit operator"" _Em(long double);
physics::units::auto_unit operator"" _Pm(long double);
physics::units::auto_unit operator"" _Tm(long double);
physics::units::auto_unit operator"" _Gm(long double);
physics::units::auto_unit operator"" _Mm(long double);
physics::units::auto_unit operator"" _km(long double);
physics::units::auto_unit operator"" _hm(long double);
physics::units::auto_unit operator"" _dam(long double);
physics::units::auto_unit operator"" _m(long double);
physics::units::auto_unit operator"" _dm(long double);
physics::units::auto_unit operator"" _cm(long double);
physics::units::auto_unit operator"" _mm(long double);
physics::units::auto_unit operator"" _um(long double);
physics::units::auto_unit operator"" _nm(long double);
physics::units::auto_unit operator"" _pm(long double);
physics::units::auto_unit operator"" _fm(long double);
physics::units::auto_unit operator"" _am(long double);
physics::units::auto_unit operator"" _zm(long double);
physics::units::auto_unit operator"" _ym(long double);

physics::units::auto_unit operator"" _s(long double);
physics::units::auto_unit operator"" _ms(long double);
physics::units::auto_unit operator"" _us(long double);
physics::units::auto_unit operator"" _ns(long double);
physics::units::auto_unit operator"" _ps(long double);
physics::units::auto_unit operator"" _fs(long double);
physics::units::auto_unit operator"" _as(long double);
physics::units::auto_unit operator"" _zs(long double);
physics::units::auto_unit operator"" _ys(long double);

physics::units::auto_unit operator"" _Yg(long double);
physics::units::auto_unit operator"" _Zg(long double);
physics::units::auto_unit operator"" _Eg(long double);
physics::units::auto_unit operator"" _Pg(long double);
physics::units::auto_unit operator"" _Tg(long double);
physics::units::auto_unit operator"" _Gg(long double);
physics::units::auto_unit operator"" _Mg(long double);
physics::units::auto_unit operator"" _kg(long double);
physics::units::auto_unit operator"" _hg(long double);
physics::units::auto_unit operator"" _dag(long double);
physics::units::auto_unit operator"" _g(long double);
physics::units::auto_unit operator"" _dg(long double);
physics::units::auto_unit operator"" _cg(long double);
physics::units::auto_unit operator"" _mg(long double);
physics::units::auto_unit operator"" _ug(long double);
physics::units::auto_unit operator"" _ng(long double);
physics::units::auto_unit operator"" _pg(long double);
physics::units::auto_unit operator"" _fg(long double);
physics::units::auto_unit operator"" _ag(long double);
physics::units::auto_unit operator"" _zg(long double);
physics::units::auto_unit operator"" _yg(long double);

physics::units::auto_unit operator"" _YC(long double);
physics::units::auto_unit operator"" _ZC(long double);
physics::units::auto_unit operator"" _EC(long double);
physics::units::auto_unit operator"" _PC(long double);
physics::units::auto_unit operator"" _TC(long double);
physics::units::auto_unit operator"" _GC(long double);
physics::units::auto_unit operator"" _MC(long double);
physics::units::auto_unit operator"" _kC(long double);
physics::units::auto_unit operator"" _hC(long double);
physics::units::auto_unit operator"" _daC(long double);
physics::units::auto_unit operator"" _C(long double);
physics::units::auto_unit operator"" _dC(long double);
physics::units::auto_unit operator"" _cC(long double);
physics::units::auto_unit operator"" _mC(long double);
physics::units::auto_unit operator"" _uC(long double);
physics::units::auto_unit operator"" _nC(long double);
physics::units::auto_unit operator"" _pC(long double);
physics::units::auto_unit operator"" _fC(long double);
physics::units::auto_unit operator"" _aC(long double);
physics::units::auto_unit operator"" _zC(long double);
physics::units::auto_unit operator"" _yC(long double);

physics::units::auto_unit operator"" _YK(long double);
physics::units::auto_unit operator"" _ZK(long double);
physics::units::auto_unit operator"" _EK(long double);
physics::units::auto_unit operator"" _PK(long double);
physics::units::auto_unit operator"" _TK(long double);
physics::units::auto_unit operator"" _GK(long double);
physics::units::auto_unit operator"" _MK(long double);
physics::units::auto_unit operator"" _kK(long double);
physics::units::auto_unit operator"" _hK(long double);
physics::units::auto_unit operator"" _daK(long double);
physics::units::auto_unit operator"" _K(long double);
physics::units::auto_unit operator"" _dK(long double);
physics::units::auto_unit operator"" _cK(long double);
physics::units::auto_unit operator"" _mK(long double);
physics::units::auto_unit operator"" _uK(long double);
physics::units::auto_unit operator"" _nK(long double);
physics::units::auto_unit operator"" _pK(long double);
physics::units::auto_unit operator"" _fK(long double);
physics::units::auto_unit operator"" _aK(long double);
physics::units::auto_unit operator"" _zK(long double);
physics::units::auto_unit operator"" _yK(long double);

physics::units::auto_unit operator"" _Ymol(long double);
physics::units::auto_unit operator"" _Zmol(long double);
physics::units::auto_unit operator"" _Emol(long double);
physics::units::auto_unit operator"" _Pmol(long double);
physics::units::auto_unit operator"" _Tmol(long double);
physics::units::auto_unit operator"" _Gmol(long double);
physics::units::auto_unit operator"" _Mmol(long double);
physics::units::auto_unit operator"" _kmol(long double);
physics::units::auto_unit operator"" _hmol(long double);
physics::units::auto_unit operator"" _damol(long double);
physics::units::auto_unit operator"" _mol(long double);
physics::units::auto_unit operator"" _dmol(long double);
physics::units::auto_unit operator"" _cmol(long double);
physics::units::auto_unit operator"" _mmol(long double);
physics::units::auto_unit operator"" _umol(long double);
physics::units::auto_unit operator"" _nmol(long double);
physics::units::auto_unit operator"" _pmol(long double);
physics::units::auto_unit operator"" _fmol(long double);
physics::units::auto_unit operator"" _amol(long double);
physics::units::auto_unit operator"" _zmol(long double);
physics::units::auto_unit operator"" _ymol(long double);

physics::units::auto_unit operator"" _Ycd(long double);
physics::units::auto_unit operator"" _Zcd(long double);
physics::units::auto_unit operator"" _Ecd(long double);
physics::units::auto_unit operator"" _Pcd(long double);
physics::units::auto_unit operator"" _Tcd(long double);
physics::units::auto_unit operator"" _Gcd(long double);
physics::units::auto_unit operator"" _Mcd(long double);
physics::units::auto_unit operator"" _kcd(long double);
physics::units::auto_unit operator"" _hcd(long double);
physics::units::auto_unit operator"" _dacd(long double);
physics::units::auto_unit operator"" _cd(long double);
physics::units::auto_unit operator"" _dcd(long double);
physics::units::auto_unit operator"" _ccd(long double);
physics::units::auto_unit operator"" _mcd(long double);
physics::units::auto_unit operator"" _ucd(long double);
physics::units::auto_unit operator"" _ncd(long double);
physics::units::auto_unit operator"" _pcd(long double);
physics::units::auto_unit operator"" _fcd(long double);
physics::units::auto_unit operator"" _acd(long double);
physics::units::auto_unit operator"" _zcd(long double);
physics::units::auto_unit operator"" _ycd(long double);

physics::units::auto_unit operator"" _angle(long double);

physics::units::auto_unit operator"" _solid_angle(long double);

physics::units::auto_unit operator"" _YB(long double);
physics::units::auto_unit operator"" _ZB(long double);
physics::units::auto_unit operator"" _EB(long double);
physics::units::auto_unit operator"" _PB(long double);
physics::units::auto_unit operator"" _TB(long double);
physics::units::auto_unit operator"" _GB(long double);
physics::units::auto_unit operator"" _MB(long double);
physics::units::auto_unit operator"" _kB(long double);
physics::units::auto_unit operator"" _B(long double);

#endif
