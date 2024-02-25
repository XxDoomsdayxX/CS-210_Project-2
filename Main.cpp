/*
 * Project 2 : Airgead Banking App
 *
 * Date: 02/10/2024
 * Author: Darrell Walker II
 *
 */



#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Declare variables
    float initInv, monDep, AnuInt, years, months;
    float totalAm;
    float intAmt, yearTotInt;

    // Display initial information
    cout << "***************************\n";
    cout << "********Data Input*********\n";
    cout << "Initial Investment Amount: ";
    cin >> initInv;
    cout << "Monthly Deposit: ";
    cin >> monDep;
    cout << "Annual Interest: ";
    cin >> AnuInt;
    cout << "Number of years: ";
    cin >> years;

    months = years * 12;

    // Pause to allow the user to read the input
    system("PAUSE");

    cout << endl;

    // Display header for the calculations
    cout << "****************************\n";
    cout << "********Data Input**********\n";
    cout << "Initial Investment Amount: " << fixed << setprecision(2) << '$' << initInv << endl;
    cout << "Monthly Deposit: " << '$' << monDep << endl;
    cout << setprecision(0);
    cout << "Annual Interest: " << '%' << AnuInt << endl;
    cout << "Number of years: " << years << endl;

    // Pause again to allow the user to read the input
    system("PAUSE");

    totalAm = initInv;

    // Display balance and interest without additional monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {
        intAmt = totalAm * (AnuInt / 100);
        totalAm = totalAm + intAmt;
        cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << intAmt << "\n";
    }

    totalAm = initInv;

    // Display balance and interest with additional monthly deposits
    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {
        yearTotInt = 0;
        for (int j = 0; j < 12; j++) {
            intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12);
            yearTotInt = yearTotInt + intAmt;
            totalAm = totalAm + monDep + intAmt;
        }
        cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << yearTotInt << "\n";
    }

    return 0;
}