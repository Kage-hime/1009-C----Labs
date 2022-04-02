#include <iostream>
#include <string>

using namespace std;

class Inventory {
	friend ostream& operator << (ostream&, const Inventory&);
	friend istream& operator >> (istream&, Inventory&);
private:
	int stockNum;
	int quantity;
	double price;
public:
	Inventory(const int = 0, const int = 0, const double = 0.0);
	void setAllToZero();
};
void Inventory::setAllToZero() {
	stockNum = 0;
	quantity = 0;
	price = 0;
}

Inventory::Inventory(int s, int q, double p)
{
    this->stockNum = s;
    this->quantity = q;
    this->price = p;
}

ostream& operator << (ostream& out, const Inventory& itm) 
{
    return out << "id " << itm.stockNum << " quantity: " << itm.quantity << " price " << itm.price<< endl;
}
istream& operator >> (istream& in, Inventory& itm) 
{
    int s, q;
    double p;
    cout << "Enter id ";
    in >> s;
    if( s < 1 || s > 999)
        throw string("out of range");  
    cout << "Enter quantity "; 
    in >> q;
    if(q < 0)
        throw 1;
    cout << "Enter price ";
    in >> p;
    if(p > 1000.0)
        throw 0.0;

    itm.price = p;
    itm.quantity = q;
    itm.stockNum = s;
    return in >> s >> q >> p;
    
}



int main() {
	const int NUM = 2;
	Inventory item[NUM];
	int x;
	for (x = 0; x < NUM; ++x) {
		try {
			cin >> item[x];
		}
		catch (const string msg) {
			cout << msg << endl;
			item[x].setAllToZero();
		}
		catch (const int quantity) {
			cout << "negative" << endl;
			item[x].setAllToZero();
		}
		catch (const double price) {
			cout << "too high" << endl;
			item[x].setAllToZero();
		}
	}
	for (x = 0; x < NUM; ++x)
		cout << item[x];
	
	return 0;
}
