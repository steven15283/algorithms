#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "header.h"
#include <time.h> 
#include <cmath>


//steven guo 
//project4 for 4320
//3/24/21
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int choice;
	Item arr[20];
	Item extreme_case_1[20];
	Item extreme_case_2[20];

	for (int i = 0; i < 20; i++)//initialize extreme casesthe one where all items can fit into knapsack)
	{
		extreme_case_1[i].items = i;
		extreme_case_1[i].weight = 1;//set weight to 1 for each item. so it always goes into knapsack
		extreme_case_1[i].value = rand() % 10 + 1;
		extreme_case_1[i].in_sack = 0;
	}

	for (int i = 0; i < 20; i++)//initialize extreme cases(the one where no items can fit into knapsack)
	{
		extreme_case_2[i].items = i;
		extreme_case_2[i].weight = 100;//set weight to 100 so no items go into knapsack
		extreme_case_2[i].value = rand() % 10 + 1;
		extreme_case_2[i].in_sack = 0;
	}
	
	cout << "enter 1-3 to choose which selection method to use" << endl;
	cout << "1. proportional selection" << endl;
	cout << "2. stochastic binary tournament" << endl;
	cout << "3. linear ranking selection" << endl;
	
	cin >> choice;

	switch (choice)
	{
		case 1:
			ps(arr, extreme_case_1, extreme_case_2);
			break;

		case 2:
			sbt(arr, extreme_case_1, extreme_case_2);
			break;

		case 3:
			lrs(arr, extreme_case_1, extreme_case_2);
			break;

		default:
			cout << "enter correct number of 1-3" << endl;
	}


	return 0;

}

void ps(Item array[], Item extreme_case_1[], Item extreme_case_2[])
{
	int sum;//sums up all values 
	double rand_pi;//random pi for selection
	int count;
	double pi_array[20];
	double avg_value = 0;
	double value;
	int capacity;
	Item new_array[20];
	double avg_capacity = 0;
	double avg_weight = 0;
	for (int y = 0; y < 10; y++)
	{
		capacity = 0;
		for (int i = 0; i < 20; i++)
		{
			array[i].items = i;
			array[i].weight = rand() % 10 + 1;
			array[i].value = rand() % 10 + 1;
			array[i].in_sack = 0;
		}

		sum = 0;
		for (int i = 0; i < 20; i++)
		{
			sum += array[i].value;//gets sum of values in population for pi
		}


		for (int i = 0; i < 20; i++)
		{
			pi_array[i] = (double)array[i].value / sum;//get pi for each item
		}


		count = 0;
		do
		{
			rand_pi = rand() / double(RAND_MAX);//random number 0-1 for selection
			if (rand_pi > pi_array[count])
			{
				new_array[count] = array[count];
				count++;
			}
		} while (count < 20);
		value = knapSack(w, array, 19);//gets best value of knapSack recursive run
		avg_value += (double)value;
		cout << "value: " << value << endl;
		cout << "binary output" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << array[i].in_sack;
			if (array[i].in_sack == 1)
			{
				capacity += array[i].weight;
			}
		}
		cout << endl;
		cout << "capacity: " << capacity << endl;
		avg_capacity += (double)capacity;
		cout << "Weights" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << array[i].weight << " ";
			avg_weight += (double)array[i].weight;
		}
		cout << endl;
		cout << "values" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << array[i].value << " ";
		}
		cout << endl;
	}
	capacity = 0;
	cout << "average value: " << avg_value / 10 << endl;
	cout << "average capacity: " << avg_capacity / 10 << endl;
	cout << "average weight: " << avg_weight / 10 << endl;
	cout << "extreme case where all items fit into knapsack" << endl;
	value = knapSack(w, extreme_case_1, 19);
	cout << "value: " << value << endl;
	cout << "binary output" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].in_sack;
		if (extreme_case_1[i].in_sack == 1)
		{
			capacity += extreme_case_1[i].weight;
		}
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "Weights" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].weight << " ";
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "values" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].value << " ";
	}
	cout << endl;

	cout << "extreme case where all items don't fit into knapsack" << endl;
	value = knapSack(w, extreme_case_2, 19);
	cout << "value: " << value << endl;
	cout << "binary output" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].in_sack;
		if (extreme_case_2[i].in_sack == 1)
		{
			capacity += extreme_case_2[i].weight;
		}
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "Weights" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].weight << " ";
	}
	cout << endl;
	cout << "values" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].value << " ";
	}
	cout << endl;
	
}

void sbt(Item array[], Item extreme_case_1[], Item extreme_case_2[])
{
	int capacity;
	double avg_value = 0;
	double value;
	double p = 0.8;
	Item new_array[20];//new array to store items that pass the tournament
	int count;
	int rand_num1, rand_num2, rand_chance;//rand num1 and num2 grab random items in population for tournament. rand chance is the chance for 
	double avg_capacity = 0;
	double avg_weight = 0;
	for (int y = 0; y < 10; y++)
	{
		count = 0;
		capacity = 0;
		for (int i = 0; i < 20; i++)
		{
			array[i].items = i;
			array[i].weight = rand() % 10 + 1;
			array[i].value = rand() % 10 + 1;
			array[i].in_sack = 0;
		}

		do
		{
			rand_num1 = rand() % 20;
			rand_num2 = rand() % 20;
			rand_chance = rand() % 10 + 1;
			if (rand_chance > 2)
			{
				if (array[rand_num1].value >= array[rand_num2].value)
				{
					new_array[count] = array[rand_num1];
				}
				else
				{
					new_array[count] = array[rand_num2];
				}
				count++;
			}

		} while (count < 20);
		value = knapSack(w, new_array, 19);
		avg_value += (double)value;
		cout << "value: " << value << endl;
		cout << "binary output" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << new_array[i].in_sack;
			if (new_array[i].in_sack == 1)
			{
				capacity += new_array[i].weight;
			}
		}
		cout << endl;
		cout << "capacity: " << capacity << endl;
		avg_capacity += (double)capacity;
		cout << "Weights" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << new_array[i].weight << " ";
			avg_weight += (double)new_array[i].weight;
		}
		cout << endl;
		cout << "values" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << new_array[i].value << " ";
		}
		cout << endl;
	}
	cout << "average value: " << avg_value / 10 << endl;
	cout << "average capacity: " << avg_capacity / 10 << endl;
	cout << "average weight: " << avg_weight / 10 << endl;
	cout << "extreme case where all items fit into knapsack" << endl;
	value = knapSack(w, extreme_case_1, 19);
	cout << "value: " << value << endl;
	cout << "binary output" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].in_sack;
		if (extreme_case_1[i].in_sack == 1)
		{
			capacity += extreme_case_1[i].weight;
		}
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "Weights" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].weight << " ";
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "values" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].value << " ";
	}
	cout << endl;

	cout << "extreme case where all items don't fit into knapsack" << endl;
	value = knapSack(w, extreme_case_2, 19);
	cout << "value: " << value << endl;
	cout << "binary output" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].in_sack;
		if (extreme_case_2[i].in_sack == 1)
		{
			capacity += extreme_case_2[i].weight;
		}
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "Weights" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].weight << " ";
	}
	cout << endl;
	cout << "values" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].value << " ";
	}
	cout << endl;
}

void lrs(Item array[], Item extreme_case_1[], Item extreme_case_2[])
{
	int capacity;
	double avg_value = 0;
	double value;
	double avg_capacity = 0;
	double avg_weight = 0;
	for (int y = 0; y < 10; y++)
	{
		capacity = 0;
		for (int i = 0; i < 20; i++)
		{
			array[i].items = i;
			array[i].weight = rand() % 10 + 1;
			array[i].value = rand() % 10 + 1;
			array[i].in_sack = 0;
		}

		selectionSort(array, 20);//sort array
		value = knapSack(w, array, 19);
		avg_value += (double)value;
		cout << "value: " << value << endl;
		cout << "binary output" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << array[i].in_sack;
			if (array[i].in_sack == 1)
			{
				capacity += array[i].weight;
			}
		}
		cout << endl;
		cout << "capacity: " << capacity << endl;
		avg_capacity += (double)capacity;
		cout << "Weights" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << array[i].weight << " ";
			avg_weight += (double)array[i].weight;
		}
		cout << endl;
		cout << "values" << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << array[i].value << " ";
		}
		cout << endl;
	}
	cout << "average value: " << avg_value / 10 << endl;
	cout << "average capacity: " << avg_capacity / 10 << endl;
	cout << "average weight: " << avg_weight / 10 << endl;
	cout << "extreme case where all items fit into knapsack" << endl;
	value = knapSack(w, extreme_case_1, 19);
	cout << "value: " << value << endl;
	cout << "binary output" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].in_sack;
		if (extreme_case_1[i].in_sack == 1)
		{
			capacity += extreme_case_1[i].weight;
		}
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "Weights" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].weight << " ";
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "values" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_1[i].value << " ";
	}
	cout << endl;

	cout << "extreme case where all items don't fit into knapsack" << endl;
	value = knapSack(w, extreme_case_2, 19);
	cout << "value: " << value << endl;
	cout << "binary output" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].in_sack;
		if (extreme_case_2[i].in_sack == 1)
		{
			capacity += extreme_case_2[i].weight;
		}
	}
	cout << endl;
	cout << "capacity: " << capacity << endl;
	cout << "Weights" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].weight << " ";
	}
	cout << endl;
	cout << "values" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << extreme_case_2[i].value << " ";
	}
	cout << endl;
}



int knapSack(int w, Item array[], int n)
{
	// Base Case
	if (n == 0||w == 0)
		return 0;

	// If weight of the nth item is more than the knapsack value, then dont include
	if (array[n - 1].weight > w)
	{
		array[n-1].in_sack = 0;
		
		return knapSack(w, array, n - 1);
	}
	else
	{
		// Return the maximum of two cases and include
		array[n-1].in_sack = 1;
		return max(array[n - 1].value + knapSack(w - array[n - 1].weight, array, n - 1), knapSack(w, array, n - 1));

	}
}

int max(int a, int b) //returns the max of two numbers
{ 
	return (a > b) ? a : b; 
}

void selectionSort(Item a[], int n) //selection sort for linear ranking selection
{

	Item i, min, temp;
	for (int i = 0; i < n - 1; i++) 
	{
		min = a[i];
		for (int j = i + 1; j < n; j++)
		{
			if (a[j].weight < min.weight)
				min = a[j];
		}
			
		temp = a[i];
		a[i] = min;
		min = temp;
	}
}
