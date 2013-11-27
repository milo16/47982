/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 7, 2013, 10:32 PM
 * Purpose: Rainfall statistics
 */

//Libraries
#include <iostream>
using namespace std;

//No Global constants

//Function Prototypes
float findLowest(float);
float findHighest(float);

//declare variable for functions
float rainFall[12];

//Execution begins here
int main()
{
	//Declare Variables
	int total = 0;
	float average,h,l,highest,lowest;
	
        //Loop to input the 12 values
        for(int counter = 0; counter < 12; counter++){
		cout<< "Please enter the amount of rainfall for month#" << counter + 1 << endl;
		cin >> rainFall[counter];
		total += rainFall[counter];
		
                while(rainFall[counter] < 0)//validation 
		{
			cout << "Error, please enter a number over 0 \n";
			cin >> rainFall[counter];
		}
		
	}
	
	//calculate average
	average = total / 12;

	//Display Yearly,Monthly amount of rainfall
	cout <<"The total amount of rainfall for the year is " << total << endl;
	cout <<"The average monthly rainfall for the year is " << average << endl;
	
        //Display lowest and highest value
        h=findHighest(highest);     
	l=findLowest(lowest);     
        cout << "Your highest value was " << h << endl;
        cout << "Your lowest value was " << l << endl;

  //Exit Stage Right
  return 0;
}

//Function to find highest number
float findHighest(float highest){
         highest = rainFall[0];

	 for(int counter = 1; counter < 12; counter++){
		 
             if(rainFall[counter] > highest)
		 {
			 highest = rainFall[counter];

		 }
	 }

	 
        return highest;
}

//Function to find lowest number
float findLowest(float lowest){
        lowest = rainFall[0];
        
        for(int counter = 1; counter < 12; counter++){
	      
               if(lowest > rainFall[counter])
                 {
		        lowest = rainFall[counter];
		 }

	
	     }
	 
		 return lowest;
	 }
	 

