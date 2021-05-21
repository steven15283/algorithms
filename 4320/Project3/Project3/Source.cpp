#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include <cstdlib>
#include "header.h"
#include <time.h> 
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
	double total_f_values = 0;//holds the sum of all f values
	/*
	cout << "________________________________SINGLE RUN________________________________" << endl;

	for (int i = 0; i < n; i++)//fill array for population
	{
		population_array[i] = rng();//random number from -1.0 to 5.0
		//cout << "-=-=--==" << population_array[i].str << endl;
		f_array[i] = get_f(population_array[i]);//calculates f value of individual and puts it into an array of fitnesses
		if (f_array[i] < solution_fitness)//keeps track of the solution, i think the smallest fitness is the best solution so if it is smaller than the best solution we got then replace it with the better one
		{
			solution_index = i;//store index
			solution.str = population_array[i].str;//stores the binary number
			solution.x1_value = population_array[i].x1_value;//store values
			solution.x2_value = population_array[i].x2_value;
			solution.x3_value = population_array[i].x3_value;
			solution_fitness = f_array[i];//store fitness
		}
		total_f_values += f_array[i];//sums up the total fitness in the generation
		//cout <<"++++++++total_f_values" <<total_f_values << endl;
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
				solution.str = selection_array[i].str;//stores binary number
				solution.x1_value = selection_array[i].x1_value;//store values
				solution.x2_value = selection_array[i].x2_value;
				solution.x3_value = selection_array[i].x3_value;
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
			cout << "___________________________Generation: " << i + 1 << "___________________________" << endl;
			cout << "best fitness in current Generation: " << best_fitness(f_array) << endl;
			cout << "the x values are: " << selection_array[best_index].x1_value << ", " << selection_array[best_index].x2_value << ", " << selection_array[best_index].x3_value << endl;
			cout << "worst fitness in current Individual: " << worst_fitness(f_array) << endl;
			cout << "the x values are: " << selection_array[worst_index].x1_value << ", " << selection_array[worst_index].x2_value << ", " << selection_array[worst_index].x3_value << endl;
			cout << "average fitness of all members in current Individual: " << average_fitness(f_array) << endl;
		}

	}

	cout << "best of run solution: " << selection_array[solution_index].x1_value << ", " << selection_array[solution_index].x2_value << ", " << selection_array[solution_index].x3_value << endl;
	cout << "best of run solution fitness: " << solution_fitness << endl;

	*/
	cout << "____________________________30 INDEPENDENT RUNS___________________________" << endl;

	for (int i = 0; i < n; i++)//fill array for population
	{
		population_array[i] = rng();
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


	
	for (int y = 0; y < n; y++)//this for loop represents each run
	{
		int count = 1;//counter for intervals of 10 generations 
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
				cout << "___________________________Generation: " << i + 1 << "___________________________" << endl;
				cout << "the best-of-generation fitness average: " << sum_of_best_of_generation_fitness / i << endl;
				cout << "average-of-generation fitness; : " << sum_of_generation_fitness / i << endl;

			}

		}

		cout << "average-best-of-run fitness; : " << sum_of_best_of_run_fitness / 50 << endl;
	}
	
	return 0;

}

Individual rng()//set random number from -1.0 to 5.0
{
	//-1.0 <= Xi <= 5.0
	//2^15=32768 get number by doing this: -1.0+((n-0)/(max-0))(5-(-1))
	//2^20=1048576 get number by doing this: -1.0+((n-0)/(max-0))(5-(-1))
	//2^25=33554432 get number by doing this: -1.0+((n-0)/(max-0))(5-(-1))
	Individual bob;
	int n1,n2,n3;
	string binary_str="";
	double num1,num2,num3;
	n1 = rand() % 32768;//random number 0-32767
	//cout << n1 << endl;
	for (int i = 14; i >= 0; i--)//convert 15 bit number into binary
	{
		int k = n1 >> i;
		if (k & 1)
			binary_str += "1";
		else
			binary_str += "0";
	}
	//cout << binary_str << endl;
	bob.str = binary_str;
	binary_str = "";
	num1 = n1/(double)32768*6 -1;
	bob.x1_value = num1;
	//cout << num1 << endl;
	n2 = rand() % 1048576;//random number 0-1048575
	//cout << n2 << endl;
	for (int i = 19; i >= 0; i--)//convert 20bit number into binary
	{
		int k = n2 >> i;
		if (k & 1)
			binary_str += "1";
		else
			binary_str += "0";
	}
	//cout << binary_str << endl;
	bob.str += binary_str;//append x2 to x1
	binary_str = "";
	num2 = n2 / (double)1048576 * 6 -1;
	bob.x2_value =num2;
	//cout << num2 << endl;
	n3 = rand() % 33554432;//random number 0-33554432
	//cout << n3 << endl;
	for (int i = 24; i >= 0; i--)//convert 25bit number into binary
	{
		int k = n3 >> i;
		if (k & 1)
			binary_str += "1";
		else
			binary_str += "0";
	}
	//cout << binary_str << endl; 
	bob.str += binary_str;//append x3 to x1 and x2
	//cout << bob.str << endl;
	num3 = n3 / (double)33554432 * 6 -1;
	bob.x3_value = num3;
	//cout << num3 << endl;
	return bob;
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
			selection_array[count].str = population_array[pop_count].str;
			selection_array[count].x1_value = population_array[pop_count].x1_value;
			selection_array[count].x2_value = population_array[pop_count].x2_value;
			selection_array[count].x3_value = population_array[pop_count].x3_value;
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

	int cutpoint = rand() % 28 + 1;//crossoverpoint
	string temp1, temp2;//temporary variables to exchange parts of parents
	int randNum;//this 
	double probability = 1/(30-1);//probability of crossover
	for (int i = 0; i < n; i += 2)//increment by 2 because i will be making 2 children from 2 parents
	{
		//cout << "spc-individuals:" << sel_array[i].str << endl;
		randNum = rand() % 29;
		if (randNum == 29)
		{
			temp1 = sel_array[i].str.substr(cutpoint, 29);//gets the binary numbers from the cutpoint untill the end
			sel_array[i].str = sel_array[i].str.substr(0,cutpoint-1);//truncate the binary number excluding everything from the cutpoint and beyond
			temp2 = sel_array[i+1].str.substr(cutpoint, 29);
			sel_array[i+1].str = sel_array[i+1].str.substr(0, cutpoint-1);
			sel_array[i].str += temp2;//appends the temporary binary numbers to the first part to simulate crossover(switching the cutpoint parts of each parent)
			sel_array[i + 1].str += temp1;
		}

	}
}

void gene_wise_mutation(Individual sel_array[])
{
	int randNum;
	string x1_str, x2_str, x3_str;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (j<sel_array[i].str.length())
		{
			//10% chance for gene mutation for each bit
			randNum = (rand() % 10) + 1;//random number between 1-10
			if (randNum < 2)//excludes 1 therefore it is a 10% chance to be true
			{
				
				if (sel_array[i].str.at(j) == '1')//mutates binary string by mutating it in the opposite: if its a 1 then mutate to 0. vice versa
				{
					sel_array[i].str.at(j) = '0';
				}
				else
				{
					sel_array[i].str.at(j) = '1';
				}
				

			}
			j++;
		}
		//cout << "genewisemutaiton===== "<<sel_array[i].str << endl;
		x1_str = sel_array[i].str.substr(0, 14);//this gets x1 binary string
		x2_str = sel_array[i].str.substr(15, 34);//this gets x2 binary string
		x3_str = sel_array[i].str.substr(35, 59);//this gets x3 binary string
		string num = x1_str;//use num to convert binary to decimal
		int dec_value = 0;

		// Initializing base value to 1, i.e 2^0
		int base = 1;
		int len = num.length();
		int x1 = 0;
		for (int k = len - 1; k >= 0; k--) 
		{
			if (num[k] == '1')
				x1 += base;
			base = base * 2;
		}
		 
		num = x2_str;
		dec_value = 0;

		// Initializing base value to 1, i.e 2^0
		base = 1;
		len = num.length();
		int x2 = 0;
		for (int k = len - 1; k >= 0; k--)
		{
			if (num[k] == '1')
				x2 += base;
			base = base * 2;
		}

		num = x3_str;
		dec_value = 0;

		// Initializing base value to 1, i.e 2^0
		base = 1;
		len = num.length();
		int x3 = 0;
		for (int k = len - 1; k >= 0; k--)
		{
			if (num[k] == '1')
				x3 += base;
			base = base * 2;
		}
		sel_array[i].x1_value = x1/(double)32768*6 -1;//convert the converted binary numbers into the number from -1.0 - 5.0
		sel_array[i].x2_value = x2/(double)1048576*6 -1;
		sel_array[i].x3_value = x3/(double)33554432 *6 -1;
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
	double worst = 0.0;
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
	return ((gen.x1_value * gen.x1_value) + (gen.x2_value * gen.x2_value) + (gen.x3_value * gen.x3_value));
}

