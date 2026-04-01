//Marshon Sellers

#include <iostream>
using namespace std;

class Appliance
{
public:
    virtual void turnOn() = 0;

};

class Fan : public Appliance
{
public:
    void turnOn()
    {
        cout << "Fan starts rotating\n";;
    }
};


class AirConditioner : public Appliance
{
public:
    void turnOn()
    {
        cout << "Air Conditioner starts cooling\n";
    }
};




int main()
{

    Fan fan_object;
    AirConditioner air_conditioner_object;

    fan_object.turnOn();
    air_conditioner_object.turnOn();


    return 0;
}
