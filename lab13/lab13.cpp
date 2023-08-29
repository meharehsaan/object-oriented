#include <iostream>
using namespace std;

class Moving_Van
{
protected:
    float payload;
    float weight;
    float mpg;

public:
    void initialize(float payload, float weight, float mpg)
    {
        this->payload = payload;
        this->weight = weight;
        this->mpg = mpg;
    }

    float efficiency() const
    {
        return payload / (payload + weight);
    }

    float cost_per_ton(float fuel_cost) const
    {
        return fuel_cost / (payload / 2000.0);
    }
};

class Driver
{
protected:
    float hourly_pay;
    float weight;

public:
    void initialize(float hourly_pay, float weight)
    {
        this->hourly_pay = hourly_pay;
        this->weight = weight;
    }

    float cost_per_mile() const
    {
        return hourly_pay / 55.0;
    }

    float drivers_weight() const
    {
        return weight;
    }
};

class Driven_Truck : public Driver, public Moving_Van
{
public:
    void initialize(float payload, float van_weight, float van_mpg,
                    float driver_hourly_pay, float driver_weight)
    {
        Moving_Van::initialize(payload, van_weight, van_mpg);
        Driver::initialize(driver_hourly_pay, driver_weight);
    }

    float cost_per_full_day(float cost_of_gas) const
    {
        return (8.0 * hourly_pay + 8.0 * cost_of_gas * 55.0) / mpg;
    }

    float total_weight() const
    {
        return payload + weight;                   //weight got ambigious because both classes and weight
        // return payload + Moving_Van::weight;
        // return payload + Driver::weight;
    }
};

int main()
{
    Driven_Truck chuck_ford;
    chuck_ford.initialize(10000.0, 6000.0, 6.0, 25.0, 180.0);

    cout << "Efficiency: " << chuck_ford.efficiency() << endl;
    cout << "Cost per mile: " << chuck_ford.cost_per_mile() << endl;
    cout << "Cost per day: " << chuck_ford.cost_per_full_day(3.0) << endl;
    cout << "Total weight: " << chuck_ford.total_weight() << endl;

    return 0;
}
