/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 20, 2013, 2:23 PM
 * Purpose: Program that lets the user enter four quarterly sales figures 
 * for six divisions of a company.
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants
const int DIVISIONS = 3;
const int QUARTERLY = 4;

//Function prototypes
void getQuarterlySales(float arr[][QUARTERLY], int size);
void showTotalPerDivision(float arr[][QUARTERLY], int size);
void showDivisionSalesDifferences(float arr[][QUARTERLY], int size);
void ShowTotalPerQuarter(float arr[][QUARTERLY], int size);
void showQuarterlySalesDifferences(float arr[][QUARTERLY], int size);
void averageSalesPerQuarter(float arr[][QUARTERLY], int size);
void highestSalesDivQuarter(float arr[][QUARTERLY], int size);

//Execution begins here
int main()
{
	// Declare variables
	float sales[DIVISIONS][QUARTERLY];

	// header
	cout << "\tQuarterly Sales :: Statistics\n\n";
	cout << "Enter the sales figures for every quarter:\n";
	cout << "------------------------------------------\n";

	// get quarterly sales.
	getQuarterlySales(sales, DIVISIONS);

	// show sales figures for each division.
	showTotalPerDivision(sales, DIVISIONS);

	// show increase or decrease for each division.
	showDivisionSalesDifferences(sales, DIVISIONS);

	// show totals for each quarter.
	ShowTotalPerQuarter(sales, DIVISIONS);

	// show increase or decrease for each quarter.
	showQuarterlySalesDifferences(sales, DIVISIONS);

	// average sales.
	averageSalesPerQuarter(sales, DIVISIONS);

	// show division with highest sales.
	highestSalesDivQuarter(sales, DIVISIONS);
        
        //Exit Stage Right
	return 0;
}

// Get the sales from 6 divisions of 4 quarterlies.
void getQuarterlySales(float arr[][QUARTERLY], int size)
{
	for (int nRows = 0; nRows < size; nRows++)
	{
		// division.
		cout << "Division " << (nRows + 1) << endl;
		for (int nCols = 0; nCols < QUARTERLY; nCols++)
		{
			// quarter.
			float sale;			
			cout << " Quarter " << (nCols + 1) << ": $";
			cin >> arr[nRows][nCols];
			while (arr[nRows][nCols] < 0)
			{
				cout << "ERROR: sales cannot be lower than 0, try again: ";
				cin >> sale;
			}
		}
		
		cout << endl;
	}
}

// Get the totals from each division and show them.
void showTotalPerDivision(float arr[][QUARTERLY], int size)
{
	// header
	cout << "\nTotal(s) per Division(s):\n";
	cout << "-------------------------\n";

	// set formatting.
	cout << fixed << setprecision(2);

	for (int nRows = 0; nRows < size; nRows++)
	{
		float total = 0;	// accumulator.
		for (int nCols = 0; nCols < QUARTERLY; nCols++)
		{
			total += arr[nRows][nCols];
		}
		cout << "Total sales for Division " << (nRows + 1)
			 << ": $" << total << endl;
	}
}

// Calculate how much each quarter increased/decreased the sale
// by comparison of the previous quarter.
void showDivisionSalesDifferences(float arr[][QUARTERLY], int size)
{
	float prevQuarter = 0;		// hold sale for previous quarter.
	for (int nRows = 0; nRows < size; nRows++)
	{
		// division.
		cout << "\nDivision " << (nRows + 1) << endl;
		float sales = 0;				// hold sale for quarter.

		for (int nCols = 0; nCols < QUARTERLY; nCols++)
		{
			sales += arr[nRows][nCols];		// add to sales total.
			
			// check for differences and show them.
			if (nCols == 0)
			{
				prevQuarter = sales;		// skipping first quarter.
			}
			else
			{
				if (sales > prevQuarter)
				{
					cout << " Quarter " << (nCols + 1) << ": $+"
						 << (sales - prevQuarter) << endl;
				}
				else if (sales < prevQuarter)
				{
					cout << " Quarter " << (nCols + 1) << ": $"
						<< (sales - prevQuarter) << endl;
				}
				else
				{
					cout << " Quarter " << (nCols + 1) << ": ";
					cout << "no increment/decrement over last quarter." << endl;
				}
			}		
			
			prevQuarter = sales;	// set prevQuarter to new sales
			sales = 0;				// reinitialize sales.
		}
	}
}

// Show total sales for each division per quarter.
void ShowTotalPerQuarter(float arr[][QUARTERLY], int size)
{
	// header
	cout << "\nQuarterly Total(s):\n";
	cout << "-------------------\n";
	for (int nCols = 0; nCols < QUARTERLY; nCols++)
	{
		float total = 0;
		for (int nRows = 0; nRows < size; nRows++)
		{
			total += arr[nRows][nCols];
		}
		cout << "Quarter " << (nCols + 1) << ": $"
			 << total << endl;
	}
}

// Get the company's increase or decrease from the previous quarter.
void showQuarterlySalesDifferences(float arr[][QUARTERLY], int size)
{
	cout << endl;
	float totalPrevQuarter = 0;
	for (int nCols = 0; nCols < QUARTERLY; nCols++)
	{
		float sales = 0;
		for (int nRows = 0; nRows < size; nRows++)
		{
			sales += arr[nRows][nCols];
		}
		// check differences
		if (nCols == 0)
		{
			totalPrevQuarter += sales;
		}
		else
		{
			if (sales > totalPrevQuarter)
			{
				cout << "Quarter " << (nCols + 1) << ": $+"
					<< (sales - totalPrevQuarter) << endl;
				totalPrevQuarter = sales;
			}
			else if (sales < totalPrevQuarter)
			{
				cout << "Quarter " << (nCols + 1) << ": $"
					<< (sales - totalPrevQuarter) << endl;
				totalPrevQuarter = sales;
			}
			else
			{
				cout << "Quarter " << (nCols + 1) << ": "
					<< "no increment/decrement over last quarter."
					<< endl;
				totalPrevQuarter = sales;
			}			
		}
	}
}

// Get the average sales for all division per quarter.
void averageSalesPerQuarter(float arr[][QUARTERLY], int size)
{
	{
		cout << "\nAverage Quarterly sale(s):\n";
		cout << "--------------------------\n";
		for (int nCols = 0; nCols < QUARTERLY; nCols++)
		{
			float total = 0;
			for (int nRows = 0; nRows < size; nRows++)
			{
				total += arr[nRows][nCols];
			}
			cout << "Quarter " << (nCols + 1) << ": $"
				<< (total / size) << endl;
		}
	}
}

// Find the division that sells the most during a quarter and display it.
void highestSalesDivQuarter(float arr[][QUARTERLY], int size)
{
	float highest = 0;		// hold highest value.
	int division = 0;		// hold division subscript.

	for (int nCol = 0; nCol < QUARTERLY; nCol++)
	{
		for (int nRow = 0; nRow < size; nRow++)
		{
			if (arr[nRow][nCol] > highest)
			{
				highest = arr[nRow][nCol];
				division++;
			}
		}
		cout << "\nDivision " << division << " has the highest sales for this quarter.\n";
		division = 0;
		highest = 0;
	}
}

