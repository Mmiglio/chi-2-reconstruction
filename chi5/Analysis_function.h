void store_bestchi2(Chi2result& result, Bestchi2& best){

	sort(result.dist_chi2.begin(),result.dist_chi2.end());
	best.chi1.push_back(result.dist_chi2[0]);
	bool check3chi = false, check2chi=true;
	for(unsigned long int i=0; i<result.dist_chi2.size(); i++){
		if( check2chi && result.dist_chi2[i] != best.chi1[best.chi1.size()-1]){
			best.chi2.push_back(result.dist_chi2[i]);
			check2chi=false;
			check3chi = true;
		}
		if(check3chi && result.dist_chi2[i] != best.chi2[best.chi2.size()-1] ){
			best.chi3.push_back(result.dist_chi2[i]);
			check3chi=false;
		}
	}

	return;
}

Hbjet_index gen_match(Jet* bjet, Jet* genbH, int nbjets){

	Hbjet_index Hbjet;

	vector<int> matchbj;
	for(int j=0; j<2; j++){
		int i_true;
		double mindr=10.;
		for(int i=0; i<nbjets; i++){
			if(j!=0 && i==matchbj[0]) continue;
			double dr = DR(bjet[i],genbH[j]);
			if(dr<mindr){
				mindr=dr;
				i_true = i;
			}
		}
		matchbj.push_back(i_true);
	}
	Hbjet.bj1=matchbj[0];
	Hbjet.bj2=matchbj[1];

	return Hbjet;
}

int match_jet(vector<Jet>& jet, Jet* bjet, int nbjets, MatchCounter& count, Hbjet_index& Hbjet){
	
	int bjfh1=0, bjfh2=0;
	for(int i=0; i<nbjets; i++){
		if(comparison(bjet[i],jet[0]) && bjfh1==0) bjfh1=i;
		if(comparison(bjet[i],jet[1]) && i!=bjfh1) bjfh2=i;
	}
	if( (bjfh1==Hbjet.bj1 || bjfh1==Hbjet.bj2) && (bjfh2==Hbjet.bj1 || bjfh2==Hbjet.bj2)) {
		count.two_m++;
		return 2;
	}
	else if( (bjfh1==Hbjet.bj1 || bjfh1==Hbjet.bj2) || (bjfh2==Hbjet.bj1 || bjfh2==Hbjet.bj2))  {
		count.one_m++;
		return 1;
	}
	else{
		count.zero_m++;
		return 0;
	}
}

double mean_vector(vector<double> v){

	double mean;

	for(unsigned long int i=0; i<v.size(); i++){
		mean += v[i];
	}

	return mean/v.size();
}

bool comparison(Jet j1, Jet j2){
	if(j1.pt == j2.pt && j1.eta==j2.eta && j1.phi==j2.phi && j1.mass==j2.mass) return true;
	else return false;
}

double sigma_frac(int n, int nEv){
	double f = 1.0*n/nEv;
	double sigma = sqrt((f*(1-f))/nEv);
	return sigma;
}

 double DR(Jet j1, Jet j2){

	TLorentzVector p1, p2;
    p1.SetPtEtaPhiM(j1.pt,j1.eta,j1.phi,j1.mass);
    p2.SetPtEtaPhiM(j2.pt,j2.eta,j2.phi,j2.mass);
    double dr = p1.DeltaR(p2);
    return dr;
}