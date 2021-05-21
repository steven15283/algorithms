#pragma once

#include <string>
//steven guo
//4320
//2/14/21
using namespace std;
const int n = 30;// constant for population size
const double pc = 0.8;//percentage for single point crossover
const double pm = 0.1;//percentage for gene mutation
const int maxGen = 50;//maximum amount of generations
const double delta = 6 / 1000;//delta for gene mutation
int best_index = 0;//index of the best fitness in a generation
int worst_index = 0;//index of the worst fitness in a generation
int solution_index = 0;//index of the best of run solution
double solution_fitness = 0;//best of run solution fitness
int generation_count = 0;
double sum_of_generation_fitness = 0;//accumulate the sum of the total fitness in a generation
double sum_of_best_of_generation_fitness = 0;// accumulate the sum of the best of generation fitness
double sum_of_best_of_run_fitness = 0;
//individual
typedef struct
{
    string str;//stores the binary number
    double x1_value;//stores actual values of x(-1.0- 5.0)
    double x2_value;
    double x3_value;

} Individual;


Individual selection_array[n];//selection array
Individual solution;//stores an individual which is the best individual in a run 
Individual rng();
void proportional_selection(Individual gen_array[], double pi_array[]);
void single_point_crossover(Individual sel_array[]);
void gene_wise_mutation(Individual sel_array[]);
double average_fitness(double f_array[]);
double best_fitness(double array[]);
double worst_fitness(double array[]);
double get_pi(double x, double f);
double get_f(Individual gen);


