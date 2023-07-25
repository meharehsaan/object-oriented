#include <iostream>

using namespace std;


//Task01

double charges(int days, double daily_rate, double medication_charges, double services_charges) {
    return days * daily_rate + medication_charges + services_charges;
}

double in_patient_charges() {
    int days;
    double daily_rate, medication_charges, services_charges;

    cout << "Enter the number of days spent in the hospital: ";
    cin >> days;
    cout << "Enter the daily rate: ";
    cin >> daily_rate;
    cout << "Enter hospital medication charges: ";
    cin >> medication_charges;
    cout << "Enter charges for hospital services (lab tests, etc.): ";
    cin >> services_charges;

    return charges(days, daily_rate, medication_charges, services_charges);
}

double out_patient_charges() {
    double medication_charges, services_charges;

    cout << "Enter charges for hospital services (lab tests, etc.): ";
    cin >> services_charges;
    cout << "Enter hospital medication charges: ";
    cin >> medication_charges;

    return charges(0, 0.0, medication_charges, services_charges);
}

//Task02

/* Implement it  */

//Task03

const int SIZE = 4;

void displayMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int transposed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main(int argc, char const *argv[])
{
    /* Start of execution */
    return 0;
}
