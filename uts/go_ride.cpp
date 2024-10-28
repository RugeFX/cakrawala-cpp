#include <iostream>
#include <iomanip>
#include <string>
#include "pembayaran.h"

using namespace std;

/*
Instruksi No 1 (GoRide):
- Pengguna menginputkan Jarak Tempuh dan Metode Pembayaran (GoPay/Cash)
- Sebagai informasi tarif layanan ini adalah Rp 3500/km
- Output yang diharapkan adalah Jarak Tempuh, Metode Pembayaran, dan Nominal Tagihan
*/
namespace go_ride
{
    const double TARIF_PER_KM = 3500.0;

    void proses()
    {
        double jarak;

        cout << "==============================================" << endl;
        cout << "Welcome to GoRide!" << endl;
        cout << "==============================================" << endl;

        cout << "Masukkan jarak tempuh (Km): ";
        cin >> jarak;

        double nominal_awal = jarak * TARIF_PER_KM;

        pair<string, double> bayar = pembayaran::proses(nominal_awal);

        cout << fixed << setprecision(2);
        cout << "==============================================" << endl;
        cout << "Jarak tempuh: " << jarak << "Km" << endl;
        cout << "Metode pembayaran: " << bayar.first << endl;
        cout << "Nominal pembayaran: Rp." << bayar.second << endl;
        cout << endl
             << "Terimakasih telah menggunakan aplikasi GoRide!" << endl;
        cout << "==============================================" << endl;
    }
}