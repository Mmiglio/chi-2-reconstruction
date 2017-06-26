struct Histo{

	int nbins=40;
 	
 	/////////////
 	// TOP
	/////////////

 	//mt1
 	TH1F *hmt1_star = new TH1F("hmt1_star","t_{1} mass (#chi^{2})",nbins,0.,600.);

 	TH1F *hmt1_star_good = new TH1F("hmt1_star_good","t_{1} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmt1_star_bad = new TH1F("hmt1_star_bad","t_{1} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//analysis
	TH1F *hmt1_star_good0 = new TH1F("hmt1_star_good0","t_{1} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmt1_star_bad0 = new TH1F("hmt1_star_bad0","t_{1} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//deeper analysis
	TH1F *hmt1_star_bad1 = new TH1F("hmt1_star_bad1","t_{1} mass (P(#chi^{2})<0.01, 9 jets)",nbins,0.,600.);
	TH1F *hmt1_star_good1 = new TH1F("hmt1_star_good1","t_{1} mass (P(#chi^{2})>0.01, 9 jets)",nbins,0.,600.);

	//mt2
	TH1F *hmt2_star = new TH1F("hmt2_star","t_{2} mass (#chi^{2})",nbins,0.,600.);
	TH1F *hmt2_star_good = new TH1F("hmt2_star_good","t_{2} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmt2_star_bad = new TH1F("hmt2_star_bad","t_{2} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//analysis
	TH1F *hmt2_star_good0 = new TH1F("hmt2_star_good0","t_{2} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmt2_star_bad0 = new TH1F("hmt2_star_bad0","t_{2} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//deeper analysis
	TH1F *hmt2_star_bad1 = new TH1F("hmt2_star_bad1","t_{2} mass (P(#chi^{2})<0.01, 9 jets)",nbins,0.,600.);
	TH1F *hmt2_star_good1 = new TH1F("hmt2_star_good1","t_{2} mass (P(#chi^{2})>0.01, 9 jets)",nbins,0.,600.);

	TH2D *ht2D_good = new TH2D("ht2D_good", "Top mass (P(#chi^{2})>0.01)",nbins,0.,600., nbins,0.,600. );
	TH2D *ht2D_bad = new TH2D("ht2D_bad", "Top mass (P(#chi^{2})<0.01)",nbins,0.,600., nbins,0.,600. );

	/////////////
 	// W
	/////////////
	//mw1
 	TH1F *hmw1_star = new TH1F("hmw1_star","W_{1} mass (#chi^{2})",nbins,0.,600.);

 	TH1F *hmw1_star_good = new TH1F("hmw1_star_good","W_{1} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmw1_star_bad = new TH1F("hmw1_star_bad","W_{1} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//analysis
	TH1F *hmw1_star_good0 = new TH1F("hmw1_star_good0","W_{1} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmw1_star_bad0 = new TH1F("hmw1_star_bad0","W_{1} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//deeper analysis
	TH1F *hmw1_star_bad1 = new TH1F("hmw1_star_bad1","W_{1} mass (P(#chi^{2})<0.01, 9 jets)",nbins,0.,600.);
	TH1F *hmw1_star_good1 = new TH1F("hmw1_star_good1","W_{1} mass (P(#chi^{2})>0.01, 9 jets)",nbins,0.,600.);

	//mw2
	TH1F *hmw2_star = new TH1F("hmw2_star","W_{2} mass (#chi^{2})",nbins,0.,600.);
	TH1F *hmw2_star_good = new TH1F("hmw2_star_good","W_{2} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmw2_star_bad = new TH1F("hmw2_star_bad","W_{2} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//analysis
	TH1F *hmw2_star_good0 = new TH1F("hmw2_star_good0","W_{2} mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmw2_star_bad0 = new TH1F("hmw2_star_bad0","W_{2} mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//deeper analysis
	TH1F *hmw2_star_bad1 = new TH1F("hmw2_star_bad1","W_{2} mass (P(#chi^{2})<0.01, 9 jets)",nbins,0.,600.);
	TH1F *hmw2_star_good1 = new TH1F("hmw2_star_good1","W_{2} mass (P(#chi^{2})>0.01, 9 jets)",nbins,0.,600.);

	/////////////
 	// Higgs
	/////////////
	TH1F *hmh_star = new TH1F("hmh_star","H mass (#chi^{2})",nbins,0.,600.);
	TH1F *hmh_star_good = new TH1F("hmh_star_good","H mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmh_star_bad = new TH1F("hmh_star_bad","H mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmh_star_good0 = new TH1F("hmh_star_good0","H mass (P(#chi^{2})>0.01)",nbins,0.,600.);
	TH1F *hmh_star_bad0 = new TH1F("hmh_star_bad0","H mass (P(#chi^{2})<0.01)",nbins,0.,600.);
	//deeper analysis
	TH1F *hmh_star_bad1 = new TH1F("hmh_star_bad1","H mass (P(#chi^{2})<0.01, 9 jets)",nbins,0.,600.);
	TH1F *hmh_star_good1 = new TH1F("hmh_star_good1","H mass (P(#chi^{2})>0.01, 9 jets)",nbins,0.,600.);

	TH1F *hmh_2match = new TH1F("hmh_2match","H mass",nbins,0.,600.);
	TH1F *hmh_1match = new TH1F("hmh_1match","H mass",nbins,0.,600.);
	TH1F *hmh_0match = new TH1F("hmh_0match","H mass",nbins,0.,600.);

	TH1F *hmh_2match1 = new TH1F("hmh_2match1","H mass",nbins,0.,600.);
	TH1F *hmh_1match1 = new TH1F("hmh_1match1","H mass",nbins,0.,600.);
	TH1F *hmh_0match1 = new TH1F("hmh_0match1","H mass",nbins,0.,600.);

	TH1F *hmh_gen = new TH1F("hmh_gen","H mass (Gen)",nbins,0.,600.);
	TH1F *hmh_dr = new TH1F("hmh_dr","H mass (Gen)",nbins,0.,600.);





};