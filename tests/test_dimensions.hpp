#ifndef MSCI_UNITS_TESTS_TEST_DIMENSIONS_HPP_INCLUDED
#define MSCI_UNITS_TESTS_TEST_DIMENSIONS_HPP_INCLUDED

#include "msci/units.hpp"

#include <sstream>

using namespace std;

#define ABBREVIATION_MATCH(name,symbol) shared_ptr<abbreviation> name(create_abbreviation(symbol)); \
	ostringstream name ## _out; \
	name ## _out << name; \
	REQUIRE (name ## _out.str().c_str() == symbol)

#define ABBREVIATION_MATCH_ALL(name,symbol) ABBREVIATION_MATCH(name ## _1,strcat("Y",symbol)); \
	ABBREVIATION_MATCH(name ## _2,strcat("Z",symbol)); \
	ABBREVIATION_MATCH(name ## _3,strcat("E",symbol)); \
	ABBREVIATION_MATCH(name ## _4,strcat("P",symbol)); \
	ABBREVIATION_MATCH(name ## _5,strcat("T",symbol)); \
	ABBREVIATION_MATCH(name ## _6,strcat("G",symbol)); \
	ABBREVIATION_MATCH(name ## _7,strcat("M",symbol)); \
	ABBREVIATION_MATCH(name ## _8,strcat("k",symbol)); \
	ABBREVIATION_MATCH(name ## _9,strcat("h",symbol)); \
	ABBREVIATION_MATCH(name ## _10,strcat("da",symbol)); \
	ABBREVIATION_MATCH(name ## _11,strcat("",symbol)); \
	ABBREVIATION_MATCH(name ## _12,strcat("d",symbol)); \
	ABBREVIATION_MATCH(name ## _13,strcat("c",symbol)); \
	ABBREVIATION_MATCH(name ## _14,strcat("m",symbol)); \
	ABBREVIATION_MATCH(name ## _15,strcat("u",symbol)); \
	ABBREVIATION_MATCH(name ## _16,strcat("n",symbol)); \
	ABBREVIATION_MATCH(name ## _17,strcat("p",symbol)); \
	ABBREVIATION_MATCH(name ## _18,strcat("f",symbol)); \
	ABBREVIATION_MATCH(name ## _19,strcat("a",symbol)); \
	ABBREVIATION_MATCH(name ## _20,strcat("z",symbol)); \
	ABBREVIATION_MATCH(name ## _21,strcat("y",symbol))

TEST_CASE("class abbreviation","Test of abbreviation classes")
{
	ABBREVIATION_MATCH_ALL(Hz,"Hz");
	/*ABBREVIATION_MATCH_ALL(N,"N");
	ABBREVIATION_MATCH_ALL(Pa,"Pa");
	ABBREVIATION_MATCH_ALL(J,"J");
	ABBREVIATION_MATCH_ALL(W,"W");
	ABBREVIATION_MATCH_ALL(A,"A");
	ABBREVIATION_MATCH_ALL(V,"V");
	ABBREVIATION_MATCH_ALL(F,"F");
	ABBREVIATION_MATCH_ALL(Ohm,"Ohm");
	ABBREVIATION_MATCH_ALL(S,"S");
	ABBREVIATION_MATCH_ALL(Wb,"Wb");
	ABBREVIATION_MATCH_ALL(T,"T");
	ABBREVIATION_MATCH_ALL(H,"H");
	ABBREVIATION_MATCH_ALL(lm,"lm");
	ABBREVIATION_MATCH_ALL(lx,"lx");
	ABBREVIATION_MATCH_ALL(Bq,"Bq");
	ABBREVIATION_MATCH_ALL(Gy,"Gy");
	ABBREVIATION_MATCH_ALL(Sv,"Sv");
	ABBREVIATION_MATCH_ALL(kat,"kat");
	ABBREVIATION_MATCH(angstrom,"angstrom");
	ABBREVIATION_MATCH(L,"");
	ABBREVIATION_MATCH(minute,"min");
	ABBREVIATION_MATCH(hour,"h");
	ABBREVIATION_MATCH(day,"d");
	ABBREVIATION_MATCH(au,"AU");
	ABBREVIATION_MATCH(pc,"pc");
	ABBREVIATION_MATCH(ev,"eV");
	ABBREVIATION_MATCH(da,"Da");
	ABBREVIATION_MATCH(amu,"amu");
	ABBREVIATION_MATCH(b,"b");
	ABBREVIATION_MATCH(M,"M");
	ABBREVIATION_MATCH(particles,"particles");
	ABBREVIATION_MATCH(ppm,"ppm");
	ABBREVIATION_MATCH(ppb,"ppb");*/
}

#endif // MSCI_UNITS_TESTS_TEST_DIMENSIONS_HPP_INCLUDED
