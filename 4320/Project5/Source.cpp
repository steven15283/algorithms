#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include <cstdlib>
#include "header.h"
#include <time.h> 
#include <cmath>


//steven guo 
//project5 for 4320
//4/30/21
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	Individual population_array[n];//generate array of 30 members
	double pi_array[n];//array to hold the pi values of each member
	double f_array[n];//array to hold the f values of each member
	
	for (int i = 0; i < n; i++)//fill array for population
	{
		population_array[i].x1 = rng();//random number from -1.0 to 5.0
		population_array[i].x2 = rng();
		population_array[i].x3 = rng();
		f_array[i] = get_f(population_array[i]);//calculates f value of individual and puts it into an array of fitnesses
	}

	jaya(population_array, f_array);

	int count = 0;
	for (int y = 0; y < n; y++)//this for loop represents each run
	{
		
		best_f = 100;
		worst_f = 0;
		for (int i = 1; i < maxGen; i++)//this for loop represents each generation
		{
			for (int a = 0; a < n; a++)
			{
				f_array[a] = get_f(new_individuals[a]);//calculates f value of individuals and puts it into an array of fitnesses
			}

			jaya(new_individuals, f_array);
			sum_of_best_of_run_fitness += best_f;
		}

		cout << "best of run fitness: " << best_f << endl;
		cout << "best of run vector = (" << best_solution.x1 << ", " << best_solution.x2 << ", " << best_solution.x3 << ")" << endl;
		best_f_run[count] = best_f;
		cout << "average-best-of-run fitness : " << sum_of_best_of_run_fitness / 50 << endl;
		best_f_run_mean[count] = sum_of_best_of_run_fitness / 50;
		count++;

	}
	double sum_of_means = 0;
	for (int i = 0; i < 30; ++i)
	{
		standardDeviation += pow(best_f_run[i] - (best_f_run_mean[i]), 2);
		sum_of_means += best_f_run_mean[i];
	}
	double sd_f = sqrt(standardDeviation / 30);
	cout << "average-best-of-30run fitness: " << sum_of_means/30 << endl;
	cout << "standardDeviation-best-of-30run fitness : " << sd_f << endl;
	return 0;

}
void jaya(Individual gen_array[], double f_array[])
{
	//set random parameters
	rbx1 = rand() / double(RAND_MAX);
	rbx2 = rand() / double(RAND_MAX); 
	rbx3 = rand() / double(RAND_MAX); 
	rwx1 = rand() / double(RAND_MAX); 
	rwx2 = rand() / double(RAND_MAX); 
	rwx3 = rand() / double(RAND_MAX);
	Individual bob;//new individual
	double bob_f; //fitness for new individual
	//find best and worst individuals in population
	for (int i = 0; i < n; i++)
	{
		if (f_array[i] < best_f)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
		{
			best_solution.x1 = gen_array[i].x1;//store values
			best_solution.x2 = gen_array[i].x2;
			best_solution.x3 = gen_array[i].x3;
			best_f = f_array[i];//store fitness
		}
		if (f_array[i] > worst_f)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
		{
			worst_solution.x1 = gen_array[i].x1;//store values
			worst_solution.x2 = gen_array[i].x2;
			worst_solution.x3 = gen_array[i].x3;
			worst_f = f_array[i];//store fitness
		}
	}

	
	//create new individual using current,best,worst and random parameters
	for (int i = 0; i < n; i++)
	{
		bob.x1 = gen_array[i].x1 + rbx1 * (best_solution.x1 - abs(gen_array[i].x1)) - rwx1 * (worst_solution.x1 - abs(gen_array[i].x1));
		//cap values of vectors to -1 -5
		if (bob.x1 > 5)
		{
			bob.x1 = 5;
		}
		if (bob.x1 < -1)
		{
			bob.x1 = -1;
		}
		bob.x2 = gen_array[i].x2 + rbx2 * (best_solution.x2 - abs(gen_array[i].x2)) - rwx2 * (worst_solution.x2 - abs(gen_array[i].x2));
		if (bob.x2 > 5)
		{
			bob.x2 = 5;
		}
		if (bob.x2 < -1)
		{
			bob.x2 = -1;
		}
		bob.x3 = gen_array[i].x3 + rbx3 * (best_solution.x3 - abs(gen_array[i].x3)) - rwx3 * (worst_solution.x3 - abs(gen_array[i].x3));
		if (bob.x3 > 5)
		{
			bob.x3 = 5;
		}
		if (bob.x3 < -1)
		{
			bob.x3 = -1;
		}
		bob_f = ((bob.x1 * bob.x1) + (bob.x2 * bob.x2) + (bob.x3 * bob.x3));//get f value of new individual
		//check to see if new individual is better than the current individual
		if (bob_f < f_array[i])//individual is better so it replaces current individual
		{
			new_individuals[i].x1 = bob.x1;
			new_individuals[i].x2 = bob.x2;
			new_individuals[i].x3 = bob.x3;
		}
		else
		{//individual is worse so current individual stays the same
			new_individuals[i].x1 = gen_array[i].x1;
			new_individuals[i].x2 = gen_array[i].x2;
			new_individuals[i].x3 = gen_array[i].x3;
		}

	}
	 
}

double average_fitness(double array[])//returns the average fitness
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += array[i];
	}
	return sum / (double)n;
}


double get_pi(double x, double f)//returns pi 
{
	return x / f;
}

double get_f(Individual gen)//returns f
{
	return ((gen.x1 * gen.x1) + (gen.x2 * gen.x2) + (gen.x3 * gen.x3));
}

double rng()//return random number from -1.0 to 5.0
{
	//-1.0 <= Xi <= 5.0
	double f = (double)rand() / RAND_MAX;
	return -1.0 + f * 6.0;
}

