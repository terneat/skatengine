#include "skatEngine/include/random_numbers.h"

#include <chrono>
#include <cmath>

randgen::randgen(int seed1): rngp(nullptr), rdist(0.0, 1.0)
{
  if(seed1==0)seed1=std::chrono::system_clock::now().time_since_epoch().count();
  rngp =new std::default_random_engine(seed1);
    
}

randgen::~randgen(){delete rngp;}

double randgen::rand_num(double a, double b)
{
	if(a<b) return a+(b-a)*rdist(*rngp);
	else return a;		
}

int randgen::rand_int(int a, int b)
{
    double dbase = rand_num(double(a), double(b+1)-1.e-06);
    return int(std::floor(dbase));
}
