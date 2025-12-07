#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TaxBracket
{
    double limit;
    double rate;
};

double calculateTax(double income, const vector<TaxBracket> &brackets)
{
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

int main()
{
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

    cout << "Select your province by number:\n";
    for (size_t i = 0; i < provinces.size(); ++i)
    {
        cout << i + 1 << ". " << provinces[i] << "\n";
    }

    int choice;
    double income;

    cout << "\nEnter your choice (1-13): ";
    cin >> choice;

    if (choice < 1 || choice > 13)
    {
        cout << "Invalid province selection.\n";
        return 1;
    }

    cout << "Enter your taxable income: $";
    cin >> income;

    double tax = calculateTax(income, taxBrackets[choice - 1]);
    double netIncome = income - tax;

    cout << "\nProvince: " << provinces[choice - 1] << "\n";
    cout << "Taxable Income: $" << income << "\n";
    cout << "Estimated Provincial Tax: $" << tax << "\n";
    cout << "Income After Tax: $" << netIncome << "\n";

    return 0;
}