#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/unit_abbreviation.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("Abbreviation literals") {
	SECTION("Abbreviation literals") {
#ifdef IS_UNIX
		CHECK(bool(100_Å == "100 Å"));
#endif

		CHECK(bool(100_QL == "100 QL"));
		CHECK(bool(100_RL == "100 RL"));
		CHECK(bool(100_YL == "100 YL"));
		CHECK(bool(100_ZL == "100 ZL"));
		CHECK(bool(100_EL == "100 EL"));
		CHECK(bool(100_PL == "100 PL"));
		CHECK(bool(100_TL == "100 TL"));
		CHECK(bool(100_GL == "100 GL"));
		CHECK(bool(100_ML == "100 ML"));
		CHECK(bool(100_kL == "100 kL"));
		CHECK(bool(100_hL == "100 hL"));
		CHECK(bool(100_daL == "100 daL"));
		CHECK(bool(100_L == "100 L"));
		CHECK(bool(100_dL == "100 dL"));
		CHECK(bool(100_cL == "100 cL"));
		CHECK(bool(100_mL == "100 mL"));
		CHECK(bool(100_µL == "100 µL"));
		CHECK(bool(100_nL == "100 nL"));
		CHECK(bool(100_pL == "100 pL"));
		CHECK(bool(100_fL == "100 fL"));
		CHECK(bool(100_aL == "100 aL"));
		CHECK(bool(100_zL == "100 zL"));
		CHECK(bool(100_yL == "100 yL"));
		CHECK(bool(100_rL == "100 rL"));
		CHECK(bool(100_qL == "100 qL"));

		CHECK(bool(100_min == "100 min"));
		CHECK(bool(100_hour == "100 hour"));
		CHECK(bool(100_day == "100 day"));

		CHECK(bool(100_QAU == "100 QAU"));
		CHECK(bool(100_RAU == "100 RAU"));
		CHECK(bool(100_YAU == "100 YAU"));
		CHECK(bool(100_ZAU == "100 ZAU"));
		CHECK(bool(100_EAU == "100 EAU"));
		CHECK(bool(100_PAU == "100 PAU"));
		CHECK(bool(100_TAU == "100 TAU"));
		CHECK(bool(100_GAU == "100 GAU"));
		CHECK(bool(100_MAU == "100 MAU"));
		CHECK(bool(100_kAU == "100 kAU"));
		CHECK(bool(100_hAU == "100 hAU"));
		CHECK(bool(100_daAU == "100 daAU"));
		CHECK(bool(100_AU == "100 AU"));
		CHECK(bool(100_dAU == "100 dAU"));
		CHECK(bool(100_cAU == "100 cAU"));
		CHECK(bool(100_mAU == "100 mAU"));
		CHECK(bool(100_µAU == "100 µAU"));
		CHECK(bool(100_nAU == "100 nAU"));
		CHECK(bool(100_pAU == "100 pAU"));
		CHECK(bool(100_fAU == "100 fAU"));
		CHECK(bool(100_aAU == "100 aAU"));
		CHECK(bool(100_zAU == "100 zAU"));
		CHECK(bool(100_yAU == "100 yAU"));
		CHECK(bool(100_rAU == "100 rAU"));
		CHECK(bool(100_qAU == "100 qAU"));

		CHECK(bool(100_Qpc == "100 Qpc"));
		CHECK(bool(100_Rpc == "100 Rpc"));
		CHECK(bool(100_Ypc == "100 Ypc"));
		CHECK(bool(100_Zpc == "100 Zpc"));
		CHECK(bool(100_Epc == "100 Epc"));
		CHECK(bool(100_Ppc == "100 Ppc"));
		CHECK(bool(100_Tpc == "100 Tpc"));
		CHECK(bool(100_Gpc == "100 Gpc"));
		CHECK(bool(100_Mpc == "100 Mpc"));
		CHECK(bool(100_kpc == "100 kpc"));
		CHECK(bool(100_hpc == "100 hpc"));
		CHECK(bool(100_dapc == "100 dapc"));
		CHECK(bool(100_pc == "100 pc"));
		CHECK(bool(100_dpc == "100 dpc"));
		CHECK(bool(100_cpc == "100 cpc"));
		CHECK(bool(100_mpc == "100 mpc"));
		CHECK(bool(100_µpc == "100 µpc"));
		CHECK(bool(100_npc == "100 npc"));
		CHECK(bool(100_ppc == "100 ppc"));
		CHECK(bool(100_fpc == "100 fpc"));
		CHECK(bool(100_apc == "100 apc"));
		CHECK(bool(100_zpc == "100 zpc"));
		CHECK(bool(100_ypc == "100 ypc"));
		CHECK(bool(100_rpc == "100 rpc"));
		CHECK(bool(100_qpc == "100 qpc"));

		CHECK(bool(100_QeV == "100 QeV"));
		CHECK(bool(100_ReV == "100 ReV"));
		CHECK(bool(100_YeV == "100 YeV"));
		CHECK(bool(100_ZeV == "100 ZeV"));
		CHECK(bool(100_EeV == "100 EeV"));
		CHECK(bool(100_PeV == "100 PeV"));
		CHECK(bool(100_TeV == "100 TeV"));
		CHECK(bool(100_GeV == "100 GeV"));
		CHECK(bool(100_MeV == "100 MeV"));
		CHECK(bool(100_keV == "100 keV"));
		CHECK(bool(100_heV == "100 heV"));
		CHECK(bool(100_daeV == "100 daeV"));
		CHECK(bool(100_eV == "100 eV"));
		CHECK(bool(100_deV == "100 deV"));
		CHECK(bool(100_ceV == "100 ceV"));
		CHECK(bool(100_meV == "100 meV"));
		CHECK(bool(100_µeV == "100 µeV"));
		CHECK(bool(100_neV == "100 neV"));
		CHECK(bool(100_peV == "100 peV"));
		CHECK(bool(100_feV == "100 feV"));
		CHECK(bool(100_aeV == "100 aeV"));
		CHECK(bool(100_zeV == "100 zeV"));
		CHECK(bool(100_yeV == "100 yeV"));
		CHECK(bool(100_reV == "100 reV"));
		CHECK(bool(100_qeV == "100 qeV"));

		CHECK(bool(100_Da == "100 Da"));

		CHECK(bool(100_amu == "100 amu"));

		CHECK(bool(100_Qbarn == "100 Qbarn"));
		CHECK(bool(100_Rbarn == "100 Rbarn"));
		CHECK(bool(100_Ybarn == "100 Ybarn"));
		CHECK(bool(100_Zbarn == "100 Zbarn"));
		CHECK(bool(100_Ebarn == "100 Ebarn"));
		CHECK(bool(100_Pbarn == "100 Pbarn"));
		CHECK(bool(100_Tbarn == "100 Tbarn"));
		CHECK(bool(100_Gbarn == "100 Gbarn"));
		CHECK(bool(100_Mbarn == "100 Mbarn"));
		CHECK(bool(100_kbarn == "100 kbarn"));
		CHECK(bool(100_hbarn == "100 hbarn"));
		CHECK(bool(100_dabarn == "100 dabarn"));
		CHECK(bool(100_barn == "100 barn"));
		CHECK(bool(100_dbarn == "100 dbarn"));
		CHECK(bool(100_cbarn == "100 cbarn"));
		CHECK(bool(100_mbarn == "100 mbarn"));
		CHECK(bool(100_µbarn == "100 µbarn"));
		CHECK(bool(100_nbarn == "100 nbarn"));
		CHECK(bool(100_pbarn == "100 pbarn"));
		CHECK(bool(100_fbarn == "100 fbarn"));
		CHECK(bool(100_abarn == "100 abarn"));
		CHECK(bool(100_zbarn == "100 zbarn"));
		CHECK(bool(100_ybarn == "100 ybarn"));
		CHECK(bool(100_rbarn == "100 rbarn"));
		CHECK(bool(100_qbarn == "100 qbarn"));

		CHECK(bool(100_QM == "100 QM"));
		CHECK(bool(100_RM == "100 RM"));
		CHECK(bool(100_YM == "100 YM"));
		CHECK(bool(100_ZM == "100 ZM"));
		CHECK(bool(100_EM == "100 EM"));
		CHECK(bool(100_PM == "100 PM"));
		CHECK(bool(100_TM == "100 TM"));
		CHECK(bool(100_GM == "100 GM"));
		CHECK(bool(100_MM == "100 MM"));
		CHECK(bool(100_kM == "100 kM"));
		CHECK(bool(100_hM == "100 hM"));
		CHECK(bool(100_daM == "100 daM"));
		CHECK(bool(100_M == "100 M"));
		CHECK(bool(100_dM == "100 dM"));
		CHECK(bool(100_cM == "100 cM"));
		CHECK(bool(100_mM == "100 mM"));
		CHECK(bool(100_µM == "100 µM"));
		CHECK(bool(100_nM == "100 nM"));
		CHECK(bool(100_pM == "100 pM"));
		CHECK(bool(100_fM == "100 fM"));
		CHECK(bool(100_aM == "100 aM"));
		CHECK(bool(100_zM == "100 zM"));
		CHECK(bool(100_yM == "100 yM"));
		CHECK(bool(100_rM == "100 rM"));
		CHECK(bool(100_qM == "100 qM"));

		CHECK(bool(100_QIU == "100 QIU"));
		CHECK(bool(100_RIU == "100 RIU"));
		CHECK(bool(100_YIU == "100 YIU"));
		CHECK(bool(100_ZIU == "100 ZIU"));
		CHECK(bool(100_EIU == "100 EIU"));
		CHECK(bool(100_PIU == "100 PIU"));
		CHECK(bool(100_TIU == "100 TIU"));
		CHECK(bool(100_GIU == "100 GIU"));
		CHECK(bool(100_MIU == "100 MIU"));
		CHECK(bool(100_kIU == "100 kIU"));
		CHECK(bool(100_hIU == "100 hIU"));
		CHECK(bool(100_daIU == "100 daIU"));
		CHECK(bool(100_IU == "100 IU"));
		CHECK(bool(100_dIU == "100 dIU"));
		CHECK(bool(100_cIU == "100 cIU"));
		CHECK(bool(100_mIU == "100 mIU"));
		CHECK(bool(100_µIU == "100 µIU"));
		CHECK(bool(100_nIU == "100 nIU"));
		CHECK(bool(100_pIU == "100 pIU"));
		CHECK(bool(100_fIU == "100 fIU"));
		CHECK(bool(100_aIU == "100 aIU"));
		CHECK(bool(100_zIU == "100 zIU"));
		CHECK(bool(100_yIU == "100 yIU"));
		CHECK(bool(100_rIU == "100 rIU"));
		CHECK(bool(100_qIU == "100 qIU"));

		CHECK(bool(100_mEq == "100 mEq"));

		CHECK(bool(100_memo == "100 memo"));
		CHECK(bool(100_deg == "100°"));
		CHECK(bool(to_string(5_rad) == "286.47°"));
		CHECK(bool(100_particles == "100 particles"));
		CHECK(bool(100_particles == "100 particles"));
		CHECK(bool(30_percentage == "30%"));
		CHECK(bool(100_ppm == "100 ppm"));
		/*CHECK(bool(100_ppb == "100 ppb"));
		CHECK(bool(100_ppt == "100 ppt"));
		CHECK(bool(100_ppq == "100 ppq"));*/
		CHECK(bool(100_px == "100 px"));
		CHECK(bool(100_abv == "100% ABV"));

#ifdef IS_UNIX
		CHECK(bool(100.0_Å == "100 Å"));
#endif

		CHECK(bool(100.0_QL == "100 QL"));
		CHECK(bool(100.0_RL == "100 RL"));
		CHECK(bool(100.0_YL == "100 YL"));
		CHECK(bool(100.0_ZL == "100 ZL"));
		CHECK(bool(100.0_EL == "100 EL"));
		CHECK(bool(100.0_PL == "100 PL"));
		CHECK(bool(100.0_TL == "100 TL"));
		CHECK(bool(100.0_GL == "100 GL"));
		CHECK(bool(100.0_ML == "100 ML"));
		CHECK(bool(100.0_kL == "100 kL"));
		CHECK(bool(100.0_hL == "100 hL"));
		CHECK(bool(100.0_daL == "100 daL"));
		CHECK(bool(100.0_L == "100 L"));
		CHECK(bool(100.0_dL == "100 dL"));
		CHECK(bool(100.0_cL == "100 cL"));
		CHECK(bool(100.0_mL == "100 mL"));
		CHECK(bool(100.0_µL == "100 µL"));
		CHECK(bool(100.0_nL == "100 nL"));
		CHECK(bool(100.0_pL == "100 pL"));
		CHECK(bool(100.0_fL == "100 fL"));
		CHECK(bool(100.0_aL == "100 aL"));
		CHECK(bool(100.0_zL == "100 zL"));
		CHECK(bool(100.0_yL == "100 yL"));
		CHECK(bool(100.0_rL == "100 rL"));
		CHECK(bool(100.0_qL == "100 qL"));

		CHECK(bool(100.0_min == "100 min"));
		CHECK(bool(100.0_hour == "100 hour"));
		CHECK(bool(100.0_day == "100 day"));

		CHECK(bool(100.0_QAU == "100 QAU"));
		CHECK(bool(100.0_RAU == "100 RAU"));
		CHECK(bool(100.0_YAU == "100 YAU"));
		CHECK(bool(100.0_ZAU == "100 ZAU"));
		CHECK(bool(100.0_EAU == "100 EAU"));
		CHECK(bool(100.0_PAU == "100 PAU"));
		CHECK(bool(100.0_TAU == "100 TAU"));
		CHECK(bool(100.0_GAU == "100 GAU"));
		CHECK(bool(100.0_MAU == "100 MAU"));
		CHECK(bool(100.0_kAU == "100 kAU"));
		CHECK(bool(100.0_hAU == "100 hAU"));
		CHECK(bool(100.0_daAU == "100 daAU"));
		CHECK(bool(100.0_AU == "100 AU"));
		CHECK(bool(100.0_dAU == "100 dAU"));
		CHECK(bool(100.0_cAU == "100 cAU"));
		CHECK(bool(100.0_mAU == "100 mAU"));
		CHECK(bool(100.0_µAU == "100 µAU"));
		CHECK(bool(100.0_nAU == "100 nAU"));
		CHECK(bool(100.0_pAU == "100 pAU"));
		CHECK(bool(100.0_fAU == "100 fAU"));
		CHECK(bool(100.0_aAU == "100 aAU"));
		CHECK(bool(100.0_zAU == "100 zAU"));
		CHECK(bool(100.0_yAU == "100 yAU"));
		CHECK(bool(100.0_rAU == "100 rAU"));
		CHECK(bool(100.0_qAU == "100 qAU"));

		CHECK(bool(100.0_Qpc == "100 Qpc"));
		CHECK(bool(100.0_Rpc == "100 Rpc"));
		CHECK(bool(100.0_Ypc == "100 Ypc"));
		CHECK(bool(100.0_Zpc == "100 Zpc"));
		CHECK(bool(100.0_Epc == "100 Epc"));
		CHECK(bool(100.0_Ppc == "100 Ppc"));
		CHECK(bool(100.0_Tpc == "100 Tpc"));
		CHECK(bool(100.0_Gpc == "100 Gpc"));
		CHECK(bool(100.0_Mpc == "100 Mpc"));
		CHECK(bool(100.0_kpc == "100 kpc"));
		CHECK(bool(100.0_hpc == "100 hpc"));
		CHECK(bool(100.0_dapc == "100 dapc"));
		CHECK(bool(100.0_pc == "100 pc"));
		CHECK(bool(100.0_dpc == "100 dpc"));
		CHECK(bool(100.0_cpc == "100 cpc"));
		CHECK(bool(100.0_mpc == "100 mpc"));
		CHECK(bool(100.0_µpc == "100 µpc"));
		CHECK(bool(100.0_npc == "100 npc"));
		CHECK(bool(100.0_ppc == "100 ppc"));
		CHECK(bool(100.0_fpc == "100 fpc"));
		CHECK(bool(100.0_apc == "100 apc"));
		CHECK(bool(100.0_zpc == "100 zpc"));
		CHECK(bool(100.0_ypc == "100 ypc"));
		CHECK(bool(100.0_rpc == "100 rpc"));
		CHECK(bool(100.0_qpc == "100 qpc"));

		CHECK(bool(100.0_QeV == "100 QeV"));
		CHECK(bool(100.0_ReV == "100 ReV"));
		CHECK(bool(100.0_YeV == "100 YeV"));
		CHECK(bool(100.0_ZeV == "100 ZeV"));
		CHECK(bool(100.0_EeV == "100 EeV"));
		CHECK(bool(100.0_PeV == "100 PeV"));
		CHECK(bool(100.0_TeV == "100 TeV"));
		CHECK(bool(100.0_GeV == "100 GeV"));
		CHECK(bool(100.0_MeV == "100 MeV"));
		CHECK(bool(100.0_keV == "100 keV"));
		CHECK(bool(100.0_heV == "100 heV"));
		CHECK(bool(100.0_daeV == "100 daeV"));
		CHECK(bool(100.0_eV == "100 eV"));
		CHECK(bool(100.0_deV == "100 deV"));
		CHECK(bool(100.0_ceV == "100 ceV"));
		CHECK(bool(100.0_meV == "100 meV"));
		CHECK(bool(100.0_µeV == "100 µeV"));
		CHECK(bool(100.0_neV == "100 neV"));
		CHECK(bool(100.0_peV == "100 peV"));
		CHECK(bool(100.0_feV == "100 feV"));
		CHECK(bool(100.0_aeV == "100 aeV"));
		CHECK(bool(100.0_zeV == "100 zeV"));
		CHECK(bool(100.0_yeV == "100 yeV"));
		CHECK(bool(100.0_reV == "100 reV"));
		CHECK(bool(100.0_qeV == "100 qeV"));

		CHECK(bool(100.0_Da == "100 Da"));

		CHECK(bool(100.0_amu == "100 amu"));

		CHECK(bool(100.0_Qbarn == "100 Qbarn"));
		CHECK(bool(100.0_Rbarn == "100 Rbarn"));
		CHECK(bool(100.0_Ybarn == "100 Ybarn"));
		CHECK(bool(100.0_Zbarn == "100 Zbarn"));
		CHECK(bool(100.0_Ebarn == "100 Ebarn"));
		CHECK(bool(100.0_Pbarn == "100 Pbarn"));
		CHECK(bool(100.0_Tbarn == "100 Tbarn"));
		CHECK(bool(100.0_Gbarn == "100 Gbarn"));
		CHECK(bool(100.0_Mbarn == "100 Mbarn"));
		CHECK(bool(100.0_kbarn == "100 kbarn"));
		CHECK(bool(100.0_hbarn == "100 hbarn"));
		CHECK(bool(100.0_dabarn == "100 dabarn"));
		CHECK(bool(100.0_barn == "100 barn"));
		CHECK(bool(100.0_dbarn == "100 dbarn"));
		CHECK(bool(100.0_cbarn == "100 cbarn"));
		CHECK(bool(100.0_mbarn == "100 mbarn"));
		CHECK(bool(100.0_µbarn == "100 µbarn"));
		CHECK(bool(100.0_nbarn == "100 nbarn"));
		CHECK(bool(100.0_pbarn == "100 pbarn"));
		CHECK(bool(100.0_fbarn == "100 fbarn"));
		CHECK(bool(100.0_abarn == "100 abarn"));
		CHECK(bool(100.0_zbarn == "100 zbarn"));
		CHECK(bool(100.0_ybarn == "100 ybarn"));
		CHECK(bool(100.0_rbarn == "100 rbarn"));
		CHECK(bool(100.0_qbarn == "100 qbarn"));

		CHECK(bool(100.0_QM == "100 QM"));
		CHECK(bool(100.0_RM == "100 RM"));
		CHECK(bool(100.0_YM == "100 YM"));
		CHECK(bool(100.0_ZM == "100 ZM"));
		CHECK(bool(100.0_EM == "100 EM"));
		CHECK(bool(100.0_PM == "100 PM"));
		CHECK(bool(100.0_TM == "100 TM"));
		CHECK(bool(100.0_GM == "100 GM"));
		CHECK(bool(100.0_MM == "100 MM"));
		CHECK(bool(100.0_kM == "100 kM"));
		CHECK(bool(100.0_hM == "100 hM"));
		CHECK(bool(100.0_daM == "100 daM"));
		CHECK(bool(100.0_M == "100 M"));
		CHECK(bool(100.0_dM == "100 dM"));
		CHECK(bool(100.0_cM == "100 cM"));
		CHECK(bool(100.0_mM == "100 mM"));
		CHECK(bool(100.0_µM == "100 µM"));
		CHECK(bool(100.0_nM == "100 nM"));
		CHECK(bool(100.0_pM == "100 pM"));
		CHECK(bool(100.0_fM == "100 fM"));
		CHECK(bool(100.0_aM == "100 aM"));
		CHECK(bool(100.0_zM == "100 zM"));
		CHECK(bool(100.0_yM == "100 yM"));
		CHECK(bool(100.0_rM == "100 rM"));
		CHECK(bool(100.0_qM == "100 qM"));

		CHECK(bool(100.0_QIU == "100 QIU"));
		CHECK(bool(100.0_RIU == "100 RIU"));
		CHECK(bool(100.0_YIU == "100 YIU"));
		CHECK(bool(100.0_ZIU == "100 ZIU"));
		CHECK(bool(100.0_EIU == "100 EIU"));
		CHECK(bool(100.0_PIU == "100 PIU"));
		CHECK(bool(100.0_TIU == "100 TIU"));
		CHECK(bool(100.0_GIU == "100 GIU"));
		CHECK(bool(100.0_MIU == "100 MIU"));
		CHECK(bool(100.0_kIU == "100 kIU"));
		CHECK(bool(100.0_hIU == "100 hIU"));
		CHECK(bool(100.0_daIU == "100 daIU"));
		CHECK(bool(100.0_IU == "100 IU"));
		CHECK(bool(100.0_dIU == "100 dIU"));
		CHECK(bool(100.0_cIU == "100 cIU"));
		CHECK(bool(100.0_mIU == "100 mIU"));
		CHECK(bool(100.0_µIU == "100 µIU"));
		CHECK(bool(100.0_nIU == "100 nIU"));
		CHECK(bool(100.0_pIU == "100 pIU"));
		CHECK(bool(100.0_fIU == "100 fIU"));
		CHECK(bool(100.0_aIU == "100 aIU"));
		CHECK(bool(100.0_zIU == "100 zIU"));
		CHECK(bool(100.0_yIU == "100 yIU"));
		CHECK(bool(100.0_rIU == "100 rIU"));
		CHECK(bool(100.0_qIU == "100 qIU"));

		CHECK(bool(100.0_mEq == "100 mEq"));

		CHECK(bool(100.0_memo == "100 memo"));
		CHECK(bool(100.0_deg == "100°"));
		CHECK(bool(to_string(5.0_rad) == "286.47°"));
		CHECK(bool(30.0_percentage == "30%"));
		CHECK(bool(100.0_ppm == "100 ppm"));
		/*CHECK(bool(100.0_ppb == "100 ppb"));
		CHECK(bool(100.0_ppt == "100 ppt"));
		CHECK(bool(100.0_ppq == "100 ppq"));*/
		CHECK(bool(100.0_px == "100 px"));
		CHECK(bool(100.0_abv == "100% ABV"));
	}
}