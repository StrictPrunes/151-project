#include <iostream>

using namespace std;

void selection (int &choice);
void budget ();
void recommendedBudget (double totalBudget);
void customBudget (doubel totalBudget);

int main() {
  int choice;

  selection (choice);

  while (choice != 4) {
    if (choice == 1) {
      
    } else if (choice == 2) {
      budget ();
    } else {

    }

    selection (choice)

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

void budget () {
  int incomeChoice;
  double totalBudget;
  
  cout << "Select 1 or 2" << endl;
  cout << "1. Use net income as total budget" << endl;
  cout << "2. Use custom value" << endl;
  cin >> incomeChoice;

  if (incomeChoice == 1){
    totalBudget = netIncome;
  } else {
    cout << "Please input your total budget." << endl;
    cin >> totalBudget;
  }

  int budgetChoice;
  cout << "Would you like to: " << endl; 
  cout << "1. use the recommended budget or" << endl;
  cout << "2. input your own categories." << endl
  cin >> budgetChoice;

  if (budgetChoice == 1) {
    recommendedBudget (totalBudget);
  } else {
    customBudget (totalBudget);
  }

}


void recommendedBudget (double totalBudget) {
  cout << "We recommend following the 50/30/20 rule for budgeting." << endl;
  cout << "This means that 50% of your budget will be allocated to needs, 30% to wants, and 20% to savings and debt repayment." << endl;

  double needs, wants, savings;

  needs = 0.5 * totalBudget;
  wants = 0.3 * totalBudget;
  savings = 0.2 * totalBudget;

  cout << "The amount allocated to needs is: " << needs << endl;
  cout << "The wants allocated to needs is: " << wants << endl;
  cout << "The savings allocated to needs is: " << savings << endl;
  
  int cont;
    
  cout << "Would you like to edit the budget or use a different component."
  cout << "
  cin << cont;

   while (cont != 2} {
      cout << "

      cout << "Would you like to edit the budget or use a different component."
      cout << "
      cin << cont;

      if (cont == 2) {
        cout << "Returning to selection screen." << endl;
      }
   }

}

void customBudget (doubel totalBudget) {
  string category[100];
  double categoryValue[100];
  
  cout << "Please input the first category and the value associated with it" << endl;
  cin >> category[0] >>
    
  while (

}
