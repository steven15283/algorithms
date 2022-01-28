#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include <cstdlib>
#include "header.h"
#include <ctime>
#include <cmath>


//steven guo 
//project1 for 4320
//2/14/21
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	Individual population_array[n];//generate array of 30 members
	double pi_array[n];//array to hold the pi values of each member
	double f_array[n];//array to hold the f values of each member
	double total_f_values=0;//holds the sum of all f values
	clock_t start;
	double duration;
	cout << "________________________________SINGLE RUN________________________________" << endl;
	cout << "__________________________roulette wheel sampling______________________________" << endl;
	start = clock();
	for (int i = 0; i < n; i++)//fill array for population
	{
		population_array[i].x1 = rng();//random number from -1.0 to 5.0
		population_array[i].x2 = rng();
		population_array[i].x3 = rng();
		f_array[i] = get_f(population_array[i]);//calculates f value of individual and puts it into an array of fitnesses
		if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
		{
			solution_index = i;//store index
			solution.x1 = population_array[i].x1;//store values
			solution.x2 = population_array[i].x2;
			solution.x3 = population_array[i].x3;
			solution_fitness = f_array[i];//store fitness
		}
		total_f_values += f_array[i];//sums up the total fitness in the generation
	}
	
	for (int i = 0; i < n; i++)//finds pi values of the individuals
	{
		pi_array[i] = get_pi(f_array[i], total_f_values);//puts pi values into array corresponding to individual
	}
	proportional_selection(population_array, pi_array);

	single_point_crossover(selection_array);

	gene_wise_mutation(selection_array);

	int count = 1;//counter for intervals of 10 generations 
	for (int i = 1; i < maxGen; i++)
	{
		for (int i = 0; i < n; i++)
		{
			f_array[i] = get_f(selection_array[i]);//calculates f value of individuals and puts it into an array of fitnesses
			if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
			{
				solution_index = i;//store index
				solution.x1 = selection_array[i].x1;//store values
				solution.x2 = selection_array[i].x2;
				solution.x3 = selection_array[i].x3;
				solution_fitness = f_array[i];//store fitness
			}
			total_f_values += f_array[i];//sums up the total fitness in the generation
			
		}
		for (int i = 0; i < n; i++)//finds pi values of the individuals
		{
			pi_array[i] = get_pi(f_array[i], total_f_values);//puts pi values into array corresponding to individual
		}
		proportional_selection(selection_array, pi_array);
		single_point_crossover(selection_array);
		gene_wise_mutation(selection_array);
		count++;
		
			if (count == 10)//outputs information
			{
				count = 0;
				cout << "___________________________Generation: "<< i+1<<"___________________________" << endl;
				cout << "best fitness in current Generation: "<< best_fitness(f_array) << endl;
				cout << "the x values are: " << selection_array[best_index].x1 << ", " << selection_array[best_index].x2 << ", " << selection_array[best_index].x3 << endl;
				cout << "worst fitness in current Individual: "<< worst_fitness(f_array) << endl;
				cout << "the x values are: " << selection_array[worst_index].x1<< ", " << selection_array[worst_index].x2 << ", " << selection_array[worst_index].x3 << endl;
				cout << "average fitness of all members in current Individual: " << average_fitness(f_array) << endl;
			}
		
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "duration: " << duration << endl;

	cout << "best of run solution: " << selection_array[solution_index].x1 << ", " << selection_array[solution_index].x2 << ", " << selection_array[solution_index].x3 <<endl;
	cout << "best of run solution fitness: " << solution_fitness<< endl;

	cout << "__________________________Stochastic universal sampling______________________________" << endl;
	for (int i = 0; i < n; i++)//fill array for population
	{
		population_array[i].x1 = rng();//random number from -1.0 to 5.0
		population_array[i].x2 = rng();
		population_array[i].x3 = rng();
		f_array[i] = get_f(population_array[i]);//calculates f value of individual and puts it into an array of fitnesses
		if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
		{
			solution_index = i;//store index
			solution.x1 = population_array[i].x1;//store values
			solution.x2 = population_array[i].x2;
			solution.x3 = population_array[i].x3;
			solution_fitness = f_array[i];//store fitness
		}
		total_f_values += f_array[i];//sums up the total fitness in the generation
	}
	
	for (int i = 0; i < n; i++)//finds pi values of the individuals
	{
		pi_array[i] = get_pi(f_array[i], total_f_values);//puts pi values into array corresponding to individual
	}
	Stochastic_universal_sampling(population_array, f_array);

	single_point_crossover(selection_array);

	gene_wise_mutation(selection_array);

	count = 1;//counter for intervals of 10 generations 
	for (int i = 1; i < maxGen; i++)
	{
		for (int i = 0; i < n; i++)
		{
			f_array[i] = get_f(selection_array[i]);//calculates f value of individuals and puts it into an array of fitnesses
			if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
			{
				solution_index = i;//store index
				solution.x1 = selection_array[i].x1;//store values
				solution.x2 = selection_array[i].x2;
				solution.x3 = selection_array[i].x3;
				solution_fitness = f_array[i];//store fitness
			}
			total_f_values += f_array[i];//sums up the total fitness in the generation
			
		}
		for (int i = 0; i < n; i++)//finds pi values of the individuals
		{
			pi_array[i] = get_pi(f_array[i], total_f_values);//puts pi values into array corresponding to individual
		}
		Stochastic_universal_sampling(selection_array, f_array);
		single_point_crossover(selection_array);
		gene_wise_mutation(selection_array);
		count++;
		
			if (count == 10)//outputs information
			{
				count = 0;
				cout << "___________________________Generation: "<< i+1<<"___________________________" << endl;
				cout << "best fitness in current Generation: "<< best_fitness(f_array) << endl;
				cout << "the x values are: " << selection_array[best_index].x1 << ", " << selection_array[best_index].x2 << ", " << selection_array[best_index].x3 << endl;
				cout << "worst fitness in current Individual: "<< worst_fitness(f_array) << endl;
				cout << "the x values are: " << selection_array[worst_index].x1<< ", " << selection_array[worst_index].x2 << ", " << selection_array[worst_index].x3 << endl;
				cout << "average fitness of all members in current Individual: " << average_fitness(f_array) << endl;
			}
		
	}
	
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "duration: " << duration << endl;
	cout << "best of run solution: " << selection_array[solution_index].x1 << ", " << selection_array[solution_index].x2 << ", " << selection_array[solution_index].x3 << endl;
	cout << "best of run solution fitness: " << solution_fitness << endl;

	cout << "__________________________deterministic sampling______________________________" << endl;
	
	for (int i = 0; i < n; i++)//fill array for population
	{
		population_array[i].x1 = rng();//random number from -1.0 to 5.0
		population_array[i].x2 = rng();
		population_array[i].x3 = rng();
		f_array[i] = get_f(population_array[i]);//calculates f value of individual and puts it into an array of fitnesses
		if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
		{
			solution_index = i;//store index
			solution.x1 = population_array[i].x1;//store values
			solution.x2 = population_array[i].x2;
			solution.x3 = population_array[i].x3;
			solution_fitness = f_array[i];//store fitness
		}
		total_f_values += f_array[i];//sums up the total fitness in the generation
	}

	for (int i = 0; i < n; i++)//finds pi values of the individuals
	{
		pi_array[i] = get_pi(f_array[i], total_f_values);//puts pi values into array corresponding to individual
	}
	Deterministic_sampling(population_array, pi_array);

	single_point_crossover(selection_array);

	gene_wise_mutation(selection_array);

	count = 1;//counter for intervals of 10 generations 
	for (int i = 1; i < maxGen; i++)
	{
		for (int i = 0; i < n; i++)
		{
			f_array[i] = get_f(selection_array[i]);//calculates f value of individuals and puts it into an array of fitnesses
			if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
			{
				solution_index = i;//store index
				solution.x1 = selection_array[i].x1;//store values
				solution.x2 = selection_array[i].x2;
				solution.x3 = selection_array[i].x3;
				solution_fitness = f_array[i];//store fitness
			}
			total_f_values += f_array[i];//sums up the total fitness in the generation

		}
		for (int i = 0; i < n; i++)//finds pi values of the individuals
		{
			pi_array[i] = get_pi(f_array[i], total_f_values);//puts pi values into array corresponding to individual
		}
		Deterministic_sampling(selection_array, pi_array);
		single_point_crossover(selection_array);
		gene_wise_mutation(selection_array);
		count++;

		if (count == 10)//outputs information
		{
			count = 0;
			cout << "___________________________Generation: " << i + 1 << "___________________________" << endl;
			cout << "best fitness in current Generation: " << best_fitness(f_array) << endl;
			cout << "the x values are: " << selection_array[best_index].x1 << ", " << selection_array[best_index].x2 << ", " << selection_array[best_index].x3 << endl;
			cout << "worst fitness in current Individual: " << worst_fitness(f_array) << endl;
			cout << "the x values are: " << selection_array[worst_index].x1 << ", " << selection_array[worst_index].x2 << ", " << selection_array[worst_index].x3 << endl;
			cout << "average fitness of all members in current Individual: " << average_fitness(f_array) << endl;
		}

	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;//calculates the duration of algorithm
	cout << "duration: " << duration << endl;
	cout << "best of run solution: " << selection_array[solution_index].x1 << ", " << selection_array[solution_index].x2 << ", " << selection_array[solution_index].x3 << endl;
	cout << "best of run solution fitness: " << solution_fitness << endl;
	cout << "____________________________30 INDEPENDENT RUNS___________________________" << endl;
	
	
	for (int y = 0; y < n; y++)//this for loop represents each run
	{
		for (int i = 0; i < n; i++)//fill array for population
		{
			population_array[i].x1 = rng();//random number from -1.0 to 5.0
			population_array[i].x2 = rng();
			population_array[i].x3 = rng();
			f_array[i] = get_f(population_array[i]);//calculates f value of individual and puts it into an array of fitnesses
			if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
			{
				sum_of_best_of_run_fitness += f_array[i];
			}
			total_f_values += f_array[i];//sums up the total fitness in the generation
		}

		for (int i = 0; i < n; i++)//finds pi values of the individuals
		{
			pi_array[i] = get_pi(f_array[i], total_f_values);//puts pi values into array corresponding to individual
		}
		proportional_selection(population_array, pi_array);

		single_point_crossover(selection_array);

		gene_wise_mutation(selection_array);

		sum_of_best_of_generation_fitness += best_fitness(f_array);// accumulate the sum of the best of generation fitness
		sum_of_generation_fitness += total_f_values;//accumulate the sum of the total fitness in a generation
		count = 1;//counter for intervals of 10 generations 

		for (int i = 1; i < maxGen; i++)//this for loop represents each generation
		{
			for (int a = 0; a < n; a++)
			{
				f_array[a] = get_f(selection_array[a]);//calculates f value of individuals and puts it into an array of fitnesses
				if (f_array[a] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
				{
					sum_of_best_of_run_fitness += f_array[a];//store fitness
				}
				total_f_values += f_array[a];//sums up the total fitness in the generation

			}

			for (int b = 0; b < n; b++)//finds pi values of the individuals
			{
				pi_array[b] = get_pi(f_array[b], total_f_values);//puts pi values into array corresponding to individual
			}

			proportional_selection(selection_array, pi_array);
			single_point_crossover(selection_array);
			gene_wise_mutation(selection_array);

			sum_of_best_of_generation_fitness += best_fitness(f_array);// accumulate the sum of the best of generation fitness
			sum_of_generation_fitness += total_f_values;//accumulate the sum of the total fitness in a generation
			count++;

			if (count == 10)//outputs information
			{
				count = 0;
				cout << "___________________________Generation: " << i+1 << "___________________________" << endl;
				cout << "the best-of-generation fitness average: " << sum_of_best_of_generation_fitness / i << endl;
				cout << "average-of-generation fitness; : " << sum_of_generation_fitness / i << endl;

			}
		}
		cout << "average-best-of-run fitness; : " << sum_of_best_of_run_fitness/ 50 << endl;
	}
	
	
	return 0;

}

double rng()//return random number from -1.0 to 5.0
{
	//-1.0 <= Xi <= 5.0
	double f = (double)rand() / RAND_MAX;
	return -1.0 + f * 6.0;
}

void proportional_selection(Individual population_array[], double pi_array[])
{//this function compares the pi values from each individual and makes a check to be selected for the generation
	double u;
	int count = 0;//keeps track of how many individuals have been selected
	int pop_count = 0;//keeps track of population index
		do
		{
			u = rand() / double(RAND_MAX);//range from 0 to 1
			if (u < pi_array[count])//check if the individual is selected
			{
				selection_array[count].x1 = population_array[pop_count].x1;
				selection_array[count].x2 = population_array[pop_count].x2;
				selection_array[count].x3 = population_array[pop_count].x3;
				count++;
			}
			pop_count++;
			if (pop_count > 29)//this is for when it has to cycle through the population again for selection process
			{
				pop_count = 0;
			}
		} while (count < 30);//this will fill the selection array with 30 individuals
	
}


void single_point_crossover(Individual sel_array[])
{
	
	int coinflip = (rand() % 2) + 1;//decides the point of crossover. there is only 2 points so its a coinflip
	double temp1,temp2,temp3;//temporary variables to exchange parts of parents
	int randNum;//this 
	for (int i = 0; i < n; i += 2)//increment by 2 because i will be making 2 children from 2 parents
	{
		if (coinflip == 1)//the crossover is between x1,x2
		{
			randNum = (rand() % 10) + 1;//rand Num is a number between 1-10
			if (randNum < 9)//excludes 9 and 10 which means 80% of the time it will be true
			{
				temp2 = sel_array[i].x2;//store parent1's x2 into temp variable
				temp3 = sel_array[i].x3;//store parent1's x3 into temp variable
				sel_array[i].x2 = sel_array[i + 1].x2;//replace parent1's x2 with parent2's x2
				sel_array[i].x3 = sel_array[i + 1].x3;//replace parent1's x3 with parent2's x3
				sel_array[i + 1].x2 = temp2;//replace parent2's x2 with temp variable 
				sel_array[i + 1].x3 = temp3;//replace parent2's x2 with temp variable 
				
			}
		}
		else//the crossover is between x2,x3
		{
			randNum = (rand() % 10) + 1;
			if (randNum < 9)
			{
				temp1 = sel_array[i].x1;//store parent1's x1 into temp variable
				temp2 = sel_array[i].x2;//store parent1's x2 into temp variable
				sel_array[i].x1 = sel_array[i + 1].x1;//replace parent1's x1 with parent2's x1
				sel_array[i].x2 = sel_array[i + 1].x2;//replace parent1's x2 with parent2's x2
				sel_array[i + 1].x1 = temp1;//replace parent2's x1 with temp variable 
				sel_array[i + 1].x2 = temp2;//replace parent2's x2 with temp variable 
			}
		}

	}
}

void gene_wise_mutation(Individual sel_array[])
{
	int randNum;
	int coinFlip;//this determines if i subtract the delta or add it
	for (int i = 0; i < n; i++)
	{
		//10% chance for gene mutation for x1
		randNum = (rand() % 10) + 1;//random number between 1-10
		if (randNum < 2)//excludes 1 therefore it is a 10% chance to be true
		{
			coinFlip = (rand() % 2) + 1;
			if (coinFlip == 1)//subtract delta
			{
				sel_array[i].x1 -= delta;
				if (sel_array[i].x1 < -1.0)
				{
					sel_array[i].x1 = -1.0;
				}
			}
			else
			{
				sel_array[i].x1 += delta;
				if (sel_array[i].x1 > 5.0)
				{
					sel_array[i].x1 = 5.0;
				}
			}
				
		}

		//10% chance for gene mutation for x2
		randNum = (rand() % 10) + 1;
		if (randNum < 2)
		{
			coinFlip = (rand() % 2) + 1;
			if (coinFlip == 1)
			{
				sel_array[i].x2 -= delta;
				if (sel_array[i].x1 < -1.0)
				{
					sel_array[i].x1 = -1.0;
				}
			}
			else
			{
				sel_array[i].x2 += delta;
				if (sel_array[i].x2 > 5.0)
				{
					sel_array[i].x2 = 5.0;
				}
			}

		}

		//10% chance for gene mutation for x3
		randNum = (rand() % 10) + 1;
		if (randNum < 2)
		{
			coinFlip = (rand() % 2) + 1;
			if (coinFlip == 1)
			{
				sel_array[i].x3 -= delta;
				if (sel_array[i].x3 < -1.0)
				{
					sel_array[i].x3 = -1.0;
				}
			}
			else
			{
				sel_array[i].x3 += delta;
				if (sel_array[i].x3 > 5.0)
				{
					sel_array[i].x3 = 5.0;
				}
			}

		}
		
	}
	
}


double average_fitness(double array[])//returns the average fitness
{
	double sum=0;
	for (int i = 0; i < n; i++)
	{
		sum += array[i];
	}
	return sum / (double)n;
}

double best_fitness(double array[])//returns the best fitness
{
	double best = 1000.00;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < best)
		{
			best = array[i];
			best_index = i;
		}
	}
	return best;
}

double worst_fitness(double array[])//returns the worst fitness
{
	double worst=0.0 ;
	for (int i = 0; i < n; i++)
	{
		if (array[i] > worst)
		{
			worst = array[i];
			worst_index = i;
		}
	}
	return worst;
}

double get_pi(double x, double f)//returns pi 
{
	return x / f;
}


double get_f(Individual gen)//returns f
{
	return ((gen.x1 * gen.x1) + (gen.x2 * gen.x2) + (gen.x3 * gen.x3));
}

void Stochastic_universal_sampling(Individual gen_array[], double f_array[])
{
	double s_array[n];//array to hold the length values of each member for Stochastic universal sampling
	double probe = rand();
	double length = 0;

	for (int i = 0; i < n; i++)//this fills an array of 30 elements that represent each individual in the population with the length of 
	{
		length+= f_array[i] / 30;
		if (length > 1)//wrap around condition
		{
			length -= 1;//wrap around to front
		}
		s_array[i] = length;//puts total length into array assigned to each  indvidual
		
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s_array[j] <= probe )//checks if the probe is within the range of the individual.
			{
				if (s_array[j - 1] > probe)//search through length array to find the individual that it belongs to
				{
					selection_array[i].x1 = gen_array[i].x1;//put individual into selection 
					selection_array[i].x2 = gen_array[i].x2;
					selection_array[i].x3 = gen_array[i].x3;
					probe += (1 / 30);//increments probe by 1/30
					break;
				}
				
			}
		}
	}
}

void Deterministic_sampling(Individual gen_array[], double pi_array[])
{
	double e_array[n];//array to hold the integer values of each member
	double fractpart, intpart;//holds the integer and fractional part of the double
	int sum=0;//sum of the ei 
	int remainder;//n-sum(ei)
	int temp;//temporary variable

	for (int i = 0; i < 30; i++)//puts integer numbers into array
	{
		
		fractpart = modf(pi_array[i] * 30 , &intpart);//gets fractional part of pi*n
		e_array[i] = intpart;//puts pi*n into array
	}
	
	for (int i = 0; i < n; i++)//sort e array
	{
		for (int j = i + 1; j < n; j++)
		{
			if (e_array[i] > e_array[j])
			{
				temp = e_array[i];
				e_array[i] = e_array[j];
				e_array[j] = temp;
			}
		}
	}

	for (int i = 0; i < 30; i++)//get sum of all values in e array
	{
		sum += e_array[i];
	}
	
	remainder = 30 - sum;//get remainder
	int top_num=29;//this is to get highest number
	for (int i = 1; i < remainder+1; i++)
	{
		selection_array[sum + i].x1 = gen_array[top_num].x1;//put the individual into selection
		selection_array[sum + i].x2 = gen_array[top_num].x2;
		selection_array[sum + i].x3 = gen_array[top_num].x3;
		top_num--;//decrement position of highest number to get next higher number
	}
}