#include <iostream>
#include <iomanip>
#include <vector>
#include "budgetComponent.h"
#include "incomeTaxComponent.h"
#include "interestComponent.h"

using namespace std;

void selection (int &choice);

int main() {
  int choice;
  double netIncome = 0;
  double savings = 0;

  selection (choice);

  while (choice != 4) {
    if (choice == 1) {
      netIncome = netCalculator();  
    } else if (choice == 2) {
      budget(netIncome, savings);
    } else {
        interest (savings);
    }

    selection (choice);

    if (choice == 4) {
      cout << "Program terminating.";
    }
  }

  return 0;  
}

void selection (int &choice) {
  cout << "Select the component you would like to use" << endl;
  cout << "1. Net income calculator." << endl;
  cout << "2. Budget breakdown." << endl;
  cout << "3. Interest calculator." << endl;
  cout << "4. Exit program." << endl;

  cin >> choice;
}
