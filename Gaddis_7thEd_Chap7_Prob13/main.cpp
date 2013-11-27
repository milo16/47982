/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 13, 2013, 3:07 PM
 * Purpose: Lottery Application
 */

//Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

 //Global Constants
const int lotteryDigits = 10;
const int SIZE = 5;

// Function Prototypes
int generateLottery(int[], int, int);
int userInput(int[], int);
int matchCounter(int[], int[], int);
void displayNumbers(int[], int[]);
void winnerOrLoser(int);

//Execution begins here
int main()
{
	// Declare variables
	int lottery[5] = {0, 0, 0, 0, 0};
	int user[5] = {0, 0, 0, 0, 0};
	int matches = 0;

	//Function Calls
	generateLottery(lottery, SIZE, lotteryDigits);

	userInput(user, SIZE);

	matches = matchCounter(lottery, user, matches);

	displayNumbers(lottery, user);

	winnerOrLoser(matches);

	//Exit Stage Right
	return 0;
} 

// Randomly generates winning lottery numbers
int generateLottery(int lottery[], int, int)
{
	unsigned seed = time(0);
	srand(seed);

	for (int y=0; y<SIZE; y++)
	{
		lottery[y] = rand() % lotteryDigits;
	}
	
	return lottery[0], lottery[1], lottery[2], lottery[3], lottery[4];
} 


// Reads user lottery number choices
int userInput(int user[], int)
{	
	cout << "This program will simulate a lottery.\n\n";

	for (int y=0; y<SIZE; y++)
	{
		cout << "Enter digit #"<<y+1<<" of 5 between 0 and 9:---> ";
		cin >> user[y];

		while (user[y]<0 || user[y]>9)
		{
		cout << "Error! Entry must be between 0 and 9:---> ";
		cin >> user[y];
		}
	}

	return user[0], user[1], user[2], user[3], user[4];
} 


// Counts the number of matches
int matchCounter(int lotto[], int input[], int)
{
	int match = 0;

	for (int x = 0; x < SIZE; ++x)
	{
		if (lotto[x] == input[x])
			match = match + 1;
	}

	return match;
}

// Diplays the winning numbers and the user's numbers
void displayNumbers(int lottery[], int user[])
{
	cout << "\nThe winning lottery numbers are: " << lottery[0] << " " << lottery[1] << " " << lottery[2] << " " << lottery[3] << " " << lottery[4] << endl;
	cout << "Your lottery numbers are: " << user[0] << " " << user[1] << " " << user[2] << " " << user[3] << " " << user[4] << endl;
} 


//Displays the number of matches and whether or not the user has won
void winnerOrLoser(int matches)
{
	cout << "You matched " << matches << " numbers";

	if (matches != SIZE)
		cout << "\nSorry--you lose. Better luck next time.\n";
	else
		cout << "\nCongratulations--you WIN!!!!\n";
		
}

