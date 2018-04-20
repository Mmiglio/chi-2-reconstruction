## Description
Code use for the ttH reconstruction using 3 different chi^2: 
* chi3 is a $\chi^2$ with 3 d.o.f which constrains the W_1 and W_2 masses and requires the equality of t_1 and t_2 masses 
* chi4 is a chi^2 with 4 d.o.f which constrains the W_1 and W_2 masses and also t_1 and t_2 masses 
* chi5 is a chi^2 with 5 d.o.f which constrains the W_1, W_2, t_1 and t_2 masses an also H mass 

## To Run: 
``root -l maintth_new.cc``

You can use also this file as input:
``/lustre/cmswork/hh/alp_moriond_base/ttH_4jets2cmva/ttHTobb_short.root``


## Output
The output is a root file containing all the histogram 
``out.root``

