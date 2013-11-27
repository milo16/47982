/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 13, 2013, 3:38 PM
 * Purpose: Program that lets a maker of chips and salsa keep track of sales
 * for five different types of salsa: mild, medium, sweet, hot, and zesty.
 */

//Libraries
#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

//No Global constants

// Function prototypes
int getTotal(int [], int);
int posOfSmallest(int [], int);
int posOfLargest(int [], int);

//Execution begins here
int main()
{
    //Declare variables
   const int NUM_TYPES = 5;   
   int sales[NUM_TYPES];
   string name[NUM_TYPES] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
  

   // Create the arrays for the names and sales amounts
   
   int totalJarsSold,
       hiSalesProduct,
       loSalesProduct;
     
   // Input the number of jars sold

	for (int type = 0; type < NUM_TYPES; type++)
	{
		cout << "Jars sold last month of " << name[type] << ": ";
      	        cin  >> sales[type];
      
		while (sales[type] < 0)
		{	cout << "Jars sold must be 0 or more.  Please re-enter: ";
		        cin  >> sales[type];
		}
	}

   
   // Call functions to get total sales and high and low selling products
   totalJarsSold  = getTotal(sales, NUM_TYPES);
   loSalesProduct = posOfSmallest(sales, NUM_TYPES);
   hiSalesProduct = posOfLargest(sales, NUM_TYPES);
   
   // Produce the sales report
   cout << endl << endl;
   cout << "     Salsa Sales Report \n\n";
   cout << "Name              Jars Sold \n";
   cout << "____________________________\n";
 
   
	   cout << name[0] << "                  " << sales[0] << "\n";
       cout << name[1] << "                " << sales[1] << "\n";
	   cout << name[2] << "                 " <<sales[2] << "\n";
	   cout << name[3] << "                   " << sales[3] << "\n";
	   cout << name[4] << "                 " << sales[4] << "\n";  

      // Outputs 
   
   cout << "\nTotal Sales:" << setw(15) << totalJarsSold << endl;
   cout << "High Seller: "  << name[hiSalesProduct] << endl;
   cout << "Low Seller : " << name[loSalesProduct] << endl;    
    
   //Exit Staqe Right
   return 0;
}


//Calculates and returns the total of the values                       
 int getTotal (int array[], int numElts)
{
	int total = 0;

	for (int type = 0; type < numElts; type++)
		total += array[type];
	return total;
}

 //Finds the salsa with highest sales                                              
 int posOfLargest(int array[], int numElts)
{
	int indexOfLargest = 0;
	
	for (int pos = 1; pos < numElts; pos++)
	{
		if (array[pos] > array[indexOfLargest])
			indexOfLargest = pos;
	}
	
        return indexOfLargest;
}


 //Finds salsa with lower sales                                            
 int posOfSmallest(int array[], int numElts)
{
	int indexOfSmallest = 0;
	
	for (int pos = 1; pos < numElts; pos++)
	{
		if (array[pos] < array[indexOfSmallest])
			indexOfSmallest = pos;
	}		
	
        return indexOfSmallest;
}

