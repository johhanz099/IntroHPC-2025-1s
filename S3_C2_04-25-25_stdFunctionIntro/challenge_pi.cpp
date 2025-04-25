#include <random>
#include <iostream>
#include <cstdlib>

double compute_pi(int seed, long nsamples);

int main(int argc, char **argv) 
{
  const int SEED = std::atoi(argv[1]);
  const long NSAMPLES = std::atol(argv[2]);
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double mypi = compute_pi(SEED, NSAMPLES);
  std::cout << mypi << "\n"; 
    
  return 0;
}

double compute_pi(int seed, long nsamples) {
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  int N_c = 0;
  double x = 0.0;
  double y = 0.0;
  for (int ii = 0; ii <= nsamples; ii++){
    x = dis(gen);
    y = dis(gen);
    if (x*x + y*y <= 0.25){
        N_c++;
    }     
  }
  return 4.0*N_c/(nsamples*1.0);
}