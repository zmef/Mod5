// Ch10Introductory16.cpp - Calculates gross pay including overtime
// Created/revised by ZMF on 4/10/25

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
void calculateOvertimePay(int hoursWorked, double hourlyRate, double &overtimePay);

int main()
{
    int hoursWorked;
    double hourlyRate;
    double regularPay;
    double overtimePay;
    double grossPay;

    cout << fixed << setprecision(2);

    // Get input until user enters a negative number of hours
    cout << "Enter hours worked (-1 to quit): ";
    cin >> hoursWorked;

    while (hoursWorked >= 0)
    {
        cout << "Enter hourly pay rate: ";
        cin >> hourlyRate;

        // Calculate regular pay
        if (hoursWorked <= 37)
        {
            regularPay = hoursWorked * hourlyRate;
        }
        else
        {
            regularPay = 37 * hourlyRate;
        }

        // Calculate overtime pay using a function
        calculateOvertimePay(hoursWorked, hourlyRate, overtimePay);

        // Calculate and display gross pay
        grossPay = regularPay + overtimePay;
        cout << "Gross pay: $" << grossPay << endl << endl;

        // Prompt again
        cout << "Enter hours worked (-1 to quit): ";
        cin >> hoursWorked;
    }

    cout << "Program ended." << endl;
    return 0;
}

// Function to calculate overtime pay
void calculateOvertimePay(int hoursWorked, double hourlyRate, double &overtimePay)
{
    overtimePay = 0.0;

    if (hoursWorked > 37 && hoursWorked <= 50)
    {
        overtimePay = (hoursWorked - 37) * hourlyRate * 1.5;
    }
    else if (hoursWorked > 50)
    {
        // Time and a half for hours 38–50
        overtimePay = (13 * hourlyRate * 1.5); // 38 to 50 = 13 hours
        // Double time for hours beyond 50
        overtimePay += (hoursWorked - 50) * hourlyRate * 2.0;
    }
}
