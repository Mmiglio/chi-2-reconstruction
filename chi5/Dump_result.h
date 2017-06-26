void Dump_result(int nEv, ChiCounter& chi_count, MatchCounter& chi_good, MatchCounter& chi_bad/*, Bestchi2& bestchi2_good, Bestchi2& bestchi2_bad*/){
	 
	/*cout<<"Fraction of events w/ Prob(chi^2,3)>0.01 = "<<1.0*chi_count.chi_good/nEv<<" +- "<<sigma_frac(chi_count.chi_good,nEv)<<endl;
	cout<<"2 match (fraction of good events): "<<1.0*chi_good.two_m/chi_count.chi_good<<" +- "<<sigma_frac(chi_good.two_m,chi_count.chi_good)<<endl;
	cout<<"1 match (fraction of good events): "<<1.0*chi_good.one_m/chi_count.chi_good<<" +- "<<sigma_frac(chi_good.one_m,chi_count.chi_good)<<endl;
	cout<<"0 match (fraction of good events): "<<1.0*chi_good.zero_m/chi_count.chi_good<<" +- "<<sigma_frac(chi_good.zero_m,chi_count.chi_good)<<endl;
	cout<<"Mean of best chi^2* (case: good): "<<endl;
	cout<<"1st: "<<mean_vector(bestchi2_good.chi1)<<" +- "<<TMath::RMS(bestchi2_good.chi1.begin(), bestchi2_good.chi1.end())<<endl;
	cout<<"2st: "<<mean_vector(bestchi2_good.chi2)<<" +- "<<TMath::RMS(bestchi2_good.chi2.begin(), bestchi2_good.chi2.end())<<endl;
	cout<<"3st: "<<mean_vector(bestchi2_good.chi3)<<" +- "<<TMath::RMS(bestchi2_good.chi3.begin(), bestchi2_good.chi3.end())<<endl;
	cout<<endl;
	cout<<"2 match (fraction of all events): "<<1.0*chi_good.two_m/nEv<<" +- "<<sigma_frac(chi_good.two_m,nEv)<<endl;
	cout<<"1 match (fraction of all events): "<<1.0*chi_good.one_m/nEv<<" +- "<<sigma_frac(chi_good.one_m,nEv)<<endl;
	cout<<"0 match (fraction of all events): "<<1.0*chi_good.zero_m/nEv<<" +- "<<sigma_frac(chi_good.zero_m,nEv)<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Fraction of events w/ Prob(chi^2,3)<0.01 = "<<1.0*chi_count.chi_bad/nEv<<" +- "<<sigma_frac(chi_count.chi_bad,nEv)<<endl;
	cout<<"2 match (fraction of bad events): "<<1.0*chi_bad.two_m/chi_count.chi_bad<<" +- "<<sigma_frac(chi_bad.two_m,chi_count.chi_bad)<<endl;
	cout<<"1 match (fraction of bad events): "<<1.0*chi_bad.one_m/chi_count.chi_bad<<" +- "<<sigma_frac(chi_bad.one_m,chi_count.chi_bad)<<endl;
	cout<<"0 match (fraction of bad events): "<<1.0*chi_bad.zero_m/chi_count.chi_bad<<" +- "<<sigma_frac(chi_bad.zero_m,chi_count.chi_bad)<<endl;
	cout<<"Mean of best chi^2* (case: bad): "<<endl;
	cout<<"1st: "<<mean_vector(bestchi2_bad.chi1)<<" +- "<<TMath::RMS(bestchi2_bad.chi1.begin(), bestchi2_bad.chi1.end())<<endl;
	cout<<"2st: "<<mean_vector(bestchi2_bad.chi2)<<" +- "<<TMath::RMS(bestchi2_bad.chi2.begin(), bestchi2_bad.chi2.end())<<endl;
	cout<<"3st: "<<mean_vector(bestchi2_bad.chi3)<<" +- "<<TMath::RMS(bestchi2_bad.chi3.begin(), bestchi2_bad.chi3.end())<<endl;
	cout<<endl;
	cout<<"2 match (fraction of all events): "<<1.0*chi_bad.two_m/nEv<<" +- "<<sigma_frac(chi_bad.two_m,nEv)<<endl;
	cout<<"1 match (fraction of all events): "<<1.0*chi_bad.one_m/nEv<<" +- "<<sigma_frac(chi_bad.one_m,nEv)<<endl;
	cout<<"0 match (fraction of all events): "<<1.0*chi_bad.zero_m/nEv<<" +- "<<sigma_frac(chi_bad.zero_m,nEv)<<endl;*/

	cout<<"Fraction of event with P(chi^2)>0.01: "<<1.0*chi_count.chi_good/nEv<<" +- "<<sigma_frac(chi_count.chi_good,nEv)<<endl;
	cout<<endl;
	cout<<"2 match (fraction of good events): "<<1.0*chi_good.two_m/chi_count.chi_good<<" +- "<<sigma_frac(chi_good.two_m,chi_count.chi_good)<<endl;
	cout<<"1 match (fraction of good events): "<<1.0*chi_good.one_m/chi_count.chi_good<<" +- "<<sigma_frac(chi_good.one_m,chi_count.chi_good)<<endl;
	cout<<"0 match (fraction of good events): "<<1.0*chi_good.zero_m/chi_count.chi_good<<" +- "<<sigma_frac(chi_good.zero_m,chi_count.chi_good)<<endl;
	cout<<endl;
	cout<<"Fraction of event with P(chi^2)<0.01: "<<1.0*chi_count.chi_bad/nEv<<" +- "<<sigma_frac(chi_count.chi_bad,nEv)<<endl;
	cout<<"2 match (fraction of bad events): "<<1.0*chi_bad.two_m/chi_count.chi_bad<<" +- "<<sigma_frac(chi_bad.two_m,chi_count.chi_bad)<<endl;
	cout<<"1 match (fraction of bad events): "<<1.0*chi_bad.one_m/chi_count.chi_bad<<" +- "<<sigma_frac(chi_bad.one_m,chi_count.chi_bad)<<endl;
	cout<<"0 match (fraction of bad events): "<<1.0*chi_bad.zero_m/chi_count.chi_bad<<" +- "<<sigma_frac(chi_bad.zero_m,chi_count.chi_bad)<<endl;
	
	return;
}