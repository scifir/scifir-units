#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/unit_basic.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("basic units","Full test of basic units") {
	SECTION("Basic functionalities of basic units") {
		
	}

	SECTION("time_duration class") {
		scifir::time_duration a = scifir::time_duration("365d");
		REQUIRE (bool(a.display_years() == "1 y"));
		scifir::time_duration b = scifir::time_duration("30 d");
		REQUIRE (bool(b.display_months() == "1 months"));
		scifir::time_duration c = scifir::time_duration("7 d");
		REQUIRE (bool(c.display_weeks() == "1 weeks"));
		scifir::time_duration d = scifir::time_duration("24 h");
		REQUIRE (bool(d.display_days() == "1 d"));
		scifir::time_duration e = scifir::time_duration("3600 s");
		REQUIRE (bool(e.display_hours() == "1 h"));
		scifir::time_duration f = scifir::time_duration("60 s");
		REQUIRE (bool(f.display_minutes() == "1 min"));
		scifir::time_duration g = scifir::time_duration("35 s");
		REQUIRE (bool(g.display_seconds() == "35 s"));
	}

	SECTION("mass class") {
		scifir::mass a = scifir::mass("5 ppm","10000000 g");
		REQUIRE (bool(to_string(a) == "50 g"));
	}

	SECTION("mole class") {
		scifir::mole a = scifir::mole("1 ppm","1000000 g");
		REQUIRE (bool(to_string(a) == "1 g"));
	}

	SECTION("Basic unit literals")
	{
		REQUIRE (bool(100_Ym == "100 Ym"));
		REQUIRE (bool(100_Zm == "100 Zm"));
		REQUIRE (bool(100_Em == "100 Em"));
		REQUIRE (bool(100_Pm == "100 Pm"));
		REQUIRE (bool(100_Tm == "100 Tm"));
		REQUIRE (bool(100_Gm == "100 Gm"));
		REQUIRE (bool(100_Mm == "100 Mm"));
		REQUIRE (bool(100_km == "100 km"));
		REQUIRE (bool(100_hm == "100 hm"));
		REQUIRE (bool(100_dam == "100 dam"));
		REQUIRE (bool(100_m == "100 m"));
		REQUIRE (bool(100_dm == "100 dm"));
		REQUIRE (bool(100_cm == "100 cm"));
		REQUIRE (bool(100_mm == "100 mm"));
		REQUIRE (bool(100_um == "100 um"));
		REQUIRE (bool(100_nm == "100 nm"));
		REQUIRE (bool(100_pm == "100 pm"));
		REQUIRE (bool(100_fm == "100 fm"));
		REQUIRE (bool(100_am == "100 am"));
		REQUIRE (bool(100_zm == "100 zm"));
		REQUIRE (bool(100_ym == "100 ym"));
		
		REQUIRE (bool(100_s == "100 s"));
		REQUIRE (bool(100_ms == "100 ms"));
		REQUIRE (bool(100_us == "100 us"));
		REQUIRE (bool(100_ns == "100 ns"));
		REQUIRE (bool(100_ps == "100 ps"));
		REQUIRE (bool(100_fs == "100 fs"));
		REQUIRE (bool(100_as == "100 as"));
		REQUIRE (bool(100_zs == "100 zs"));
		REQUIRE (bool(100_ys == "100 ys"));
		
		REQUIRE (bool(100_Yg == "100 Yg"));
		REQUIRE (bool(100_Zg == "100 Zg"));
		REQUIRE (bool(100_Eg == "100 Eg"));
		REQUIRE (bool(100_Pg == "100 Pg"));
		REQUIRE (bool(100_Tg == "100 Tg"));
		REQUIRE (bool(100_Gg == "100 Gg"));
		REQUIRE (bool(100_Mg == "100 Mg"));
		REQUIRE (bool(100_kg == "100 kg"));
		REQUIRE (bool(100_hg == "100 hg"));
		REQUIRE (bool(100_dag == "100 dag"));
		REQUIRE (bool(100_g == "100 g"));
		REQUIRE (bool(100_dg == "100 dg"));
		REQUIRE (bool(100_cg == "100 cg"));
		REQUIRE (bool(100_mg == "100 mg"));
		REQUIRE (bool(100_ug == "100 ug"));
		REQUIRE (bool(100_ng == "100 ng"));
		REQUIRE (bool(100_pg == "100 pg"));
		REQUIRE (bool(100_fg == "100 fg"));
		REQUIRE (bool(100_ag == "100 ag"));
		REQUIRE (bool(100_zg == "100 zg"));
		REQUIRE (bool(100_yg == "100 yg"));

		REQUIRE (bool(100_YC == "100 YC"));
		REQUIRE (bool(100_ZC == "100 ZC"));
		REQUIRE (bool(100_EC == "100 EC"));
		REQUIRE (bool(100_PC == "100 PC"));
		REQUIRE (bool(100_TC == "100 TC"));
		REQUIRE (bool(100_GC == "100 GC"));
		REQUIRE (bool(100_MC == "100 MC"));
		REQUIRE (bool(100_kC == "100 kC"));
		REQUIRE (bool(100_hC == "100 hC"));
		REQUIRE (bool(100_daC == "100 daC"));
		REQUIRE (bool(100_C == "100 C"));
		REQUIRE (bool(100_dC == "100 dC"));
		REQUIRE (bool(100_cC == "100 cC"));
		REQUIRE (bool(100_mC == "100 mC"));
		REQUIRE (bool(100_uC == "100 uC"));
		REQUIRE (bool(100_nC == "100 nC"));
		REQUIRE (bool(100_pC == "100 pC"));
		REQUIRE (bool(100_fC == "100 fC"));
		REQUIRE (bool(100_aC == "100 aC"));
		REQUIRE (bool(100_zC == "100 zC"));
		REQUIRE (bool(100_yC == "100 yC"));

		REQUIRE (bool(100_YK == "100 YK"));
		REQUIRE (bool(100_ZK == "100 ZK"));
		REQUIRE (bool(100_EK == "100 EK"));
		REQUIRE (bool(100_PK == "100 PK"));
		REQUIRE (bool(100_TK == "100 TK"));
		REQUIRE (bool(100_GK == "100 GK"));
		REQUIRE (bool(100_MK == "100 MK"));
		REQUIRE (bool(100_kK == "100 kK"));
		REQUIRE (bool(100_hK == "100 hK"));
		REQUIRE (bool(100_daK == "100 daK"));
		REQUIRE (bool(100_K == "100 K"));
		REQUIRE (bool(100_dK == "100 dK"));
		REQUIRE (bool(100_cK == "100 cK"));
		REQUIRE (bool(100_mK == "100 mK"));
		REQUIRE (bool(100_uK == "100 uK"));
		REQUIRE (bool(100_nK == "100 nK"));
		REQUIRE (bool(100_pK == "100 pK"));
		REQUIRE (bool(100_fK == "100 fK"));
		REQUIRE (bool(100_aK == "100 aK"));
		REQUIRE (bool(100_zK == "100 zK"));
		REQUIRE (bool(100_yK == "100 yK"));

		REQUIRE (bool(100_Ymol == "100 Ymol"));
		REQUIRE (bool(100_Zmol == "100 Zmol"));
		REQUIRE (bool(100_Emol == "100 Emol"));
		REQUIRE (bool(100_Pmol == "100 Pmol"));
		REQUIRE (bool(100_Tmol == "100 Tmol"));
		REQUIRE (bool(100_Gmol == "100 Gmol"));
		REQUIRE (bool(100_Mmol == "100 Mmol"));
		REQUIRE (bool(100_kmol == "100 kmol"));
		REQUIRE (bool(100_hmol == "100 hmol"));
		REQUIRE (bool(100_damol == "100 damol"));
		REQUIRE (bool(100_mol == "100 mol"));
		REQUIRE (bool(100_dmol == "100 dmol"));
		REQUIRE (bool(100_cmol == "100 cmol"));
		REQUIRE (bool(100_mmol == "100 mmol"));
		REQUIRE (bool(100_umol == "100 umol"));
		REQUIRE (bool(100_nmol == "100 nmol"));
		REQUIRE (bool(100_pmol == "100 pmol"));
		REQUIRE (bool(100_fmol == "100 fmol"));
		REQUIRE (bool(100_amol == "100 amol"));
		REQUIRE (bool(100_zmol == "100 zmol"));
		REQUIRE (bool(100_ymol == "100 ymol"));

		REQUIRE (bool(100_Ycd == "100 Ycd"));
		REQUIRE (bool(100_Zcd == "100 Zcd"));
		REQUIRE (bool(100_Ecd == "100 Ecd"));
		REQUIRE (bool(100_Pcd == "100 Pcd"));
		REQUIRE (bool(100_Tcd == "100 Tcd"));
		REQUIRE (bool(100_Gcd == "100 Gcd"));
		REQUIRE (bool(100_Mcd == "100 Mcd"));
		REQUIRE (bool(100_kcd == "100 kcd"));
		REQUIRE (bool(100_hcd == "100 hcd"));
		REQUIRE (bool(100_dacd == "100 dacd"));
		REQUIRE (bool(100_cd == "100 cd"));
		REQUIRE (bool(100_dcd == "100 dcd"));
		REQUIRE (bool(100_ccd == "100 ccd"));
		REQUIRE (bool(100_mcd == "100 mcd"));
		REQUIRE (bool(100_ucd == "100 ucd"));
		REQUIRE (bool(100_ncd == "100 ncd"));
		REQUIRE (bool(100_pcd == "100 pcd"));
		REQUIRE (bool(100_fcd == "100 fcd"));
		REQUIRE (bool(100_acd == "100 acd"));
		REQUIRE (bool(100_zcd == "100 zcd"));
		REQUIRE (bool(100_ycd == "100 ycd"));

		REQUIRE (bool(100_YB == "100 YB"));
		REQUIRE (bool(100_ZB == "100 ZB"));
		REQUIRE (bool(100_EB == "100 EB"));
		REQUIRE (bool(100_PB == "100 PB"));
		REQUIRE (bool(100_TB == "100 TB"));
		REQUIRE (bool(100_GB == "100 GB"));
		REQUIRE (bool(100_MB == "100 MB"));
		REQUIRE (bool(100_kB == "100 kB"));
		REQUIRE (bool(100_B == "100 B"));

		REQUIRE (bool(100.0_Ym == "100 Ym"));
		REQUIRE (bool(100.0_Zm == "100 Zm"));
		REQUIRE (bool(100.0_Em == "100 Em"));
		REQUIRE (bool(100.0_Pm == "100 Pm"));
		REQUIRE (bool(100.0_Tm == "100 Tm"));
		REQUIRE (bool(100.0_Gm == "100 Gm"));
		REQUIRE (bool(100.0_Mm == "100 Mm"));
		REQUIRE (bool(100.0_km == "100 km"));
		REQUIRE (bool(100.0_hm == "100 hm"));
		REQUIRE (bool(100.0_dam == "100 dam"));
		REQUIRE (bool(100.0_m == "100 m"));
		REQUIRE (bool(100.0_dm == "100 dm"));
		REQUIRE (bool(100.0_cm == "100 cm"));
		REQUIRE (bool(100.0_mm == "100 mm"));
		REQUIRE (bool(100.0_um == "100 um"));
		REQUIRE (bool(100.0_nm == "100 nm"));
		REQUIRE (bool(100.0_pm == "100 pm"));
		REQUIRE (bool(100.0_fm == "100 fm"));
		REQUIRE (bool(100.0_am == "100 am"));
		REQUIRE (bool(100.0_zm == "100 zm"));
		REQUIRE (bool(100.0_ym == "100 ym"));
		
		REQUIRE (bool(100.0_s == "100 s"));
		REQUIRE (bool(100.0_ms == "100 ms"));
		REQUIRE (bool(100.0_us == "100 us"));
		REQUIRE (bool(100.0_ns == "100 ns"));
		REQUIRE (bool(100.0_ps == "100 ps"));
		REQUIRE (bool(100.0_fs == "100 fs"));
		REQUIRE (bool(100.0_as == "100 as"));
		REQUIRE (bool(100.0_zs == "100 zs"));
		REQUIRE (bool(100.0_ys == "100 ys"));
		
		REQUIRE (bool(100.0_Yg == "100 Yg"));
		REQUIRE (bool(100.0_Zg == "100 Zg"));
		REQUIRE (bool(100.0_Eg == "100 Eg"));
		REQUIRE (bool(100.0_Pg == "100 Pg"));
		REQUIRE (bool(100.0_Tg == "100 Tg"));
		REQUIRE (bool(100.0_Gg == "100 Gg"));
		REQUIRE (bool(100.0_Mg == "100 Mg"));
		REQUIRE (bool(100.0_kg == "100 kg"));
		REQUIRE (bool(100.0_hg == "100 hg"));
		REQUIRE (bool(100.0_dag == "100 dag"));
		REQUIRE (bool(100.0_g == "100 g"));
		REQUIRE (bool(100.0_dg == "100 dg"));
		REQUIRE (bool(100.0_cg == "100 cg"));
		REQUIRE (bool(100.0_mg == "100 mg"));
		REQUIRE (bool(100.0_ug == "100 ug"));
		REQUIRE (bool(100.0_ng == "100 ng"));
		REQUIRE (bool(100.0_pg == "100 pg"));
		REQUIRE (bool(100.0_fg == "100 fg"));
		REQUIRE (bool(100.0_ag == "100 ag"));
		REQUIRE (bool(100.0_zg == "100 zg"));
		REQUIRE (bool(100.0_yg == "100 yg"));

		REQUIRE (bool(100.0_YC == "100 YC"));
		REQUIRE (bool(100.0_ZC == "100 ZC"));
		REQUIRE (bool(100.0_EC == "100 EC"));
		REQUIRE (bool(100.0_PC == "100 PC"));
		REQUIRE (bool(100.0_TC == "100 TC"));
		REQUIRE (bool(100.0_GC == "100 GC"));
		REQUIRE (bool(100.0_MC == "100 MC"));
		REQUIRE (bool(100.0_kC == "100 kC"));
		REQUIRE (bool(100.0_hC == "100 hC"));
		REQUIRE (bool(100.0_daC == "100 daC"));
		REQUIRE (bool(100.0_C == "100 C"));
		REQUIRE (bool(100.0_dC == "100 dC"));
		REQUIRE (bool(100.0_cC == "100 cC"));
		REQUIRE (bool(100.0_mC == "100 mC"));
		REQUIRE (bool(100.0_uC == "100 uC"));
		REQUIRE (bool(100.0_nC == "100 nC"));
		REQUIRE (bool(100.0_pC == "100 pC"));
		REQUIRE (bool(100.0_fC == "100 fC"));
		REQUIRE (bool(100.0_aC == "100 aC"));
		REQUIRE (bool(100.0_zC == "100 zC"));
		REQUIRE (bool(100.0_yC == "100 yC"));

		REQUIRE (bool(100.0_YK == "100 YK"));
		REQUIRE (bool(100.0_ZK == "100 ZK"));
		REQUIRE (bool(100.0_EK == "100 EK"));
		REQUIRE (bool(100.0_PK == "100 PK"));
		REQUIRE (bool(100.0_TK == "100 TK"));
		REQUIRE (bool(100.0_GK == "100 GK"));
		REQUIRE (bool(100.0_MK == "100 MK"));
		REQUIRE (bool(100.0_kK == "100 kK"));
		REQUIRE (bool(100.0_hK == "100 hK"));
		REQUIRE (bool(100.0_daK == "100 daK"));
		REQUIRE (bool(100.0_K == "100 K"));
		REQUIRE (bool(100.0_dK == "100 dK"));
		REQUIRE (bool(100.0_cK == "100 cK"));
		REQUIRE (bool(100.0_mK == "100 mK"));
		REQUIRE (bool(100.0_uK == "100 uK"));
		REQUIRE (bool(100.0_nK == "100 nK"));
		REQUIRE (bool(100.0_pK == "100 pK"));
		REQUIRE (bool(100.0_fK == "100 fK"));
		REQUIRE (bool(100.0_aK == "100 aK"));
		REQUIRE (bool(100.0_zK == "100 zK"));
		REQUIRE (bool(100.0_yK == "100 yK"));

		REQUIRE (bool(100.0_Ymol == "100 Ymol"));
		REQUIRE (bool(100.0_Zmol == "100 Zmol"));
		REQUIRE (bool(100.0_Emol == "100 Emol"));
		REQUIRE (bool(100.0_Pmol == "100 Pmol"));
		REQUIRE (bool(100.0_Tmol == "100 Tmol"));
		REQUIRE (bool(100.0_Gmol == "100 Gmol"));
		REQUIRE (bool(100.0_Mmol == "100 Mmol"));
		REQUIRE (bool(100.0_kmol == "100 kmol"));
		REQUIRE (bool(100.0_hmol == "100 hmol"));
		REQUIRE (bool(100.0_damol == "100 damol"));
		REQUIRE (bool(100.0_mol == "100 mol"));
		REQUIRE (bool(100.0_dmol == "100 dmol"));
		REQUIRE (bool(100.0_cmol == "100 cmol"));
		REQUIRE (bool(100.0_mmol == "100 mmol"));
		REQUIRE (bool(100.0_umol == "100 umol"));
		REQUIRE (bool(100.0_nmol == "100 nmol"));
		REQUIRE (bool(100.0_pmol == "100 pmol"));
		REQUIRE (bool(100.0_fmol == "100 fmol"));
		REQUIRE (bool(100.0_amol == "100 amol"));
		REQUIRE (bool(100.0_zmol == "100 zmol"));
		REQUIRE (bool(100.0_ymol == "100 ymol"));

		REQUIRE (bool(100.0_Ycd == "100 Ycd"));
		REQUIRE (bool(100.0_Zcd == "100 Zcd"));
		REQUIRE (bool(100.0_Ecd == "100 Ecd"));
		REQUIRE (bool(100.0_Pcd == "100 Pcd"));
		REQUIRE (bool(100.0_Tcd == "100 Tcd"));
		REQUIRE (bool(100.0_Gcd == "100 Gcd"));
		REQUIRE (bool(100.0_Mcd == "100 Mcd"));
		REQUIRE (bool(100.0_kcd == "100 kcd"));
		REQUIRE (bool(100.0_hcd == "100 hcd"));
		REQUIRE (bool(100.0_dacd == "100 dacd"));
		REQUIRE (bool(100.0_cd == "100 cd"));
		REQUIRE (bool(100.0_dcd == "100 dcd"));
		REQUIRE (bool(100.0_ccd == "100 ccd"));
		REQUIRE (bool(100.0_mcd == "100 mcd"));
		REQUIRE (bool(100.0_ucd == "100 ucd"));
		REQUIRE (bool(100.0_ncd == "100 ncd"));
		REQUIRE (bool(100.0_pcd == "100 pcd"));
		REQUIRE (bool(100.0_fcd == "100 fcd"));
		REQUIRE (bool(100.0_acd == "100 acd"));
		REQUIRE (bool(100.0_zcd == "100 zcd"));
		REQUIRE (bool(100.0_ycd == "100 ycd"));

		REQUIRE (bool(100.0_YB == "100 YB"));
		REQUIRE (bool(100.0_ZB == "100 ZB"));
		REQUIRE (bool(100.0_EB == "100 EB"));
		REQUIRE (bool(100.0_PB == "100 PB"));
		REQUIRE (bool(100.0_TB == "100 TB"));
		REQUIRE (bool(100.0_GB == "100 GB"));
		REQUIRE (bool(100.0_MB == "100 MB"));
		REQUIRE (bool(100.0_kB == "100 kB"));
		REQUIRE (bool(100.0_B == "100 B"));
	}
}
