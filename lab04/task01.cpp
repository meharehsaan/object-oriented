#include <iostream>

using namespace std;

int main()
{
    float *ptrX = nullptr;
    float *ptrY = nullptr;

    ptrX = new float;
    *ptrX = 4.5;

    ptrY = new float;
    *ptrY = 9.3;

    cout << "ptrX address: " << &ptrX << ", ptrX value: " << ptrX << ", pointed value: " << *ptrX << endl;
    cout << "ptrY address: " << &ptrY << ", ptrY value: " << ptrY << ", pointed value: " << *ptrY << endl;

    delete ptrX;
    delete ptrY;

    return 0;
}
