/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 7, 2013, 10:12 PM
 * Purpose: Program that lets user enter 10 values into an array. Then it should
 * display the largest and smallest values stored in the array.
 */

//Libraries
#include <iostream>
using namespace std;

//No global constants

//No function prototypes

//Execution begins here
int main (){
    //Declare variables
    int mn,mx;
    const int NUMB = 10;
    int a[NUMB]; //10 elements
    
    //Prompts for inputs
    cout<<"Enter 10 values:"; 
    for(int i=0;i<10;i++)
    {
    cout<< "\nEnter value: ";
    cin>> a[i]; // puts values in array
    }

    mn=a[0];
    mx=a[0];
    for(int i=1;i<10;i++)
            {
                    if(mn>a[i])
                    {
                            mn=a[i];
                    }
                    else if(mx<a[i])
                    {
                            mx = a[i];
                    }
            }
    
    //Outputs maximum and minimum number
    cout<<"Maximum number is: "<< mx << endl;
    cout<<"Minimum number is: "<< mn << endl;

   //Exit Stage Right
   return 0;

}

