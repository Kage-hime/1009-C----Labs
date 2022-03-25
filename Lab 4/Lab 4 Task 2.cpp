#include <iostream>
#include <string>


using namespace std;


class SailingBoat
{
    private:
        string boatName;
        double distance;
    
    public:
        SailingBoat(string s , double d )
        {
            this->boatName = s;
            this-> distance = d;
        }
        string getName()
        {
            return this->boatName;
        }

    friend double operator / (SailingBoat const &boat1, SailingBoat const &boat2)
    {
        return boat1.distance / boat2.distance;
    }

    friend ostream& operator << (ostream& out , SailingBoat const &boat )
    {

        return out << boat.boatName << " " << boat.distance << "m." <<endl;
    }

};


int main()
{
    SailingBoat boat1("SE", 660);
	SailingBoat boat2("IS", 880);

    double ratio;
	ratio = boat1 / boat2;
	cout << boat1.getName() << " " << int(ratio * 100) << "% dist of " << boat2.getName() << endl;
	cout << boat1;
	cout << boat2;

	return 0;


}
