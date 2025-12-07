#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void selection (int &choice);
void budget (double netIncome, double &savingValue);
void recommendedBudget (double totalBudget, double &savingValue);
void customBudget (double totalBudget, double &savingValue);
double netCalculator();

struct TaxBracket{
  double limit;
  double rate;
};

double calculateTax(double income, const vector<TaxBracket> &brackets);

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

  cout << "The amount allocated to needs is: $" << needs << endl;
  cout << "The wants allocated to wants is: $" << wants << endl;
  cout << "The savings allocated to savings is: $" << savingValue << endl;
}

void customBudget (double totalBudget, double &savingValue) {
/*
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
*/
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



double netCalculator(){

  vector<string> provinces = {
    "Alberta", "British Columbia", "Saskatchewan", "Manitoba", "Ontario",
    "Quebec", "New Brunswick", "Nova Scotia", "Prince Edward Island",
    "Newfoundland and Labrador", "Yukon", "Northwest Territories", "Nunavut"};

  vector<vector<TaxBracket>> taxBrackets = {
    {{60000, 0.08}, {151234, 0.10}, {181481, 0.12}, {241974, 0.13}, {362961, 0.14}, {1e9, 0.15}},
    {{49279, 0.0506}, {98560, 0.077}, {113158, 0.105}, {137407, 0.1229}, {186306, 0.147}, {259829, 0.168}, {1e9, 0.205}},
    {{53463, 0.105}, {152750, 0.125}, {1e9, 0.145}},
    {{47000, 0.108}, {100000, 0.1275}, {1e9, 0.174}},
    {{52886, 0.0505}, {105775, 0.0915}, {150000, 0.1116}, {220000, 0.1216}, {1e9, 0.1316}},
    {{53255, 0.14}, {106495, 0.19}, {129590, 0.24}, {1e9, 0.2575}},
    {{51306, 0.094}, {102614, 0.14}, {190060, 0.16}, {1e9, 0.195}},
    {{29590, 0.0879}, {59180, 0.1495}, {93000, 0.1667}, {150000, 0.175}, {1e9, 0.21}},
    {{33328, 0.095}, {64656, 0.1347}, {105000, 0.166}, {140000, 0.1762}, {1e9, 0.19}},
    {{44192, 0.087}, {88382, 0.145}, {157792, 0.158}, {220910, 0.178}, {282214, 0.198}, {564429, 0.208}, {1128858, 0.213}, {1e9, 0.218}},
    {{57375, 0.064}, {114750, 0.09}, {177882, 0.109}, {500000, 0.128}, {1e9, 0.15}},
    {{51964, 0.059}, {103930, 0.086}, {168967, 0.122}, {1e9, 0.1405}},
    {{54707, 0.04}, {109413, 0.07}, {177881, 0.09}, {1e9, 0.115}}};


  cout << "Select your province by number:\n" << endl;
  for (size_t i = 0; i < provinces.size(); ++i)
    {
      cout << i + 1 << ". " << provinces[i] << "\n";
    }

  int choice = 0;
  double income;

  cout << "\nEnter your choice (1-13): ";
  cin >> choice;

  while (choice < 1 || choice > 13)
  {
    cout << "Invalid province selection.\n";
    cin >> choice;
  }

  cout << "Enter your taxable income: $";
  cin >> income;

  double tax = calculateTax(income, taxBrackets[choice - 1]);
  double netIncome = income - tax;

  cout << "\nProvince: " << provinces[choice - 1] << "\n";
  cout << "Taxable Income: $" << income << "\n";
  cout << "Estimated Provincial Tax: $" << tax << "\n";
  cout << "Income After Tax: $" << netIncome << "\n";

  return netIncome;
}

double calculateTax(double income, const vector<TaxBracket> &brackets){

    double tax = 0.0;
    double previous_limit = 0.0;

    for (const auto &bracket : brackets)
    {
        if (income > bracket.limit)
        {
            tax += (bracket.limit - previous_limit) * bracket.rate;
            previous_limit = bracket.limit;
        }
        else
        {
            tax += (income - previous_limit) * bracket.rate;
            break;
        }
    }

    return tax;
}
