#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string firstname;
    string lastname;
    string SSN;

public:
    Employee(const string &first, const string &last, const string &ssn);
    virtual void print() const;
    virtual double earnings() const = 0; // Pure virtual function
    // Getters and setters for firstname, lastname, and SSN
    // ...
};

Employee::Employee(const string &first, const string &last, const string &ssn)
    : firstname(first), lastname(last), SSN(ssn) {}

void Employee::print() const
{
    cout << "Name: " << firstname << " " << lastname << endl;
    cout << "SSN: " << SSN << endl;
}

class SalariedEmployee : public Employee
{
private:
    double weeklySalary;

public:
    SalariedEmployee(const string &first, const string &last, const string &ssn, double salary = 0.0);
    virtual void print() const override;
    virtual double earnings() const override;
    // Getters and setters for weeklySalary
    // ...
};

SalariedEmployee::SalariedEmployee(const string &first, const string &last, const string &ssn, double salary)
    : Employee(first, last, ssn), weeklySalary(salary) {}

void SalariedEmployee::print() const
{
    Employee::print();
    cout << "Weekly Salary: " << weeklySalary << endl;
}

double SalariedEmployee::earnings() const
{
    return weeklySalary;
}

class HourlyEmployee : public Employee
{
private:
    double wage;
    double hours;

public:
    HourlyEmployee(const string &first, const string &last, const string &ssn, double hourlyWage = 0.0, double hoursWorked = 0.0);
    virtual void print() const override;
    virtual double earnings() const override;
    // Getters and setters for wage and hours
    // ...
};

HourlyEmployee::HourlyEmployee(const string &first, const string &last, const string &ssn, double hourlyWage, double hoursWorked)
    : Employee(first, last, ssn), wage(hourlyWage), hours(hoursWorked) {}

void HourlyEmployee::print() const
{
    Employee::print();
    cout << "Hourly Wage: " << wage << endl;
    cout << "Hours Worked: " << hours << endl;
}

double HourlyEmployee::earnings() const
{
    return wage * hours;
}

class CommissionEmployee : public Employee
{
private:
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(const string &first, const string &last, const string &ssn, double sales = 0.0, double rate = 0.0);
    virtual void print() const override;
    virtual double earnings() const override;
    // Getters and setters for grossSales and commissionRate
    // ...
};

CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate)
    : Employee(first, last, ssn), grossSales(sales), commissionRate(rate) {}

void CommissionEmployee::print() const
{
    Employee::print();
    cout << "Gross Sales: " << grossSales << endl;
    cout << "Commission Rate: " << commissionRate << endl;
}

double CommissionEmployee::earnings() const
{
    return grossSales * commissionRate;
}

class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, double sales = 0.0, double rate = 0.0, double salary = 0.0);
    virtual void print() const override;
    virtual double earnings() const override;
    // Getters and setters for baseSalary
    // ...
};

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate), baseSalary(salary) {}

void BasePlusCommissionEmployee::print() const
{
    CommissionEmployee::print();
    cout << "Base Salary: " << baseSalary << endl;
}

double BasePlusCommissionEmployee::earnings() const
{
    return CommissionEmployee::earnings() + baseSalary;
}

int main()
{
    SalariedEmployee salariedEmp("John", "Doe", "123-45-6789", 800.0);
    HourlyEmployee hourlyEmp("Alice", "Smith", "987-65-4321", 15.0, 40.0);
    CommissionEmployee commissionEmp("Bob", "Johnson", "456-78-9123", 50000.0, 0.1);
    BasePlusCommissionEmployee basePlusCommissionEmp("Eva", "Lee", "567-89-1234", 75000.0, 0.08, 1500.0);

    salariedEmp.print();
    cout << "Earnings: " << salariedEmp.earnings() << endl
         << endl;

    hourlyEmp.print();
    cout << "Earnings: " << hourlyEmp.earnings() << endl
         << endl;

    commissionEmp.print();
    cout << "Earnings: " << commissionEmp.earnings() << endl
         << endl;

    basePlusCommissionEmp.print();
    cout << "Earnings: " << basePlusCommissionEmp.earnings() << endl
         << endl;

    Employee *employees[4] = {&salariedEmp, &hourlyEmp, &commissionEmp, &basePlusCommissionEmp};

    for (int i = 0; i < 4; i++)
    {
        employees[i]->print();
        cout << "Earnings: " << employees[i]->earnings() << endl
             << endl;
    }

    return 0;
}
