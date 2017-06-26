#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TMath.h"
#include "TMinuit.h"
#include "TROOT.h"
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

void chi_dist(){

	const int file_number=2;
	TString data_name[file_number] = {"/Users/matteo/Desktop/tth/data/ttHTobb_short.root","/Users/matteo/Desktop/tth/data/TT_short.root"};

	for(int file=0; file<file_number; file++){

		TFile *fin = new TFile(data_name[file]);
		if(!fin->IsOpen()){
			cout<<"Error: cannot open the file!"<<endl;
			return;
		}

		if(file==0){cout<<"Signal ttH"<<endl;}
		if(file==1){cout<<"Bkg tt"<<endl;}

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

		t->SetBranchAddress("met_pt",&met_pt);
		t->SetBranchAddress("met_phi",&met_phi);

		t->SetBranchAddress("weight",&weight);


	}


	return;
}