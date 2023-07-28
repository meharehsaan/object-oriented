#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    int yearModel;
    string make;
    int speed;

public:
    // Constructors
    Car(int year, const string &carMake);
    Car(const Car &otherCar);

    // Destructor
    ~Car();

    // Accessor functions
    int getYearModel() const;
    string getMake() const;
    int getSpeed() const;

    // Mutator functions
    void setYearModel(int year);
    void setMake(const string &carMake);
    void setSpeed(int carSpeed);

    // Member functions
    void setCar(int year, const string &carMake, int carSpeed);
    void getCar();
    void putCar();
    void accelerate();
    void brake();
};

// Constructor
Car::Car(int year, const string &carMake) : yearModel(year), make(carMake), speed(0) {}

// Copy constructor
Car::Car(const Car &otherCar) : yearModel(otherCar.yearModel), make(otherCar.make), speed(otherCar.speed) {}

// Destructor
Car::~Car()
{
    cout << "Destructor executed..." << endl;
}

// Accessor functions
int Car::getYearModel() const
{
    return yearModel;
}

string Car::getMake() const
{
    return make;
}

int Car::getSpeed() const
{
    return speed;
}

// Mutator functions
void Car::setYearModel(int year)
{
    yearModel = year;
}

void Car::setMake(const string &carMake)
{
    make = carMake;
}

void Car::setSpeed(int carSpeed)
{
    speed = carSpeed;
}

// Member functions
void Car::setCar(int year, const string &carMake, int carSpeed)
{
    yearModel = year;
    make = carMake;
    speed = carSpeed;
}

void Car::getCar()
{
    cout << "Enter Year Model: ";
    cin >> yearModel;
    cin.ignore(); // Ignore the newline character left in the input buffer

    cout << "Enter Make: ";
    getline(cin, make);

    cout << "Enter Speed: ";
    cin >> speed;
}

void Car::putCar()
{
    cout << "Year Model: " << yearModel << endl;
    cout << "Make: " << make << endl;
    cout << "Speed: " << speed << " km/h" << endl;
}

void Car::accelerate()
{
    speed += 5;
}

void Car::brake()
{
    if (speed >= 5)
    {
        speed -= 5;
    }
    else
    {
        speed = 0;
    }
}

int main()
{
    Car car1(2021, "Suzuki Alto");
    Car car2(2015, "Toyota Camry");
    Car car3(2011, "Honda Accord");
    Car car4(2012, "Toyota Prius");
    Car car5(2018, "Daihatsu Boon");

    car1.putCar();
    car1.accelerate();
    car1.accelerate();
    car1.putCar();
    car1.brake();
    car1.putCar();

    car2.putCar();
    car3.putCar();
    car4.putCar();
    car5.putCar();

    return 0;
}
