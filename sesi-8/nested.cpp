#include <iostream>
#include <string>

using namespace std;

int main()
{
    double amount;
    string currency;

    cout << "Pengen beli Laptop Rp.15.000.000 / $1.000 'o'" << endl;

    cout << "Masukkan Jumlah Uang: ";
    cin >> amount;

    cout << "Masukkan Tipe Currency (IDR / USD): ";
    cin >> currency;

    if (currency == "IDR")
    {
        if (amount >= 15000000.0)
        {
            cout << "Kamu bisa beli laptop ini :)";
        }
        else
        {
            cout << "Kamu belum bisa beli laptop ini :(";
        }
    }
    else if (currency == "USD")
    {
        if (amount >= 1000.0)
        {
            cout << "You can buy this laptop :)";
        }
        else
        {
            cout << "You cannot buy this laptop yet :(";
        }
    }
}