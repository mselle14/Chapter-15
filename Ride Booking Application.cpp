//Marshon Sellers

#include <iostream>
using namespace std;

class Ride
{
public:
    virtual void bookRide() = 0;

};

class BikeRide : public Ride
{
public:
    void bookRide()
    {
        cout << "Bike ride booked\n";
    }
};


class CarRide : public Ride
{
public:
    void bookRide()
    {
        cout << "Car ride booked\n";
    }
};




int main()
{
    Ride* ride_pointer;
    
    BikeRide bike_object;
    CarRide car_object;

    ride_pointer = &bike_object;
    ride_pointer->bookRide();

    ride_pointer = &car_object;
    ride_pointer->bookRide();


    return 0;
}
