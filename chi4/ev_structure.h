#ifndef ev_structure_h
#define ev_structure_h

struct Jet{
	float pt;
	float eta;
	float phi;
	float mass;
	float csv;
	float cmva;
};

struct Muon{
	float pt;
	float eta;
	float phi;
	float mass;
	float iso03;
};

struct Met{
	float pt;
	float phi;
};

#endif