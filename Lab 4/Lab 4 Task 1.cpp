#include <string>
#include <iostream>

using namespace std;

class Product;
class Box
{
    private:
        double volume;
    public:
        void setVolume(double);
    friend bool checkSize(Box , Product);
    

};


class Product
{
    private:
        double length;
        double width;
        double depth;
    public:
        void setDimensions(double, double, double);
    friend bool checkSize(Box, Product);
    

};

void Box::setVolume(double vol)
{
    this->volume = vol;
}

void Product::setDimensions(double l , double w, double d)
{
    this->depth = d;
    this->length = l;
    this->width = w;
}

bool checkSize(Box b, Product p)
{

    return ( (p.length * p.width * p.depth) < b.volume );

}


int main()
{
    double vol, len, wid, dep;

    Box newbox;
    Product newpro;

    cout << "Vol: ";
    cin >> vol;
    newbox.setVolume(vol);
    
    cout << "\nL W D: ";
    cin >> len;
    cin >> wid;
    cin >> dep;

    newpro.setDimensions(len, wid, dep);

    cout <<"Fit? "<< checkSize(newbox, newpro) << endl;


    return 0 ;
};