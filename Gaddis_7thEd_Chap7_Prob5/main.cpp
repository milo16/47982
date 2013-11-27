/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 13, 2013, 8:28 PM
 * Purpose: Program that reads the weather data in from a file.
 */

//Libraries
#include <iostream>
#include <fstream>
using namespace std;

// Global constants
const int MONTHS = 3;
const int DAYS = 30;

// function prototypes.
void readDataFromFile(char arr[][DAYS], int size);
void showMonthlyReport(char arr[][DAYS], int size);
void showTotalReport(int rainy, int cloudy, int sunny);
void monthWithMostRain(char arr[][DAYS], int size);

// Execution begins here
int main()
{
	// Declare variables
	char weatherStatistics[MONTHS][DAYS];

	// header.
	cout << "\tRain or Shine :::\n\n";

	// read the file.
	readDataFromFile(weatherStatistics, MONTHS);

	// report
	showMonthlyReport(weatherStatistics, MONTHS);

	// monthly
	monthWithMostRain(weatherStatistics, MONTHS);

	cout << endl;
        
        //Exit Stage Right
	return 0;
}

// readDataFromFile function "RainOrShine.dat" and read its characters into an
// array. Then close the file.
void readDataFromFile(char arr[][DAYS], int size)
{
	// open file.
	ifstream inputFile("RainOrShine.dat");
	
	// read data.
        cout << "Reading weather data...\n";
	for (int nRow = 0; nRow < size; nRow++)
	{
		for (int nCol = 0; (nCol < DAYS) && (inputFile >> arr[nRow][nCol]); nCol++)
		{
			
		}
		cout << "\nWriting Row[" << (nRow)<<"]...\n";
	}

	// close file.
	inputFile.close();
	cout << "Done, closing file...\n" << endl;
}


//Monthly Report function
// Show report for each month with how many days were rainy, cloudy and how many were sunny.
void showMonthlyReport(char arr[][DAYS], int size)
{
	// pass by value to next function.
	static int totalRainy = 0;
	int totalCoudy = 0;
	int totalSunny = 0;
	int totalMismatch = 0;

	cout << "Report:\n";
	cout << "This will show how many days were: rainy, cloudy or sunny.\n";
	cout << "-----------------------------------------------------------\n";

	for (int nRows = 0; nRows < size; nRows++)
	{
		// counters.
		int rainy = 0;
		int cloudy = 0;
		int sunny = 0;
		int mismatch = 0;

		for (int nCols = 0; nCols < DAYS; nCols++)
		{
			// check if rainy, cloudy or sunny.
			if (arr[nRows][nCols] == 'R')
			{
				rainy++;
				totalRainy++;
			}
			else if ((arr[nRows][nCols] == 'C'))
			{
				cloudy++;
				totalCoudy++;
			}
			else if ((arr[nRows][nCols] == 'S'))
			{
				sunny++;
				totalSunny++;
			}
			else
			{
				mismatch++;
				cout << "ERROR: inaccurate results! Found ";
				cout << mismatch << " mismatched character(s)" << endl;
				totalMismatch++;
			}
		}
		// monthly report.
		cout << "Month " << (nRows + 1);
		cout << ": Rain (" << rainy;
		cout << ") - Cloudy (" << cloudy;
		cout << ") - Sunny (" << sunny;
		cout << ")" << endl;
	}

	// send
	showTotalReport(totalRainy, totalCoudy, totalSunny);
}

// showTotalReport function
// Get data from showMonthlyReport and show totals.
void showTotalReport(int rainy, int cloudy, int sunny)
{
	cout << "\nStatistics from total months.\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Rain (" << rainy;
	cout << ") - Cloudy (" << cloudy;
	cout << ") - Sunny (" << sunny;
	cout << ")" << endl;
}

// Get the month with the most rain.
void monthWithMostRain(char arr[][DAYS], int size)
{
	char months[3][7] = {"June", "July", "August"};
	int subscript = -1;
	int rainy = 0;
	int highest = 0;

	for (int nRows = 0; nRows < size; nRows++)
	{
		for (int nCols = 0; nCols < DAYS; nCols++)
		{			
			// check if rainy.
			if (arr[nRows][nCols] == 'R')
			{
				rainy++;
			}
		}
		// check highest.
		if (rainy > highest)
		{
			highest = rainy;
			subscript++;
		}
		rainy = 0;
	}
	cout << "\nThe month " << months[subscript] << " had the most rain." << endl;
}

