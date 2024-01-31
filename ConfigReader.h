#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <string>
#include <map>
#include <vector>
#include "TString.h"

class ConfigReader
{
 public:
  ConfigReader();
  ~ConfigReader();

  bool errorFound();
  void notifyError();
  void initialize();
  void setAllCuts();
  void read(std::string fileName);
  Bool_t triggersMatch(UInt_t readTrigger);
  Bool_t isNotBadRun(UInt_t readBadRuns);
  
  
  //Standard information
  std::string name;
  Int_t fixed_target; // boolean: 0 or 1
  Double_t sqrt_s_NN;
  Double_t y_mid;
  Double_t y_beam;
  std::vector<UInt_t> triggers;
  std::vector<UInt_t> badRunList;
  
  //Maker Size Cuts
  Double_t m_r_vtx;
  Double_t m_z_vtx_low;
  Double_t m_z_vtx_high;
  Double_t m_nHits_ratio;
  Double_t m_dca;
  Int_t m_nHits;
  Int_t m_nHits_dEdx;
  
  //Maker PID Cuts
  Double_t m_nSig_dEdx_pi;
  Double_t m_nSig_dEdx_ka;
  Double_t m_nSig_dEdx_pr;
  Double_t m_nSig_m2_pi;
  Double_t m_nSig_m2_ka;
  Double_t m_nSig_m2_pr;
  
  Double_t m_lambda_mass_low;
  Double_t m_lambda_mass_high;
  Double_t m_xi_mass_low;
  Double_t m_xi_mass_high;
  Double_t m_omega_mass_low;
  Double_t m_omega_mass_high;

  //Analysis Cuts
  Int_t order_n;
  Int_t order_m;
  Int_t shift_terms;
  Int_t epd_max_weight;
  Double_t epd_threshold;
  Int_t useV1Weights; // boolean: 0 or 1
  Int_t useNegChargeM2; // boolean: 0 or 1
  
  Int_t nHits;
  Int_t nHits_dEdx;
  Int_t min_tracks;
  Double_t nHits_ratio;
  Double_t dca;
  Double_t r_vtx;
  Double_t z_vtx_low;
  Double_t z_vtx_high;
  Double_t nSig_pi_high;
  Double_t nSig_pi_low;
  Double_t nSig_ka_high;
  Double_t nSig_ka_low;
  Double_t nSig_pr_high;
  Double_t nSig_pr_low;
  Double_t m2_pi_low;
  Double_t m2_pi_high;
  Double_t m2_ka_low;
  Double_t m2_ka_high;
  Double_t m2_pr_low;
  Double_t m2_pr_high;
  Double_t m2_e_high;
  Double_t d_mom_pi_low;
  
  //Subevents
  std::vector<char> subEventType;
  std::vector<Float_t> subEventMin;
  std::vector<Float_t> subEventMax;
  std::vector<Int_t> subEventPriority; 
  
  //Acceptance regions
  Double_t yCM_pi_plus_central_low;
  Double_t yCM_pi_plus_central_high;
  Double_t yCM_pi_plus_semicentral_low;
  Double_t yCM_pi_plus_semicentral_high;
  Double_t yCM_pi_plus_peripheral_low;
  Double_t yCM_pi_plus_peripheral_high;

  Double_t yCM_pi_minus_central_low;
  Double_t yCM_pi_minus_central_high;
  Double_t yCM_pi_minus_semicentral_low;
  Double_t yCM_pi_minus_semicentral_high;
  Double_t yCM_pi_minus_peripheral_low;
  Double_t yCM_pi_minus_peripheral_high;

  Double_t yCM_ka_plus_central_low;
  Double_t yCM_ka_plus_central_high;
  Double_t yCM_ka_plus_semicentral_low;
  Double_t yCM_ka_plus_semicentral_high;
  Double_t yCM_ka_plus_peripheral_low;
  Double_t yCM_ka_plus_peripheral_high;

  Double_t yCM_ka_minus_central_low;
  Double_t yCM_ka_minus_central_high;
  Double_t yCM_ka_minus_semicentral_low;
  Double_t yCM_ka_minus_semicentral_high;
  Double_t yCM_ka_minus_peripheral_low;
  Double_t yCM_ka_minus_peripheral_high;

  Double_t yCM_pr_central_low;
  Double_t yCM_pr_central_high;
  Double_t yCM_pr_semicentral_low;
  Double_t yCM_pr_semicentral_high;
  Double_t yCM_pr_peripheral_low;
  Double_t yCM_pr_peripheral_high;

  Double_t yCM_apr_central_low;
  Double_t yCM_apr_central_high;
  Double_t yCM_apr_semicentral_low;
  Double_t yCM_apr_semicentral_high;
  Double_t yCM_apr_peripheral_low;
  Double_t yCM_apr_peripheral_high;

  Double_t yCM_la_central_low;
  Double_t yCM_la_central_high;
  Double_t yCM_la_semicentral_low;
  Double_t yCM_la_semicentral_high;
  Double_t yCM_la_peripheral_low;
  Double_t yCM_la_peripheral_high;
  
  Double_t yCM_ala_central_low;
  Double_t yCM_ala_central_high;
  Double_t yCM_ala_semicentral_low;
  Double_t yCM_ala_semicentral_high;
  Double_t yCM_ala_peripheral_low;
  Double_t yCM_ala_peripheral_high;
  
  Double_t yCM_xi_plus_central_low;
  Double_t yCM_xi_plus_central_high;
  Double_t yCM_xi_plus_semicentral_low;
  Double_t yCM_xi_plus_semicentral_high;
  Double_t yCM_xi_plus_peripheral_low;
  Double_t yCM_xi_plus_peripheral_high;
  
  Double_t yCM_xi_minus_central_low;
  Double_t yCM_xi_minus_central_high;
  Double_t yCM_xi_minus_semicentral_low;
  Double_t yCM_xi_minus_semicentral_high;
  Double_t yCM_xi_minus_peripheral_low;
  Double_t yCM_xi_minus_peripheral_high;
  
  Double_t yCM_omega_plus_central_low;
  Double_t yCM_omega_plus_central_high;
  Double_t yCM_omega_plus_semicentral_low;
  Double_t yCM_omega_plus_semicentral_high;
  Double_t yCM_omega_plus_peripheral_low;
  Double_t yCM_omega_plus_peripheral_high;
  
  Double_t yCM_omega_minus_central_low;
  Double_t yCM_omega_minus_central_high;
  Double_t yCM_omega_minus_semicentral_low;
  Double_t yCM_omega_minus_semicentral_high;
  Double_t yCM_omega_minus_peripheral_low;
  Double_t yCM_omega_minus_peripheral_high;

  Double_t pT_pi_plus_central_low;
  Double_t pT_pi_plus_central_high;
  Double_t pT_pi_plus_semicentral_low;
  Double_t pT_pi_plus_semicentral_high;
  Double_t pT_pi_plus_peripheral_low;
  Double_t pT_pi_plus_peripheral_high;

  Double_t pT_pi_minus_central_low;
  Double_t pT_pi_minus_central_high;
  Double_t pT_pi_minus_semicentral_low;
  Double_t pT_pi_minus_semicentral_high;
  Double_t pT_pi_minus_peripheral_low;
  Double_t pT_pi_minus_peripheral_high;

  Double_t pT_ka_plus_central_low;
  Double_t pT_ka_plus_central_high;
  Double_t pT_ka_plus_semicentral_low;
  Double_t pT_ka_plus_semicentral_high;
  Double_t pT_ka_plus_peripheral_low;
  Double_t pT_ka_plus_peripheral_high;

  Double_t pT_ka_minus_central_low;
  Double_t pT_ka_minus_central_high;
  Double_t pT_ka_minus_semicentral_low;
  Double_t pT_ka_minus_semicentral_high;
  Double_t pT_ka_minus_peripheral_low;
  Double_t pT_ka_minus_peripheral_high;

  Double_t pT_pr_central_low;
  Double_t pT_pr_central_high;
  Double_t pT_pr_semicentral_low;
  Double_t pT_pr_semicentral_high;
  Double_t pT_pr_peripheral_low;
  Double_t pT_pr_peripheral_high;

  Double_t pT_apr_central_low;
  Double_t pT_apr_central_high;
  Double_t pT_apr_semicentral_low;
  Double_t pT_apr_semicentral_high;
  Double_t pT_apr_peripheral_low;
  Double_t pT_apr_peripheral_high;

  Double_t pT_la_central_low;
  Double_t pT_la_central_high;
  Double_t pT_la_semicentral_low;
  Double_t pT_la_semicentral_high;
  Double_t pT_la_peripheral_low;
  Double_t pT_la_peripheral_high;
  
  Double_t pT_ala_central_low;
  Double_t pT_ala_central_high;
  Double_t pT_ala_semicentral_low;
  Double_t pT_ala_semicentral_high;
  Double_t pT_ala_peripheral_low;
  Double_t pT_ala_peripheral_high;
  
  Double_t pT_xi_plus_central_low;
  Double_t pT_xi_plus_central_high;
  Double_t pT_xi_plus_semicentral_low;
  Double_t pT_xi_plus_semicentral_high;
  Double_t pT_xi_plus_peripheral_low;
  Double_t pT_xi_plus_peripheral_high;
  
  Double_t pT_xi_minus_central_low;
  Double_t pT_xi_minus_central_high;
  Double_t pT_xi_minus_semicentral_low;
  Double_t pT_xi_minus_semicentral_high;
  Double_t pT_xi_minus_peripheral_low;
  Double_t pT_xi_minus_peripheral_high;
  
  Double_t pT_omega_plus_central_low;
  Double_t pT_omega_plus_central_high;
  Double_t pT_omega_plus_semicentral_low;
  Double_t pT_omega_plus_semicentral_high;
  Double_t pT_omega_plus_peripheral_low;
  Double_t pT_omega_plus_peripheral_high;
  
  Double_t pT_omega_minus_central_low;
  Double_t pT_omega_minus_central_high;
  Double_t pT_omega_minus_semicentral_low;
  Double_t pT_omega_minus_semicentral_high;
  Double_t pT_omega_minus_peripheral_low;
  Double_t pT_omega_minus_peripheral_high;
  
  Double_t GetDouble(std::string);
  Int_t GetInt(std::string);

 private:
  bool errorFlag;
  TString lastKey;
  TString lastValue;
  std::map<std::string, int> intValCuts;
  std::map<std::string, double> dblValCuts;
};

#endif
