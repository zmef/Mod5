//Lab9-2.cpp - displays two monthly car payments
//Created/revised by ZMF on 4/10/25

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
double getPayment(int principal, double rate, int months);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;

    return 0;
}

// Function definition
double getPayment(int principal, double rate, int months)
{
    if (rate == 0) // Handle zero interest rate case
    {
        return static_cast<double>(principal) / months;
    }
    return (principal * rate) / (1 - pow(1 + rate, -months));
}