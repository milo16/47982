/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 13, 2013, 2:34 PM
 * Purpose: Program should display each employee number and ask the user to enter 
 * that employee's hours and pay rate. It should then calculate the gross wages
 * for that employee.
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//No Global constants

//Function prototypes
void getWages(long[], int[], float[], float[], int);

//Execution begins here
int main()
{
    //Declare variables
	const int SIZE = 7;
	long empId[SIZE] = {5658845, 4520125, 7895122, 8777541,
        8451277, 1302850, 7580489};
	int hours[SIZE];
	float payRate[SIZE], wages[SIZE];
    
    //get wages for each employee
	getWages(empId, hours, payRate, wages, SIZE);
    
   //Exit Stage Right
   return 0;	
}

//Displays the inputs for each employee and calculates the total gross wages of
//each employee.
void getWages(long empId[], int hours[], float payRate[], float wages[], int SIZE)
{
    
    
    for (int index = 0; index < SIZE; index++)
    {
        
        cout << "Employee number: "<<empId[index] << endl;
        cout << "Number of hours worked: ";
        cin >> hours[index];
        
        //eliminate negative numbers
        while (hours[index] < 0)
        {
            cout << "Please enter a positive number." << endl;
            cout << "Number of hours worked: ";
            cin >> hours[index];
            
        }    
        
        cout << "Employee pay rate: ";
        cin>>payRate[index];
        
        while (payRate[index] < 6.00)
        {
            cout << "Please enter a number greater or equal than 6." << endl;
            cout << "Enter pay rate: ";
            cin >> payRate[index];
            
        }    
        
        
        wages[index] = hours[index] * payRate[index];
        cout<<"Employee's gross wage: "<<wages[index]<<endl;
        cout<<endl;
        }
    }

