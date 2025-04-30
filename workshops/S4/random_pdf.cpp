#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]); 
  const double MU = std::atof(argv[3]); // std:atof ("a.x" -- > a.x ) instead std::atoi ("a.x" -- > a )
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};

  // TODO: histogram stuff
  std::vector<int> count_hist(nbins,0);

  double width = (xmax - xmin)/(nbins*1.0); // bins width

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen); //a
    //std::cout << r << std::endl; //test for checking because if mu or sigma = a.x dis(gen) generates mu or sigma = a

    ///*
    // TODO: fill here the counting histogram stuff
    // Avoid r out of range
    bool out = r < xmin || r >= xmax;
    if (!out){
      int bin_index = (r - xmin) / width  ;
      count_hist[bin_index]++;
    }
    //*/
  }
  
  ///*
  // TODO: compute an d print the pdf
  for (int ii = 0; ii < nbins; ii++)
  {
    double pdf_ii = count_hist[ii] / (nsamples * width * 1.0); // Probability density function for each position
    double bin_center = xmin + (ii + 0.5) * width;  // I take bin_center as a representative of the bin
    std::cout << bin_center << "\t" << pdf_ii << "\n";
  }
  //*/
}