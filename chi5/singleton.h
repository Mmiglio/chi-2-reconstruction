class singleton{

private:
	singleton(){};
	singleton(const singleton&);
	void operator=(const singleton&); 

public:
	static singleton& get_instance(){

		static singleton instance;
		return instance;
	}
	//TH1F* prova(){TH1F* histo = new TH1F("histo","histo title",50,0.,300); return histo;}

};