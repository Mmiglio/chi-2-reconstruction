struct Cuts{

	const int   njets_max = 20, nmuons_max = 0;
	const int   njets_min = 8,  nmuons_min = 0;
	const int   nbjets_min= 4,  nbjets_max = 20;//20
	const float jetspt_min= 30., muonspt_max=5.; 
	const float metpt_min=0., eta_max=2.5;
	const double csvcut=0.8484; //loss=0.5426 //medium=0.8484  //tight=0.9535
	double readfrac=1.;
};