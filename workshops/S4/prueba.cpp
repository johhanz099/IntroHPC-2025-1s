#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

//void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
    int seed = 1;
    int nsamples = 10;
    double mu = 0.5;
    double sigma = 0.01;
    double xmin = 0;
    double xmax = 1;
    int nbins = 10;
    
    // random stuff
    std::mt19937 gen(seed);
    std::normal_distribution<double> dis{mu, sigma};

    double width = (xmax - xmin)/(nbins*1.0); // bins width
    
    for(int n = 0; n < nsamples; ++n) {
        double r = dis(gen); //a
        std::cout << r << std::endl;
    }
    return 0;
}