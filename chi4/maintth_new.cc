#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TMath.h"
#include "TMinuit.h"
#include "TROOT.h"
#include "TLatex.h"
#include "TImage.h"
#include "TLorentzVector.h"
#include "TLegend.h"
//c++
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
//struct & functions 
#include "ev_structure.h"
#include "Analysis_structure.h"
#include "histo.h"
#include "func_declaration.h"
#include "sort.h"
#include "cuts.h"
#include "chi2combination.h"
#include "Analysis_function.h"
#include "Dump_result.h"
#include "PrintHisto.h"
#endif
	
using namespace std;

Histo histo;
Cuts cuts;
extern int counter_bad;
int count1=0;
void maintth_new(){


	TFile *fin = new TFile("/lustre/cmswork/hh/alp_moriond_base/ttH_4jets2cmva/ttHTobb.root");
	if(!fin->IsOpen()){
		cout<<"Error: cannot open the file!"<<endl;
		return;
	}
	TTree* t;
	fin->GetObject("tree",t);

	vector<float> *jets_pt=0;
	vector<float> *jets_eta=0;
	vector<float> *jets_phi=0;
	vector<float> *jets_mass=0;
	vector<float> *jets_csv=0;
	vector<float> *jets_cmva=0;

	vector<float> *muons_pt=0;
	vector<float> *muons_eta=0;
	vector<float> *muons_phi=0;
	vector<float> *muons_mass=0;
	vector<float> *muons_iso03=0;

	vector<float> *genBfromH_pt=0;
	vector<float> *genBfromH_eta=0;
	vector<float> *genBfromH_phi=0;
	vector<float> *genBfromH_mass=0;

	float met_pt;
	float met_phi;

	float weight;

	t->SetBranchAddress("jets_pt",&jets_pt);
	t->SetBranchAddress("jets_eta",&jets_eta);
	t->SetBranchAddress("jets_phi",&jets_phi);
	t->SetBranchAddress("jets_mass",&jets_mass);
	t->SetBranchAddress("jets_csv",&jets_csv);
	t->SetBranchAddress("jets_cmva",&jets_cmva);

	t->SetBranchAddress("muons_pt",&muons_pt);
	t->SetBranchAddress("muons_eta",&muons_eta);
	t->SetBranchAddress("muons_phi",&muons_phi);
	t->SetBranchAddress("muons_mass",&muons_mass);
	t->SetBranchAddress("muons_iso03",&muons_iso03);

	t->SetBranchAddress("genBfromH_pt",&genBfromH_pt);
	t->SetBranchAddress("genBfromH_eta",&genBfromH_eta);
	t->SetBranchAddress("genBfromH_phi",&genBfromH_phi);
	t->SetBranchAddress("genBfromH_mass",&genBfromH_mass);

	t->SetBranchAddress("met_pt",&met_pt);
	t->SetBranchAddress("met_phi",&met_phi);

	t->SetBranchAddress("weight",&weight);

	//chi^2 star
	Bestchi2 bestchi2star_good;
	Bestchi2 bestchi2star_bad;
	ChiCounter chistar_count; //contains counter for the chi* analysis
	MatchCounter chistar_good;
	MatchCounter chistar_bad;

	ChiCounter chistar_count0; //contains counter for the chi* analysis
	MatchCounter chistar_good0;
	MatchCounter chistar_bad0;

	ChiCounter chistar_count1; //contains counter for the chi* analysis
	MatchCounter chistar_good1;
	MatchCounter chistar_bad1;

	//////////////////////////
	//loop over all the events
	//////////////////////////

	int evCounter=0; //Selected event
	int nEv=t->GetEntries();
	if(cuts.readfrac>1.0) cuts.readfrac=1.0;
	for(int k=0; k<(nEv*cuts.readfrac); k++){

		t->GetEntry(k);

		/////////////////////////
		//JETS
		/////////////////////////
		int njets0=jets_pt->size();

		Jet jet[njets0];
		int nbjets=0,njets=0; //Count jets after jet_pt cut...

		for(int i=0; i<njets0; i++){

			if((*jets_pt)[i]<cuts.jetspt_min) continue;
			if((*jets_eta)[i]>cuts.eta_max) continue;

			jet[i].pt=(*jets_pt)[i];
			jet[i].eta=(*jets_eta)[i];
			jet[i].phi=(*jets_phi)[i];
			jet[i].mass=(*jets_mass)[i];
			jet[i].csv=(*jets_csv)[i];
			jet[i].cmva=(*jets_cmva)[i];
			//count jets
			njets++;
			//Count b-jets
			if(jet[i].csv>cuts.csvcut){
				nbjets++;
			}
		}
		//sort jet_pt 
		sort_pt(jet,njets);

		if( nbjets<cuts.nbjets_min || nbjets>cuts.nbjets_max ) continue;
		if( njets<cuts.njets_min || njets>cuts.njets_max ) continue;

		//store bjets 
		Jet bjet[nbjets];
		int bcont_tmp=0;
		for(int i=0; i<njets; i++){
			if(jet[i].csv>cuts.csvcut){
				bjet[bcont_tmp]=jet[i];
				bcont_tmp++;
			}
		}

		/////////////////////////
		//MUONS
		/////////////////////////
		int nmuons0=muons_pt->size(), nmuons=0;//Count muons after the cuts

		if( nmuons<cuts.nmuons_min || nmuons>cuts.nmuons_max ) continue;

		Muon muon[nmuons0];
		bool veto=false;

		for(int i=0; i<nmuons0; i++){
			
			if( ((*muons_pt)[i]>cuts.muonspt_max) && ((*muons_eta)[i]<2.4) ) {veto=true; continue;} //veto
			muon[i].pt=(*muons_pt)[i];
			muon[i].eta=(*muons_eta)[i];
			muon[i].phi=(*muons_phi)[i];
			muon[i].mass=(*muons_mass)[i];
			muon[i].iso03=(*muons_iso03)[i];

			nmuons++;
		}

		if(veto) continue;

		/////////////////////////
		//MET
		/////////////////////////
		Met met;
		met.pt  = met_pt;
		met.phi = met_phi;

		if(met.pt<cuts.metpt_min) continue;

		/////////////////////////
		//GenBfromH
		/////////////////////////
		int nGenBfromH0 = genBfromH_pt->size();
		Jet genbH[nGenBfromH0];

		for(int i=0; i<nGenBfromH0; i++){
			genbH[i].pt=(*genBfromH_pt)[i];
			genbH[i].eta=(*genBfromH_eta)[i];
			genbH[i].phi=(*genBfromH_phi)[i];
			genbH[i].mass=(*genBfromH_mass)[i];
		}
		sort_pt(genbH,nGenBfromH0);
		//evCounter++;

		//////////////////////////////////////////
		//End of reading->Analysis
		//////////////////////////////////////////

		TLorentzVector bj_gen1, bj_gen2;
		bj_gen1.SetPtEtaPhiM(genbH[0].pt,genbH[0].eta,genbH[0].phi,genbH[0].mass);
		bj_gen2.SetPtEtaPhiM(genbH[1].pt,genbH[1].eta,genbH[1].phi,genbH[1].mass);
		TLorentzVector h_gen=bj_gen1+bj_gen2;
		histo.hmh_gen->Fill(h_gen.M(),weight);

		Hbjet_index Hbjets = gen_match(bjet, genbH, nbjets); //find bjets from higgs using gen_level info 
															 //using \DeltaR
		TLorentzVector bj_dr1, bj_dr2;
		bj_dr1.SetPtEtaPhiM(bjet[Hbjets.bj1].pt,bjet[Hbjets.bj1].eta,bjet[Hbjets.bj1].phi,bjet[Hbjets.bj1].mass);
		bj_dr2.SetPtEtaPhiM(bjet[Hbjets.bj2].pt,bjet[Hbjets.bj2].eta,bjet[Hbjets.bj2].phi,bjet[Hbjets.bj2].mass);
		TLorentzVector h_dr=bj_dr1+bj_dr2;
		histo.hmh_dr->Fill(h_dr.M(),weight);


		//////////////////////
		//chi2_star*
		//////////////////////

		
		Bestchi2 bestchi2_star; 
		int nmatch;

		//4 jets not b-tagged required 
		if((njets-nbjets)>=4){

			evCounter++;
			Chi2result chi2star=combchi2_star2(jet, njets,4,4);
			store_bestchi2(chi2star,bestchi2_star); //sort & store 1st 2nd and 3rd best chi2 for this event
		
			histo.hmt1_star->Fill(chi2star.mt1,weight);
			histo.hmt2_star->Fill(chi2star.mt2,weight);
			histo.hmw1_star->Fill(chi2star.mw1,weight);
			histo.hmw2_star->Fill(chi2star.mw2,weight);
			histo.hmh_star->Fill(chi2star.mh,weight);

			if( TMath::Prob((bestchi2_star.chi1[0]),4) >=0.01){
				//prob(\chi^2*>1%)
				chistar_count.chi_good++;
				chistar_count0.chi_good++;
				//store best chi for all the event
				bestchi2star_good.chi1.push_back(bestchi2_star.chi1[0]);
				bestchi2star_good.chi2.push_back(bestchi2_star.chi2[0]);
				bestchi2star_good.chi3.push_back(bestchi2_star.chi3[0]);
				//count how many bjets (from H) find by chi2* are bjets (from higgs, genLev) identified with \deltaR
				nmatch=match_jet(chi2star.bjH,bjet,nbjets,chistar_good,Hbjets);
				match_jet(chi2star.bjH,bjet,nbjets,chistar_good0,Hbjets);

				if(nmatch==2){
					histo.hmh_2match->Fill(chi2star.mh,weight);
					histo.hmh_2match1->Fill(chi2star.mh,weight);
				}
				else if(nmatch==1){
					histo.hmh_1match->Fill(chi2star.mh,weight);
					histo.hmh_1match1->Fill(chi2star.mh,weight);
				}
				else{
					histo.hmh_0match->Fill(chi2star.mh,weight);
					histo.hmh_0match1->Fill(chi2star.mh,weight);
				}


				histo.hmt1_star_good->Fill(chi2star.mt1,weight);
				histo.hmt2_star_good->Fill(chi2star.mt2,weight);
				histo.hmw1_star_good->Fill(chi2star.mw1,weight);
				histo.hmw2_star_good->Fill(chi2star.mw2,weight);
				histo.hmh_star_good->Fill(chi2star.mh,weight);
	
				histo.hmt1_star_good0->Fill(chi2star.mt1,weight);
				histo.hmt2_star_good0->Fill(chi2star.mt2,weight);
				histo.hmw1_star_good0->Fill(chi2star.mw1,weight);
				histo.hmw2_star_good0->Fill(chi2star.mw2,weight);
				histo.hmh_star_good0->Fill(chi2star.mh,weight);

				histo.ht2D_good->Fill(chi2star.mt1,chi2star.mt2,weight);
			

			}
			else{ //prob(\chi^2*<1%)
	
				chistar_count0.chi_bad++; //for level 0 analysis
				match_jet(chi2star.bjH,bjet,nbjets,chistar_bad0,Hbjets);
				
				histo.hmt1_star_bad0->Fill(chi2star.mt1,weight);
				histo.hmt2_star_bad0->Fill(chi2star.mt2,weight);
				histo.hmw1_star_bad0->Fill(chi2star.mw1,weight);
				histo.hmw2_star_bad0->Fill(chi2star.mw2,weight);
				histo.hmh_star_bad0->Fill(chi2star.mh,weight);

				if((njets>=9) && (njets-nbjets)>=5){

					chi2star=combchi2_star2(jet, njets,5,4);
					Bestchi2 bestchi2_star2;
					store_bestchi2(chi2star,bestchi2_star2);

					if( TMath::Prob((bestchi2_star2.chi1[0]),4) >=0.01){
						//prob(\chi^2*>1%)
						chistar_count.chi_good++;
						chistar_count1.chi_good++;
						//store best chi for all the event
						bestchi2star_good.chi1.push_back(bestchi2_star2.chi1[0]);
						bestchi2star_good.chi2.push_back(bestchi2_star2.chi2[0]);
						bestchi2star_good.chi3.push_back(bestchi2_star2.chi3[0]);
						//count how many bjets (from H) find by chi2* are bjets (from higgs, genLev) identified with \deltaR
						nmatch=match_jet(chi2star.bjH,bjet,nbjets,chistar_good,Hbjets);
						match_jet(chi2star.bjH,bjet,nbjets,chistar_good1,Hbjets);
						
						if(nmatch==2){
							histo.hmh_2match1->Fill(chi2star.mh,weight);
						}
						else if(nmatch==1){
							histo.hmh_1match1->Fill(chi2star.mh,weight);
						}
						else{
							histo.hmh_0match1->Fill(chi2star.mh,weight);
						}

						histo.hmt1_star_good->Fill(chi2star.mt1,weight);
						histo.hmt2_star_good->Fill(chi2star.mt2,weight);
						histo.hmw1_star_good->Fill(chi2star.mw1,weight);
						histo.hmw2_star_good->Fill(chi2star.mw2,weight);
						histo.hmh_star_good->Fill(chi2star.mh,weight);
	
						histo.hmt1_star_good1->Fill(chi2star.mt1,weight);
						histo.hmt2_star_good1->Fill(chi2star.mt2,weight);
						histo.hmw1_star_good1->Fill(chi2star.mw1,weight);
						histo.hmw2_star_good1->Fill(chi2star.mw2,weight);
						histo.hmh_star_good1->Fill(chi2star.mh,weight);

						histo.ht2D_good->Fill(chi2star.mt1,chi2star.mt2,weight);

					}
					else{
						chistar_count.chi_bad++;
						chistar_count1.chi_bad++;
						//store_bestchi2(chi2star,bestchi2star2_bad);
						bestchi2star_bad.chi1.push_back(bestchi2_star2.chi1[0]);
						bestchi2star_bad.chi2.push_back(bestchi2_star2.chi2[0]);
						bestchi2star_bad.chi3.push_back(bestchi2_star2.chi3[0]);
						match_jet(chi2star.bjH,bjet,nbjets,chistar_bad,Hbjets);
						match_jet(chi2star.bjH,bjet,nbjets,chistar_bad1,Hbjets);
						histo.hmt1_star_bad->Fill(chi2star.mt1,weight);
						histo.hmt2_star_bad->Fill(chi2star.mt2,weight);
						histo.hmw1_star_bad->Fill(chi2star.mw1,weight);
						histo.hmw2_star_bad->Fill(chi2star.mw2,weight);
						histo.hmh_star_bad->Fill(chi2star.mh,weight);

						histo.hmt1_star_bad1->Fill(chi2star.mt1,weight);
						histo.hmt2_star_bad1->Fill(chi2star.mt2,weight);
						histo.hmw1_star_bad1->Fill(chi2star.mw1,weight);
						histo.hmw2_star_bad1->Fill(chi2star.mw2,weight);
						histo.hmh_star_bad1->Fill(chi2star.mh,weight);
	
						histo.ht2D_bad->Fill(chi2star.mt1,chi2star.mt2,weight);

					}
				}
				//Found nothing 
				else{
					chistar_count.chi_bad++;
					chistar_count1.chi_bad++;
					//store_bestchi2(chi2star,bestchi2star_bad);
					bestchi2star_bad.chi1.push_back(bestchi2_star.chi1[0]);
					bestchi2star_bad.chi2.push_back(bestchi2_star.chi2[0]);
					bestchi2star_bad.chi3.push_back(bestchi2_star.chi3[0]);
					match_jet(chi2star.bjH,bjet,nbjets,chistar_bad,Hbjets);
					match_jet(chi2star.bjH,bjet,nbjets,chistar_bad1,Hbjets);
					histo.hmt1_star_bad->Fill(chi2star.mt1,weight);
					histo.hmt2_star_bad->Fill(chi2star.mt2,weight);
					histo.hmw1_star_bad->Fill(chi2star.mw1,weight);
					histo.hmw2_star_bad->Fill(chi2star.mw2,weight);
					histo.hmh_star_bad->Fill(chi2star.mh,weight);
	
					histo.hmt1_star_bad1->Fill(chi2star.mt1,weight);
					histo.hmt2_star_bad1->Fill(chi2star.mt2,weight);
					histo.hmw1_star_bad1->Fill(chi2star.mw1,weight);
					histo.hmw2_star_bad1->Fill(chi2star.mw2,weight);
					histo.hmh_star_bad1->Fill(chi2star.mh,weight);
	
					histo.ht2D_bad->Fill(chi2star.mt1,chi2star.mt2,weight);

				}
			}

		}
		else //we do not have at least 4 jets not b-tagged 
		{
			count1++;
		}


	}
	////////////////////////////
	//loop over the events end
	////////////////////////////
	cout<<endl;
	cout<<"number of events: "<<nEv<<endl;
	cout<<"number of events selected: "<<evCounter<<endl;
	cout<<"fraction of events selected: "<<1.0*evCounter/nEv<<" +- "<<sigma_frac(evCounter,nEv)<<endl;
	cout<<endl;
	cout<<counter_bad<<endl;
	cout<<count1<<endl;
	cout<<"**************************"<<endl;
	cout<<"*         Chi^2*         *"<<endl;
	cout<<"**************************"<<endl;
	//Dump_result(evCounter, chistar_count, chistar_good, chistar_bad, bestchi2star_good, bestchi2star_bad);
	/*Dump_result(evCounter, chistar_count0, chistar_good, chistar_bad, bestchi2star_good, bestchi2star_bad);
	cout<<endl;*/
	cout<<endl;
	cout<<"****Level 0 selection****"<<endl;
	Dump_result(evCounter, chistar_count0, chistar_good0, chistar_bad0/*, bestchi2star_good, bestchi2star_bad*/);
	cout<<endl;
	cout<<"****Level 1 selection****"<<endl;
	Dump_result(evCounter, chistar_count1, chistar_good1, chistar_bad1/*, bestchi2star_good, bestchi2star_bad*/);
	cout<<endl;
	cout<<"****Combined****"<<endl;
	Dump_result(evCounter, chistar_count, chistar_good, chistar_bad/*, bestchi2star_good, bestchi2star_bad*/);
	cout<<endl;


	printHisto(histo);


	return;
}