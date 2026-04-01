//Marshon Sellers

#include <iostream>
using namespace std;

class OrderStatus
{
public:
    virtual void showStatus()
    {
        cout << "Status Currently Unavailable\n";
    }

};

class Preparing : public OrderStatus
{
public:
    void showStatus()
    {
        cout << "Order is being Prepared!\n";
    }
};


class OutForDelivery : public OrderStatus
{
public:
    void showStatus()
    {
        cout << "Order is on its Way!\n";
    }
};

class Delivered : public OrderStatus
{
public :
    void showStatus()
    {
        cout << "Order has been Delivered.\n";
    }
};



int main()
{

    OrderStatus *status_pointer;

    Preparing preparing_object;
    OutForDelivery out_for_delivery_object;
    Delivered delivery_object;

    status_pointer = &preparing_object;
    status_pointer->showStatus();

    status_pointer = &out_for_delivery_object;
    status_pointer->showStatus();

    status_pointer = &delivery_object;
    status_pointer->showStatus();


    return 0;
}
