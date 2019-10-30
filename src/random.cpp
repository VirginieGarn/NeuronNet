#include "random.h"
RandomNumbers::RandomNumbers(unsigned long int seed) {
    if (seed == 0) {
        std::random_device rd;
        seed = rd();
    }
    rng = std::mt19937(seed);
}

void RandomNumbers:: uniform_double(std::vector<double> &res, double lower, double upper)
{
	size_t i;
	for(i=0; i<(res.size()); ++i)
	{
		res[i]=uniform_double(lower,upper);
	}
	
}
double RandomNumbers:: uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<> unif(lower, upper);
	return unif(rng);
}
void RandomNumbers::normal(std::vector<double> &res, double mean, double sd)
{
	size_t i;
	for(i=0; i<(res.size()); ++i)
	{
		res[i]=normal(mean,sd);
	}
	
}
double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<> norm (mean,sd);
	return norm(rng); 
}
void RandomNumbers::poisson(std::vector<int> &res, double mean)
{
	size_t i;
	for(i=0; i<(res.size()); ++i)
	{
		res[i]=poisson(mean);
	}
	
}
int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<>pois(mean);
	return pois(rng);
}
