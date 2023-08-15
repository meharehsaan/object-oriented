#include <iostream>

using namespace std;

class Array
{
private:
    int *data;
    int size;

public:
    // Constructors
    Array();
    Array(int arraySize);
    Array(const Array &otherArray);
    ~Array();

    // Member functions
    int getSize() const;
    void setElement(int index, int value);
    int countElement(int key) const;
    Array &operator=(const Array &otherArray);
    Array getSubArray(int start_index, int end_index) const;
    friend istream &operator>>(istream &is, Array &array);
    friend ostream &operator<<(ostream &os, const Array &array);
    Array operator+(const Array &otherArray) const;
    bool operator==(const Array &otherArray) const;
    int &operator[](int index);
    const int &operator[](int index) const;
};

// Constructors
Array::Array() : size(5)
{
    data = new int[size]();
}

Array::Array(int arraySize) : size(arraySize)
{
    data = new int[size]();
}

Array::Array(const Array &otherArray) : size(otherArray.size)
{
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = otherArray.data[i];
    }
}

// Destructor
Array::~Array()
{
    delete[] data;
}

// Member functions
int Array::getSize() const
{
    return size;
}

void Array::setElement(int index, int value)
{
    if (index >= 0 && index < size)
    {
        data[index] = value;
    }
    else
    {
        cout << "Invalid index. Element not set." << endl;
    }
}

int Array::countElement(int key) const
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == key)
        {
            count++;
        }
    }
    return count;
}

Array &Array::operator=(const Array &otherArray)
{
    if (this != &otherArray)
    {
        delete[] data;
        size = otherArray.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = otherArray.data[i];
        }
    }
    return *this;
}

Array Array::getSubArray(int start_index, int end_index) const
{
    if (start_index < 0 || end_index >= size || start_index > end_index)
    {
        cout << "Invalid range. Returning empty sub-array." << endl;
        return Array();
    }

    int subSize = end_index - start_index + 1;
    int *subData = new int[subSize];
    for (int i = 0; i < subSize; i++)
    {
        subData[i] = data[start_index + i];
    }
    return Array(subData, subSize);
}

// Stream insertion (>>)
istream &operator>>(istream &is, Array &array)
{
    for (int i = 0; i < array.size; i++)
    {
        cout << "Enter element at index " << i << ": ";
        is >> array.data[i];
    }
    return is;
}

// Stream extraction (<<)
ostream &operator<<(ostream &os, const Array &array)
{
    os << "[";
    for (int i = 0; i < array.size; i++)
    {
        os << array.data[i];
        if (i != array.size - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

// Arithmetic binary (+)
Array Array::operator+(const Array &otherArray) const
{
    Array result(size + otherArray.size);
    for (int i = 0; i < size; i++)
    {
        result.data[i] = data[i];
    }
    for (int i = 0; i < otherArray.size; i++)
    {
        result.data[size + i] = otherArray.data[i];
    }
    return result;
}

// Comparison (==)
bool Array::operator==(const Array &otherArray) const
{
    if (size != otherArray.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (data[i] != otherArray.data[i])
        {
            return false;
        }
    }
    return true;
}

// Subscript ([]) for lvalue and rvalue of non-const objects
int &Array::operator[](int index)
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }
    else
    {
        cout << "Invalid index. Returning first element." << endl;
        return data[0];
    }
}

// Subscript ([]) for rvalue of const objects
const int &Array::operator[](int index) const
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }
    else
    {
        cout << "Invalid index. Returning first element." << endl;
        return data[0];
    }
}

int main()
{
    Array intArray(5);
    cout << "Enter elements for intArray: " << endl;
    cin >> intArray;

    cout << "intArray: " << intArray << endl;
    cout << "Size of intArray: " << intArray.getSize() << endl;

    Array floatArray;
    cout << "floatArray (default constructor): " << floatArray << endl;

    floatArray = intArray;
    cout << "floatArray (assigned from intArray): " << floatArray << endl;

    cout << "Count of 0 in intArray: " << intArray.countElement(0) << endl;
    cout << "Count of 5 in intArray: " << intArray.countElement(5) << endl;

    Array subArray = intArray.getSubArray(1, 3);
    cout << "Sub-array of intArray (indices 1 to 3): " << subArray << endl;

    Array combinedArray = intArray + subArray;
    cout << "Combined array of intArray and subArray: " << combinedArray << endl;

    cout << "intArray and subArray are " << (intArray == subArray ? "equal" : "not equal") << endl;

    cout << "Element at index 2 of floatArray: " << floatArray[2] << endl;

    return 0;
}
