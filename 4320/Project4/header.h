#pragma once

#include <string>
//steven guo
//4320
//3/24/21
using namespace std;
int w = 60;//knapsack capacity
int static_penalty = 10;

//item
typedef struct
{
    int items;
    int weight;
    int value;
    int in_sack;
} Item;


void ps(Item array[], Item extreme_case_1[], Item extreme_case_2[]);
void sbt(Item array[], Item extreme_case_1[], Item extreme_case_2[]);
void lrs(Item array[], Item extreme_case_1[], Item extreme_case_2[]);
int knapSack(int w, Item array[], int n);
int max(int a, int b);
void selectionSort(Item a[], int n);