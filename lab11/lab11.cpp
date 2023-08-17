#include <iostream>
#include "FeetInches.cpp" //I lost that file so grap the concept here only

using namespace std;

class RoomDimension
{
private:
    FeetInches length;
    FeetInches width;

public:
    // Constructors
    RoomDimension();
    RoomDimension(const FeetInches &roomLength, const FeetInches &roomWidth);

    // Mutators
    void setLength(const FeetInches &roomLength);
    void setWidth(const FeetInches &roomWidth);

    // Accessors
    FeetInches getLength() const;
    FeetInches getWidth() const;

    // Member functions
    FeetInches calculateArea() const;
    void display() const;
};

// Default constructor
RoomDimension::RoomDimension()
{
    length.setFeet(0);
    length.setInches(0);
    width.setFeet(0);
    width.setInches(0);
}

// Parameterized constructor
RoomDimension::RoomDimension(const FeetInches &roomLength, const FeetInches &roomWidth)
{
    length = roomLength;
    width = roomWidth;
}

// Mutators
void RoomDimension::setLength(const FeetInches &roomLength)
{
    length = roomLength;
}

void RoomDimension::setWidth(const FeetInches &roomWidth)
{
    width = roomWidth;
}

// Accessors
FeetInches RoomDimension::getLength() const
{
    return length;
}

FeetInches RoomDimension::getWidth() const
{
    return width;
}

// Member function to calculate the area of the room
FeetInches RoomDimension::calculateArea() const
{
    int totalInches = (length.getFeet() * 12 + length.getInches()) * (width.getFeet() * 12 + width.getInches());
    FeetInches area(totalInches / 12, totalInches % 12);
    return area;
}

// Member function to display the length and width of the room
void RoomDimension::display() const
{
    cout << "Room Length: " << length << endl;
    cout << "Room Width: " << width << endl;
}

class RoomCarpet
{
private:
    RoomDimension roomSize;
    float costPerSquareFoot;

public:
    // Constructors
    RoomCarpet();
    RoomCarpet(const RoomDimension &roomSize, float cost);

    // Mutators
    void setRoomSize(const RoomDimension &roomSize);
    void setCostPerSquareFoot(float cost);

    // Accessors
    RoomDimension getRoomSize() const;
    float getCostPerSquareFoot() const;

    // Member function to calculate the total cost of the carpet
    float calculateTotalCost() const;

    // Member function to display the room size and cost per square foot
    void display() const;
};

// Default constructor
RoomCarpet::RoomCarpet()
{
    costPerSquareFoot = 0;
}

// Parameterized constructor
RoomCarpet::RoomCarpet(const RoomDimension &roomSize, float cost)
{
    this->roomSize = roomSize;
    costPerSquareFoot = cost;
}

// Mutators
void RoomCarpet::setRoomSize(const RoomDimension &roomSize)
{
    this->roomSize = roomSize;
}

void RoomCarpet::setCostPerSquareFoot(float cost)
{
    costPerSquareFoot = cost;
}

// Accessors
RoomDimension RoomCarpet::getRoomSize() const
{
    return roomSize;
}

float RoomCarpet::getCostPerSquareFoot() const
{
    return costPerSquareFoot;
}

// Member function to calculate the total cost of the carpet
float RoomCarpet::calculateTotalCost() const
{
    FeetInches area = roomSize.calculateArea();
    float totalCost = area.getFeet() * area.getInches() * costPerSquareFoot;
    return totalCost;
}

// Member function to display the room size and cost per square foot
void RoomCarpet::display() const
{
    cout << "Room Size: " << endl;
    roomSize.display();
    cout << "Cost per Square Foot: Rs. " << costPerSquareFoot << endl;
}

int main()
{
    //implement main for execution
}