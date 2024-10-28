#include <iostream>
#include <iomanip>
#include <string>
#include "pembayaran.h"

using namespace std;

/*
Instruksi No 2 (GoFood):
- Pengguna menginputkan Kategori Makanan (Nusantara/Barat), Jumlah pesanan (pcs) dan Metode Pembayaran (GoPay/Cash)
- Sebagai informasi harga makanan Nusantara adalah Rp 100rb/pcs dan makanan Barat adalah Rp 150rb/pcs
- Ongkos kirim flat Rp 25rb
- Output yang diharapkan adalah Kategori Makanan, Jumlah Pesanan, Metode Pembayaran, dan Nominal Tagihan
*/
namespace go_food
{
    const double HARGA_NUSANTARA = 100000.0, HARGA_BARAT = 150000.0, ONGKIR = 25000.0;

    void proses()
    {
        cout << "==============================================" << endl;
        cout << "Welcome to GoFood!" << endl;
        cout << "==============================================" << endl;

        string kategori;
        while (true)
        {
            cout << "Masukkan kategori makanan (Nusantara / Barat): ";
            cin >> kategori;

            if (kategori == "Nusantara" || kategori == "Barat")
                break;

            cout << "Kategori salah! Tolong masukkan kategori yang tersedia (Nusantara / Barat)";
        }

        int jumlah;
        cout << "Masukkan jumlah pesanan: ";
        cin >> jumlah;

        double nominal_awal = static_cast<double>(jumlah) * (kategori == "Nusantara" ? HARGA_NUSANTARA : HARGA_BARAT);

        pair<string, double> bayar = pembayaran::proses(nominal_awal);
        bayar.second += ONGKIR;

        cout << fixed << setprecision(2);
        cout << "==============================================" << endl;
        cout << "Kategori makanan: " << kategori << endl;
        cout << "Jumlah pesanan: " << jumlah << endl;
        cout << "Metode pembayaran: " << bayar.first << endl;
        cout << "Nominal pembayaran: Rp." << bayar.second << " (termasuk ongkir sebesar Rp." << ONGKIR << ")" << endl;
        cout << endl
             << "Terimakasih telah menggunakan aplikasi GoFood!" << endl;
        cout << "==============================================" << endl;
    }
}