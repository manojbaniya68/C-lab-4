/*Create a class publication that stores the title and price of a 
publication. From this class derive two classes:book, which adds a 
page count and tape, which adds a playing time in minutes. Each of 
these three classes should have getdata() function to get its data 
from the user at the keyboard and putdata() function to display its 
data.
*/


#include<iostream>
using namespace std;

class publication
{
    protected:
    string title;
    float price;  // price in dollor

    public:
      void getDate()
      {
        cout<<"Enter the title of publication : "<<endl;
        fflush(stdin);
        getline(cin,title);
        cout<<"Enter the price of publication: "<<endl;
        cin>>price;
      }

      void putData()
      {
        cout<<"Book Publication : "<<title<<endl;
      }
};

class Book : public publication {
    int pageCount;
    public:
     void getDate()
     {
        cout<<"Enter the Book Details : "<<endl;
        publication :: getDate();
        cout<<"Enter the number of pages : "<<endl;
        cin>>pageCount;
     }

     void putData()
      {
        cout<<"------------------------------------"<<endl;
        publication :: putData();
        cout<<"Page Count       : "<<pageCount<<endl;
        cout<<"------------------------------------"<<endl;
      }
};

class tape : public publication{
    int playingTimeInMinutes;
    public:
    void getData()
    {
        cout<<"Enter the Tape Details : "<<endl;
        publication :: getDate();
        cout<<"Enter the total playing time in minutes : "<<endl;
        cin>>playingTimeInMinutes;
    }

    void putData()
      {
        cout<<"------------------------------------"<<endl;
        publication :: putData();
        cout<<"Playing time     : "<<playingTimeInMinutes<<" Minutes"<<endl;
        cout<<"------------------------------------"<<endl;
      }
};
int main()
{
    Book b;
    tape t;
    b.getDate();
    system("cls");
    t.getData();
    system("cls");
    cout<<endl<<"Book Details is : "<<endl;
    b.putData();
    cout<<endl<<"Tape Details is : "<<endl;
    t.putData();
    return 0;
}