 /******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * main.cpp -- 
 *
 * Authors: Jeromey Gong, Gabriel Dryer, Khang Luu, Jonathan Chen, Naseem Folami
 *
 *******************************************************************/
#include <iostream>
#include <iomanip>
#include "budgetComponent.h"
#include "incomeTaxComponent.h"
#include "interestComponent.h"

using namespace std;

void selection (int &choice); //prompts user to choose a component

/******************************************************************
 * main -
 *
 * Parameters: none
 * Modifies: nothing
 *
 * Returns: 0
 *******************************************************************/
int main() {
  int choice;
  double netIncome = 0;
  double savings = 0;

  selection (choice); //prompts user for component choice

  cout << fixed << setprecision(2); //all values expressed to two decimal places

  while (choice != 4) {
    //loading message
    cout << "\nLoading component " << choice << "... " << endl;
    cout << "--------------------------------------------\n";

    //load component depending on user choice
    if (choice == 1) {
      netIncome = netCalculator();  
    } else if (choice == 2) {
      budget(netIncome, savings);
    } else {
        interest (savings);
    }

    selection (choice); //reprompt for component

    //if user selects choice for, display termination message and exit loop
    if (choice == 4) {
      cout << "\nProgram terminating.";
    }
  }

  return 0;  
}
 /******************************************************************
 * selection -- prompts for users choice of component
 *
 * Parameters: choice -- user choice of component
 * 
 * Modifies: choice -- user choice of component
 *
 * Precondition: none
 *
 * Returns: nothing
 *******************************************************************/
void selection (int &choice) {
  cout << "Select the component you would like to use: " << endl;
  cout << "1. Net income calculator." << endl;
  cout << "2. Budget breakdown." << endl;
  cout << "3. Interest calculator." << endl;
  cout << "4. Exit program." << endl;

  cin >> choice;
}
