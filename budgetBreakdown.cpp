#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void selection (int &choice);
void budget (double netIncome, double &savingValue);
void recommendedBudget (double totalBudget, double &savingValue);
void customBudget (double totalBudget, double &savingValue);

int main() {
  int choice;
  double netIncome = 1000;
  double savings = 0;

  selection (choice);

  while (choice != 4) {
    if (choice == 1) {
      
    } else if (choice == 2) {
      budget (netIncome, savings);
    } else {

      if(savings > 0){

      }else{
        cout << "No savings value given!" << endl;
      }

    }

    selection (choice);

    if (choice == 4) {
      cout << "Program terminating.";
      cout << savings;
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

void budget (double netIncome, double &savingValue) {
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
  cout << "2. input your own categories." << endl;
  cin >> budgetChoice;

  if (budgetChoice == 1) {
    recommendedBudget (totalBudget, savingValue);
  } else {
    customBudget (totalBudget, savingValue);
  }

}


void recommendedBudget (double totalBudget, double &savingValue) {
  cout << "We recommend following the 50/30/20 rule for budgeting." << endl;
  cout << "This means that 50% of your budget will be allocated to needs, 30% to wants, and 20% to savings and debt repayment." << endl;

  double needs, wants;

  needs = 0.5 * totalBudget;
  wants = 0.3 * totalBudget;
  savingValue = 0.2 * totalBudget;

  cout << "The amount allocated to needs is: " << needs << endl;
  cout << "The wants allocated to wants is: " << wants << endl;
  cout << "The savings allocated to savings is: " << savingValue << endl;
  
  int cont;

}

void customBudget (double totalBudget, double &savingValue) {

  int categoryCount, check = 0;
  double totalPercent = 0, totalAmount = 0, choice;
  
  cout << "Input amount of categories: " << endl;
  cin >> categoryCount;

  do{
    cout << "Will investments be an amount or percentage \n1) Amount \n2) Percent" << endl;
    cout << "Note: All remaining percentages or amounts will be added to a savings category with the option to calculate interest" << endl;
    cin >> choice;
  } while (choice != 1 && choice != 2);
  
  string category[categoryCount];
  double categoryValue[categoryCount];

  for(int i = 0; i < categoryCount; i++){
  cout << "Please input title for category " << (i + 1) << endl;
  cin >> category[i];
  }

  while(check == 0){
  totalAmount = 0;
  totalPercent = 0;
    for(int i = 0; i < categoryCount; i++){
      if(choice == 1){
        cout << "Please input amount for " << category[i] << endl;
        cin >> categoryValue[i]; 
        totalAmount = totalAmount + categoryValue[i];
      }else {
        cout << "Please input percentage for " << category[i] << (i + 1) << endl;
        cin >> categoryValue[i]; 
        totalPercent = totalPercent + categoryValue[i];
      }

    }

    if(choice == 1 && totalAmount <= totalBudget && totalAmount >= 0 || choice == 2 && totalPercent <= 100 && totalPercent >= 0){
      check = 1;
    }

  }



  for(int i = 0; i < categoryCount; i++){

  if(choice == 1){

    cout << category[i] << ": $" << categoryValue[i] << "(" << (categoryValue[i] / totalBudget * 100) << "%)" << endl;
    
  }else {

    cout << category[i] << ": $" << (categoryValue[i] * totalBudget / 100) << "(" << (categoryValue[i]) << "%)" << endl;
    
  }

}
  if(choice == 1){
    savingValue = totalBudget - totalAmount;
  }else {
    savingValue = totalBudget - (totalPercent * totalBudget / 100);
  }

  cout << "Savings: $" << savingValue << "(" << savingValue / totalBudget * 100 << "%)" << endl;

}

