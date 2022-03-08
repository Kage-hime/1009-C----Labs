#include <iostream>
#include <string>

using namespace std;

class Pizza
{
    private:
        string topping;
        int diameter;
        double price;
        const static string STTOP;
        const static int STSIZE ;
        const static double STPRICE; 

    public:
        Pizza(const string = STTOP, const int = STSIZE, const double = STPRICE);
        void setValues();
        void displayValues();
};

const string Pizza::STTOP = "cheese";
const int Pizza::STSIZE = 12;
const double Pizza::STPRICE = 8.99;

Pizza::Pizza(const string topping, const int size, const double price)
{
    this->topping = topping;
    this->diameter = size;
    this->price = price;

};

void Pizza::setValues()
{
    if(this->topping != STTOP)
        this->price += 1;
    if(this->diameter != STSIZE)
        this->price += 1.5;

}

void Pizza::displayValues()
{
    cout << this->diameter<< " " << this->topping<< " " << this->price<<endl;

}


int main()
{
  
    Pizza stdPizza;
    Pizza special("pineapple");
    Pizza deluxeSpecial("sausage",16);
    Pizza veryDeluxeSpecial("lobster",20,17.99);
    cout << "Standard "; stdPizza.displayValues();
    cout << "Special "; special.displayValues();
    cout << "Deluxe "; deluxeSpecial.displayValues();
    cout << "Very Deluxe "; veryDeluxeSpecial.displayValues();
  
    string newTopping;
    int newSize;
    cout << "Topping ";
    cin >> newTopping;
    cout << "Size ";
    cin >> newSize;
    Pizza newPizza(newTopping, newSize);
    newPizza.setValues(); 
    cout << "New "; newPizza.displayValues();
    return 0;
}