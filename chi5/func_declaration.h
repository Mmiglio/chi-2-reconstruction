
void store_bestchi2(Chi2result& result, Bestchi2& best);
Hbjet_index gen_match(Jet* bjet, Jet* genbH, int nbjets);
int match_jet(vector<Jet>& jet, Jet* bjet, int nbjets, MatchCounter& count, Hbjet_index& Hbjet);
double mean_vector(vector<double> v);
bool comparison(Jet j1, Jet j2);
double sigma_frac(int n, int nEv);
double DR(Jet j1, Jet j2);
Chi2result combchi2_star(Jet* jets,int njets);
Chi2result combchi2_star2(Jet* jets,int njets, int nj, int nbj);
void sort_pt(Jet *vj, int size);
void sort_csv(Jet *vj, int size);
void Dump_result(int nEv, ChiCounter& chi_count, MatchCounter& chi_good, MatchCounter& chi_bad/*, Bestchi2& bestchi2_good, Bestchi2& bestchi2_bad*/);
void printHisto(Histo& histo);