#include <string>
#include <iostream>

using namespace std;


class Car
{
    protected:
        bool isIgnitionOn;
        int speed;

    public:
        void turnIgnitionOn()
        {
            this->isIgnitionOn = true;
        };

        void turnIgnitionOff()
        {
            this->isIgnitionOn = false;
            this->speed = 0;
        };

        void setSpeed(int speed)
        {
            if(this->isIgnitionOn)
                if(speed <= 65)
                    this->speed = speed;
                else
                    this->speed = 65;           
        };

        void showCar()
        {
            if(isIgnitionOn)
                cout << "Ignition is on. Speed is " << this->speed <<"mph"<<endl;
            else
                cout << "Ignition is off. Speed is " << this->speed <<"mph"<<endl;    
        };

};


class Convertible: virtual public Car
{
    protected:
        bool isTopUp = true;

    public:
        void putTopUp()
        {
            this->isTopUp = true;
        };

        void putTopDown()
        {
            this->isTopUp = false;
        };

        void showCar()
        {
            // if(isIgnitionOn)
            //     cout << "Ignition is on. Speed is " << this->speed <<"mph"<<endl;
            // else
            //     cout << "Ignition is off. Speed is " << this->speed <<"mph"<<endl;

            Car::showCar();
            //cout << "Ignition is " << (isIgnitionOn ? "on" : "off") <<". Speed is " << this->speed <<" mph"<<endl;

            cout <<"Top is " << (isTopUp ? "up" : "down") << endl;
        };


};


class RaceCar: virtual public Car
{
    public:
        void setSpeed(int speed)
        {
            if(this->isIgnitionOn)
                if(speed <= 200)
                    this->speed = speed;
                else
                    this->speed = 200;           
        };


};

class ConvertibleRaceCar : public Convertible, public RaceCar
{

};

int main()
{
    ConvertibleRaceCar newcar;
    newcar.turnIgnitionOn();
    newcar.showCar();
    

    return 0;
}