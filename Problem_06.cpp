#include <iostream>
#include <cstring>
using namespace std;
class student
{
protected:
  int rn;
  char name[30];

public:
  void getData()
  {
    cout << "Enter the name: ";
    cin.getline(name,30);
    cout << "Enter the roll number: ";
    cin >> rn;
  }
  void displayData()
  {
    cout << "Name             : " << name << endl
         << "Roll Number      : " << rn << endl;
  }
};

class InternalExam : virtual public student
{
protected:
  int m[7];

public:
  void getMarks()
  {
    cout << "Enter the marks of seven subjects of Internal Exam : " << endl;
    for (int i = 0; i < 7; i++)
    {
      cin >> m[i];
    }
  }
};
class FinalExam : virtual public student
{
protected:
  int m[7];

public:
  void getMarks()
  {
    cout << "Enter the marks of seven subjects of Final Exam : " << endl;
    for (int i = 0; i < 7; i++)
    {
      cin >> m[i];
    }
  }
};

class AverageMarks : public FinalExam, public InternalExam
{
  float averageMarks, sum = 0;

public:
  void calculate()
  {
    for (int i = 0; i < 7; i++)
    {
      sum += (FinalExam::m[i] + InternalExam::m[i]);
    }
    averageMarks = sum / 14;
  }

  void display()
  {
    cout <<endl<< "----------------------------------------------" << endl;
    calculate();
    displayData();
    cout << "Average marks is : " << averageMarks << endl;
    cout << "----------------------------------------------" << endl;
  }
};

int main()
{
  AverageMarks avg;
  avg.getData();
  avg.InternalExam::getMarks();
  avg.FinalExam::getMarks();

  avg.display();
  return 0;
}