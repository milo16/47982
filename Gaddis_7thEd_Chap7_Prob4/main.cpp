/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 8, 2013, 12:12 AM
 * Purpose: Program that stores how many pounds of food each of its three monkeys
 * eats each day.
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants
const int MONKEYS = 3;
const int DAYS = 7;

//function prototypes
void getFood(float arr[][DAYS], int rows);
void avgFood(float arr[][DAYS], int rows);
void leastAmount(float arr[][DAYS], int rows);
void greatestAmount(float arr[][DAYS], int rows);

//Execution begins here
int main()
{
	//declare variables
	float food[MONKEYS][DAYS];

	//header
	cout << "\tMonkey Business :::\n\n";
	cout << "Enter the food each monkey eats (in pounds) during the week.\n\n";

	//get food
	getFood(food, MONKEYS);

	cout << "Report:\n";
	cout << "----------------------\n";

	//get average.
	avgFood(food, MONKEYS);

	//get least amount in that week.
	leastAmount(food, MONKEYS);

	//get greatest amount in that week.
	greatestAmount(food, MONKEYS);

	//Exit Stage Right
	return 0;
}


// Takes three arguments. It asks the user to enter the food in
// pounds that each monkey eats, for every day in a single week.
void getFood(float arr[][DAYS], int rows)
{
	for (int nRows = 0; nRows < rows; nRows++)
	{
		cout << "Monkey " << (nRows + 1) << "\n";
		for (int nCols = 0; nCols < DAYS; nCols++)
		{
			cout << " Day " << (nCols + 1) << ": ";
			cin >> arr[nRows][nCols];
			// validate.
			while (arr[nRows][nCols] < 0)
			{
				cout << "ERROR: food cannot be lower than 0, try again: ";
				cin >> arr[nRows][nCols];
			}
		}
		
		cout << endl;
	}
}



// Gets the average food each monkey eats during the week. It
// will then show a message on the screen.
void avgFood(float arr[][DAYS], int rows)
{
	float total = 0;	// accumulator.

	cout << "Average food a day for " << MONKEYS;
	cout << " monkeys: ";

	for (int nRows = 0; nRows < rows; nRows++)
	{
		for (int nCols = 0; nCols < DAYS; nCols++)
			total += arr[nRows][nCols];
	}

	// set formatting.
	cout << fixed << setprecision(2);
	cout << (total / MONKEYS) << " pounds.\n" << endl;
}


// Get from each monkey the least amount of food eaten
// during the week.
void leastAmount(float arr[][DAYS], int rows)
{
	for (int nRows = 0; nRows < rows; nRows++)
	{
		float least = arr[0][0];
		int day = 0;	// accumulator.
		for (int nCols = 0; nCols < DAYS; nCols++)
		{
			if (arr[nRows][nCols] < least)
			{
				least = arr[nRows][nCols];
				day += (nCols + 1);
			}
		}
		cout << "On day " << day;
		cout << " monkey " << (nRows + 1);
		cout << " ate the least amount of food.\n";
	}
	
	cout << endl;	
}


// greatest Amount eaten during the week
void greatestAmount(float arr[][DAYS], int rows)
{
	for (int nRows = 0; nRows < rows; nRows++)
	{
		float greatest = arr[0][0];
		int day = 0;	// accumulator.
		for (int nCols = 0; nCols < DAYS; nCols++)
		{
			if (arr[nRows][nCols] > greatest)
			{
				greatest = arr[nRows][nCols];
				day += (nCols + 1);
			}
		}
		cout << "On day " << day;
		cout << " monkey " << (nRows + 1);
		cout << " ate the greatest amount of food.\n";
	}
	
	cout << endl;	
}


