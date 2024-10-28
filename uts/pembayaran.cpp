#include <iostream>
#include <string>

using namespace std;

namespace pembayaran
{
    const double DISKON_GOPAY = 0.2;

    std::pair<std::string, double> proses(double nominal)
    {
        pair<string, double> hasil;

        while (true)
        {
            cout << "Masukkan Metode Pembayaran (GoPay / Cash): ";
            cin >> hasil.first;

            if (hasil.first == "GoPay" || hasil.first == "Cash")
                break;

            cout << "Metode pembayaran tidak didukung! Tolong masukkan metode yang terdukung (GoPay / Cash)";
        }

        hasil.second = hasil.first == "GoPay" ? nominal - (nominal * DISKON_GOPAY) : nominal;

        return hasil;
    }
}