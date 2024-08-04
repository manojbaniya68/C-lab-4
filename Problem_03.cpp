/*. Modify Q.2 to add base class sales that holds an array of three 
floats so that it can record the dollar sales of a particular 
publication for the last three months. Include getdata() function to 
get three Sales amount from the user and a putdata() function to 
display sales figures. Alter the book and tape classes so they are 
derived from both publication and sales. An object of class book or 
tape should input and output sales data along with its other data.*/

#include<iostream>
using namespace std;

class sales{
    protected:
     float sale[3];

     public:
       sales()
       {
          for(int i = 0;i<3;i++)
            sale[i] = 0.0f;
       }
       void getData()
       {
          cout<<"Enter the sales amount for last three months: "<<endl;
          for(int i = 0;i<3;i++)
          {
            cout<<"Month "<<(i + 1)<<endl;
            cin>>sale[i];
          }
       }
       void putData()
       {
          cout<<"------------------------------------------"<<endl;
          cout<<"Sales Figures for last three months are : "<<endl;
          int index = 0;
          for(auto b : sale)
          {
              cout<<"Month "<<(index + 1)<<" : $"<<b<<endl;
              index++;
          }
          cout<<"------------------------------------------"<<endl;
       }
};

class publication
{
    protected:
    string title;
    float price;  // price in dollor

    public:
      void getData()
      {
        cout<<"Enter the title of publication : "<<endl;
        fflush(stdin);
        getline(cin,title);
        cout<<"Enter the price of publication: "<<endl;
        cin>>price;
      }

      void putData()
      {
        cout<<"Book Publication     : "<<title<<endl;
        cout<<"Price of Publication : "<<price<<endl;
      }
};

class Book : public publication ,public sales {
    int pageCount;
    public:
     void getData()
     {
        publication :: getData();
        sales :: getData();
        cout<<"Enter the number of pages in the book: "<<endl;
        cin>>pageCount;
     }

     void putData()
      {
        cout<<"---------------------------------------------------------"<<endl;
        publication :: putData();
        sales :: putData();
        cout<<"Page Count           : "<<pageCount<<endl;
        cout<<"---------------------------------------------------------"<<endl;
      }
};

class tape : public publication,public sales{
    int playingTimeInMinutes;
    public:
    void getData()
    {
        publication :: getData();
        sales :: getData();
        cout<<"Enter the total playing time in minutes : "<<endl;
        cin>>playingTimeInMinutes;
    }

    void putData()
      {
        cout<<"---------------------------------------------------------"<<endl;
        publication :: putData();
        sales :: putData();
        cout<<"Playing time        : "<<playingTimeInMinutes<<" Minutes"<<endl;
        cout<<"---------------------------------------------------------"<<endl;
      }
};
int main()
{
    Book b;
    tape t;
    cout<<"Enter data for book : \n";
    b.getData();
    system("cls");
    cout<<"Enter data for tape: \n";
    t.getData();

    system("cls");
    cout<<"Book Details : "<<endl;
    b.putData();
    
    cout<<endl;
    cout<<"Tape Details : "<<endl;
    t.putData();
    return 0;
}