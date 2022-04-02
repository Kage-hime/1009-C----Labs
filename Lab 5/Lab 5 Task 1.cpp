#include <iostream>
#include <string>

using namespace std;

template<class T>
class Array {
private:
	T* data;
	int size;
public:
	Array(T* d, int s);
	void showList();
	void showFirst();
};

class Vehicle {
	friend ostream& operator<<(ostream&, const Vehicle&);
	string name;
	double price;
public:
	void setVehicle(string, double);
};

template<typename T>
Array<T>::Array(T*d, int s)
{
    data = new T[s];
    size = s;
    for(int i  = 0; i < size ; i++)
        data[i] = d[i];
}

template <typename T>
void Array<T>::showList()
{
	cout << "showList()";
    for (int i = 0; i < size ; i++)
    {
		
        cout << " " << (data[i]);
    }
	cout << endl;
}

template <typename T>
void Array<T>::showFirst()
{
	cout << "showFirst()";
    cout << " " << (data[0]) << endl;
}



void Vehicle::setVehicle(string name, double price)
{
    this->name = name;
    this->price = price;
}

ostream& operator <<(ostream& out, const Vehicle& vehicle)
{
    return out << vehicle.name << " " << vehicle.price; 
}

int main() {
	int arrayElements;
	Vehicle cars[2];
	cars[0].setVehicle("McQueen", 1111);
	cars[1].setVehicle("Mater", 22222);

	arrayElements = sizeof(cars) / sizeof(cars[0]);
	Array<Vehicle> arrayOfVehicles(cars, arrayElements);

	arrayOfVehicles.showList();
	arrayOfVehicles.showFirst();
	
	return 0;
}

