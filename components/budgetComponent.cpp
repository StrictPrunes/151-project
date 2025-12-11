 /******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * budgetComponent.cpp -- prompts and computes user budget
 *
 * Authors: Jeromey Gong and Gabriel Dryer
 *
 *******************************************************************/
#include <iostream>
#include <vector>
#include "budgetComponent.h"

using namespace std;

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
  
  do {
    //prompt for user choice of total budget
    cout << "\nSelect one of the following options: " << endl;
    cout << "1. Use net income as total budget." << endl;
    cout << "2. Use custom value." << endl;
    cin >> incomeChoice;

    if (incomeChoice != 1 && incomeChoice !=2) {
      cout << "\nInvalid input, please reenter a valid number: \n";
    }
  } while (incomeChoice != 1 && incomeChoice !=2);

  //input total budget depending on choice
  if (incomeChoice == 1){
    if (netIncome <= 0) {
      cout << "\nNo net income found" << endl;
      do {
        cout << "Please input your total budget." << endl;
        cin >> totalBudget;
      
        if (totalBudget < 0) {
          cout << "\nBudget cannot be negative, please reenter a valid number: \n";
        }
      } while (totalBudget < 0);  
    }else{
      totalBudget = netIncome;
    }
  } else {
    do {
      cout << "\nPlease input your total budget." << endl;
      cin >> totalBudget;

      if (totalBudget < 0) {
        cout << "\nBudget cannot be negative, please reenter a valid number: \n";
      }
    } while (totalBudget < 0);
  }

  //prompt for choice of budget type
  int budgetChoice;
  do {
  
    cout << "\nWould you like to: " << endl; 
    cout << "1. Use the recommended budget or" << endl;
    cout << "2. Input your own categories." << endl;
    cin >> budgetChoice;
    
    if (budgetChoice != 1 && budgetChoice !=2) {
      cout << "\nInvalid input, please reenter a valid number: \n";
    }
  } while (budgetChoice != 1 && budgetChoice !=2);

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
  cout << "\nWe recommend following the 50/30/20 rule for budgeting." << endl;
  cout << "This means that 50% of your budget will be allocated to needs, 30% to wants, and 20% to savings and debt repayment." << endl;

  double needs, wants;

  //calculate categories
  needs = 0.5 * totalBudget;
  wants = 0.3 * totalBudget;
  savingValue = 0.2 * totalBudget;

  //output results
  cout << "\nThe amount allocated to needs is: $" << needs << endl;
  cout << "The amount allocated to wants is: $" << wants << endl;
  cout << "The amount allocated to savings is: $" << savingValue << endl;

  cout << "\nReturning to selection screen...\n";
  cout << "--------------------------------------------\n\n";
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
  int choice, cont, erase;
  int check = 0;
  double totalPercent = 0;
  double totalAmount = 0;

  int i=0;
  vector<string> catName;
  vector<double> catPercent;
  vector<double> catAmount;
  string temp;   
  double tempAmount, tempPercent; 

  cout << "\nNote: All remaining percentages or amounts will be added to a savings category with the option to calculate interest" << endl;

  while (cont != 4){
    //prompt for category name
    cout << "\nPlease input title for category " << (i + 1) << ": " << endl;
    cin >> temp;
    catName.push_back(temp);
    
    //prompt for value type
    do {
      cout << "\nWill the value given to the category be an amount or a percentage: \n1) Amount \n2) Percent" << endl;
      cin >> choice;
      
      if (choice != 1 && choice !=2) {
        cout << "\nInvalid input, please reenter a valid number: \n";
      }     
    } while (choice != 1 && choice != 2);
    
    if(choice == 1){ //prompt for amount
      do {
        cout << "\nPlease input amount for " << catName[i] << " ($): " << endl;
        cin >> tempAmount;

        if (tempAmount < 0) {
          cout << "\nValue cannot be negative, please reenter a valid number: \n";
        }
      } while (tempAmount < 0);   
        
      catAmount.push_back(tempAmount); 

      //update variables
      tempPercent = catAmount[i] / totalBudget * 100;
      catPercent.push_back(tempPercent);

      totalAmount = totalAmount + catAmount[i];
      totalPercent = totalPercent + catPercent[i];
    }else { //prompt for percent
      do {
        cout << "\nPlease input percentage for " << catName[i] << " (%): " <<endl;
        cin >> tempPercent; 

        if (tempPercent < 0) {
          cout << "\nValue cannot be negative, please reenter a valid number: \n";
        }
      } while (tempPercent < 0);
       
      catPercent.push_back(tempPercent);

      //update variables
      tempAmount = catPercent[i] * totalBudget / 100;
      catAmount.push_back(tempAmount);

      totalPercent = totalPercent + catPercent[i];
      totalAmount = totalAmount + catAmount[i];
    }

    //output current categories
    cout << "\n--------------------------------------------\n";
    cout << "Current categories: \n";
    for (int i = 0; i < catName.size(); i++) {
      cout << i+1 << ". " << catName[i] << ": $" << catAmount[i] << " (" << catPercent[i] << "%)" << endl;
    }
    savingValue = totalBudget - totalAmount;
    cout << "\nAmount in savings: $" << savingValue << " (" << 100 - totalPercent << "%)" <<endl;
    
    if (totalAmount > totalBudget) {
      cout << "\nWarning: total allocated exceeds total budget.\n";
    }
   
    cout << "--------------------------------------------\n";

    i++;

    do {
      //prompt for user choice
      cout << "\nWould you like to: \n";
      cout << "1) Add more categories.\n";
      cout << "2) Erase a category.\n";
      cout << "3) Erase all categories.\n";
      cout << "4) Return to selection screen.\n";
      cin >> cont;

      if (cont != 1 && cont !=2 && cont != 3 && cont != 4) {
        cout << "\nInvalid input, please reenter a valid number: \n";
      }
    } while (cont != 1 && cont != 2 && cont != 3 && cont != 4);  

    while (cont != 4 && cont != 1) {
      if (cont == 2){ //erase one category
        cout << "\nWhich category would you like to erase (input the category number): \n";
        cin >> erase;

        //updates variables
        savingValue = savingValue + catAmount[erase-1];
        totalPercent = totalPercent - catPercent[erase-1];
        totalAmount = totalAmount - catAmount[erase-1];

        //erases from vectors
        catAmount.erase(catAmount.begin() + (erase - 1));
        catName.erase(catName.begin() + (erase - 1));
        catPercent.erase(catPercent.begin() + (erase - 1));

        i--; 
            
        //outputs new categories
        cout << "\n--------------------------------------------\n";
        cout << "Current categories: \n";
        for (int i = 0; i < catName.size(); i++) {
            cout << i+1 << ". " << catName[i] << ": $" << catAmount[i] << " (" << catPercent[i] << "%)" << endl;
        }
        cout << "\nAmount in savings: $" << savingValue << " (" << 100 - totalPercent << "%)" <<endl; 
        cout << "--------------------------------------------\n";
      } else { //erase all categories
        cout << "\nClearing all categories...\n";
        cout << "--------------------------------------------\n";

        //clear vectors
        catAmount.clear();
        catName.clear();
        catPercent.clear();
            
        //reset all variables to 0
        totalAmount = 0;
        totalPercent = 0;
        savingValue = 0;
        i=0;
      }

      do {
        //prompt for user choice
        cout << "\nWould you like to: \n";
        cout << "1) Add more categories.\n";
        cout << "2) Erase a category.\n";
        cout << "3) Erase all categories.\n";
        cout << "4) Return to selection screen.\n";
        cin >> cont;

        if (cont != 1 && cont !=2 && cont != 3 && cont != 4) {
          cout << "\nInvalid input, please reenter a valid number: \n";
        }
      } while (cont != 1 && cont != 2 && cont != 3 && cont != 4);
    }
    
    //return to selection screen
    if (cont == 4) {
      cout << "\nReturning to selection screen...\n";
      cout << "--------------------------------------------\n\n";
    }
  }
}

