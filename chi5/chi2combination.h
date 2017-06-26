////////////////////////////
//chi^2*_2
/////////////////////////////
int counter_bad=0;
extern Cuts cuts;
Chi2result combchi2_star2(Jet* jets,int njets, int nj, int nbj){

	//nj=number of jets considered in the combination
	Chi2result result;
	Jet bjet[nbj];
	Jet jet[nj];
	Jet jet_tmp[njets-nbj];

	sort_csv(jets,njets);

	for(int i=0; i<nbj; i++){
		bjet[i]=jets[i];
	}

	for(int i=0;i<njets-nbj;i++){
		jet_tmp[i]=jets[i+nbj];
	}

	sort_pt(jet_tmp,njets-nbj);
	//fino a qui giusto...

	int index=0;
	for(int i=0;i<njets-nbj;i++){
		if(jet_tmp[i].csv<cuts.csvcut && index<nj){jet[index]=jet_tmp[i]; index++;}
		else {counter_bad++;}
	}
	

	vector<double> dist_tmp;

	double mindist=pow(10,10);
	double mh=0,mw1=0,mw2=0,mt1=0,mt2=0;
	int bjfh1=0,bjfh2=0;
	//search for a combination
	for(int bj1=0; bj1<nbj; bj1++){
		
		for(int bj2=0; bj2<nbj; bj2++){
			if(bj2==bj1) continue;
			
			for(int bj3=0; bj3<nbj; bj3++){
				if(bj3==bj1 || bj3==bj2 ) continue;

				for(int bj4=0; bj4<nbj; bj4++){
					if(bj4==bj1 || bj4==bj2 || bj4==bj3) continue; 

					//jets
					for(int j1=0; j1<nj; j1++){

						for(int j2=0; j2<nj; j2++){
							if(j2==j1) continue;

							for(int j3=0; j3<nj; j3++){
								if(j3==j1 || j3==j2) continue;

								for(int j4=0; j4<nj; j4++){
									if(j4==j1 || j4==j2 || j4==j3) continue;
									//we have a combination!

									TLorentzVector vbj1, vbj2, vbj3, vbj4;
    								vbj1.SetPtEtaPhiM(bjet[bj1].pt,bjet[bj1].eta,bjet[bj1].phi,bjet[bj1].mass);
    								vbj2.SetPtEtaPhiM(bjet[bj2].pt,bjet[bj2].eta,bjet[bj2].phi,bjet[bj2].mass);
    								vbj3.SetPtEtaPhiM(bjet[bj3].pt,bjet[bj3].eta,bjet[bj3].phi,bjet[bj3].mass);
    								vbj4.SetPtEtaPhiM(bjet[bj4].pt,bjet[bj4].eta,bjet[bj4].phi,bjet[bj4].mass);

    								TLorentzVector vj1, vj2, vj3, vj4;
    								vj1.SetPtEtaPhiM(jet[j1].pt,jet[j1].eta,jet[j1].phi,jet[j1].mass);
    								vj2.SetPtEtaPhiM(jet[j2].pt,jet[j2].eta,jet[j2].phi,jet[j2].mass);
    								vj3.SetPtEtaPhiM(jet[j3].pt,jet[j3].eta,jet[j3].phi,jet[j3].mass);
    								vj4.SetPtEtaPhiM(jet[j4].pt,jet[j4].eta,jet[j4].phi,jet[j4].mass);


    								TLorentzVector w1, w2;
    								w1=vj1+vj2;
    								w2=vj3+vj4;

    								TLorentzVector t1, t2;
    								t1=w1+vbj1;
    								t2=w2+vbj2; 

    								TLorentzVector H;
    								H=vbj3+vbj4;

    								double dist = pow(w1.M()-80.4,2)/pow(15,2) + pow(w2.M()-80.4,2)/pow(15,2) +
    											  pow(t1.M()-173,2)/pow(30,2) + pow(t2.M()-173,2)/pow(30,2)+
    											  pow(H.M()-125,2)/pow(20,2);

    								dist_tmp.push_back(dist);
    								if(dist<mindist){
    									mindist=dist;
    									mh=H.M();
    									mw1=w1.M();
    									mw2=w2.M();
    									mt1=t1.M();
    									mt2=t2.M();
    									bjfh1=bj3;
    									bjfh2=bj4;
    								}

    							}

							}

						}
					}

				}
			}
		}
	}
	result.mt1=mt1;
	result.mt2=mt2;
	result.mw1=mw1;
	result.mw2=mw2;
	result.mh=mh;
	result.dist_chi2= dist_tmp;
	result.bjH.push_back(bjet[bjfh1]);
	result.bjH.push_back(bjet[bjfh2]);

	return result;
}




/*Chi2result combchi2_star(Jet* jets,int njets){

	Chi2result result;
	Jet bjet[4];
	Jet jet[4];
	Jet jet_tmp[njets-4];

	sort_csv(jets,njets);

	for(int i=0; i<4; i++){
		bjet[i]=jets[i];
	}

	for(int i=0;i<njets-4;i++){
		jet_tmp[i]=jets[i+4];
	}

	sort_pt(jet_tmp,njets-4);

	for(int i=0;i<4;i++){
		jet[i]=jet_tmp[i];
	}

	//fino a qui giusto...

	vector<double> dist_tmp;

	double mindist=pow(10,10);
	double mh=0,mw1=0,mw2=0,mt1=0,mt2=0;
	int bjfh1=0,bjfh2=0;
	//search for a combination
	for(int bj1=0; bj1<4; bj1++){
		
		for(int bj2=0; bj2<4; bj2++){
			if(bj2==bj1) continue;
			
			for(int bj3=0; bj3<4; bj3++){
				if(bj3==bj1 || bj3==bj2 ) continue;

				for(int bj4=0; bj4<4; bj4++){
					if(bj4==bj1 || bj4==bj2 || bj4==bj3) continue; 

					//jets
					for(int j1=0; j1<4; j1++){

						for(int j2=0; j2<4; j2++){
							if(j2==j1) continue;

							for(int j3=0; j3<4; j3++){
								if(j3==j1 || j3==j2) continue;

								for(int j4=0; j4<4; j4++){
									if(j4==j1 || j4==j2 || j4==j3) continue;
									//we have a combination!

									TLorentzVector vbj1, vbj2, vbj3, vbj4;
    								vbj1.SetPtEtaPhiM(bjet[bj1].pt,bjet[bj1].eta,bjet[bj1].phi,bjet[bj1].mass);
    								vbj2.SetPtEtaPhiM(bjet[bj2].pt,bjet[bj2].eta,bjet[bj2].phi,bjet[bj2].mass);
    								vbj3.SetPtEtaPhiM(bjet[bj3].pt,bjet[bj3].eta,bjet[bj3].phi,bjet[bj3].mass);
    								vbj4.SetPtEtaPhiM(bjet[bj4].pt,bjet[bj4].eta,bjet[bj4].phi,bjet[bj4].mass);

    								TLorentzVector vj1, vj2, vj3, vj4;
    								vj1.SetPtEtaPhiM(jet[j1].pt,jet[j1].eta,jet[j1].phi,jet[j1].mass);
    								vj2.SetPtEtaPhiM(jet[j2].pt,jet[j2].eta,jet[j2].phi,jet[j2].mass);
    								vj3.SetPtEtaPhiM(jet[j3].pt,jet[j3].eta,jet[j3].phi,jet[j3].mass);
    								vj4.SetPtEtaPhiM(jet[j4].pt,jet[j4].eta,jet[j4].phi,jet[j4].mass);


    								TLorentzVector w1, w2;
    								w1=vj1+vj2;
    								w2=vj3+vj4;

    								TLorentzVector t1, t2;
    								t1=w1+vbj1;
    								t2=w2+vbj2; 

    								TLorentzVector H;
    								H=vbj3+vbj4;

    								double dist = pow(w1.M()-80.4,2)/pow(15,2) + pow(w2.M()-80.4,2)/pow(15,2) +
    											  pow(t1.M()-t2.M(),2)/(2*pow(30,2));

    								dist_tmp.push_back(dist);
    								if(dist<mindist){
    									mindist=dist;
    									mh=H.M();
    									mw1=w1.M();
    									mw2=w2.M();
    									mt1=t1.M();
    									mt2=t2.M();
    									bjfh1=bj3;
    									bjfh2=bj4;
    								}

    							}

							}

						}
					}

				}
			}
		}
	}
	result.mt1=mt1;
	result.mt2=mt2;
	result.mw1=mw1;
	result.mw2=mw2;
	result.mh=mh;
	result.dist_chi2= dist_tmp;
	result.bjH.push_back(bjet[bjfh1]);
	result.bjH.push_back(bjet[bjfh2]);

	return result;
}*/