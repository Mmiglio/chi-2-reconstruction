void sort_pt(Jet *vj, int size){

	for( int i=0; i<size; i++){
		float max=vj[i].pt;
		for( int j=i+1; j<size; j++){
			if(vj[j].pt > max){
				max=vj[j].pt;
				Jet tmp = vj[i];
				vj[i] = vj[j];
				vj[j] = tmp;
			}
		}
	}
	return;
}

void sort_csv(Jet *vj, int size){

	for( int i=0; i<size; i++){
		float max=vj[i].csv;
		for( int j=i+1; j<size; j++){
			if(vj[j].csv > max){
				max=vj[j].csv;
				Jet tmp = vj[i];
				vj[i] = vj[j];
				vj[j] = tmp;
			}
		}
	}
	return;
}
