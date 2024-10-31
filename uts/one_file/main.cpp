#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;

int main()
{
    int layanan;

    cout << "===============================================" << endl;
    cout << "       Selamat datang di aplikasi GoJek!       " << endl;
    cout << "===============================================" << endl;

    while (layanan != 4)
    {
        cout << "Pilih layanan (1. GoRide, 2. GoFood, 3. GoSend, 4. Quit): ";
        cin >> layanan;

        switch (layanan)
        {
        case 1:
            go_ride::proses();
            break;
        case 2:
            go_food::proses();
            break;
        case 3:
            go_send::proses();
            break;
        case 4:
            break;
        default:
            cout << "===============================================" << endl;
            cout << "   Layanan tidak tersedia, mohon input ulang   " << endl;
            cout << "===============================================" << endl;
            break;
        }
    }

    cout << "===============================================" << endl;
    cout << " Terimakasih telah menggunakan aplikasi GoJek! " << endl;
    cout << "===============================================" << endl;
}

/*
Pembayaran
- Biar fungsionalitas pembayaran jadi modular dan bisa dipakai di fungsi lainnya
*/
namespace pembayaran
{
    // cannot redeclare karna dah di declare didalem headerfile (main.h)
    // const double DISKON_GOPAY = 0.2;

    struct HasilPembayaran
    {
        string metode;
        double total;
    };

    HasilPembayaran proses(double nominal)
    {
        HasilPembayaran hasil;

        while (true)
        {
            cout << "Masukkan Metode Pembayaran (GoPay / Cash): ";
            cin >> hasil.metode;

            if (hasil.metode == "GoPay" || hasil.metode == "Cash")
                break;

            cout << "Metode pembayaran tidak didukung! Tolong masukkan metode yang terdukung (GoPay / Cash)" << endl;
        }

        hasil.total = hasil.metode == "GoPay" ? nominal - (nominal * DISKON_GOPAY) : nominal;

        return hasil;
    }
}

/*
Instruksi No 1 (GoRide):
- Pengguna menginputkan Jarak Tempuh dan Metode Pembayaran (GoPay/Cash)
- Sebagai informasi tarif layanan ini adalah Rp 3500/km
- Output yang diharapkan adalah Jarak Tempuh, Metode Pembayaran, dan Nominal Tagihan
*/
namespace go_ride
{
    // const double TARIF_PER_KM = 3500.0;

    void proses()
    {
        double jarak;

        cout << "===============================================" << endl;
        cout << "               Welcome to GoRide!              " << endl;
        cout << "===============================================" << endl;

        cout << "Masukkan jarak tempuh (Km): ";
        cin >> jarak;

        double nominal_awal = jarak * TARIF_PER_KM;

        pembayaran::HasilPembayaran bayar = pembayaran::proses(nominal_awal);

        cout << fixed << setprecision(2);
        cout << "===============================================" << endl;
        cout << "Jarak tempuh: " << jarak << "Km" << endl;
        cout << "Metode pembayaran: " << bayar.metode << endl;
        cout << "Nominal pembayaran: Rp." << bayar.total << endl;
        cout << endl
             << "Terimakasih telah menggunakan aplikasi GoRide!" << endl;
        cout << "===============================================" << endl;
    }
}

/*
Instruksi No 2 (GoFood):
- Pengguna menginputkan Kategori Makanan (Nusantara/Barat), Jumlah pesanan (pcs) dan Metode Pembayaran (GoPay/Cash)
- Sebagai informasi harga makanan Nusantara adalah Rp 100rb/pcs dan makanan Barat adalah Rp 150rb/pcs
- Ongkos kirim flat Rp 25rb
- Output yang diharapkan adalah Kategori Makanan, Jumlah Pesanan, Metode Pembayaran, dan Nominal Tagihan
*/
namespace go_food
{
    // const double HARGA_NUSANTARA = 100000.0, HARGA_BARAT = 150000.0, ONGKIR = 25000.0;

    void proses()
    {
        cout << "===============================================" << endl;
        cout << "               Welcome to GoFood!              " << endl;
        cout << "===============================================" << endl;

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

        pembayaran::HasilPembayaran bayar = pembayaran::proses(nominal_awal);
        bayar.total += ONGKIR;

        cout << fixed << setprecision(2);
        cout << "===============================================" << endl;
        cout << "Kategori makanan: " << kategori << endl;
        cout << "Jumlah pesanan: " << jumlah << endl;
        cout << "Metode pembayaran: " << bayar.metode << endl;
        cout << "Nominal pembayaran: Rp." << bayar.total << " (termasuk ongkir sebesar Rp." << ONGKIR << ")" << endl;
        cout << endl
             << "Terimakasih telah menggunakan aplikasi GoFood!" << endl;
        cout << "===============================================" << endl;
    }
}

/*
Instruksi No 3 (GoSend):
- Pengguna menginputkan Jarak Tempuh, Berat Barang, Volume Barang, dan Metode Pembayaran (GoPay/Cash)
- Formula perhitungan tarif = Jarak Tempuh Berat Barang Volume Barang * 5000
- Jika Volume Barang lebih dari 50 maka akan ada tambahan tarif flat sebesar Rp 25rb
- Output yang diharapkan adalah Jarak Tempuh, Berat Barang, Volume Barang, Metode Pembayaran, dan Nominal Tagihan
*/
namespace go_send
{
    // const double TARIF = 5000.0, TARIF_TAMBAHAN = 25000.0;

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

        pembayaran::HasilPembayaran bayar = pembayaran::proses(nominal_awal);

        if (volume > 50.0)
            bayar.total += TARIF_TAMBAHAN;

        cout << fixed << setprecision(2);
        cout << "===============================================" << endl;
        cout << "Jarak tempuh: " << jarak << endl;
        cout << "Berat barang: " << berat << endl;
        cout << "Volume barang: " << volume << endl;
        cout << "Metode pembayaran: " << bayar.metode << endl;
        cout << "Nominal pembayaran: Rp." << bayar.total;
        if (volume > 50.0)
            cout << " (termasuk tarif tambahan sebesar Rp." << TARIF_TAMBAHAN << ")";
        cout << endl;
        cout << endl
             << "Terimakasih telah menggunakan aplikasi GoSend!" << endl;
        cout << "===============================================" << endl;
    }
}