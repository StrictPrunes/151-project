 /******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * budgetComponent.h -- prompts and computes user budget
 * 
 * Input: -
 * 
 * Output: 
 *
 * Authors: Jeromey Gong and Gabriel Dryer
 *
 *******************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void budget (double netIncome, double &savingValue);
void recommendedBudget (double totalBudget, double &savingValue);
void customBudget (double totalBudget, double &savingValue);

 /******************************************************************
 * budget -- provides user choice for budget selection
 *
 * Parameters: netIncome -- the users net income if calculated previously
 *             savingValue -- amount of savings
 * 
 * Modifies: savingValue -- amount of savings
 *
 * Precondition: none
 *
 * Returns: nothing
 *******************************************************************/
void budget (double netIncome, double &savingValue) {
  int incomeChoice;
  double totalBudget;
  
  cout << "\nSelect one of the following options: " << endl;
  cout << "1. Use net income as total budget." << endl;
  cout << "2. Use custom value." << endl;
  cin >> incomeChoice;

  if (incomeChoice == 1){
    if (netIncome <= 0) {
      cout << "\nNo net income found" << endl;
      cout << "Please input your total budget." << endl;
      cin >> totalBudget;
    }else{
      totalBudget = netIncome;
    }
  } else {
    cout << "\nPlease input your total budget." << endl;
    cin >> totalBudget;
  }

  int budgetChoice;
  cout << "\nWould you like to: " << endl; 
  cout << "1. Use the recommended budget or" << endl;
  cout << "2. Input your own categories." << endl;
  cin >> budgetChoice;

  if (budgetChoice == 1) {
    recommendedBudget (totalBudget, savingValue);
  } else {
    customBudget (totalBudget, savingValue);
  }

}

 /******************************************************************
 * recommendedBudget -- computes recommended budget
 *
 * Parameters: totalBudget -- user's total budget
 *             savingValue -- amount of savings
 * 
 * Modifies: savingValue -- amount of savings
 *
 * Precondition: none
 *
 * Returns: nothing
 *******************************************************************/
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

 /******************************************************************
 * customBudget -- prompts for users choice of budget category and value
 *
 * Parameters: totalBudget -- user's total budget
 *             savingValue -- amount of savings
 * 
 * Modifies: savingValue -- amount of savings
 *
 * Precondition: none
 *
 * Returns: nothing
 *******************************************************************/
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

  while (cont != "N" && cont != "n"){
    cout << "\nPlease input title for category " << (i + 1) << ": " << endl;
    cin >> temp;
    catName.push_back(temp);
    
    do{
      cout << "\nWill the value given to the category be an amount or a percentage: \n1) Amount \n2) Percent" << endl;
      cin >> choice;
    } while (choice != 1 && choice != 2);
    
    if(choice == 1){
      cout << "\nPlease input amount for " << catName[i] << ": " << endl;
      cin >> tempAmount;
      catAmount.push_back(tempAmount); 

      tempPercent = catAmount[i] / totalBudget * 100;
      catPercent.push_back(tempPercent);

      totalAmount = totalAmount + catAmount[i];
      totalPercent = totalPercent + catPercent[i];
    }else {
      cout << "\nPlease input percentage for " << catName[i] << ": " <<endl;
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
