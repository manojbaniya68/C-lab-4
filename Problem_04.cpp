#include<iostream>
using namespace std;

class Date 
{
        int day,month,year;
  public:
      Date(int day = 12, int month = 12 , int year = 2060): day(day),month(month),year(year){}
        // ~Date();
        void display(); // displays the date
        Date get(); //  accesses the date members
        void set();     // sets the date members
 };

 void Date :: display()
 {
    cout<<"Date : "<<year<<"-"<<month<<"-"<<day<<endl;
 }
 Date Date :: get()
 {
    return *this;
 }
 void Date :: set()
 {
    cout<<"Enter the date in YY:MM:DD formate: ";
    cin>>year>>month>>day;
 }


 class Time 
{
        int hour;
        int minute;
        int second;
  public:
        Time(int hr = 0, int min = 0, int sec = 0): hour(hr),minute(min),second(sec){}
        // ~Time();
        void display(); // displays the time
        Time get();// accesses the time members
        void set(); // sets the time members
 };

 void Time :: display()
 {
    cout<<"Time : "<<hour<<":"<<minute<<":"<<second<<endl;
 }
 Time Time :: get()
 {
    return *this;
 }
 void Time :: set()
 {
    cout<<"Enter the time in HH:MM:SS formate : ";
    cin>>hour>>minute>>second;
 }


 class DateAndTime : public Date, public Time 
{      
  public:
      void display(); // prints date and time
 };
 void DateAndTime :: display()
 {
    Date :: display();
    Time :: display();
 }

int main()
{
    DateAndTime Watch;
    Watch.display();
    Watch.Date::set();
    Watch.Time::set();
    Watch.display();

    
    
    return 0;
}