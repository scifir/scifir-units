#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/base_units.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("Base units") {
	SECTION("Constructors of base unit classes")
	{
		length a;
		CHECK(to_string(a) == "0 m");
		mass b = 100_g;
		mass c(b);
		CHECK(to_string(c) == "100 g");
		mass b2 = 100_g;
		mass c2(std::move(b2));
		CHECK(to_string(c2) == "100 g");
		temperature h(30.0f, dimension::KELVIN, prefix::KILO);
		CHECK(to_string(h) == "30 kK");
		temperature h2(30.0, dimension::KELVIN, prefix::KILO);
		CHECK(to_string(h2) == "30 kK");
		temperature h3(30.0l, dimension::KELVIN, prefix::KILO);
		CHECK(to_string(h3) == "30 kK");
		temperature h4(30, dimension::KELVIN, prefix::KILO);
		CHECK(to_string(h4) == "30 kK");
		mass d(100.0f,"g");
		CHECK(to_string(d) == "100 g");
		mass d2(100.0,"g");
		CHECK(to_string(d2) == "100 g");
		mass d3(100.0l,"g");
		CHECK(to_string(d3) == "100 g");
		mass d4(100,"g");
		CHECK(to_string(d4) == "100 g");
		mass e(100.0f,{dimension("g",dimension::NUMERATOR)});
		CHECK(to_string(e) == "100 g");
		mass e2(100.0,{dimension("g",dimension::NUMERATOR)});
		CHECK(to_string(e2) == "100 g");
		mass e3(100.0l,{dimension("g",dimension::NUMERATOR)});
		CHECK(to_string(e3) == "100 g");
		mass e4(100,{dimension("g",dimension::NUMERATOR)});
		CHECK(to_string(e4) == "100 g");
		mass f("100 g");
		CHECK(to_string(f) == "100 g");
		mass g("2E5 g");
		CHECK(to_string(g) == "200000 g");
	}

	SECTION("Functionalities of base unit classes") {
		mass a("10 g");
		CHECK(to_string(a) == "10 g");
		mass b("10 g");
		mass c("20 g");
		CHECK(bool(a == b));
		CHECK(bool(a != c));
		CHECK(bool(a < c));
	}

	SECTION("time_duration class") {
		scifir::time_duration a = scifir::time_duration("365d");
		CHECK(a.display_years() == "1 y");
		scifir::time_duration b = scifir::time_duration("30 d");
		CHECK(b.display_months() == "1 months");
		scifir::time_duration c = scifir::time_duration("7 d");
		CHECK(c.display_weeks() == "1 weeks");
		scifir::time_duration d = scifir::time_duration("24 h");
		CHECK(d.display_days() == "1 d");
		scifir::time_duration e = scifir::time_duration("3600 s");
		CHECK(e.display_hours() == "1 h");
		scifir::time_duration f = scifir::time_duration("60 s");
		CHECK(f.display_minutes() == "1 min");
		scifir::time_duration g = scifir::time_duration("35 s");
		CHECK(g.display_seconds() == "35 s");
	}

	SECTION("mass class") {
		scifir::mass a = scifir::mass("5 ppm","10000000 g");
		CHECK(to_string(a) == "50 g");
	}

	SECTION("mole class") {
		scifir::mole a = scifir::mole("1 ppm","1000000 mol");
		CHECK(to_string(a) == "1 mol");
	}

	SECTION("Base unit literals")
	{
		CHECK(bool(100_Qm == "100 Qm"));
		CHECK(bool(100_Rm == "100 Rm"));
		CHECK(bool(100_Ym == "100 Ym"));
		CHECK(bool(100_Zm == "100 Zm"));
		CHECK(bool(100_Em == "100 Em"));
		CHECK(bool(100_Pm == "100 Pm"));
		CHECK(bool(100_Tm == "100 Tm"));
		CHECK(bool(100_Gm == "100 Gm"));
		CHECK(bool(100_Mm == "100 Mm"));
		CHECK(bool(100_km == "100 km"));
		CHECK(bool(100_hm == "100 hm"));
		CHECK(bool(100_dam == "100 dam"));
		CHECK(bool(100_m == "100 m"));
		CHECK(bool(100_dm == "100 dm"));
		CHECK(bool(100_cm == "100 cm"));
		CHECK(bool(100_mm == "100 mm"));
		CHECK(bool(100_µm == "100 µm"));
		CHECK(bool(100_nm == "100 nm"));
		CHECK(bool(100_pm == "100 pm"));
		CHECK(bool(100_fm == "100 fm"));
		CHECK(bool(100_am == "100 am"));
		CHECK(bool(100_zm == "100 zm"));
		CHECK(bool(100_ym == "100 ym"));
		CHECK(bool(100_rm == "100 rm"));
		CHECK(bool(100_qm == "100 qm"));
		CHECK(bool(100e2_m == "10000 m"));
		CHECK(bool(100.0e2_m == "10000 m"));

		CHECK(bool(100_s == "100 s"));
		CHECK(bool(100_ms == "100 ms"));
		CHECK(bool(100_µs == "100 µs"));
		CHECK(bool(100_ns == "100 ns"));
		CHECK(bool(100_ps == "100 ps"));
		CHECK(bool(100_fs == "100 fs"));
		CHECK(bool(100_as == "100 as"));
		CHECK(bool(100_zs == "100 zs"));
		CHECK(bool(100_ys == "100 ys"));
		CHECK(bool(100_rs == "100 rs"));
		CHECK(bool(100_qs == "100 qs"));

		CHECK(bool(100_Qg == "100 Qg"));
		CHECK(bool(100_Rg == "100 Rg"));
		CHECK(bool(100_Yg == "100 Yg"));
		CHECK(bool(100_Zg == "100 Zg"));
		CHECK(bool(100_Eg == "100 Eg"));
		CHECK(bool(100_Pg == "100 Pg"));
		CHECK(bool(100_Tg == "100 Tg"));
		CHECK(bool(100_Gg == "100 Gg"));
		CHECK(bool(100_Mg == "100 Mg"));
		CHECK(bool(100_kg == "100 kg"));
		CHECK(bool(100_hg == "100 hg"));
		CHECK(bool(100_dag == "100 dag"));
		CHECK(bool(100_g == "100 g"));
		CHECK(bool(100_dg == "100 dg"));
		CHECK(bool(100_cg == "100 cg"));
		CHECK(bool(100_mg == "100 mg"));
		CHECK(bool(100_µg == "100 µg"));
		CHECK(bool(100_ng == "100 ng"));
		CHECK(bool(100_pg == "100 pg"));
		CHECK(bool(100_fg == "100 fg"));
		CHECK(bool(100_ag == "100 ag"));
		CHECK(bool(100_zg == "100 zg"));
		CHECK(bool(100_yg == "100 yg"));
		CHECK(bool(100_rg == "100 rg"));
		CHECK(bool(100_qg == "100 qg"));

		CHECK(bool(100_QC == "100 QC"));
		CHECK(bool(100_RC == "100 RC"));
		CHECK(bool(100_YC == "100 YC"));
		CHECK(bool(100_ZC == "100 ZC"));
		CHECK(bool(100_EC == "100 EC"));
		CHECK(bool(100_PC == "100 PC"));
		CHECK(bool(100_TC == "100 TC"));
		CHECK(bool(100_GC == "100 GC"));
		CHECK(bool(100_MC == "100 MC"));
		CHECK(bool(100_kC == "100 kC"));
		CHECK(bool(100_hC == "100 hC"));
		CHECK(bool(100_daC == "100 daC"));
		CHECK(bool(100_C == "100 C"));
		CHECK(bool(100_dC == "100 dC"));
		CHECK(bool(100_cC == "100 cC"));
		CHECK(bool(100_mC == "100 mC"));
		CHECK(bool(100_µC == "100 µC"));
		CHECK(bool(100_nC == "100 nC"));
		CHECK(bool(100_pC == "100 pC"));
		CHECK(bool(100_fC == "100 fC"));
		CHECK(bool(100_aC == "100 aC"));
		CHECK(bool(100_zC == "100 zC"));
		CHECK(bool(100_yC == "100 yC"));
		CHECK(bool(100_rC == "100 rC"));
		CHECK(bool(100_qC == "100 qC"));

		CHECK(bool(100_QK == "100 QK"));
		CHECK(bool(100_RK == "100 RK"));
		CHECK(bool(100_YK == "100 YK"));
		CHECK(bool(100_ZK == "100 ZK"));
		CHECK(bool(100_EK == "100 EK"));
		CHECK(bool(100_PK == "100 PK"));
		CHECK(bool(100_TK == "100 TK"));
		CHECK(bool(100_GK == "100 GK"));
		CHECK(bool(100_MK == "100 MK"));
		CHECK(bool(100_kK == "100 kK"));
		CHECK(bool(100_hK == "100 hK"));
		CHECK(bool(100_daK == "100 daK"));
		CHECK(bool(100_K == "100 K"));
		CHECK(bool(100_dK == "100 dK"));
		CHECK(bool(100_cK == "100 cK"));
		CHECK(bool(100_mK == "100 mK"));
		CHECK(bool(100_µK == "100 µK"));
		CHECK(bool(100_nK == "100 nK"));
		CHECK(bool(100_pK == "100 pK"));
		CHECK(bool(100_fK == "100 fK"));
		CHECK(bool(100_aK == "100 aK"));
		CHECK(bool(100_zK == "100 zK"));
		CHECK(bool(100_yK == "100 yK"));
		CHECK(bool(100_rK == "100 rK"));
		CHECK(bool(100_qK == "100 qK"));

		CHECK(bool(100_Qmol == "100 Qmol"));
		CHECK(bool(100_Rmol == "100 Rmol"));
		CHECK(bool(100_Ymol == "100 Ymol"));
		CHECK(bool(100_Zmol == "100 Zmol"));
		CHECK(bool(100_Emol == "100 Emol"));
		CHECK(bool(100_Pmol == "100 Pmol"));
		CHECK(bool(100_Tmol == "100 Tmol"));
		CHECK(bool(100_Gmol == "100 Gmol"));
		CHECK(bool(100_Mmol == "100 Mmol"));
		CHECK(bool(100_kmol == "100 kmol"));
		CHECK(bool(100_hmol == "100 hmol"));
		CHECK(bool(100_damol == "100 damol"));
		CHECK(bool(100_mol == "100 mol"));
		CHECK(bool(100_dmol == "100 dmol"));
		CHECK(bool(100_cmol == "100 cmol"));
		CHECK(bool(100_mmol == "100 mmol"));
		CHECK(bool(100_µmol == "100 µmol"));
		CHECK(bool(100_nmol == "100 nmol"));
		CHECK(bool(100_pmol == "100 pmol"));
		CHECK(bool(100_fmol == "100 fmol"));
		CHECK(bool(100_amol == "100 amol"));
		CHECK(bool(100_zmol == "100 zmol"));
		CHECK(bool(100_ymol == "100 ymol"));
		CHECK(bool(100_rmol == "100 rmol"));
		CHECK(bool(100_qmol == "100 qmol"));

		CHECK(bool(100_Qcd == "100 Qcd"));
		CHECK(bool(100_Rcd == "100 Rcd"));
		CHECK(bool(100_Ycd == "100 Ycd"));
		CHECK(bool(100_Zcd == "100 Zcd"));
		CHECK(bool(100_Ecd == "100 Ecd"));
		CHECK(bool(100_Pcd == "100 Pcd"));
		CHECK(bool(100_Tcd == "100 Tcd"));
		CHECK(bool(100_Gcd == "100 Gcd"));
		CHECK(bool(100_Mcd == "100 Mcd"));
		CHECK(bool(100_kcd == "100 kcd"));
		CHECK(bool(100_hcd == "100 hcd"));
		CHECK(bool(100_dacd == "100 dacd"));
		CHECK(bool(100_cd == "100 cd"));
		CHECK(bool(100_dcd == "100 dcd"));
		CHECK(bool(100_ccd == "100 ccd"));
		CHECK(bool(100_mcd == "100 mcd"));
		CHECK(bool(100_µcd == "100 µcd"));
		CHECK(bool(100_ncd == "100 ncd"));
		CHECK(bool(100_pcd == "100 pcd"));
		CHECK(bool(100_fcd == "100 fcd"));
		CHECK(bool(100_acd == "100 acd"));
		CHECK(bool(100_zcd == "100 zcd"));
		CHECK(bool(100_ycd == "100 ycd"));
		CHECK(bool(100_rcd == "100 rcd"));
		CHECK(bool(100_qcd == "100 qcd"));

		CHECK(bool(100_QB == "100 QB"));
		CHECK(bool(100_RB == "100 RB"));
		CHECK(bool(100_YB == "100 YB"));
		CHECK(bool(100_ZB == "100 ZB"));
		CHECK(bool(100_EB == "100 EB"));
		CHECK(bool(100_PB == "100 PB"));
		CHECK(bool(100_TB == "100 TB"));
		CHECK(bool(100_GB == "100 GB"));
		CHECK(bool(100_MB == "100 MB"));
		CHECK(bool(100_kB == "100 kB"));
		CHECK(bool(100_B == "100 B"));

		CHECK(bool(100_Qbit == "100 Qbit"));
		CHECK(bool(100_Rbit == "100 Rbit"));
		CHECK(bool(100_Ybit == "100 Ybit"));
		CHECK(bool(100_Zbit == "100 Zbit"));
		CHECK(bool(100_Ebit == "100 Ebit"));
		CHECK(bool(100_Pbit == "100 Pbit"));
		CHECK(bool(100_Tbit == "100 Tbit"));
		CHECK(bool(100_Gbit == "100 Gbit"));
		CHECK(bool(100_Mbit == "100 Mbit"));
		CHECK(bool(100_kbit == "100 kbit"));
		CHECK(bool(100_bit == "100 bit"));

		CHECK(bool(100.0_Qm == "100 Qm"));
		CHECK(bool(100.0_Rm == "100 Rm"));
		CHECK(bool(100.0_Ym == "100 Ym"));
		CHECK(bool(100.0_Zm == "100 Zm"));
		CHECK(bool(100.0_Em == "100 Em"));
		CHECK(bool(100.0_Pm == "100 Pm"));
		CHECK(bool(100.0_Tm == "100 Tm"));
		CHECK(bool(100.0_Gm == "100 Gm"));
		CHECK(bool(100.0_Mm == "100 Mm"));
		CHECK(bool(100.0_km == "100 km"));
		CHECK(bool(100.0_hm == "100 hm"));
		CHECK(bool(100.0_dam == "100 dam"));
		CHECK(bool(100.0_m == "100 m"));
		CHECK(bool(100.0_dm == "100 dm"));
		CHECK(bool(100.0_cm == "100 cm"));
		CHECK(bool(100.0_mm == "100 mm"));
		CHECK(bool(100.0_µm == "100 µm"));
		CHECK(bool(100.0_nm == "100 nm"));
		CHECK(bool(100.0_pm == "100 pm"));
		CHECK(bool(100.0_fm == "100 fm"));
		CHECK(bool(100.0_am == "100 am"));
		CHECK(bool(100.0_zm == "100 zm"));
		CHECK(bool(100.0_ym == "100 ym"));
		CHECK(bool(100.0_rm == "100 rm"));
		CHECK(bool(100.0_qm == "100 qm"));
		
		CHECK(bool(100.0_s == "100 s"));
		CHECK(bool(100.0_ms == "100 ms"));
		CHECK(bool(100.0_µs == "100 µs"));
		CHECK(bool(100.0_ns == "100 ns"));
		CHECK(bool(100.0_ps == "100 ps"));
		CHECK(bool(100.0_fs == "100 fs"));
		CHECK(bool(100.0_as == "100 as"));
		CHECK(bool(100.0_zs == "100 zs"));
		CHECK(bool(100.0_ys == "100 ys"));
		CHECK(bool(100.0_rs == "100 rs"));
		CHECK(bool(100.0_qs == "100 qs"));
		
		CHECK(bool(100.0_Qg == "100 Qg"));
		CHECK(bool(100.0_Rg == "100 Rg"));
		CHECK(bool(100.0_Yg == "100 Yg"));
		CHECK(bool(100.0_Zg == "100 Zg"));
		CHECK(bool(100.0_Eg == "100 Eg"));
		CHECK(bool(100.0_Pg == "100 Pg"));
		CHECK(bool(100.0_Tg == "100 Tg"));
		CHECK(bool(100.0_Gg == "100 Gg"));
		CHECK(bool(100.0_Mg == "100 Mg"));
		CHECK(bool(100.0_kg == "100 kg"));
		CHECK(bool(100.0_hg == "100 hg"));
		CHECK(bool(100.0_dag == "100 dag"));
		CHECK(bool(100.0_g == "100 g"));
		CHECK(bool(100.0_dg == "100 dg"));
		CHECK(bool(100.0_cg == "100 cg"));
		CHECK(bool(100.0_mg == "100 mg"));
		CHECK(bool(100.0_µg == "100 µg"));
		CHECK(bool(100.0_ng == "100 ng"));
		CHECK(bool(100.0_pg == "100 pg"));
		CHECK(bool(100.0_fg == "100 fg"));
		CHECK(bool(100.0_ag == "100 ag"));
		CHECK(bool(100.0_zg == "100 zg"));
		CHECK(bool(100.0_yg == "100 yg"));
		CHECK(bool(100.0_rg == "100 rg"));
		CHECK(bool(100.0_qg == "100 qg"));

		CHECK(bool(100.0_QC == "100 QC"));
		CHECK(bool(100.0_RC == "100 RC"));
		CHECK(bool(100.0_YC == "100 YC"));
		CHECK(bool(100.0_ZC == "100 ZC"));
		CHECK(bool(100.0_EC == "100 EC"));
		CHECK(bool(100.0_PC == "100 PC"));
		CHECK(bool(100.0_TC == "100 TC"));
		CHECK(bool(100.0_GC == "100 GC"));
		CHECK(bool(100.0_MC == "100 MC"));
		CHECK(bool(100.0_kC == "100 kC"));
		CHECK(bool(100.0_hC == "100 hC"));
		CHECK(bool(100.0_daC == "100 daC"));
		CHECK(bool(100.0_C == "100 C"));
		CHECK(bool(100.0_dC == "100 dC"));
		CHECK(bool(100.0_cC == "100 cC"));
		CHECK(bool(100.0_mC == "100 mC"));
		CHECK(bool(100.0_µC == "100 µC"));
		CHECK(bool(100.0_nC == "100 nC"));
		CHECK(bool(100.0_pC == "100 pC"));
		CHECK(bool(100.0_fC == "100 fC"));
		CHECK(bool(100.0_aC == "100 aC"));
		CHECK(bool(100.0_zC == "100 zC"));
		CHECK(bool(100.0_yC == "100 yC"));
		CHECK(bool(100.0_rC == "100 rC"));
		CHECK(bool(100.0_qC == "100 qC"));

		CHECK(bool(100.0_QK == "100 QK"));
		CHECK(bool(100.0_RK == "100 RK"));
		CHECK(bool(100.0_YK == "100 YK"));
		CHECK(bool(100.0_ZK == "100 ZK"));
		CHECK(bool(100.0_EK == "100 EK"));
		CHECK(bool(100.0_PK == "100 PK"));
		CHECK(bool(100.0_TK == "100 TK"));
		CHECK(bool(100.0_GK == "100 GK"));
		CHECK(bool(100.0_MK == "100 MK"));
		CHECK(bool(100.0_kK == "100 kK"));
		CHECK(bool(100.0_hK == "100 hK"));
		CHECK(bool(100.0_daK == "100 daK"));
		CHECK(bool(100.0_K == "100 K"));
		CHECK(bool(100.0_dK == "100 dK"));
		CHECK(bool(100.0_cK == "100 cK"));
		CHECK(bool(100.0_mK == "100 mK"));
		CHECK(bool(100.0_µK == "100 µK"));
		CHECK(bool(100.0_nK == "100 nK"));
		CHECK(bool(100.0_pK == "100 pK"));
		CHECK(bool(100.0_fK == "100 fK"));
		CHECK(bool(100.0_aK == "100 aK"));
		CHECK(bool(100.0_zK == "100 zK"));
		CHECK(bool(100.0_yK == "100 yK"));
		CHECK(bool(100.0_rK == "100 rK"));
		CHECK(bool(100.0_qK == "100 qK"));

		CHECK(bool(100.0_Qmol == "100 Qmol"));
		CHECK(bool(100.0_Rmol == "100 Rmol"));
		CHECK(bool(100.0_Ymol == "100 Ymol"));
		CHECK(bool(100.0_Zmol == "100 Zmol"));
		CHECK(bool(100.0_Emol == "100 Emol"));
		CHECK(bool(100.0_Pmol == "100 Pmol"));
		CHECK(bool(100.0_Tmol == "100 Tmol"));
		CHECK(bool(100.0_Gmol == "100 Gmol"));
		CHECK(bool(100.0_Mmol == "100 Mmol"));
		CHECK(bool(100.0_kmol == "100 kmol"));
		CHECK(bool(100.0_hmol == "100 hmol"));
		CHECK(bool(100.0_damol == "100 damol"));
		CHECK(bool(100.0_mol == "100 mol"));
		CHECK(bool(100.0_dmol == "100 dmol"));
		CHECK(bool(100.0_cmol == "100 cmol"));
		CHECK(bool(100.0_mmol == "100 mmol"));
		CHECK(bool(100.0_µmol == "100 µmol"));
		CHECK(bool(100.0_nmol == "100 nmol"));
		CHECK(bool(100.0_pmol == "100 pmol"));
		CHECK(bool(100.0_fmol == "100 fmol"));
		CHECK(bool(100.0_amol == "100 amol"));
		CHECK(bool(100.0_zmol == "100 zmol"));
		CHECK(bool(100.0_ymol == "100 ymol"));
		CHECK(bool(100.0_rmol == "100 rmol"));
		CHECK(bool(100.0_qmol == "100 qmol"));

		CHECK(bool(100.0_Qcd == "100 Qcd"));
		CHECK(bool(100.0_Rcd == "100 Rcd"));
		CHECK(bool(100.0_Ycd == "100 Ycd"));
		CHECK(bool(100.0_Zcd == "100 Zcd"));
		CHECK(bool(100.0_Ecd == "100 Ecd"));
		CHECK(bool(100.0_Pcd == "100 Pcd"));
		CHECK(bool(100.0_Tcd == "100 Tcd"));
		CHECK(bool(100.0_Gcd == "100 Gcd"));
		CHECK(bool(100.0_Mcd == "100 Mcd"));
		CHECK(bool(100.0_kcd == "100 kcd"));
		CHECK(bool(100.0_hcd == "100 hcd"));
		CHECK(bool(100.0_dacd == "100 dacd"));
		CHECK(bool(100.0_cd == "100 cd"));
		CHECK(bool(100.0_dcd == "100 dcd"));
		CHECK(bool(100.0_ccd == "100 ccd"));
		CHECK(bool(100.0_mcd == "100 mcd"));
		CHECK(bool(100.0_µcd == "100 µcd"));
		CHECK(bool(100.0_ncd == "100 ncd"));
		CHECK(bool(100.0_pcd == "100 pcd"));
		CHECK(bool(100.0_fcd == "100 fcd"));
		CHECK(bool(100.0_acd == "100 acd"));
		CHECK(bool(100.0_zcd == "100 zcd"));
		CHECK(bool(100.0_ycd == "100 ycd"));
		CHECK(bool(100.0_rcd == "100 rcd"));
		CHECK(bool(100.0_qcd == "100 qcd"));

		CHECK(bool(100.0_QB == "100 QB"));
		CHECK(bool(100.0_RB == "100 RB"));
		CHECK(bool(100.0_YB == "100 YB"));
		CHECK(bool(100.0_ZB == "100 ZB"));
		CHECK(bool(100.0_EB == "100 EB"));
		CHECK(bool(100.0_PB == "100 PB"));
		CHECK(bool(100.0_TB == "100 TB"));
		CHECK(bool(100.0_GB == "100 GB"));
		CHECK(bool(100.0_MB == "100 MB"));
		CHECK(bool(100.0_kB == "100 kB"));
		CHECK(bool(100.0_B == "100 B"));

		CHECK(bool(100.0_Qbit == "100 Qbit"));
		CHECK(bool(100.0_Rbit == "100 Rbit"));
		CHECK(bool(100.0_Ybit == "100 Ybit"));
		CHECK(bool(100.0_Zbit == "100 Zbit"));
		CHECK(bool(100.0_Ebit == "100 Ebit"));
		CHECK(bool(100.0_Pbit == "100 Pbit"));
		CHECK(bool(100.0_Tbit == "100 Tbit"));
		CHECK(bool(100.0_Gbit == "100 Gbit"));
		CHECK(bool(100.0_Mbit == "100 Mbit"));
		CHECK(bool(100.0_kbit == "100 kbit"));
		CHECK(bool(100.0_bit == "100 bit"));
	}
}
