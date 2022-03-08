#include <iostream>
#include "Name.h"
#include "CreditData.h"


using namespace std;

class Customer
{
    private:
        Name name;
        CreditData credit;
        string phoneNumber;

    public:
        Customer(string,string,double,double,string);
        void showCustomer();

};

Customer::Customer(string first, string last, double balance, double limit, string phone)
{
    this->name = Name(first,last);
    this->credit = CreditData(balance, limit);
    this->phoneNumber = phone;

}

void Customer::showCustomer()
{
    cout <<"Customer ";
    this->name.displayFullName();
    cout << this->phoneNumber<< endl;
    this->credit.displayCreditData();

}


int main()
{   
    int x;
    const int TIMES = 1;
    string first, middle,last,phone;
    double bal, lim;

    for (x = 0; x < TIMES; x++)
    {
        cout<<"Fname ";
        cin>> first;
        cout<<"Lname ";
        cin>> last;
        cout<<"Balance ";
        cin>> bal;
        cout<<"Limit ";
        cin>> lim;
        cout<<"Phone ";
        cin>> phone;

        Customer cust(first,last,bal,lim,phone);
        cust.showCustomer();
    }

    return 0;
}