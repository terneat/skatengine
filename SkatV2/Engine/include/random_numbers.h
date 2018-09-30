#ifndef RANDOM_NUMBERS_H
#define RANDOM_NUMBERS_H

#include <random>

class randgen{

public: 
    randgen(int seed1=0);
    ~randgen();
    double rand_num(double, double);
    int rand_int(int, int);

private: 
    std::default_random_engine* rngp;
    std::uniform_real_distribution<double> rdist;
};

#endif
