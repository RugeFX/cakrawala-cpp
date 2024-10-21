#include <iostream>
#include <string>

using namespace std;

double input_nominal(int total_transaksi);
double hitung_point(double total_nominal);
string tentukan_level(double point);

int main()
{
    double total_nominal = input_nominal(5);
    double point = hitung_point(total_nominal);
    string level = tentukan_level(point);

    cout << "Nominal Belanja: " << total_nominal << endl;
    cout << "Total Point: " << point << endl;
    cout << "Level: " << level << endl;
}

double input_nominal(int total_transaksi)
{
    double total_nominal = 0.0;
    for (int i = 0; i < total_transaksi; i++)
    {
        double nominal;
        cout << "Masukkan nominal transaksi belanja ke-" << i + 1 << ": ";
        cin >> nominal;
        total_nominal += nominal;
    }
    return total_nominal;
}

double hitung_point(double total_nominal)
{
    if (total_nominal > 1000000)
    {
        return total_nominal * 0.1;
    }
    else if (total_nominal >= 500000 && total_nominal <= 1000000)
    {
        return total_nominal * 0.05;
    }
    else
    {
        return 0;
    }
}

string tentukan_level(double point)
{
    if (point < 25000)
    {
        return "Bronze";
    }
    else if (point >= 25000 && point < 50000)
    {
        return "Silver";
    }
    else if (point >= 50000 && point < 300000)
    {
        return "Gold";
    }
    else
    {
        return "Platinum";
    }
}