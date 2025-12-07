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
  double netIncome = 0;
  double savings = 0;

  selection (choice);

  while (choice != 4) {
    if (choice == 1) {
    
    } else if (choice == 2) {
        budget(netIncome, savings);
    } else {
      if(savings > 0){

      }else{
        cout << "No savings value given!" << endl;
      }
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

void budget (double netIncome, double &savingValue) {
  int incomeChoice;
  double totalBudget;
  
  cout << "Select 1 or 2" << endl;
  cout << "1. Use net income as total budget" << endl;
  cout << "2. Use custom value" << endl;
  cin >> incomeChoice;

  if (incomeChoice == 1){
    if (netIncome <= 0) {
      cout << "No net income found" << endl;
      cout << "Please input your total budget." << endl;
      cin >> totalBudget;
    }else{
      totalBudget = netIncome;
    }
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
}

void customBudget (double totalBudget, double &savingValue) {
  string cont;
  int choice;
  int check = 0;
  double totalPercent = 0;
  double totalAmount = 0;

  int i=0;
  vector<string> catName;
  vector<double> catPercent;
  vector<double> catAmount;
  string temp;   
  double tempAmount, tempPercent; 

  cout << "Note: All remaining percentages or amounts will be added to a savings category with the option to calculate interest" << endl << endl;
  
  while (cont != "N" && cont != "n"){
    cout << "Please input title for category " << (i + 1) << endl;
    cin >> temp;
    catName.push_back(temp);
    
    do{
      cout << "Will investments be an amount or percentage \n1) Amount \n2) Percent" << endl;
      cin >> choice;
    } while (choice != 1 && choice != 2);
    
    if(choice == 1){
      cout << "Please input amount for " << catName[i] << endl;
      cin >> tempAmount;
      catAmount.push_back(tempAmount); 

      tempPercent = catAmount[i] / totalBudget * 100;
      catPercent.push_back(tempPercent);

      totalAmount = totalAmount + catAmount[i];
      totalPercent = totalPercent + catPercent[i];
    }else {
      cout << "Please input percentage for " << catName[i] << endl;
      cin >> tempPercent; 
      catPercent.push_back(tempPercent);

      tempAmount = catPercent[i] * totalBudget / 100;
      catAmount.push_back(tempAmount);

      totalPercent = totalPercent + catPercent[i];
      totalAmount = totalAmount + catAmount[i];
    }

    cout << "\n-------------------------------------\n";
    cout << "Current categories: \n";
    for (int i = 0; i < catName.size(); i++) {
      cout << catName[i] << ": $" << catAmount[i] << " (" << catPercent[i] << "%)" << endl;
    }

    cout << "\nAmount remaining: $" << totalBudget - totalAmount << " (" << 100 - totalPercent << "%)" <<endl;

    cout << "\nWould you like to add more categories? (Y/N)";
    cin >> cont;

    if (cont == "N" || cont == "n") {
      cout << "\nReturning to selection screen...\n";
      cout << "-------------------------------------\n\n";
    }

    i++;
  }
}
