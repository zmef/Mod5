#include <iostream>
#include <iomanip>
#include <cmath> // For std::round
#include <limits> // For numeric_limits
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
    while (!(cin >> hoursWorked)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number of hours: ";
    }

    while (hoursWorked >= 0)
    {
        cout << "Enter hourly pay rate: ";
        while (!(cin >> hourlyRate)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid hourly pay rate: ";
        }

        if (hourlyRate < 0) {
            cout << "Hourly pay rate cannot be negative. Please try again." << endl;
            continue;
        }

        // Calculate regular pay
        if (hoursWorked <= 37) {
            regularPay = hoursWorked * hourlyRate;
            overtimePay = 0.0;
        } else {
            regularPay = 37 * hourlyRate;
            calculateOvertimePay(hoursWorked, hourlyRate, overtimePay);
        }

        // Calculate and display gross pay
        grossPay = std::round((regularPay + overtimePay) * 100.0) / 100.0;
        cout << "Gross pay: $" << grossPay << endl << endl;

        // Prompt again
        cout << "Enter hours worked (-1 to quit): ";
        while (!(cin >> hoursWorked)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number of hours: ";
        }
    }

    cout << "Program ended." << endl;
    return 0;
}

// Function to calculate overtime pay
void calculateOvertimePay(int hoursWorked, double hourlyRate, double &overtimePay)
{
    if (hoursWorked <= 37) {
        overtimePay = 0.0;
    } else if (hoursWorked <= 50) {
        overtimePay = (hoursWorked - 37) * hourlyRate * 1.5;
    } else {
        overtimePay = (13 * hourlyRate * 1.5) + ((hoursWorked - 50) * hourlyRate * 2.0);
    }
}