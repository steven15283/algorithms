#pragma once
#include <string>
//steven guo
//4320
//4/30/21
using namespace std;

const int n = 30;// constant for population size
const double pc = 0.8;//percentage for single point crossover
const double pm = 0.1;//percentage for gene mutation
const int maxGen = 50;//maximum amount of generations
int best_run_index = 0;//index of the best fitness in a generation
int worst_index = 0;//index of the worst fitness in a generation
int solution_index = 0;//index of the best of run solution
int generation_count = 0;
double sum_of_best_of_run_fitness = 0;
double best_f_run[n];
double best_f;
double worst_f;
double rbx1, rbx2, rbx3, rwx1, rwx2, rwx3;//
double standardDeviation;
double best_f_run_mean[n];
//individual
typedef struct
{
    double x1;//stores actual values of x(-1.0- 5.0)
    double x2;
    double x3;

} Individual;

Individual worst_solution;//stores an individual which is the worst individual in a run 
Individual best_solution;//stores an individual which is the best individual in a run 
Individual new_individuals[30];
double rng();
double average_fitness(double f_array[]);
double get_pi(double x, double f);
double get_f(Individual gen);
void jaya(Individual gen_array[], double f_array[]);