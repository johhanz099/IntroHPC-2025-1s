#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atoi(argv[3]);
  const double SIGMA = std::atoi(argv[4]);
  const double XMIN = std::atoi(argv[5]);
  const double XMAX = std::atoi(argv[6]);
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

  double width = (xmax - xmin)/nbins; // bins's width
  int n_normalize = 0;

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    // TODO: fill here the counting histogram stuff
    // Avoid r out of range
    bool out = r < xmin || r >= xmax;
    if (!out){
      int width_count = 0; // Counter to go through each bin
      while (width_count < nbins){
        double bin_min = xmin + width*width_count;
        double bin_max = xmin + width*(width_count+1);
        if (r >= bin_min && r < bin_max){
          count_hist[width_count]++;
          n_normalize++;
          break;
        }
      width_count++;
      }
    }  
  }
  // TODO: compute an d print the pdf
  for (int ii = 0; ii < nbins; ii++)
  {
    double pdf_ii = count_hist[ii] / (nsamples * width); // Probability density function for each position
    double bin_center = xmin + (ii + 0.5) * width;  // I take bin_center as a representative of the bin
    std::cout << bin_center << "\t" << pdf_ii << std::endl;
  }
  

}