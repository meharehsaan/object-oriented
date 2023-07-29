#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int regNo;
    string firstName;
    string lastName;
    string program;
    float cgpa;

public:
    // Constructors
    Student(int reg, const string &fName, const string &lName, const string &prog);
    Student(int reg, const string &fName, const string &prog);
    Student(int reg, const string &fName, const string &lName, const string &prog, float cgpa);
    Student(const Student &otherStudent);

    // Destructor
    ~Student();

    // Mutators
    void setRegistrationNumber(int reg);
    void setFirstName(const string &fName);
    void setLastName(const string &lName);
    void setProgram(const string &prog);
    void setCGPA(float cgpa);

    // Accessors
    int getRegistrationNumber() const;
    string getFirstName() const;
    string getLastName() const;
    string getProgram() const;
    float getCGPA() const;

    // Member functions
    void set(int reg, const string &fName, const string &lName, const string &prog, float cgpa);
    void read();
    void write() const;
    bool isFirstSemester() const;
    float getPercentage() const;
    bool isPromoted() const;
};

// Constructor with all arguments
Student::Student(int reg, const string &fName, const string &lName, const string &prog, float cgpa)
    : regNo(reg), firstName(fName), lastName(lName), program(prog), cgpa(cgpa) {}

// Constructor with regNo, firstName, and program only
Student::Student(int reg, const string &fName, const string &prog)
    : regNo(reg), firstName(fName), program(prog), cgpa(-1) {}

// Constructor with regNo, firstName, and program only
Student::Student(int reg, const string &fName, const string &lName, const string &prog)
    : regNo(reg), firstName(fName), lastName(lName), program(prog), cgpa(-1) {}

// Copy constructor
Student::Student(const Student &otherStudent)
    : regNo(otherStudent.regNo), firstName(otherStudent.firstName),
      lastName(otherStudent.lastName), program(otherStudent.program), cgpa(otherStudent.cgpa) {}

// Destructor
Student::~Student()
{
    cout << "Destructor executed..." << endl;
}

// Mutators
void Student::setRegistrationNumber(int reg)
{
    if (reg >= 501 && reg <= 565)
    {
        regNo = reg;
    }
    else
    {
        cout << "Invalid registration number. Setting to 0." << endl;
        regNo = 0;
    }
}

void Student::setFirstName(const string &fName)
{
    firstName = fName;
}

void Student::setLastName(const string &lName)
{
    lastName = lName;
}

void Student::setProgram(const string &prog)
{
    program = prog;
}

void Student::setCGPA(float cgpa)
{
    if (cgpa >= 0.0 && cgpa <= 4.0)
    {
        this->cgpa = cgpa;
    }
    else
    {
        cout << "Invalid CGPA. Setting to -1." << endl;
        this->cgpa = -1;
    }
}

// Accessors
int Student::getRegistrationNumber() const
{
    return regNo;
}

string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

string Student::getProgram() const
{
    return program;
}

float Student::getCGPA() const
{
    return cgpa;
}

// Member functions
void Student::set(int reg, const string &fName, const string &lName, const string &prog, float cgpa)
{
    setRegistrationNumber(reg);
    setFirstName(fName);
    setLastName(lName);
    setProgram(prog);
    setCGPA(cgpa);
}

void Student::read()
{
    cout << "Enter Registration Number (between 501 and 565): ";
    cin >> regNo;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    cout << "Enter Program: ";
    cin >> program;

    cout << "Enter CGPA (between 0.0 and 4.0): ";
    cin >> cgpa;
}

void Student::write() const
{
    cout << "Registration Number: " << regNo << endl;
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Program: " << program << endl;
    cout << "CGPA: " << cgpa << endl;
}

bool Student::isFirstSemester() const
{
    return cgpa == -1;
}

float Student::getPercentage() const
{
    return (cgpa >= 0) ? (cgpa / 4.0) * 100.0 : -1;
}

bool Student::isPromoted() const
{
    return cgpa >= 2.0;
}

int main()
{
    Student s1(501, "John", "Doe", "Computer Science", 3.5);
    Student s2(502, "Alice", "Smith", "Electrical Engineering");
    Student s3(503, "Bob", "Johnson", "Mechanical Engineering", 3.0);

    s2.setCGPA(3.8);

    s1.write();
    cout << "Percentage: " << s1.getPercentage() << "%" << endl;
    cout << "Promoted: " << (s1.isPromoted() ? "Yes" : "No") << endl;
    cout << "First Semester: " << (s1.isFirstSemester() ? "Yes" : "No") << endl;
    cout << endl;

    s2.write();
    cout << "Percentage: " << s2.getPercentage() << "%" << endl;
    cout << "Promoted: " << (s2.isPromoted() ? "Yes" : "No") << endl;
    cout << "First Semester: " << (s2.isFirstSemester() ? "Yes" : "No") << endl;
    cout << endl;

    s3.write();
    cout << "Percentage: " << s3.getPercentage() << "%" << endl;
    cout << "Promoted: " << (s3.isPromoted() ? "Yes" : "No") << endl;
    cout << "First Semester: " << (s3.isFirstSemester() ? "Yes" : "No") << endl;

    return 0;
}
