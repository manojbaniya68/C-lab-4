// Assume class person stores the Name, Age and ID, class employee
// stores the designation, basic salary, total overtime(hr) in a month
// and hourly rate and class computedSalary stores the total salary of
// the employee. Implement above concept using appropriate inheritance

#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string Name;
    int age, Id;
};

class computedSalary : protected Person
{
    protected:
    float totalSalary;
};

class employee : protected computedSalary
{
    string designation;
    float basicSalary;
    int totalOvertimePerMonth;
    float hourlyRate;
public:
     void getInfo()
     {
        cout<<"Enter your name                      : ";
        getline(cin,Name);
        cout<<"Enter your ID                        : ";
        cin>>Id;
        cout<<"Enter your age                       : ";
        cin>>age;
        cout<<"Enter your Designation               : ";
        cin>>designation;
        cout<<"Enter Basic Salary                   : ";
        cin>>basicSalary;
        cout<<"Enter total overtime hours per month : ";
        cin>>totalOvertimePerMonth;
        cout<<"Enter hourly Rate                    : ";
        cin>>hourlyRate;
     }

     void calculateSalary()
     {
        totalSalary = basicSalary + (totalOvertimePerMonth * hourlyRate);
     }

    void displayDetail()
    {
        cout<<"Detail of Employee is : "<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Name         : "<<Name<<endl;
        cout<<"ID           : "<<Id<<endl;
        cout<<"Age          : "<<age<<endl;
        cout<<"Designation  : "<<designation<<endl;
        cout<<"Total Salary : "<<totalSalary<<endl;
        cout<<"----------------------------------------------"<<endl;
    }

};

int main()
{
    employee e;
    e.getInfo();
    e.calculateSalary();
    system("cls");
    e.displayDetail();
    return 0;
}