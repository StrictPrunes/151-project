 /******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * incomeTaxComponent.h -- function declarations and structs for handling income tax
 *
 * Authors: Khang Luu and Naseem Folami
 *
 *******************************************************************/
#include <vector>

using namespace std;

double netCalculator();

struct TaxBracket
{
    double limit;
    double rate;
};

double calculateTax(double income, const vector<TaxBracket> &brackets);
