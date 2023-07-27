#include <iostream>

using namespace std;

int *getPositiveNumbers(const int ar[], const int size, int &newArraySize)
{
    int positiveCount = 0;
    for (int i = 0; i < size; ++i)
    {
        if (ar[i] > 0)
            positiveCount++;
    }

    if (positiveCount == 0)
    {
        newArraySize = 0;
        return nullptr;
    }

    int *positiveArray = new int[positiveCount];
    int index = 0;
    for (int i = 0; i < size; ++i)
    {
        if (ar[i] > 0)
        {
            positiveArray[index] = ar[i];
            index++;
        }
    }

    newArraySize = positiveCount;
    return positiveArray;
}

int main()
{
    int size = 10;
    int arr[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    int newArraySize = 0;
    int *positiveArray = getPositiveNumbers(arr, size, newArraySize);

    if (positiveArray != nullptr)
    {
        cout << "Positive Numbers in the Array: ";
        for (int i = 0; i < newArraySize; ++i)
        {
            cout << positiveArray[i] << " ";
        }
        cout << endl;
        delete[] positiveArray;
    }
    else
    {
        cout << "No Positive Numbers Exist in the Array!" << endl;
    }

    return 0;
}
