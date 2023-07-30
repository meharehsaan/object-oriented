#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
    int id;
    string name;
    int quantity;
    float cost;

public:
    // Constructors
    Item(int itemId, const string &itemName, int itemQuantity, float itemCost);
    Item(int itemId, const string &itemName, int itemQuantity);
    Item(int itemId, const string &itemName, float itemCost);
    Item(const Item &otherItem);

    // Destructor
    ~Item();

    // Mutators
    void setId(int itemId);
    void setName(const string &itemName);
    void setQuantity(int itemQuantity);
    void setCost(float itemCost);

    // Accessors
    int getId() const;
    string getName() const;
    int getQuantity() const;
    float getCost() const;

    // Member functions
    void setItem(int itemId, const string &itemName, int itemQuantity, float itemCost);
    void getItem();
    void putItem() const;
    float getTotalCost() const;
    bool isEqual(const Item &otherItem) const;
    void updateName(Item itemList[], int size);
    static Item getMinimumCostItem(Item itemList[], int size);
    static void getAveragePrice(Item itemList[], int size, float &averageCost);
};

// Constructor with all arguments
Item::Item(int itemId, const string &itemName, int itemQuantity, float itemCost)
    : id(itemId), name(itemName), quantity(itemQuantity), cost(itemCost)
{
    // Value should only be assigned if they are positive, zero otherwise
    if (id < 0)
        id = 0;
    if (quantity < 0)
        quantity = 0;
    if (cost < 0)
        cost = 0;
}

// Constructor with itemId, itemName, and itemQuantity only
Item::Item(int itemId, const string &itemName, int itemQuantity)
    : id(itemId), name(itemName), quantity(itemQuantity), cost(0)
{
    // Value should only be assigned if they are positive, zero otherwise
    if (id < 0)
        id = 0;
    if (quantity < 0)
        quantity = 0;
}

// Constructor with itemId, itemName, and itemCost only
Item::Item(int itemId, const string &itemName, float itemCost)
    : id(itemId), name(itemName), quantity(0), cost(itemCost)
{
    // Value should only be assigned if they are positive, zero otherwise
    if (id < 0)
        id = 0;
    if (cost < 0)
        cost = 0;
}

// Copy constructor
Item::Item(const Item &otherItem)
    : id(otherItem.id), name(otherItem.name),
      quantity(otherItem.quantity), cost(otherItem.cost) {}

// Destructor
Item::~Item()
{
    cout << "Destructor executed..." << endl;
}

// Mutators
void Item::setId(int itemId)
{
    if (itemId >= 0)
    {
        id = itemId;
    }
    else
    {
        cout << "Invalid item ID. Setting to 0." << endl;
        id = 0;
    }
}

void Item::setName(const string &itemName)
{
    name = itemName;
}

void Item::setQuantity(int itemQuantity)
{
    if (itemQuantity >= 0)
    {
        quantity = itemQuantity;
    }
    else
    {
        cout << "Invalid item quantity. Setting to 0." << endl;
        quantity = 0;
    }
}

void Item::setCost(float itemCost)
{
    if (itemCost >= 0)
    {
        cost = itemCost;
    }
    else
    {
        cout << "Invalid item cost. Setting to 0." << endl;
        cost = 0;
    }
}

// Accessors
int Item::getId() const
{
    return id;
}

string Item::getName() const
{
    return name;
}

int Item::getQuantity() const
{
    return quantity;
}

float Item::getCost() const
{
    return cost;
}

// Member functions
void Item::setItem(int itemId, const string &itemName, int itemQuantity, float itemCost)
{
    setId(itemId);
    setName(itemName);
    setQuantity(itemQuantity);
    setCost(itemCost);
}

void Item::getItem()
{
    cout << "Enter Item ID: ";
    cin >> id;

    cout << "Enter Item Name: ";
    cin.ignore(); // Ignore the newline character left in the input buffer
    getline(cin, name);

    cout << "Enter Item Quantity: ";
    cin >> quantity;

    cout << "Enter Item Cost: ";
    cin >> cost;
}

void Item::putItem() const
{
    cout << "Item ID: " << id << endl;
    cout << "Item Name: " << name << endl;
    cout << "Item Quantity: " << quantity << endl;
    cout << "Item Cost: " << cost << endl;
}

float Item::getTotalCost() const
{
    return (quantity >= 1) ? (quantity * cost) : 0;
}

bool Item::isEqual(const Item &otherItem) const
{
    return (id == otherItem.id &&
            name == otherItem.name &&
            quantity == otherItem.quantity &&
            cost == otherItem.cost);
}

void Item::updateName(Item itemList[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (itemList[i].id == id)
        {
            itemList[i].name = name;
        }
    }
}

Item Item::getMinimumCostItem(Item itemList[], int size)
{
    if (size == 0)
    {
        cout << "Error: Empty item list. Returning default item." << endl;
        return Item(0, "", 0, 0);
    }

    Item minItem = itemList[0];
    for (int i = 1; i < size; i++)
    {
        if (itemList[i].cost < minItem.cost)
        {
            minItem = itemList[i];
        }
    }
    return minItem;
}

void Item::getAveragePrice(Item itemList[], int size, float &averageCost)
{
    if (size == 0)
    {
        averageCost = 0;
        return;
    }

    float totalCost = 0;
    int totalItems = 0;
    for (int i = 0; i < size; i++)
    {
        if (itemList[i].cost >= 0)
        {
            totalCost += itemList[i].cost;
            totalItems++;
        }
    }

    averageCost = (totalItems > 0) ? (totalCost / totalItems) : 0;
}

int main()
{
    Item item1(101, "Laptop", 5, 850.50);
    Item item2(102, "Mouse", 20);
    Item item3(103, "Keyboard", 40, 150.75);

    item1.putItem();
    cout << "Total Cost: " << item1.getTotalCost() << endl;
    cout << "Is Equal to item2: " << (item1.isEqual(item2) ? "Yes" : "No") << endl;
    cout << "Is Equal to item3: " << (item1.isEqual(item3) ? "Yes" : "No") << endl;
    cout << endl;

    Item itemList[] = {item1, item2, item3};
    Item minCostItem = Item::getMinimumCostItem(itemList, 3);
    cout << "Item with minimum cost: " << endl;
    minCostItem.putItem();
    cout << endl;

    float averageCost;
    Item::getAveragePrice(itemList, 3, averageCost);
    cout << "Average Cost: " << averageCost << endl;

    return 0;
}
