 /******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * main.cpp -- 
 * 
 * Input: choice -- user choice of component
 * 
 * Output: 
 *
 * Authors: Jeromey Gong, Gabriel Dryer, Khang Luu, Jonathan Chen, Naseem Folami
 *
 *******************************************************************/
#include <iostream>
#include "budgetComponent.h"
#include "incomeTaxComponent.h"
#include "interestComponent.h"

using namespace std;

void selection (int &choice);

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

  selection (choice);

  while (choice != 4) {
    cout << "\nLoading component " << choice << "... " << endl;
    cout << "--------------------------------------------\n";

    if (choice == 1) {
      netIncome = netCalculator();  
    } else if (choice == 2) {
      budget(netIncome, savings);
    } else {
        interest (savings);
    }

    selection (choice);

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
