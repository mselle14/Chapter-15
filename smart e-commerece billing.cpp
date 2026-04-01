//Marshon Sellers

#include <iostream>
#include <string>
using namespace std;

class BillCalculator
{
    public:
        int calculateBill(int product_price, int shipping_charge)
        {
            return product_price + shipping_charge;
        }

        double calculateBill(double product_price, double tax_rate)
        {
            return product_price + (product_price * tax_rate);
        }

        double calculateBill(double product_price, double tax_rate, double discount)
        {
            return (product_price + (product_price * tax_rate)) - discount;
        }
};

class PaymentMethod
{
protected:
    string customer_name;
    double amount;
    string transaction_id;

public:
    void setPaymentDetails(string name, double payment_amount, string id)
    {
        customer_name = name;
        amount = payment_amount;
        transaction_id = id;
    }

    void displayPaymentDetails()
    {
        cout << "----- PAYMENT DETAILS -----" << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Transaction ID: " << transaction_id << endl;
        cout << "Amount: " << amount << endl;
    }

    virtual void pay() = 0;
};


class UPIPayment : public PaymentMethod
{
private:
    string upi_id;

public:
    void setUPIDetails(string id)
    {
        upi_id = id;
    }

    void pay()
    {
        cout << "Payment Method: UPI" << endl;
        cout << "UPI ID: " << upi_id << endl;
        cout << "UPI payment successful!" << endl;
    }
};

class CardPayment : public PaymentMethod
{
private:
    string bank_name;

public:
    void setCardDetails(string bank)
    {
        bank_name = bank;
    }

    void pay()
    {
        cout << "Payment Method: Card" << endl;
        cout << "Bank Name: " << bank_name << endl;
        cout << "Card payment successful!" << endl;
    }
};

class WalletPayment : public PaymentMethod
{
private:
    string wallet_name;

public:
    void setWalletDetails(string wallet)
    {
        wallet_name = wallet;
    }

    void pay()
    {
        cout << "Payment Method: Wallet" << endl;
        cout << "Wallet Name: " << wallet_name << endl;
        cout << "Wallet payment successful!" << endl;
    }
};

int main()
{
    BillCalculator bill_object;

    string customer_name;
    int product_price;
    int shipping_charge;
    double tax_rate;
    double discount;
    string upi_id;
    string bank_name;
    string wallet_name;

    cout << "Enter customer name: ";
    getline(cin, customer_name);

    cout << "Enter product price: ";
    cin >> product_price;

    cout << "Enter shipping charge: ";
    cin >> shipping_charge;

    cout << "Enter tax rate: ";
    cin >> tax_rate;

    cout << "Enter discount: ";
    cin >> discount;

    cin.ignore();

    cout << "Enter UPI ID: ";
    getline(cin, upi_id);

    cout << "Enter bank name: ";
    getline(cin, bank_name);

    cout << "Enter wallet name: ";
    getline(cin, wallet_name);

    int total_with_shipping = bill_object.calculateBill(product_price, shipping_charge);

    double total_with_tax = bill_object.calculateBill((double)product_price, tax_rate);

    double final_total = bill_object.calculateBill((double)product_price, tax_rate, discount);

    cout << endl;
    cout << "Customer Name: " << customer_name << endl;
    cout << "Total using product price and shipping: " << total_with_shipping << endl;
    cout << "Total using product price and tax: " << total_with_tax << endl;
    cout << "Total using product price, tax and discount: " << final_total << endl;
    cout << endl;

    PaymentMethod* payment_pointer;

    UPIPayment upi_object;
    CardPayment card_object;
    WalletPayment wallet_object;

    upi_object.setPaymentDetails(customer_name, final_total, "TXN1001");
    upi_object.setUPIDetails(upi_id);

    card_object.setPaymentDetails(customer_name, final_total, "TXN1002");
    card_object.setCardDetails(bank_name);

    wallet_object.setPaymentDetails(customer_name, final_total, "TXN1003");
    wallet_object.setWalletDetails(wallet_name);

    payment_pointer = &upi_object;
    payment_pointer->displayPaymentDetails();
    payment_pointer->pay();

    cout << endl;

    payment_pointer = &card_object;
    payment_pointer->displayPaymentDetails();
    payment_pointer->pay();


    return 0;
}