#include <iostream>

using namespace std;

void getEvenOdd(const int ar[], const int n_ar, int *&even, int &n_even, int *&odd, int &n_odd)
{
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < n_ar; ++i)
    {
        if (ar[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    if (evenCount == 0)
    {
        even = nullptr;
        n_even = 0;
    }
    else
    {
        even = new int[evenCount];
        n_even = evenCount;
    }

    if (oddCount == 0)
    {
        odd = nullptr;
        n_odd = 0;
    }
    else
    {
        odd = new int[oddCount];
        n_odd = oddCount;
    }

    int evenIndex = 0;
    int oddIndex = 0;
    for (int i = 0; i < n_ar; ++i)
    {
        if (ar[i] % 2 == 0)
        {
            even[evenIndex] = ar[i];
            evenIndex++;
        }
        else
        {
            odd[oddIndex] = ar[i];
            oddIndex++;
        }
    }
}

int main()
{
    int size = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *even = nullptr;
    int n_even = 0;
    int *odd = nullptr;
    int n_odd = 0;

    getEvenOdd(arr, size, even, n_even, odd, n_odd);

    if (n_even > 0)
    {
        cout << "Even Numbers in the Array: ";
        for (int i = 0; i < n_even; ++i)
        {
            cout << even[i] << " ";
        }
        cout << endl;
        delete[] even;
    }
    else
    {
        cout << "No Even Numbers Exist in the Array!" << endl;
    }

    if (n_odd > 0)
    {
        cout << "Odd Numbers in the Array: ";
        for (int i = 0; i < n_odd; ++i)
        {
            cout << odd[i] << " ";
        }
        cout << endl;
        delete[] odd;
    }
    else
    {
        cout << "No Odd Numbers Exist in the Array!" << endl;
    }

    return 0;
}
