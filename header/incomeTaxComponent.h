#include <vector>

using namespace std;

double netCalculator();

struct TaxBracket
{
    double limit;
    double rate;
};

double calculateTax(double income, const vector<TaxBracket> &brackets);
