#include <iostream>

using namespace std;

class Collection
{
private:
    int *data;
    int size;

public:
    // Constructors
    Collection(int arraySize);
    Collection(int array[], int arraySize);
    Collection(const Collection &otherCollection);

    // Destructor
    ~Collection();

    // Member functions
    int getSize() const;
    void setElement(int index, int value);
    int countElement(int key) const;
    Collection &operator=(const Collection &otherCollection);
    Collection getSubCollection(int start_index, int end_index) const;
    friend istream &operator>>(istream &is, Collection &collection);
    friend ostream &operator<<(ostream &os, const Collection &collection);
    Collection operator+(const Collection &otherCollection) const;
    bool operator==(const Collection &otherCollection) const;
    int &operator[](int index);
    const int &operator[](int index) const;
    bool operator-() const;
};

// Constructors
Collection::Collection(int arraySize) : size(arraySize)
{
    if (size <= 0)
    {
        size = 0;
    }
    data = new int[size]();
}

Collection::Collection(int array[], int arraySize) : size(arraySize)
{
    if (size <= 0)
    {
        size = 0;
    }
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = array[i];
    }
}

Collection::Collection(const Collection &otherCollection) : size(otherCollection.size)
{
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = otherCollection.data[i];
    }
}

// Destructor
Collection::~Collection()
{
    delete[] data;
}

// Member functions
int Collection::getSize() const
{
    return size;
}

void Collection::setElement(int index, int value)
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

int Collection::countElement(int key) const
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

Collection &Collection::operator=(const Collection &otherCollection)
{
    if (this != &otherCollection)
    {
        delete[] data;
        size = otherCollection.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = otherCollection.data[i];
        }
    }
    return *this;
}

Collection Collection::getSubCollection(int start_index, int end_index) const
{
    if (start_index < 0 || end_index >= size || start_index > end_index)
    {
        cout << "Invalid range. Returning empty sub-collection." << endl;
        return Collection();
    }

    int subSize = end_index - start_index + 1;
    int *subData = new int[subSize];
    for (int i = 0; i < subSize; i++)
    {
        subData[i] = data[start_index + i];
    }
    return Collection(subData, subSize);
}

istream &operator>>(istream &is, Collection &collection)
{
    for (int i = 0; i < collection.size; i++)
    {
        cout << "Enter element at index " << i << ": ";
        is >> collection.data[i];
    }
    return is;
}

ostream &operator<<(ostream &os, const Collection &collection)
{
    os << "[";
    for (int i = 0; i < collection.size; i++)
    {
        os << collection.data[i];
        if (i != collection.size - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

Collection Collection::operator+(const Collection &otherCollection) const
{
    Collection result(size + otherCollection.size);
    for (int i = 0; i < size; i++)
    {
        result.data[i] = data[i];
    }
    for (int i = 0; i < otherCollection.size; i++)
    {
        result.data[size + i] = otherCollection.data[i];
    }
    return result;
}

bool Collection::operator==(const Collection &otherCollection) const
{
    if (size != otherCollection.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (data[i] != otherCollection.data[i])
        {
            return false;
        }
    }
    return true;
}

int &Collection::operator[](int index)
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

const int &Collection::operator[](int index) const
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

bool Collection::operator-() const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Collection collection1(5);
    cout << "Enter elements for collection1: " << endl;
    cin >> collection1;

    cout << "collection1: " << collection1 << endl;
    cout << "Size of collection1: " << collection1.getSize() << endl;

    Collection collection2(3);
    collection2.setElement(0, 10);
    collection2.setElement(1, -5);
    collection2.setElement(2, 0);
    cout << "collection2: " << collection2 << endl;

    Collection collection3(collection1);
    cout << "collection3 (copy of collection1): " << collection3 << endl;

    Collection subCollection = collection1.getSubCollection(1, 3);
    cout << "Sub-collection of collection1 (indices 1 to 3): " << subCollection << endl;

    Collection combinedCollection = collection1 + collection2;
    cout << "Combined collection of collection1 and collection2: " << combinedCollection << endl;

    cout << "collection1 and collection2 are " << (collection1 == collection2 ? "equal" : "not equal") << endl;

    cout << "Element at index 2 of collection3: " << collection3[2] << endl;
    return 0;
}
