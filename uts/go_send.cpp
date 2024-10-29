#include <iostream>
#include <iomanip>
#include <string>
#include "pembayaran.h"

using namespace std;

/*
Instruksi No 3 (GoSend):
- Pengguna menginputkan Jarak Tempuh, Berat Barang, Volume Barang, dan Metode Pembayaran (GoPay/Cash)
- Formula perhitungan tarif = Jarak Tempuh Berat Barang Volume Barang * 5000
- Jika Volume Barang lebih dari 50 maka akan ada tambahan tarif flat sebesar Rp 25rb
- Output yang diharapkan adalah Jarak Tempuh, Berat Barang, Volume Barang, Metode Pembayaran, dan Nominal Tagihan
*/
namespace go_send
{
    const double TARIF = 5000.0, TARIF_TAMBAHAN = 25000.0;

    void proses()
    {
        cout << "===============================================" << endl;
        cout << "               Welcome to GoSend!              " << endl;
        cout << "===============================================" << endl;

        double jarak;
        cout << "Masukkan jarak tempuh: ";
        cin >> jarak;

        double berat;
        cout << "Masukkan berat barang: ";
        cin >> berat;

        double volume;
        cout << "Masukkan volume barang: ";
        cin >> volume;

        double nominal_awal = jarak * berat * volume * TARIF;

        pair<string, double> bayar = pembayaran::proses(nominal_awal);

        if (volume > 50.0)
            bayar.second += TARIF_TAMBAHAN;

        cout << fixed << setprecision(2);
        cout << "===============================================" << endl;
        cout << "Jarak tempuh: " << jarak << endl;
        cout << "Berat barang: " << berat << endl;
        cout << "Volume barang: " << volume << endl;
        cout << "Metode pembayaran: " << bayar.first << endl;
        cout << "Nominal pembayaran: Rp." << bayar.second;
        if (volume > 50.0)
            cout << " (termasuk tarif tambahan sebesar Rp." << TARIF_TAMBAHAN << ")";
        cout << endl;
        cout << endl
             << "Terimakasih telah menggunakan aplikasi GoFood!" << endl;
        cout << "===============================================" << endl;
    }
}