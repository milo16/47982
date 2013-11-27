/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 13, 2013, 7:17 PM
 * Purpose: Grade Book -> program that should allow the user to enter each student's name
 * and his or her four scores. Then it should display each student's average.
 */

//Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//No global constants

//function prototype
char letterGrade(float score);

//Execution begins here
int main(){
    //Declare variables
    char names[5][25]; //student names
    char grades[5]; //letter grades
    float scores[5][4]; //test scores
    float avgScore[5]; //average of 4 test scores
    
    //gets student name and
    //his 4 test scores from the keyboard
    for(int i=0;i<5;i++){
        cout<<"\nEnter student "<<(i+1)<<" name: ";
        cin>>names[i];
        cout<<"Enter his 4 scores: ";

        for(int j=0;j<4;j++){
            cin>>scores[i][j];
            //validating test score
            while(scores[i][j] > 100 || scores[i][j] <0){
            cout<<"\ntest score should between 0 and 100"<<endl;
            cout<<"enter test score: ";
            cin>>scores[i][j];
       }
    }
    
  }
    
    //finding average score of each student
    //and letter grade
    for(int i=0;i<5;i++){
        avgScore[i] = 0;
        for(int j=0;j<4;j++)
        avgScore[i] += scores[i][j];
        avgScore[i] /= 4;
        grades[i] = letterGrade(avgScore[i]);
     }

    //displaying average test score and letter grade
    cout<<"\nStudent Name\tAverage Score\tLetter Grade"<<endl;
    for(int i=0;i<5;i++){
        cout<<names[i]<<"\t\t"<<setprecision(2)<<avgScore[i]<<"\t\t"<<grades[i]<<endl;
    }
    
    //Exit Stage Right
    return 0;
}

//return letter grade based on the test score
//passed as parameter
char letterGrade(float score){
    if(score >= 90 && score <=100)
    return 'A';
    else if(score >= 80 && score <90)
    return 'B';
    else if(score >= 70 && score <80)
    return 'C';
    else if(score >= 60 && score <70)
    return 'D';
    else
    return 'F';
}



