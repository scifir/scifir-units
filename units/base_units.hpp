#ifndef SCIFIR_UNITS_UNITS_BASE_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_BASE_UNITS_HPP_INCLUDED

#include "./prefix.hpp"
#include "./scalar_unit.hpp"
#include "../meca_number/percentage.hpp"

#include <chrono>
#include <iostream>
#include <sstream>

using namespace std;

namespace scifir
{
	SCALAR_UNIT_HPP(length);

	class time_duration : public scalar_unit
	{
		public:
			time_duration();
			time_duration(const scalar_unit&);
			time_duration(scalar_unit&&);
			explicit time_duration(float new_value, dimension::type new_dimension, prefix::type new_prefix, dimension::position new_position = dimension::NUMERATOR);
			explicit time_duration(double new_value, dimension::type new_dimension, prefix::type new_prefix, dimension::position new_position = dimension::NUMERATOR);
			explicit time_duration(long double new_value, dimension::type new_dimension, prefix::type new_prefix, dimension::position new_position = dimension::NUMERATOR);
			explicit time_duration(int new_value, dimension::type new_dimension, prefix::type new_prefix, dimension::position new_position = dimension::NUMERATOR);
			explicit time_duration(float new_value, const string& init_dimensions);
			explicit time_duration(double new_value, const string& init_dimensions);
			explicit time_duration(long double new_value, const string& init_dimensions);
			explicit time_duration(int new_value, const string& init_dimensions);
			explicit time_duration(float new_value, const vector<dimension>& new_dimensions);
			explicit time_duration(double new_value, const vector<dimension>& new_dimensions);
			explicit time_duration(long double new_value, const vector<dimension>& new_dimensions);
			explicit time_duration(int new_value, const vector<dimension>& new_dimensions);
			explicit time_duration(const string& init_time);

			explicit operator std::chrono::seconds() const;

			int get_years() const;
			int get_months() const;
			int get_weeks() const;
			int get_days() const;
			int get_hours() const;
			int get_minutes() const;
			int get_seconds() const;

			string get_finish_date() const;
			string display_as_time() const;

			string display_years() const;
			string display_months() const;
			string display_weeks() const;
			string display_days() const;
			string display_hours() const;
			string display_minutes() const;
			string display_seconds() const;

			template<typename T1,typename T2>
			scifir::time_duration& operator+=(chrono::duration<T1,T2> x)
			{
				 chrono::seconds d = chrono::duration_cast<chrono::seconds>(x);
				 scifir::time_duration x_second = scifir::time_duration((long double)d.count(),"s");
				 scalar_unit::operator+=(x_second);
				 return *this;
			}

			template<typename T1,typename T2>
			scifir::time_duration& operator-=(chrono::duration<T1,T2> x)
			{
				 chrono::seconds d = chrono::duration_cast<chrono::seconds>(x);
				 scifir::time_duration x_second = scifir::time_duration((long double)d.count(),"s");
				 scalar_unit::operator-=(x_second);
				 return *this;
			}

			using scalar_unit::operator =;
			using scalar_unit::operator+=;
			using scalar_unit::operator-=;

		public:
			static const string dimensions_match;
			static const vector<dimension> real_dimensions;
	};

	SCALAR_UNIT_HPP_BEGIN(mass);
		public:
			mass(const percentage& new_percentage,const mass& new_mass);
			mass(const string& init_percentage,const string& init_mass);

	SCALAR_UNIT_HPP_END();

	SCALAR_UNIT_HPP(charge);
	SCALAR_UNIT_HPP(temperature);

	SCALAR_UNIT_HPP_BEGIN(mole);
		public:
			mole(const percentage& new_percentage,const mole& new_mole);
			mole(const string& init_percentage,const string& init_mole);

			int get_number_of_particles() const;
	SCALAR_UNIT_HPP_END();

	SCALAR_UNIT_HPP(light_intensity);
	SCALAR_UNIT_HPP(information_size);
}

scifir::length operator"" _Qm(unsigned long long int);
scifir::length operator"" _Rm(unsigned long long int);
scifir::length operator"" _Ym(unsigned long long int);
scifir::length operator"" _Zm(unsigned long long int);
scifir::length operator"" _Em(unsigned long long int);
scifir::length operator"" _Pm(unsigned long long int);
scifir::length operator"" _Tm(unsigned long long int);
scifir::length operator"" _Gm(unsigned long long int);
scifir::length operator"" _Mm(unsigned long long int);
scifir::length operator"" _km(unsigned long long int);
scifir::length operator"" _hm(unsigned long long int);
scifir::length operator"" _dam(unsigned long long int);
scifir::length operator"" _m(unsigned long long int);
scifir::length operator"" _dm(unsigned long long int);
scifir::length operator"" _cm(unsigned long long int);
scifir::length operator"" _mm(unsigned long long int);
scifir::length operator"" _um(unsigned long long int);
scifir::length operator"" _nm(unsigned long long int);
scifir::length operator"" _pm(unsigned long long int);
scifir::length operator"" _fm(unsigned long long int);
scifir::length operator"" _am(unsigned long long int);
scifir::length operator"" _zm(unsigned long long int);
scifir::length operator"" _ym(unsigned long long int);
scifir::length operator"" _rm(unsigned long long int);
scifir::length operator"" _qm(unsigned long long int);

scifir::time_duration operator"" _s(unsigned long long int);
scifir::time_duration operator"" _ms(unsigned long long int);
scifir::time_duration operator"" _us(unsigned long long int);
scifir::time_duration operator"" _ns(unsigned long long int);
scifir::time_duration operator"" _ps(unsigned long long int);
scifir::time_duration operator"" _fs(unsigned long long int);
scifir::time_duration operator"" _as(unsigned long long int);
scifir::time_duration operator"" _zs(unsigned long long int);
scifir::time_duration operator"" _ys(unsigned long long int);
scifir::time_duration operator"" _rs(unsigned long long int);
scifir::time_duration operator"" _qs(unsigned long long int);

scifir::mass operator"" _Qg(unsigned long long int);
scifir::mass operator"" _Rg(unsigned long long int);
scifir::mass operator"" _Yg(unsigned long long int);
scifir::mass operator"" _Zg(unsigned long long int);
scifir::mass operator"" _Eg(unsigned long long int);
scifir::mass operator"" _Pg(unsigned long long int);
scifir::mass operator"" _Tg(unsigned long long int);
scifir::mass operator"" _Gg(unsigned long long int);
scifir::mass operator"" _Mg(unsigned long long int);
scifir::mass operator"" _kg(unsigned long long int);
scifir::mass operator"" _hg(unsigned long long int);
scifir::mass operator"" _dag(unsigned long long int);
scifir::mass operator"" _g(unsigned long long int);
scifir::mass operator"" _dg(unsigned long long int);
scifir::mass operator"" _cg(unsigned long long int);
scifir::mass operator"" _mg(unsigned long long int);
scifir::mass operator"" _ug(unsigned long long int);
scifir::mass operator"" _ng(unsigned long long int);
scifir::mass operator"" _pg(unsigned long long int);
scifir::mass operator"" _fg(unsigned long long int);
scifir::mass operator"" _ag(unsigned long long int);
scifir::mass operator"" _zg(unsigned long long int);
scifir::mass operator"" _yg(unsigned long long int);
scifir::mass operator"" _rg(unsigned long long int);
scifir::mass operator"" _qg(unsigned long long int);

scifir::charge operator"" _QC(unsigned long long int);
scifir::charge operator"" _RC(unsigned long long int);
scifir::charge operator"" _YC(unsigned long long int);
scifir::charge operator"" _ZC(unsigned long long int);
scifir::charge operator"" _EC(unsigned long long int);
scifir::charge operator"" _PC(unsigned long long int);
scifir::charge operator"" _TC(unsigned long long int);
scifir::charge operator"" _GC(unsigned long long int);
scifir::charge operator"" _MC(unsigned long long int);
scifir::charge operator"" _kC(unsigned long long int);
scifir::charge operator"" _hC(unsigned long long int);
scifir::charge operator"" _daC(unsigned long long int);
scifir::charge operator"" _C(unsigned long long int);
scifir::charge operator"" _dC(unsigned long long int);
scifir::charge operator"" _cC(unsigned long long int);
scifir::charge operator"" _mC(unsigned long long int);
scifir::charge operator"" _uC(unsigned long long int);
scifir::charge operator"" _nC(unsigned long long int);
scifir::charge operator"" _pC(unsigned long long int);
scifir::charge operator"" _fC(unsigned long long int);
scifir::charge operator"" _aC(unsigned long long int);
scifir::charge operator"" _zC(unsigned long long int);
scifir::charge operator"" _yC(unsigned long long int);
scifir::charge operator"" _rC(unsigned long long int);
scifir::charge operator"" _qC(unsigned long long int);

scifir::temperature operator"" _QK(unsigned long long int);
scifir::temperature operator"" _RK(unsigned long long int);
scifir::temperature operator"" _YK(unsigned long long int);
scifir::temperature operator"" _ZK(unsigned long long int);
scifir::temperature operator"" _EK(unsigned long long int);
scifir::temperature operator"" _PK(unsigned long long int);
scifir::temperature operator"" _TK(unsigned long long int);
scifir::temperature operator"" _GK(unsigned long long int);
scifir::temperature operator"" _MK(unsigned long long int);
scifir::temperature operator"" _kK(unsigned long long int);
scifir::temperature operator"" _hK(unsigned long long int);
scifir::temperature operator"" _daK(unsigned long long int);
scifir::temperature operator"" _K(unsigned long long int);
scifir::temperature operator"" _dK(unsigned long long int);
scifir::temperature operator"" _cK(unsigned long long int);
scifir::temperature operator"" _mK(unsigned long long int);
scifir::temperature operator"" _uK(unsigned long long int);
scifir::temperature operator"" _nK(unsigned long long int);
scifir::temperature operator"" _pK(unsigned long long int);
scifir::temperature operator"" _fK(unsigned long long int);
scifir::temperature operator"" _aK(unsigned long long int);
scifir::temperature operator"" _zK(unsigned long long int);
scifir::temperature operator"" _yK(unsigned long long int);
scifir::temperature operator"" _rK(unsigned long long int);
scifir::temperature operator"" _qK(unsigned long long int);

scifir::mole operator"" _Qmol(unsigned long long int);
scifir::mole operator"" _Rmol(unsigned long long int);
scifir::mole operator"" _Ymol(unsigned long long int);
scifir::mole operator"" _Zmol(unsigned long long int);
scifir::mole operator"" _Emol(unsigned long long int);
scifir::mole operator"" _Pmol(unsigned long long int);
scifir::mole operator"" _Tmol(unsigned long long int);
scifir::mole operator"" _Gmol(unsigned long long int);
scifir::mole operator"" _Mmol(unsigned long long int);
scifir::mole operator"" _kmol(unsigned long long int);
scifir::mole operator"" _hmol(unsigned long long int);
scifir::mole operator"" _damol(unsigned long long int);
scifir::mole operator"" _mol(unsigned long long int);
scifir::mole operator"" _dmol(unsigned long long int);
scifir::mole operator"" _cmol(unsigned long long int);
scifir::mole operator"" _mmol(unsigned long long int);
scifir::mole operator"" _umol(unsigned long long int);
scifir::mole operator"" _nmol(unsigned long long int);
scifir::mole operator"" _pmol(unsigned long long int);
scifir::mole operator"" _fmol(unsigned long long int);
scifir::mole operator"" _amol(unsigned long long int);
scifir::mole operator"" _zmol(unsigned long long int);
scifir::mole operator"" _ymol(unsigned long long int);
scifir::mole operator"" _rmol(unsigned long long int);
scifir::mole operator"" _qmol(unsigned long long int);

scifir::light_intensity operator"" _Qcd(unsigned long long int);
scifir::light_intensity operator"" _Rcd(unsigned long long int);
scifir::light_intensity operator"" _Ycd(unsigned long long int);
scifir::light_intensity operator"" _Zcd(unsigned long long int);
scifir::light_intensity operator"" _Ecd(unsigned long long int);
scifir::light_intensity operator"" _Pcd(unsigned long long int);
scifir::light_intensity operator"" _Tcd(unsigned long long int);
scifir::light_intensity operator"" _Gcd(unsigned long long int);
scifir::light_intensity operator"" _Mcd(unsigned long long int);
scifir::light_intensity operator"" _kcd(unsigned long long int);
scifir::light_intensity operator"" _hcd(unsigned long long int);
scifir::light_intensity operator"" _dacd(unsigned long long int);
scifir::light_intensity operator"" _cd(unsigned long long int);
scifir::light_intensity operator"" _dcd(unsigned long long int);
scifir::light_intensity operator"" _ccd(unsigned long long int);
scifir::light_intensity operator"" _mcd(unsigned long long int);
scifir::light_intensity operator"" _ucd(unsigned long long int);
scifir::light_intensity operator"" _ncd(unsigned long long int);
scifir::light_intensity operator"" _pcd(unsigned long long int);
scifir::light_intensity operator"" _fcd(unsigned long long int);
scifir::light_intensity operator"" _acd(unsigned long long int);
scifir::light_intensity operator"" _zcd(unsigned long long int);
scifir::light_intensity operator"" _ycd(unsigned long long int);
scifir::light_intensity operator"" _rcd(unsigned long long int);
scifir::light_intensity operator"" _qcd(unsigned long long int);

scifir::information_size operator"" _QB(unsigned long long int);
scifir::information_size operator"" _RB(unsigned long long int);
scifir::information_size operator"" _YB(unsigned long long int);
scifir::information_size operator"" _ZB(unsigned long long int);
scifir::information_size operator"" _EB(unsigned long long int);
scifir::information_size operator"" _PB(unsigned long long int);
scifir::information_size operator"" _TB(unsigned long long int);
scifir::information_size operator"" _GB(unsigned long long int);
scifir::information_size operator"" _MB(unsigned long long int);
scifir::information_size operator"" _kB(unsigned long long int);
scifir::information_size operator"" _B(unsigned long long int);

scifir::information_size operator"" _Qbit(unsigned long long int);
scifir::information_size operator"" _Rbit(unsigned long long int);
scifir::information_size operator"" _Ybit(unsigned long long int);
scifir::information_size operator"" _Zbit(unsigned long long int);
scifir::information_size operator"" _Ebit(unsigned long long int);
scifir::information_size operator"" _Pbit(unsigned long long int);
scifir::information_size operator"" _Tbit(unsigned long long int);
scifir::information_size operator"" _Gbit(unsigned long long int);
scifir::information_size operator"" _Mbit(unsigned long long int);
scifir::information_size operator"" _kbit(unsigned long long int);
scifir::information_size operator"" _bit(unsigned long long int);

scifir::length operator"" _Qm(long double);
scifir::length operator"" _Rm(long double);
scifir::length operator"" _Ym(long double);
scifir::length operator"" _Zm(long double);
scifir::length operator"" _Em(long double);
scifir::length operator"" _Pm(long double);
scifir::length operator"" _Tm(long double);
scifir::length operator"" _Gm(long double);
scifir::length operator"" _Mm(long double);
scifir::length operator"" _km(long double);
scifir::length operator"" _hm(long double);
scifir::length operator"" _dam(long double);
scifir::length operator"" _m(long double);
scifir::length operator"" _dm(long double);
scifir::length operator"" _cm(long double);
scifir::length operator"" _mm(long double);
scifir::length operator"" _um(long double);
scifir::length operator"" _nm(long double);
scifir::length operator"" _pm(long double);
scifir::length operator"" _fm(long double);
scifir::length operator"" _am(long double);
scifir::length operator"" _zm(long double);
scifir::length operator"" _ym(long double);
scifir::length operator"" _rm(long double);
scifir::length operator"" _qm(long double);

scifir::time_duration operator"" _s(long double);
scifir::time_duration operator"" _ms(long double);
scifir::time_duration operator"" _us(long double);
scifir::time_duration operator"" _ns(long double);
scifir::time_duration operator"" _ps(long double);
scifir::time_duration operator"" _fs(long double);
scifir::time_duration operator"" _as(long double);
scifir::time_duration operator"" _zs(long double);
scifir::time_duration operator"" _ys(long double);
scifir::time_duration operator"" _rs(long double);
scifir::time_duration operator"" _qs(long double);

scifir::mass operator"" _Qg(long double);
scifir::mass operator"" _Rg(long double);
scifir::mass operator"" _Yg(long double);
scifir::mass operator"" _Zg(long double);
scifir::mass operator"" _Eg(long double);
scifir::mass operator"" _Pg(long double);
scifir::mass operator"" _Tg(long double);
scifir::mass operator"" _Gg(long double);
scifir::mass operator"" _Mg(long double);
scifir::mass operator"" _kg(long double);
scifir::mass operator"" _hg(long double);
scifir::mass operator"" _dag(long double);
scifir::mass operator"" _g(long double);
scifir::mass operator"" _dg(long double);
scifir::mass operator"" _cg(long double);
scifir::mass operator"" _mg(long double);
scifir::mass operator"" _ug(long double);
scifir::mass operator"" _ng(long double);
scifir::mass operator"" _pg(long double);
scifir::mass operator"" _fg(long double);
scifir::mass operator"" _ag(long double);
scifir::mass operator"" _zg(long double);
scifir::mass operator"" _yg(long double);
scifir::mass operator"" _rg(long double);
scifir::mass operator"" _qg(long double);

scifir::charge operator"" _QC(long double);
scifir::charge operator"" _RC(long double);
scifir::charge operator"" _YC(long double);
scifir::charge operator"" _ZC(long double);
scifir::charge operator"" _EC(long double);
scifir::charge operator"" _PC(long double);
scifir::charge operator"" _TC(long double);
scifir::charge operator"" _GC(long double);
scifir::charge operator"" _MC(long double);
scifir::charge operator"" _kC(long double);
scifir::charge operator"" _hC(long double);
scifir::charge operator"" _daC(long double);
scifir::charge operator"" _C(long double);
scifir::charge operator"" _dC(long double);
scifir::charge operator"" _cC(long double);
scifir::charge operator"" _mC(long double);
scifir::charge operator"" _uC(long double);
scifir::charge operator"" _nC(long double);
scifir::charge operator"" _pC(long double);
scifir::charge operator"" _fC(long double);
scifir::charge operator"" _aC(long double);
scifir::charge operator"" _zC(long double);
scifir::charge operator"" _yC(long double);
scifir::charge operator"" _rC(long double);
scifir::charge operator"" _qC(long double);

scifir::temperature operator"" _QK(long double);
scifir::temperature operator"" _RK(long double);
scifir::temperature operator"" _YK(long double);
scifir::temperature operator"" _ZK(long double);
scifir::temperature operator"" _EK(long double);
scifir::temperature operator"" _PK(long double);
scifir::temperature operator"" _TK(long double);
scifir::temperature operator"" _GK(long double);
scifir::temperature operator"" _MK(long double);
scifir::temperature operator"" _kK(long double);
scifir::temperature operator"" _hK(long double);
scifir::temperature operator"" _daK(long double);
scifir::temperature operator"" _K(long double);
scifir::temperature operator"" _dK(long double);
scifir::temperature operator"" _cK(long double);
scifir::temperature operator"" _mK(long double);
scifir::temperature operator"" _uK(long double);
scifir::temperature operator"" _nK(long double);
scifir::temperature operator"" _pK(long double);
scifir::temperature operator"" _fK(long double);
scifir::temperature operator"" _aK(long double);
scifir::temperature operator"" _zK(long double);
scifir::temperature operator"" _yK(long double);
scifir::temperature operator"" _rK(long double);
scifir::temperature operator"" _qK(long double);

scifir::mole operator"" _Qmol(long double);
scifir::mole operator"" _Rmol(long double);
scifir::mole operator"" _Ymol(long double);
scifir::mole operator"" _Zmol(long double);
scifir::mole operator"" _Emol(long double);
scifir::mole operator"" _Pmol(long double);
scifir::mole operator"" _Tmol(long double);
scifir::mole operator"" _Gmol(long double);
scifir::mole operator"" _Mmol(long double);
scifir::mole operator"" _kmol(long double);
scifir::mole operator"" _hmol(long double);
scifir::mole operator"" _damol(long double);
scifir::mole operator"" _mol(long double);
scifir::mole operator"" _dmol(long double);
scifir::mole operator"" _cmol(long double);
scifir::mole operator"" _mmol(long double);
scifir::mole operator"" _umol(long double);
scifir::mole operator"" _nmol(long double);
scifir::mole operator"" _pmol(long double);
scifir::mole operator"" _fmol(long double);
scifir::mole operator"" _amol(long double);
scifir::mole operator"" _zmol(long double);
scifir::mole operator"" _ymol(long double);
scifir::mole operator"" _rmol(long double);
scifir::mole operator"" _qmol(long double);

scifir::light_intensity operator"" _Qcd(long double);
scifir::light_intensity operator"" _Rcd(long double);
scifir::light_intensity operator"" _Ycd(long double);
scifir::light_intensity operator"" _Zcd(long double);
scifir::light_intensity operator"" _Ecd(long double);
scifir::light_intensity operator"" _Pcd(long double);
scifir::light_intensity operator"" _Tcd(long double);
scifir::light_intensity operator"" _Gcd(long double);
scifir::light_intensity operator"" _Mcd(long double);
scifir::light_intensity operator"" _kcd(long double);
scifir::light_intensity operator"" _hcd(long double);
scifir::light_intensity operator"" _dacd(long double);
scifir::light_intensity operator"" _cd(long double);
scifir::light_intensity operator"" _dcd(long double);
scifir::light_intensity operator"" _ccd(long double);
scifir::light_intensity operator"" _mcd(long double);
scifir::light_intensity operator"" _ucd(long double);
scifir::light_intensity operator"" _ncd(long double);
scifir::light_intensity operator"" _pcd(long double);
scifir::light_intensity operator"" _fcd(long double);
scifir::light_intensity operator"" _acd(long double);
scifir::light_intensity operator"" _zcd(long double);
scifir::light_intensity operator"" _ycd(long double);
scifir::light_intensity operator"" _rcd(long double);
scifir::light_intensity operator"" _qcd(long double);

scifir::information_size operator"" _QB(long double);
scifir::information_size operator"" _RB(long double);
scifir::information_size operator"" _YB(long double);
scifir::information_size operator"" _ZB(long double);
scifir::information_size operator"" _EB(long double);
scifir::information_size operator"" _PB(long double);
scifir::information_size operator"" _TB(long double);
scifir::information_size operator"" _GB(long double);
scifir::information_size operator"" _MB(long double);
scifir::information_size operator"" _kB(long double);
scifir::information_size operator"" _B(long double);

scifir::information_size operator"" _Qbit(long double);
scifir::information_size operator"" _Rbit(long double);
scifir::information_size operator"" _Ybit(long double);
scifir::information_size operator"" _Zbit(long double);
scifir::information_size operator"" _Ebit(long double);
scifir::information_size operator"" _Pbit(long double);
scifir::information_size operator"" _Tbit(long double);
scifir::information_size operator"" _Gbit(long double);
scifir::information_size operator"" _Mbit(long double);
scifir::information_size operator"" _kbit(long double);
scifir::information_size operator"" _bit(long double);

#endif // SCIFIR_UNITS_UNITS_BASE_UNITS_HPP_INCLUDED
