struct Hbjet_index{//contains two index (bjets from higgs using \deltaR)
	int bj1=0;
	int bj2=0;
};

struct Chi2result{
	double mh;
	double mt1;
	double mt2;
	double mw1;
	double mw2;
	vector<Jet> bjH; //bjets from higgs;
	vector<double> dist_chi2; //store chi2 
};

struct Bestchi2{
	vector<double> chi1;
	vector<double> chi2;
	vector<double> chi3;
};

struct ChiCounter{
	int chi_good=0;
	int chi_bad=0;
};

struct MatchCounter{
	int two_m=0;
	int one_m=0;
	int zero_m=0;
};