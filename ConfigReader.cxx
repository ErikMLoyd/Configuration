#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "ConfigReader.h"

// I have to initialize the maps like this because c++98 sucks (or maybe just the CINT does)
void ConfigReader::initialize()
{
	//Standard information
	name = "";
	fixed_target = intValCuts["fixed_target"] = -999;
	sqrt_s_NN = dblValCuts["sqrt_s_NN"] = -999.0;
	y_mid = dblValCuts["y_mid"] = -999.0;
	y_beam = dblValCuts["y_beam"] = -999.0;

	//Maker Size Cuts	
	m_r_vtx = dblValCuts["m_r_vtx"] = -999.0;
	m_z_vtx_low = dblValCuts["m_z_vtx_low"] = -999.0;
	m_z_vtx_high = dblValCuts["m_z_vtx_high"] = -999.0;
	m_nHits_ratio = dblValCuts["m_nHits_ratio"] = -999.0;
	m_dca = dblValCuts["m_dca"] = -999.0;
	m_nHits = intValCuts["m_nHits"] = -999;
	m_nHits_dEdx = intValCuts["m_nHits_dEdx"] = -999;	
	
	//Maker PID Cuts
	nSig_pi = dblValCuts["nSig_pi"] = -999.0;
	nSig_ka = dblValCuts["nSig_ka"] = -999.0;
	nSig_pr = dblValCuts["nSig_pr"] = -999.0;
	TOFnSigma = dblValCuts["TOFnSigma"] = -999.0;
  
	m_lambda_mass_low = dblValCuts["m_lambda_mass_low"] = -999.0;
	m_lambda_mass_high = dblValCuts["m_lambda_mass_high"] = -999.0;
	m_xi_mass_low = dblValCuts["m_xi_mass_low"] = -999.0;
	m_xi_mass_high = dblValCuts["m_xi_mass_high"] = -999.0;
	m_omega_mass_low = dblValCuts["m_omega_mass_low"] = -999.0;
	m_omega_mass_high = dblValCuts["m_omega_mass_high"] = -999.0;

	//Analysis Cuts
	order_n = intValCuts["order_n"] = -999;
	order_m = intValCuts["order_m"] = -999;
	shift_terms = intValCuts["shift_terms"] = -999;
	epd_max_weight = intValCuts["epd_max_weight"] = -999;
	epd_threshold = dblValCuts["epd_threshold"] = -999.0;

	nHits = intValCuts["nHits"] = -999;
	nHits_dEdx = intValCuts["nHits_dEdx"] = -999;
	min_tracks = intValCuts["min_tracks"] = -999;
	nHits_ratio = dblValCuts["nHits_ratio"] = -999.0;
	dca = dblValCuts["dca"] = -999.0;
	r_vtx = dblValCuts["r_vtx"] = -999.0;
	z_vtx_low = dblValCuts["z_vtx_low"] = -999.0;
	z_vtx_high = dblValCuts["z_vtx_high"] = -999.0;
	nSig_pi_high = dblValCuts["nSig_pi_high"] = -999.0;
	nSig_pi_low = dblValCuts["nSig_pi_low"] = -999.0;
	nSig_ka_high = dblValCuts["nSig_ka_high"] = -999.0;
	nSig_ka_low = dblValCuts["nSig_ka_low"] = -999.0;
	nSig_pr_high = dblValCuts["nSig_pr_high"] = -999.0;
	nSig_pr_low = dblValCuts["nSig_pr_low"] = -999.0;
	m2_pi_low = dblValCuts["m2_pi_low"] = -999.0;
	m2_pi_high = dblValCuts["m2_pi_high"] = -999.0;
	m2_ka_low = dblValCuts["m2_ka_low"] = -999.0;
	m2_ka_high = dblValCuts["m2_ka_high"] = -999.0;
	m2_pr_low = dblValCuts["m2_pr_low"] = -999.0;
	m2_pr_high = dblValCuts["m2_pr_high"] = -999.0;
	m2_e_high = dblValCuts["m2_e_high"] = -999.0;
	d_mom_pi_low = dblValCuts["d_mom_pi_low"] = -999.0;

	//Acceptance regions
	yCM_pi_plus_central_low = dblValCuts["yCM_pi_plus_central_low"] = -999.0;
	yCM_pi_plus_central_high = dblValCuts["yCM_pi_plus_central_high"] = -999.0;
	yCM_pi_plus_semicentral_low = dblValCuts["yCM_pi_plus_semicentral_low"] = -999.0;
	yCM_pi_plus_semicentral_high = dblValCuts["yCM_pi_plus_semicentral_high"] = -999.0;
	yCM_pi_plus_peripheral_low = dblValCuts["yCM_pi_plus_peripheral_low"] = -999.0;
	yCM_pi_plus_peripheral_high = dblValCuts["yCM_pi_plus_peripheral_high"] = -999.0;

	yCM_pi_minus_central_low = dblValCuts["yCM_pi_minus_central_low"] = -999.0;
	yCM_pi_minus_central_high = dblValCuts["yCM_pi_minus_central_high"] = -999.0;
	yCM_pi_minus_semicentral_low = dblValCuts["yCM_pi_minus_semicentral_low"] = -999.0;
	yCM_pi_minus_semicentral_high = dblValCuts["yCM_pi_minus_semicentral_high"] = -999.0;
	yCM_pi_minus_peripheral_low = dblValCuts["yCM_pi_minus_peripheral_low"] = -999.0;
	yCM_pi_minus_peripheral_high = dblValCuts["yCM_pi_minus_peripheral_high"] = -999.0;

	yCM_ka_plus_central_low = dblValCuts["yCM_ka_plus_central_low"] = -999.0;
	yCM_ka_plus_central_high = dblValCuts["yCM_ka_plus_central_high"] = -999.0;
	yCM_ka_plus_semicentral_low = dblValCuts["yCM_ka_plus_semicentral_low"] = -999.0;
	yCM_ka_plus_semicentral_high = dblValCuts["yCM_ka_plus_semicentral_high"] = -999.0;
	yCM_ka_plus_peripheral_low = dblValCuts["yCM_ka_plus_peripheral_low"] = -999.0;
	yCM_ka_plus_peripheral_high = dblValCuts["yCM_ka_plus_peripheral_high"] = -999.0;

	yCM_ka_minus_central_low = dblValCuts["yCM_ka_minus_central_low"] = -999.0;
	yCM_ka_minus_central_high = dblValCuts["yCM_ka_minus_central_high"] = -999.0;
	yCM_ka_minus_semicentral_low = dblValCuts["yCM_ka_minus_semicentral_low"] = -999.0;
	yCM_ka_minus_semicentral_high = dblValCuts["yCM_ka_minus_semicentral_high"] = -999.0;
	yCM_ka_minus_peripheral_low = dblValCuts["yCM_ka_minus_peripheral_low"] = -999.0;
	yCM_ka_minus_peripheral_high = dblValCuts["yCM_ka_minus_peripheral_high"] = -999.0;

	yCM_pr_central_low = dblValCuts["yCM_pr_central_low"] = -999.0;
	yCM_pr_central_high = dblValCuts["yCM_pr_central_high"] = -999.0;
	yCM_pr_semicentral_low = dblValCuts["yCM_pr_semicentral_low"] = -999.0;
	yCM_pr_semicentral_high = dblValCuts["yCM_pr_semicentral_high"] = -999.0;
	yCM_pr_peripheral_low = dblValCuts["yCM_pr_peripheral_low"] = -999.0;
	yCM_pr_peripheral_high = dblValCuts["yCM_pr_peripheral_high"] = -999.0;

	yCM_apr_central_low = dblValCuts["yCM_apr_central_low"] = -999.0;
	yCM_apr_central_high = dblValCuts["yCM_apr_central_high"] = -999.0;
	yCM_apr_semicentral_low = dblValCuts["yCM_apr_semicentral_low"] = -999.0;
	yCM_apr_semicentral_high = dblValCuts["yCM_apr_semicentral_high"] = -999.0;
	yCM_apr_peripheral_low = dblValCuts["yCM_apr_peripheral_low"] = -999.0;
	yCM_apr_peripheral_high = dblValCuts["yCM_apr_peripheral_high"] = -999.0;

	yCM_la_central_low = dblValCuts["yCM_la_central_low"] = -999.0;
	yCM_la_central_high = dblValCuts["yCM_la_central_high"] = -999.0;
	yCM_la_semicentral_low = dblValCuts["yCM_la_semicentral_low"] = -999.0;
	yCM_la_semicentral_high = dblValCuts["yCM_la_semicentral_high"] = -999.0;
	yCM_la_peripheral_low = dblValCuts["yCM_la_peripheral_low"] = -999.0;
	yCM_la_peripheral_high = dblValCuts["yCM_la_peripheral_high"] = -999.0;
	
	yCM_ala_central_low = dblValCuts["yCM_ala_central_low"] = -999.0;
	yCM_ala_central_high = dblValCuts["yCM_ala_central_high"] = -999.0;
	yCM_ala_semicentral_low = dblValCuts["yCM_ala_semicentral_low"] = -999.0;
	yCM_ala_semicentral_high = dblValCuts["yCM_ala_semicentral_high"] = -999.0;
	yCM_ala_peripheral_low = dblValCuts["yCM_ala_peripheral_low"] = -999.0;
	yCM_ala_peripheral_high = dblValCuts["yCM_ala_peripheral_high"] = -999.0;
	
	yCM_xi_plus_central_low = dblValCuts["yCM_xi_plus_central_low"] = -999.0;
	yCM_xi_plus_central_high = dblValCuts["yCM_xi_plus_central_high"] = -999.0;
	yCM_xi_plus_semicentral_low = dblValCuts["yCM_xi_plus_semicentral_low"] = -999.0;
	yCM_xi_plus_semicentral_high = dblValCuts["yCM_xi_plus_semicentral_high"] = -999.0;
	yCM_xi_plus_peripheral_low = dblValCuts["yCM_xi_plus_peripheral_low"] = -999.0;
	yCM_xi_plus_peripheral_high = dblValCuts["yCM_xi_plus_peripheral_high"] = -999.0;
	
	yCM_xi_minus_central_low = dblValCuts["yCM_xi_minus_central_low"] = -999.0;
	yCM_xi_minus_central_high = dblValCuts["yCM_xi_minus_central_high"] = -999.0;
	yCM_xi_minus_semicentral_low = dblValCuts["yCM_xi_minus_semicentral_low"] = -999.0;
	yCM_xi_minus_semicentral_high = dblValCuts["yCM_xi_minus_semicentral_high"] = -999.0;
	yCM_xi_minus_peripheral_low = dblValCuts["yCM_xi_minus_peripheral_low"] = -999.0;
	yCM_xi_minus_peripheral_high = dblValCuts["yCM_xi_minus_peripheral_high"] = -999.0;
	
	yCM_omega_plus_central_low = dblValCuts["yCM_omega_plus_central_low"] = -999.0;
	yCM_omega_plus_central_high = dblValCuts["yCM_omega_plus_central_high"] = -999.0;
	yCM_omega_plus_semicentral_low = dblValCuts["yCM_omega_plus_semicentral_low"] = -999.0;
	yCM_omega_plus_semicentral_high = dblValCuts["yCM_omega_plus_semicentral_high"] = -999.0;
	yCM_omega_plus_peripheral_low = dblValCuts["yCM_omega_plus_peripheral_low"] = -999.0;
	yCM_omega_plus_peripheral_high = dblValCuts["yCM_omega_plus_peripheral_high"] = -999.0;
	
	yCM_omega_minus_central_low = dblValCuts["yCM_omega_minus_central_low"] = -999.0;
	yCM_omega_minus_central_high = dblValCuts["yCM_omega_minus_central_high"] = -999.0;
	yCM_omega_minus_semicentral_low = dblValCuts["yCM_omega_minus_semicentral_low"] = -999.0;
	yCM_omega_minus_semicentral_high = dblValCuts["yCM_omega_minus_semicentral_high"] = -999.0;
	yCM_omega_minus_peripheral_low = dblValCuts["yCM_omega_minus_peripheral_low"] = -999.0;
	yCM_omega_minus_peripheral_high = dblValCuts["yCM_omega_minus_peripheral_high"] = -999.0;

	pT_pi_plus_central_low = dblValCuts["pT_pi_plus_central_low"] = -999.0;
	pT_pi_plus_central_high = dblValCuts["pT_pi_plus_central_high"] = -999.0;
	pT_pi_plus_semicentral_low = dblValCuts["pT_pi_plus_semicentral_low"] = -999.0;
	pT_pi_plus_semicentral_high = dblValCuts["pT_pi_plus_semicentral_high"] = -999.0;
	pT_pi_plus_peripheral_low = dblValCuts["pT_pi_plus_peripheral_low"] = -999.0;
	pT_pi_plus_peripheral_high = dblValCuts["pT_pi_plus_peripheral_high"] = -999.0;

	pT_pi_minus_central_low = dblValCuts["pT_pi_minus_central_low"] = -999.0;
	pT_pi_minus_central_high = dblValCuts["pT_pi_minus_central_high"] = -999.0;
	pT_pi_minus_semicentral_low = dblValCuts["pT_pi_minus_semicentral_low"] = -999.0;
	pT_pi_minus_semicentral_high = dblValCuts["pT_pi_minus_semicentral_high"] = -999.0;
	pT_pi_minus_peripheral_low = dblValCuts["pT_pi_minus_peripheral_low"] = -999.0;
	pT_pi_minus_peripheral_high = dblValCuts["pT_pi_minus_peripheral_high"] = -999.0;

	pT_ka_plus_central_low = dblValCuts["pT_ka_plus_central_low"] = -999.0;
	pT_ka_plus_central_high = dblValCuts["pT_ka_plus_central_high"] = -999.0;
	pT_ka_plus_semicentral_low = dblValCuts["pT_ka_plus_semicentral_low"] = -999.0;
	pT_ka_plus_semicentral_high = dblValCuts["pT_ka_plus_semicentral_high"] = -999.0;
	pT_ka_plus_peripheral_low = dblValCuts["pT_ka_plus_peripheral_low"] = -999.0;
	pT_ka_plus_peripheral_high = dblValCuts["pT_ka_plus_peripheral_high"] = -999.0;

	pT_ka_minus_central_low = dblValCuts["pT_ka_minus_central_low"] = -999.0;
	pT_ka_minus_central_high = dblValCuts["pT_ka_minus_central_high"] = -999.0;
	pT_ka_minus_semicentral_low = dblValCuts["pT_ka_minus_semicentral_low"] = -999.0;
	pT_ka_minus_semicentral_high = dblValCuts["pT_ka_minus_semicentral_high"] = -999.0;
	pT_ka_minus_peripheral_low = dblValCuts["pT_ka_minus_peripheral_low"] = -999.0;
	pT_ka_minus_peripheral_high = dblValCuts["pT_ka_minus_peripheral_high"] = -999.0;

	pT_pr_central_low = dblValCuts["pT_pr_central_low"] = -999.0;
	pT_pr_central_high = dblValCuts["pT_pr_central_high"] = -999.0;
	pT_pr_semicentral_low = dblValCuts["pT_pr_semicentral_low"] = -999.0;
	pT_pr_semicentral_high = dblValCuts["pT_pr_semicentral_high"] = -999.0;
	pT_pr_peripheral_low = dblValCuts["pT_pr_peripheral_low"] = -999.0;
	pT_pr_peripheral_high = dblValCuts["pT_pr_peripheral_high"] = -999.0;

	pT_apr_central_low = dblValCuts["pT_apr_central_low"] = -999.0;
	pT_apr_central_high = dblValCuts["pT_apr_central_high"] = -999.0;
	pT_apr_semicentral_low = dblValCuts["pT_apr_semicentral_low"] = -999.0;
	pT_apr_semicentral_high = dblValCuts["pT_apr_semicentral_high"] = -999.0;
	pT_apr_peripheral_low = dblValCuts["pT_apr_peripheral_low"] = -999.0;
	pT_apr_peripheral_high = dblValCuts["pT_apr_peripheral_high"] = -999.0;

	pT_la_central_low = dblValCuts["pT_la_central_low"] = -999.0;
	pT_la_central_high = dblValCuts["pT_la_central_high"] = -999.0;
	pT_la_semicentral_low = dblValCuts["pT_la_semicentral_low"] = -999.0;
	pT_la_semicentral_high = dblValCuts["pT_la_semicentral_high"] = -999.0;
	pT_la_peripheral_low = dblValCuts["pT_la_peripheral_low"] = -999.0;
	pT_la_peripheral_high = dblValCuts["pT_la_peripheral_high"] = -999.0;
	
	pT_ala_central_low = dblValCuts["pT_ala_central_low"] = -999.0;
	pT_ala_central_high = dblValCuts["pT_ala_central_high"] = -999.0;
	pT_ala_semicentral_low = dblValCuts["pT_ala_semicentral_low"] = -999.0;
	pT_ala_semicentral_high = dblValCuts["pT_ala_semicentral_high"] = -999.0;
	pT_ala_peripheral_low = dblValCuts["pT_ala_peripheral_low"] = -999.0;
	pT_ala_peripheral_high = dblValCuts["pT_ala_peripheral_high"] = -999.0;
	
	pT_xi_plus_central_low = dblValCuts["pT_xi_plus_central_low"] = -999.0;
	pT_xi_plus_central_high = dblValCuts["pT_xi_plus_central_high"] = -999.0;
	pT_xi_plus_semicentral_low = dblValCuts["pT_xi_plus_semicentral_low"] = -999.0;
	pT_xi_plus_semicentral_high = dblValCuts["pT_xi_plus_semicentral_high"] = -999.0;
	pT_xi_plus_peripheral_low = dblValCuts["pT_xi_plus_peripheral_low"] = -999.0;
	pT_xi_plus_peripheral_high = dblValCuts["pT_xi_plus_peripheral_high"] = -999.0;
	
	pT_xi_minus_central_low = dblValCuts["pT_xi_minus_central_low"] = -999.0;
	pT_xi_minus_central_high = dblValCuts["pT_xi_minus_central_high"] = -999.0;
	pT_xi_minus_semicentral_low = dblValCuts["pT_xi_minus_semicentral_low"] = -999.0;
	pT_xi_minus_semicentral_high = dblValCuts["pT_xi_minus_semicentral_high"] = -999.0;
	pT_xi_minus_peripheral_low = dblValCuts["pT_xi_minus_peripheral_low"] = -999.0;
	pT_xi_minus_peripheral_high = dblValCuts["pT_xi_minus_peripheral_high"] = -999.0;
	
	pT_omega_plus_central_low = dblValCuts["pT_omega_plus_central_low"] = -999.0;
	pT_omega_plus_central_high = dblValCuts["pT_omega_plus_central_high"] = -999.0;
	pT_omega_plus_semicentral_low = dblValCuts["pT_omega_plus_semicentral_low"] = -999.0;
	pT_omega_plus_semicentral_high = dblValCuts["pT_omega_plus_semicentral_high"] = -999.0;
	pT_omega_plus_peripheral_low = dblValCuts["pT_omega_plus_peripheral_low"] = -999.0;
	pT_omega_plus_peripheral_high = dblValCuts["pT_omega_plus_peripheral_high"] = -999.0;
	
	pT_omega_minus_central_low = dblValCuts["pT_omega_minus_central_low"] = -999.0;
	pT_omega_minus_central_high = dblValCuts["pT_omega_minus_central_high"] = -999.0;
	pT_omega_minus_semicentral_low = dblValCuts["pT_omega_minus_semicentral_low"] = -999.0;
	pT_omega_minus_semicentral_high = dblValCuts["pT_omega_minus_semicentral_high"] = -999.0;
	pT_omega_minus_peripheral_low = dblValCuts["pT_omega_minus_peripheral_low"] = -999.0;
	pT_omega_minus_peripheral_high = dblValCuts["pT_omega_minus_peripheral_high"] = -999.0;
}

//Note: attempt to have the same order of variables as the header file
void ConfigReader::setAllCuts()
{
    //Standard information
	fixed_target = intValCuts["fixed_target"];
	sqrt_s_NN = dblValCuts["sqrt_s_NN"];
	y_mid = dblValCuts["y_mid"];
	y_beam = dblValCuts["y_beam"];

	//Maker Size Cuts	
	m_r_vtx = dblValCuts["m_r_vtx"];
	m_z_vtx_low = dblValCuts["m_z_vtx_low"];
	m_z_vtx_high = dblValCuts["m_z_vtx_high"];
	m_nHits_ratio = dblValCuts["m_nHits_ratio"];
	m_dca = dblValCuts["m_dca"];
	m_nHits = intValCuts["m_nHits"];
	m_nHits_dEdx = intValCuts["m_nHits_dEdx"];	
	
	//Maker PID Cuts
	nSig_pi = dblValCuts["nSig_pi"];
	nSig_ka = dblValCuts["nSig_ka"];
	nSig_pr = dblValCuts["nSig_pr"];
	TOFnSigma = dblValCuts["TOFnSigma"];
  
	m_lambda_mass_low = dblValCuts["m_lambda_mass_low"];
	m_lambda_mass_high = dblValCuts["m_lambda_mass_high"];
	m_xi_mass_low = dblValCuts["m_xi_mass_low"];
	m_xi_mass_high = dblValCuts["m_xi_mass_high"];
	m_omega_mass_low = dblValCuts["m_omega_mass_low"];
	m_omega_mass_high = dblValCuts["m_omega_mass_high"];

	//Analysis Cuts
	order_n = intValCuts["order_n"];
	order_m = intValCuts["order_m"];
	shift_terms = intValCuts["shift_terms"];
	epd_max_weight = intValCuts["epd_max_weight"];
	epd_threshold = dblValCuts["epd_threshold"];

	nHits = intValCuts["nHits"];
	nHits_dEdx = intValCuts["nHits_dEdx"];
	min_tracks = intValCuts["min_tracks"];
	nHits_ratio = dblValCuts["nHits_ratio"];
	dca = dblValCuts["dca"];
	r_vtx = dblValCuts["r_vtx"];
	z_vtx_low = dblValCuts["z_vtx_low"];
	z_vtx_high = dblValCuts["z_vtx_high"];
	nSig_pi_high = dblValCuts["nSig_pi_high"];
	nSig_pi_low = dblValCuts["nSig_pi_low"];
	nSig_ka_high = dblValCuts["nSig_ka_high"];
	nSig_ka_low = dblValCuts["nSig_ka_low"];
	nSig_pr_high = dblValCuts["nSig_pr_high"];
	nSig_pr_low = dblValCuts["nSig_pr_low"];
	m2_pi_low = dblValCuts["m2_pi_low"];
	m2_pi_high = dblValCuts["m2_pi_high"];
	m2_ka_low = dblValCuts["m2_ka_low"];
	m2_ka_high = dblValCuts["m2_ka_high"];
	m2_pr_low = dblValCuts["m2_pr_low"];
	m2_pr_high = dblValCuts["m2_pr_high"];
	m2_e_high = dblValCuts["m2_e_high"];
	d_mom_pi_low = dblValCuts["d_mom_pi_low"];

	//Acceptance regions
	yCM_pi_plus_central_low = dblValCuts["yCM_pi_plus_central_low"];
	yCM_pi_plus_central_high = dblValCuts["yCM_pi_plus_central_high"];
	yCM_pi_plus_semicentral_low = dblValCuts["yCM_pi_plus_semicentral_low"];
	yCM_pi_plus_semicentral_high = dblValCuts["yCM_pi_plus_semicentral_high"];
	yCM_pi_plus_peripheral_low = dblValCuts["yCM_pi_plus_peripheral_low"];
	yCM_pi_plus_peripheral_high = dblValCuts["yCM_pi_plus_peripheral_high"];

	yCM_pi_minus_central_low = dblValCuts["yCM_pi_minus_central_low"];
	yCM_pi_minus_central_high = dblValCuts["yCM_pi_minus_central_high"];
	yCM_pi_minus_semicentral_low = dblValCuts["yCM_pi_minus_semicentral_low"];
	yCM_pi_minus_semicentral_high = dblValCuts["yCM_pi_minus_semicentral_high"];
	yCM_pi_minus_peripheral_low = dblValCuts["yCM_pi_minus_peripheral_low"];
	yCM_pi_minus_peripheral_high = dblValCuts["yCM_pi_minus_peripheral_high"];

	yCM_ka_plus_central_low = dblValCuts["yCM_ka_plus_central_low"];
	yCM_ka_plus_central_high = dblValCuts["yCM_ka_plus_central_high"];
	yCM_ka_plus_semicentral_low = dblValCuts["yCM_ka_plus_semicentral_low"];
	yCM_ka_plus_semicentral_high = dblValCuts["yCM_ka_plus_semicentral_high"];
	yCM_ka_plus_peripheral_low = dblValCuts["yCM_ka_plus_peripheral_low"];
	yCM_ka_plus_peripheral_high = dblValCuts["yCM_ka_plus_peripheral_high"];

	yCM_ka_minus_central_low = dblValCuts["yCM_ka_minus_central_low"];
	yCM_ka_minus_central_high = dblValCuts["yCM_ka_minus_central_high"];
	yCM_ka_minus_semicentral_low = dblValCuts["yCM_ka_minus_semicentral_low"];
	yCM_ka_minus_semicentral_high = dblValCuts["yCM_ka_minus_semicentral_high"];
	yCM_ka_minus_peripheral_low = dblValCuts["yCM_ka_minus_peripheral_low"];
	yCM_ka_minus_peripheral_high = dblValCuts["yCM_ka_minus_peripheral_high"];

	yCM_pr_central_low = dblValCuts["yCM_pr_central_low"];
	yCM_pr_central_high = dblValCuts["yCM_pr_central_high"];
	yCM_pr_semicentral_low = dblValCuts["yCM_pr_semicentral_low"];
	yCM_pr_semicentral_high = dblValCuts["yCM_pr_semicentral_high"];
	yCM_pr_peripheral_low = dblValCuts["yCM_pr_peripheral_low"];
	yCM_pr_peripheral_high = dblValCuts["yCM_pr_peripheral_high"];

	yCM_apr_central_low = dblValCuts["yCM_apr_central_low"];
	yCM_apr_central_high = dblValCuts["yCM_apr_central_high"];
	yCM_apr_semicentral_low = dblValCuts["yCM_apr_semicentral_low"];
	yCM_apr_semicentral_high = dblValCuts["yCM_apr_semicentral_high"];
	yCM_apr_peripheral_low = dblValCuts["yCM_apr_peripheral_low"];
	yCM_apr_peripheral_high = dblValCuts["yCM_apr_peripheral_high"];

	yCM_la_central_low = dblValCuts["yCM_la_central_low"];
	yCM_la_central_high = dblValCuts["yCM_la_central_high"];
	yCM_la_semicentral_low = dblValCuts["yCM_la_semicentral_low"];
	yCM_la_semicentral_high = dblValCuts["yCM_la_semicentral_high"];
	yCM_la_peripheral_low = dblValCuts["yCM_la_peripheral_low"];
	yCM_la_peripheral_high = dblValCuts["yCM_la_peripheral_high"];
	
	yCM_ala_central_low = dblValCuts["yCM_ala_central_low"];
	yCM_ala_central_high = dblValCuts["yCM_ala_central_high"];
	yCM_ala_semicentral_low = dblValCuts["yCM_ala_semicentral_low"];
	yCM_ala_semicentral_high = dblValCuts["yCM_ala_semicentral_high"];
	yCM_ala_peripheral_low = dblValCuts["yCM_ala_peripheral_low"];
	yCM_ala_peripheral_high = dblValCuts["yCM_ala_peripheral_high"];
	
	yCM_xi_plus_central_low = dblValCuts["yCM_xi_plus_central_low"];
	yCM_xi_plus_central_high = dblValCuts["yCM_xi_plus_central_high"];
	yCM_xi_plus_semicentral_low = dblValCuts["yCM_xi_plus_semicentral_low"];
	yCM_xi_plus_semicentral_high = dblValCuts["yCM_xi_plus_semicentral_high"];
	yCM_xi_plus_peripheral_low = dblValCuts["yCM_xi_plus_peripheral_low"];
	yCM_xi_plus_peripheral_high = dblValCuts["yCM_xi_plus_peripheral_high"];
	
	yCM_xi_minus_central_low = dblValCuts["yCM_xi_minus_central_low"];
	yCM_xi_minus_central_high = dblValCuts["yCM_xi_minus_central_high"];
	yCM_xi_minus_semicentral_low = dblValCuts["yCM_xi_minus_semicentral_low"];
	yCM_xi_minus_semicentral_high = dblValCuts["yCM_xi_minus_semicentral_high"];
	yCM_xi_minus_peripheral_low = dblValCuts["yCM_xi_minus_peripheral_low"];
	yCM_xi_minus_peripheral_high = dblValCuts["yCM_xi_minus_peripheral_high"];
	
	yCM_omega_plus_central_low = dblValCuts["yCM_omega_plus_central_low"];
	yCM_omega_plus_central_high = dblValCuts["yCM_omega_plus_central_high"];
	yCM_omega_plus_semicentral_low = dblValCuts["yCM_omega_plus_semicentral_low"];
	yCM_omega_plus_semicentral_high = dblValCuts["yCM_omega_plus_semicentral_high"];
	yCM_omega_plus_peripheral_low = dblValCuts["yCM_omega_plus_peripheral_low"];
	yCM_omega_plus_peripheral_high = dblValCuts["yCM_omega_plus_peripheral_high"];
	
	yCM_omega_minus_central_low = dblValCuts["yCM_omega_minus_central_low"];
	yCM_omega_minus_central_high = dblValCuts["yCM_omega_minus_central_high"];
	yCM_omega_minus_semicentral_low = dblValCuts["yCM_omega_minus_semicentral_low"];
	yCM_omega_minus_semicentral_high = dblValCuts["yCM_omega_minus_semicentral_high"];
	yCM_omega_minus_peripheral_low = dblValCuts["yCM_omega_minus_peripheral_low"];
	yCM_omega_minus_peripheral_high = dblValCuts["yCM_omega_minus_peripheral_high"];

	pT_pi_plus_central_low = dblValCuts["pT_pi_plus_central_low"];
	pT_pi_plus_central_high = dblValCuts["pT_pi_plus_central_high"];
	pT_pi_plus_semicentral_low = dblValCuts["pT_pi_plus_semicentral_low"];
	pT_pi_plus_semicentral_high = dblValCuts["pT_pi_plus_semicentral_high"];
	pT_pi_plus_peripheral_low = dblValCuts["pT_pi_plus_peripheral_low"];
	pT_pi_plus_peripheral_high = dblValCuts["pT_pi_plus_peripheral_high"];

	pT_pi_minus_central_low = dblValCuts["pT_pi_minus_central_low"];
	pT_pi_minus_central_high = dblValCuts["pT_pi_minus_central_high"];
	pT_pi_minus_semicentral_low = dblValCuts["pT_pi_minus_semicentral_low"];
	pT_pi_minus_semicentral_high = dblValCuts["pT_pi_minus_semicentral_high"];
	pT_pi_minus_peripheral_low = dblValCuts["pT_pi_minus_peripheral_low"];
	pT_pi_minus_peripheral_high = dblValCuts["pT_pi_minus_peripheral_high"];

	pT_ka_plus_central_low = dblValCuts["pT_ka_plus_central_low"];
	pT_ka_plus_central_high = dblValCuts["pT_ka_plus_central_high"];
	pT_ka_plus_semicentral_low = dblValCuts["pT_ka_plus_semicentral_low"];
	pT_ka_plus_semicentral_high = dblValCuts["pT_ka_plus_semicentral_high"];
	pT_ka_plus_peripheral_low = dblValCuts["pT_ka_plus_peripheral_low"];
	pT_ka_plus_peripheral_high = dblValCuts["pT_ka_plus_peripheral_high"];

	pT_ka_minus_central_low = dblValCuts["pT_ka_minus_central_low"];
	pT_ka_minus_central_high = dblValCuts["pT_ka_minus_central_high"];
	pT_ka_minus_semicentral_low = dblValCuts["pT_ka_minus_semicentral_low"];
	pT_ka_minus_semicentral_high = dblValCuts["pT_ka_minus_semicentral_high"];
	pT_ka_minus_peripheral_low = dblValCuts["pT_ka_minus_peripheral_low"];
	pT_ka_minus_peripheral_high = dblValCuts["pT_ka_minus_peripheral_high"];

	pT_pr_central_low = dblValCuts["pT_pr_central_low"];
	pT_pr_central_high = dblValCuts["pT_pr_central_high"];
	pT_pr_semicentral_low = dblValCuts["pT_pr_semicentral_low"];
	pT_pr_semicentral_high = dblValCuts["pT_pr_semicentral_high"];
	pT_pr_peripheral_low = dblValCuts["pT_pr_peripheral_low"];
	pT_pr_peripheral_high = dblValCuts["pT_pr_peripheral_high"];

	pT_apr_central_low = dblValCuts["pT_apr_central_low"];
	pT_apr_central_high = dblValCuts["pT_apr_central_high"];
	pT_apr_semicentral_low = dblValCuts["pT_apr_semicentral_low"];
	pT_apr_semicentral_high = dblValCuts["pT_apr_semicentral_high"];
	pT_apr_peripheral_low = dblValCuts["pT_apr_peripheral_low"];
	pT_apr_peripheral_high = dblValCuts["pT_apr_peripheral_high"];

	pT_la_central_low = dblValCuts["pT_la_central_low"];
	pT_la_central_high = dblValCuts["pT_la_central_high"];
	pT_la_semicentral_low = dblValCuts["pT_la_semicentral_low"];
	pT_la_semicentral_high = dblValCuts["pT_la_semicentral_high"];
	pT_la_peripheral_low = dblValCuts["pT_la_peripheral_low"];
	pT_la_peripheral_high = dblValCuts["pT_la_peripheral_high"];
	
	pT_ala_central_low = dblValCuts["pT_ala_central_low"];
	pT_ala_central_high = dblValCuts["pT_ala_central_high"];
	pT_ala_semicentral_low = dblValCuts["pT_ala_semicentral_low"];
	pT_ala_semicentral_high = dblValCuts["pT_ala_semicentral_high"];
	pT_ala_peripheral_low = dblValCuts["pT_ala_peripheral_low"];
	pT_ala_peripheral_high = dblValCuts["pT_ala_peripheral_high"];
	
	pT_xi_plus_central_low = dblValCuts["pT_xi_plus_central_low"];
	pT_xi_plus_central_high = dblValCuts["pT_xi_plus_central_high"];
	pT_xi_plus_semicentral_low = dblValCuts["pT_xi_plus_semicentral_low"];
	pT_xi_plus_semicentral_high = dblValCuts["pT_xi_plus_semicentral_high"];
	pT_xi_plus_peripheral_low = dblValCuts["pT_xi_plus_peripheral_low"];
	pT_xi_plus_peripheral_high = dblValCuts["pT_xi_plus_peripheral_high"];
	
	pT_xi_minus_central_low = dblValCuts["pT_xi_minus_central_low"];
	pT_xi_minus_central_high = dblValCuts["pT_xi_minus_central_high"];
	pT_xi_minus_semicentral_low = dblValCuts["pT_xi_minus_semicentral_low"];
	pT_xi_minus_semicentral_high = dblValCuts["pT_xi_minus_semicentral_high"];
	pT_xi_minus_peripheral_low = dblValCuts["pT_xi_minus_peripheral_low"];
	pT_xi_minus_peripheral_high = dblValCuts["pT_xi_minus_peripheral_high"];
	
	pT_omega_plus_central_low = dblValCuts["pT_omega_plus_central_low"];
	pT_omega_plus_central_high = dblValCuts["pT_omega_plus_central_high"];
	pT_omega_plus_semicentral_low = dblValCuts["pT_omega_plus_semicentral_low"];
	pT_omega_plus_semicentral_high = dblValCuts["pT_omega_plus_semicentral_high"];
	pT_omega_plus_peripheral_low = dblValCuts["pT_omega_plus_peripheral_low"];
	pT_omega_plus_peripheral_high = dblValCuts["pT_omega_plus_peripheral_high"];
	
	pT_omega_minus_central_low = dblValCuts["pT_omega_minus_central_low"];
	pT_omega_minus_central_high = dblValCuts["pT_omega_minus_central_high"];
	pT_omega_minus_semicentral_low = dblValCuts["pT_omega_minus_semicentral_low"];
	pT_omega_minus_semicentral_high = dblValCuts["pT_omega_minus_semicentral_high"];
	pT_omega_minus_peripheral_low = dblValCuts["pT_omega_minus_peripheral_low"];
	pT_omega_minus_peripheral_high = dblValCuts["pT_omega_minus_peripheral_high"];
}

ConfigReader::ConfigReader() 
{ 
  initialize();
  errorFlag = false; 
}

ConfigReader::~ConfigReader()
{}

bool ConfigReader::errorFound()
{ return errorFlag; }

void ConfigReader::notifyError()
{
  std::cout << std::endl;
  std::cout << "There was an error in reading the config file." << std::endl;

  if (lastKey != "")
    { std::cout << "The last key and value read were: " << lastKey << ", " << lastValue << std::endl; }
  else
    { std::cout << "There were no keys or values read successfully." << std::endl; }
}

Bool_t ConfigReader::triggersMatch(UInt_t readTrigger)
{
	Bool_t triggerMatchFound = false;
	for (unsigned int i = 0; i < triggers.size(); i++)
    { 
		if (readTrigger == triggers[i]) 
		{ 
			triggerMatchFound = true; 
			break;
		} 
    }
	
	return triggerMatchFound;
}

Bool_t ConfigReader::isNotBadRun(UInt_t readBadRuns)
{
	Bool_t badRunFound = false;
	for (unsigned int i = 0; i < badRunList.size(); i++)
    { 
		if (readBadRuns == badRunList[i]) 
		{ 
			badRunFound = true; 
			break;
		} 
    }
	
	return badRunFound;
}

  
Int_t ConfigReader::GetInt(std::string entryName){
	
	try
	{ return intValCuts.at(entryName); }
	catch (...)//(const std::out_of_range& oorInt) 
	{
		return (Int_t)dblValCuts.at(entryName);
	}
	
	//return intValCuts.at(entryName);
}

Double_t ConfigReader::GetDouble(std::string entryName){
	
	try
	{ return dblValCuts.at(entryName); }
	catch (...)//(const std::out_of_range& oorInt) 
	{
		return (Double_t)intValCuts.at(entryName);
	}
	
	//return dblValCuts.at(entryName);
}

void ConfigReader::read(std::string fileName)
{
	std::ifstream inputStream(fileName.c_str());

	std::string line;
	std::getline(inputStream, line);  // Get the first line

	// Loop over lines of input in current file
	while (inputStream.good())
    {
		// Skip the text lines and the empty lines
		if (line[0] == '#' || line.empty())
		{
			std::getline(inputStream, line);
			continue;
		}

		// Split string by delimeter '='
		std::string delimeter = "=";
		size_t pos = line.find(delimeter);

		if (pos == std::string::npos) 
		{ 
			std::cout << "Missing \'=\' in a line of the config file." << std::endl; 
			errorFlag = true;
			break;
		}

		std::string key   = line.substr(0, pos);
		std::string value = line.substr(pos+1, std::string::npos);
      
		lastKey   = key;
		lastValue = value;

		// Now check if "value" is actually a list of values, if so, split it and try to save.
		//Trigger list, bad run list, and subevent list may be lists
		size_t commaPos = value.find(",");
		
		//Is a list with more than one entry
		//Subevent always has more than one entry
		if (commaPos != std::string::npos)
		{
			std::stringstream valueStream(value);

			while(valueStream.good())
			{
				std::string subString;
				std::getline(valueStream, subString, ',');
				try
				{
					if (key == "triggers"){
						UInt_t triggerValue = (UInt_t)std::atoi(subString.c_str()); 
						triggers.push_back(triggerValue);						
					}
					else if (key == "badRunList"){
						UInt_t runNumber = (UInt_t)std::atoi(subString.c_str()); 
						badRunList.push_back(runNumber);							
	
					}
					else if (key == "subEvent"){
						Char_t subEventTypeValue = (Char_t)subString[0]; 
						subEventType.push_back(subEventTypeValue);	

						std::getline(valueStream, subString, ','); //Get associated low value
						Float_t minimum = (Float_t)std::atof(subString.c_str());
						subEventMin.push_back(minimum);	

						std::getline(valueStream, subString, ','); //Get associated high value	
						Float_t maximum = (Float_t)std::atof(subString.c_str());		
						subEventMax.push_back(maximum);	

						std::getline(valueStream, subString, ','); //Get associated use priority
						Int_t priority = (Int_t)std::atof(subString.c_str());		
						subEventPriority.push_back(priority);						
	
					}
				}
				catch (...)
				{
					std::cout << "Error parsing this value: " << value << " for key " << key << std::endl;
					errorFlag = true;
					break;
				}
			}
		}
		// Is a list with a single entry
		else if (key.compare("triggers") == 0 ||
				key.compare("badRunList") == 0){
					
			try
			{
				if (key == "triggers"){
					UInt_t triggerValue = (UInt_t)std::atoi(value.c_str()); 
					triggers.push_back(triggerValue);						
				}
				else if (key == "badRunList"){
					UInt_t runNumber = (UInt_t)std::atoi(value.c_str()); 
					badRunList.push_back(runNumber);
				}
			}
			catch (...)
			{
				std::cout << "Error in this value: " << value << " for key " << key << std::endl;
				errorFlag = true;
			}					
		}
		
		if (errorFlag) break;

		if (key == "name"){
			name = value;
		}

		if (key != "triggers" && key != "badRunList" && key != "subEvent"){			
			try
			{ intValCuts.at(key) = std::atoi(value.c_str()); }
			catch (...)//(const std::out_of_range& oorInt) 
			{
				try
				{ dblValCuts.at(key) = std::atof(value.c_str()); }
				catch (...)//(const std::out_of_range& oorDbl) 
				{
					std::cout << "Unknown config key: " << key << std::endl;
					errorFlag = true;
					break;	      
				}
			}
		}

		std::getline(inputStream, line); // Get the next line
		
    }// End while(inputStream.good())

  if (errorFlag) { notifyError(); }
  setAllCuts();
}// End function read()
