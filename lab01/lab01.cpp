#include <iostream>
#include <iomanip>
using namespace std;

//Task01

double calculateAnnualPay(double payAmount, int payPeriods) {
    double annualPay = payAmount * payPeriods;
    return annualPay;
}

//Task02

double calculateTotalCost(int quantity) {
    const double packagePrice = 99.0;
    double discount = 0.0;

    if (quantity >= 10 && quantity <= 19) {
        discount = 0.2; // 20% discount
    } else if (quantity >= 20 && quantity <= 49) {
        discount = 0.3; // 30% discount
    } else if (quantity >= 50 && quantity <= 99) {
        discount = 0.4; // 40% discount
    } else if (quantity >= 100) {
        discount = 0.5; // 50% discount
    }

    double totalCost = quantity * packagePrice * (1 - discount);
    return totalCost;
}

//Task03

double calculateOceanRise(double oceanRiseRate, int year) {
    return oceanRiseRate * year;
}

void displayTable(int numberOfYears) {
    double oceanRiseRate = 1.5; // Millimeters per year

    // Display the table header
    cout << setw(5) << "Year" << setw(10) << "Level (mm)" << endl;

    // Calculate and display the ocean level for each year
    for (int year = 1; year <= numberOfYears; ++year) {
        double totalRise = calculateOceanRise(oceanRiseRate, year);
        cout << setw(5) << year << setw(10) << totalRise << endl;
    }
}

//Task04

bool isDivisibleBy235(int num) {
    return (num % 2 == 0) && (num % 3 == 0) && (num % 5 == 0);
}

int calculateSumBetweenLimits(int sLimit, int eLimit) {
    int sum = 0;
    for (int num = sLimit; num <= eLimit; ++num) {
        if (isDivisibleBy235(num)) {
            sum += num;
        }
    }
    return sum;
}

int main(){
    // write main and execute the functions
}
