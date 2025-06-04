#include <iostream>
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <ctime>
#include <cmath>

void solveSystem(int size);
void stats(const int size, const int reps, // input parameters
               double & mean_wtime, double & sigma_wtime, // output
               double & mean_ctime, double & sigma_ctime); // output

int main(int argc, char ** argv)
{
    const int M = atoi(argv[1]); // Matrix size
    const int R = atoi(argv[2]); // Repetitions

    double mean_wtime, sigma_wtime;
    double mean_ctime, sigma_ctime;
    stats(M, R, mean_wtime, sigma_wtime, mean_ctime, sigma_ctime);
    std::cout << M
                << "\t" << mean_wtime << "\t" << sigma_wtime
                << "\t" << mean_ctime << "\t" << sigma_ctime
                << std::endl;
        
    return 0;
}   

void solveSystem(int size)
{
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);
  // crono star
  //Eigen::MatrixXd x = A.fullPivLu().solve(b);
  //Eigen::MatrixXd x = A.partialPivLu().solve(b);
  Eigen::MatrixXd x = A.lu().solve(b);
  // crono end
  double relative_error = (A*x - b).norm() / b.norm(); // norm() is L2 norm
  //std::cout << A << std::endl;
  //std::cout << b << std::endl;
  //std::cout << "The relative error is:\n" << relative_error << std::endl;
  std::cerr << x(0,0) << "\n";
}

void stats(const int size, const int reps,
               double & mean_wtime, double & sigma_wtime,
               double & mean_ctime, double & sigma_ctime)
{
    // 1. Definir variables para sumar tiempos en stats
    double suma_wtime = 0.0;
    double suma_wtime2 = 0.0;
    double suma_ctime = 0.0;
    double suma_ctime2 = 0.0;

    // 2. Llamar/copiar codigo reps (R) veces a solvesystem y medir su tiempo
    for(int ii = 0; ii < reps; ++ii){
        Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
        Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);

        // dos relojes, para wtime, ctime
        std::clock_t c_start = std::clock();
        auto w_start = std::chrono::steady_clock::now();
        Eigen::MatrixXd x = A.lu().solve(b);
        std::cerr << x(0,0) << "\n";
        std::clock_t c_end = std::clock();
        auto w_end = std::chrono::steady_clock::now();
        // terminar tiempos

        // convertir a segundos:
        std::chrono::duration<double> elapsed_seconds{w_end - w_start};
        double w_aux = elapsed_seconds.count();
        double c_aux = (c_end - c_start) / CLOCKS_PER_SEC;

        // Sumarlos
        suma_wtime2 += w_aux;
        suma_ctime2 += c_aux;


    }

    // 3. Calcular las stats y retornar/guardar sus valores
    // sigma² * (N-1) = \sum x_i² -2 \sum x_i * x_prom + \sum x_prom²
    // para llegar a
    mean_wtime = suma_wtime/reps;
    sigma_wtime = std::sqrt(reps*(suma_wtime2/reps - mean_wtime*mean_wtime)/(reps-1));
    mean_ctime = suma_ctime/reps; 
    sigma_ctime = std::sqrt(reps*(suma_ctime2/reps - mean_ctime*mean_ctime)/(reps-1));
}




// usar chrono para medir el tiempo
// perf
// remove printing
// modify printing


// Pasos
// 1. Definir variables para sumar tiempos en stats
// 2. Llamar/copiar codigo reps (R) veces a solvesystem y medir su tiempo
// 3. Calcular las stats y retornar/guardar sus valores