/****************
 * Simon Fraser University
 * ENSC151 Intro to Software Development for Engineers
 * ENSC151InterestProject.cpp -- Program that calculates the interest gained on savings
 * 
 * Input: The principal (initial) amount
 *            Annual interest rate
 *            Number of times interest is compounded
 * Output: The amount of interest earned
 * 
 * Author: Jonathan Chen
 *****************/
#include <iostream>
#include <cmath>
#include "interestComponent.h"

using namespace std;

/**********************************************************************
 * interest -- calculates the interest earned from savings
 * 
 * Parameters: savings -- the amount of money saved 
 * Modifies: 
 * 
 * Returns: amount -- the amount of interest earned
 *********************************************************************/
void interest(double savingValue) {
  int choice, choice2, frequency;
  double rate, time, amount, principle;

  cout << "\nPlease choose which type of interest to use: \n1) Simple Interest \n2) Compound Interest\n";
  cin >> choice;

  cout << "\nSelect one of the following options: " << endl;
  cout << "1. Use savings as principle amount." << endl;
  cout << "2. Use custom value." << endl;
  cin >> choice2;

  if (choice2 == 1){
    if (savingValue <= 0) {
      cout << "\nNo saving value found" << endl;
      cout << "Please input the principle amount." << endl;
      cin >> principle;
    }else{
      principle = savingValue;
    }
  } else {
    cout << "\nPlease enter the principle amount: " << endl;
    cin >> principle;
  }

  do {
        cout << "\nPlease enter how much time (in years) the interest is calculated for: ";
        cin >> time;
        if (time < 0 || time > 100)
        {
            cout << "\nInvalid input, please reenter the time: ";
        }
  } while (time < 0 || time > 100);

  do {
        cout << "\nPlease enter the annual interest rate (percentage): ";
        cin >> rate;
        if (rate < 0 || rate > 100)
        {
            cout << "\nInvalid input, please reenter the interest rate: ";
        }
    } while (rate < 0 || rate > 100);

  if (choice == 1) {
    amount = principle * (rate / 100) * time;
  }
  else if (choice == 2) {
    do {
          cout << "\nPlease enter how many times per year interest is compounded:" << 
          "\nAnnualy: 1 \nSemi-Annualy: 2 \nQuarterly: 4 \nMonthly: 12 \nWeekly: 52 \nDaily: 365\n";
          cin >> frequency;
          if (frequency <= 0 || frequency > 365)
          {
              cout << "\nInvalid input, please reenter the frequency: ";
          }
      } while (frequency <=0 || frequency > 365);

      amount = (principle * pow((1 + (rate / 100) / frequency), frequency * time)) - principle;
  }

  cout << "\nInterest earned: $" << amount << endl;
  cout << "Total savings: $" << amount + principle << endl;

  cout << "\nReturning to selection screen...\n";
  cout << "--------------------------------------------\n\n";
}

