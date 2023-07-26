#include <iostream>

// Task 02

void subtractByPointer(double* ptrA, double* ptrB, double* ptrR) {
    *ptrR = *ptrA - *ptrB;
}

// Task 03

void arrayByPointer(float* ptrArray, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Memory Address: " << &ptrArray[i] << ", Contents: " << ptrArray[i] << std::endl;
    }
}

// Task 04

// implement it


// Task 01

int main() {
    // Declare integer variables x and y and initialize them with 2 and 8 respectively.
    int x = 2;
    int y = 8;

    // Declare pointer variables ptrX and ptrY and initialize them with the addresses of x and y respectively.
    int* ptrX = &x;
    int* ptrY = &y;

    // Print the information
    std::cout << "1. Address of x: " << &x << ", Value of x: " << x << std::endl;
    std::cout << "2. Address of ptrX: " << &ptrX << ", Value of ptrX: " << ptrX << ", Pointed Value: " << *ptrX << std::endl;
    std::cout << "3. Address of y: " << &y << ", Value of y: " << y << std::endl;
    std::cout << "4. Address of ptrY: " << &ptrY << ", Value of ptrY: " << ptrY << ", Pointed Value: " << *ptrY << std::endl;

    return 0;
}
