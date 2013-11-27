/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on November 13, 2013, 7:57 PM
 * Purpose: Driver's license exam -> Program that grades the written portion
 * of the driver's license exam.
 */

//Libraries
#include <iostream>
using namespace std;

//No global constants

//Function Prototypes
void input(char[], int); 
void checkAnswers(char[], char[], int, int);

//Execution begins here
int main()
{
    //Declare Variables
    const int NUM_QUESTIONS = 20;
    const int MIN_CORRECT = 15;
    int correctAnswers = 0;	 //Accumulator for number of correct answers
    int incorrectAnswers = 0;	 //Accumulator for number of incorrect answers
    char answers[NUM_QUESTIONS] = { 'B', 'D', 'A', 'A', 'C',
    'A', 'B', 'A', 'C', 'D',
    'B', 'C', 'D', 'A', 'D',
    'C', 'C', 'B', 'D', 'A'};
    int replies;
    char stu_answers[NUM_QUESTIONS];

    //Loop for users answers
    for (replies = 0; replies < NUM_QUESTIONS; replies++){ 
        cout<< "Please enter your answers (Hint: Use capital letters): "
        << (replies + 1) << ": ";
        cin >> stu_answers[replies];

        //Validation of users answers
        while (stu_answers[replies] != 'A' && stu_answers[replies] != 'B' && stu_answers[replies] != 'C' && stu_answers[replies] != 'D')
        {
            cout << "You must enter A, B, C, or D\n";

            cout<< "Please enter your answers (Hint: Use capital letters): "
            << (replies + 1) << ": ";
            cin >> stu_answers[replies];
        }

    }

    //Calling function
    checkAnswers(answers, stu_answers, NUM_QUESTIONS, MIN_CORRECT);	
  
  //Exit Stage Right
  return 0;
}

//Function verifies if the answers are the right answers
void checkAnswers(char answers1[], char stu_answers1[], int NUM_QUESTIONS, int MIN_CORRECT)
{
    //Declare variables
    //cout << "max: " << NUM_QUESTIONS;
    int correctAnswers = 0;	
    int incorrectAnswers = 0;
    int wrongAnswers[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int j = 0;

    //Check the student's replies against the correct answers
    for (int i = 0; i < NUM_QUESTIONS; i++){
        if (answers1[i] == stu_answers1[i])
        correctAnswers++;
        else if (answers1[i] != stu_answers1[i])
        {
            incorrectAnswers++;
            wrongAnswers[j] = i + 1;
            j++;
        }
    }
    
    //Did they pass or fail?
    if (correctAnswers >= MIN_CORRECT)
    {
        cout << "\nYou must have at least 15 correct to pass.";
        cout << "\nStudent passed the exam!!!!\n\n";
    }
    else
    {
        cout << "\nYou must have at least 15 correct to pass.";
        cout <<"\nStudent failed the exam!!!!\n\n";
    }

    //Display a list of the questions that were incorrectly answered.
    cout << "The list below shows the question numbers of the incorrectly"; 
    cout << " answered questions.\n";
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (wrongAnswers[i] != 0)
        cout << "Question # " << wrongAnswers[i] << " is incorrect." << endl;
    }

    //Display the number of correct and incorrect answers provided by the student.
    cout << "\nCorrect Answers = " << correctAnswers << endl; 
    cout << "Incorrect Answers = " << incorrectAnswers << endl;
}

