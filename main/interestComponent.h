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

using namespace std;

double interest(double savings);

/**********************************************************************
 * interest -- calculates the interest earned from savings
 * 
 * Parameters: savings -- the amount of money saved 
 * Modifies: 
 * 
 * Returns: amount -- the amount of interest earned
 *********************************************************************/
double interest(double savings) {
  int choice, frequency;
  double rate, time, amount;

  cout << "\nPlease choose which type of interest to use: \n1) Simple Interest \n2) Compound Interest";
  cin >> choice;

  do {
        cout << "\nPlease enter how much time (in years) the interest is compounding for: ";
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
    amount = savings * (rate / 100) * time;
  }
  else if (choice == 2) {
    do {
          cout << "\nPlease enter how many times per year interest is compounded:" << 
          "\nAnnualy: 1 \nSemi-Annualy: 2 \nQuarterly: 4 \nMonthly: 12 \nWeekly: 52 \nDaily: 365";
          cin >> frequency;
          if (frequency <= 0 || frequency > 365)
          {
              cout << "\nInvalid input, please reenter the frequency: ";
          }
      } while (frequency <=0 || frequency > 365);

      amount = (savings * pow((1 + (rate / 100) / frequency), frequency * time)) - savings;
  }

  cout << "\nInterest earned: $" << amount << endl;


  return amount;
}
