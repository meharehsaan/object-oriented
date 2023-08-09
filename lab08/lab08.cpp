#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

    // Private helper functions
    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;

public:
    // Constructors
    Date(int d, int m, int y);
    Date(int m, int y);
    Date();

    // Mutators
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Accessors
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Overloaded operators
    friend ostream &operator<<(ostream &os, const Date &date);
    friend istream &operator>>(istream &is, Date &date);
    Date &operator++();                         // Pre-increment
    Date operator++(int);                       // Post-increment
    Date &operator--();                         // Pre-decrement
    Date operator--(int);                       // Post-decrement
    int operator-(const Date &otherDate) const; // Subtraction (-)
    bool operator+() const;                     // Addition (+) unary
};

// Constructors
Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
    // Value should only be assigned within valid ranges
    if (day < 1 || day > daysInMonth(month, year))
    {
        day = 1;
    }
    if (month < 1 || month > 12)
    {
        month = 1;
    }
    if (year < 1900)
    {
        year = 1900;
    }
}

Date::Date(int m, int y) : day(1), month(m), year(y)
{
    // Value should only be assigned within valid ranges
    if (month < 1 || month > 12)
    {
        month = 1;
    }
    if (year < 1900)
    {
        year = 1900;
    }
}

Date::Date() : day(1), month(1), year(1900) {}

// Mutators
void Date::setDay(int d)
{
    if (d >= 1 && d <= daysInMonth(month, year))
    {
        day = d;
    }
    else
    {
        cout << "Invalid day. Setting to 1." << endl;
        day = 1;
    }
}

void Date::setMonth(int m)
{
    if (m >= 1 && m <= 12)
    {
        month = m;
    }
    else
    {
        cout << "Invalid month. Setting to 1." << endl;
        month = 1;
    }
}

void Date::setYear(int y)
{
    if (y >= 1900)
    {
        year = y;
    }
    else
    {
        cout << "Invalid year. Setting to 1900." << endl;
        year = 1900;
    }
}

// Accessors
int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

// Private helper function to check leap year
bool Date::isLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Private helper function to get the number of days in a month
int Date::daysInMonth(int month, int year) const
{
    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

// Overloaded stream insertion operator (<<)
ostream &operator<<(ostream &os, const Date &date)
{
    static const string monthNames[] = {"January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December"};
    os << monthNames[date.month - 1] << " " << date.day << ", " << date.year;
    return os;
}

// Overloaded stream extraction operator (>>)
istream &operator>>(istream &is, Date &date)
{
    char slash;
    is >> date.day >> slash >> date.month >> slash >> date.year;
    return is;
}

// Overloaded pre-increment operator (++)
Date &Date::operator++()
{
    day++;
    if (day > daysInMonth(month, year))
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *this;
}

// Overloaded post-increment operator (++)
Date Date::operator++(int)
{
    Date temp(*this);
    operator++();
    return temp;
}

// Overloaded pre-decrement operator (--)
Date &Date::operator--()
{
    day--;
    if (day < 1)
    {
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
    return *this;
}

// Overloaded post-decrement operator (--)
Date Date::operator--(int)
{
    Date temp(*this);
    operator--();
    return temp;
}

// Overloaded subtraction operator (-)
int Date::operator-(const Date &otherDate) const
{
    int days = 0;
    Date temp = *this;

    // Subtract days from temp until it matches otherDate
    while (!(temp.day == otherDate.day && temp.month == otherDate.month && temp.year == otherDate.year))
    {
        temp--;
        days++;
    }

    return days;
}

// Overloaded unary addition operator (+)
bool Date::operator+() const
{
    return (month == 2 && day == 5) || (month == 3 && day == 23) || (month == 5 && day == 1);
}

int main()
{
    Date date1(18, 11, 2021);
    Date date2(10, 11, 2021);
    Date date3(31, 12, 2021);

    cout << "Date 1: " << date1 << endl;
    cout << "Date 2: " << date2 << endl;
    cout << "Date 3: " << date3 << endl;

    cout << "\nIncrementing Date 1: ";
    for (int i = 0; i < 10; i++)
    {
        cout << date1++ << " ";
    }

    cout << "\n\nDecrementing Date 3: ";
    for (int i = 0; i < 5; i++)
    {
        cout << date3-- << " ";
    }

    cout << "\n\nEnter a date (dd/mm/yyyy): ";
    cin >> date1;
    cout << "You entered: " << date1 << endl;

    cout << "\nIs Date 1 a public holiday? " << (+(date1) ? "Yes" : "No") << endl;

    return 0;
}
