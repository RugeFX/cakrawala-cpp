#include "main.h"

using namespace std;

int main()
{
    ListPelanggan list_pelanggan;

    cout << fixed << setprecision(2);

    while (true)
    {
        int pilihan = main_menu();

        switch (pilihan)
        {
        case 1:
            tambah_pelanggan(list_pelanggan);
            break;
        case 2:
            input_transaksi(list_pelanggan);
            break;
        case 3:
            daftar_pelanggan(list_pelanggan);
            break;
        case 4:
            garis();
            cout << "Bye bye!" << endl;
            garis();
            return 0;
        default:
            cout << "it's cool that you've managed to trigger this line of code";
            return 1;
        }
    }

    return 0;
}

template <typename T>
T input(const string pesan)
{
    // TODO: add validasi atau semacamnya, namun malas
    T value;
    cout << pesan;
    cin >> value;

    return value;
}

string input_line(const string pesan)
{
    string result;
    cin.ignore();
    cout << pesan;
    getline(cin, result);

    return result;
}

void enter_lanjut(const string pesan = "Tekan enter untuk melanjutkan...")
{
    cout << pesan;
    cin.get();
    cin.ignore();
}

void garis()
{
    cout << "==================================================" << endl;
}

int main_menu()
{
    garis();
    cout << "Menu Utama" << endl
         << endl;
    cout << "1. Tambah pelanggan baru" << endl;
    cout << "2. Input data transaksi" << endl;
    cout << "3. Lihat daftar pelanggan" << endl;
    cout << "4. Keluar dari aplikasi" << endl;
    garis();

    short pilihan = input<short>("Masukkan pilihan anda: ");

    while (pilihan < 1 || pilihan > 4)
    {
        cout << "Tolong masukkan input yang valid! (1, 2, 3, 4)" << endl;
        pilihan = input<short>("Masukkan pilihan anda: ");
    }

    return pilihan;
}

bool input_lagi(string text = "Ingin input lagi(y/n)?: ")
{
    char pilihan = (char)tolower(input<char>(text));

    while (pilihan != 'y' && pilihan != 'n')
    {
        cout << "Tolong masukkan input yang valid!" << endl;
        pilihan = (char)tolower(input<char>(text));
    }

    return pilihan == 'y';
}

void tambah_pelanggan(ListPelanggan &list_pelanggan)
{
    while (true)
    {
        garis();

        cout << "Tambah pelanggan" << endl
             << endl;

        cout << "Kode pelanggan saat ini: " << list_pelanggan.size() + 1 << endl;

        string nama = input_line("Input nama: ");

        list_pelanggan.push_back(Pelanggan{nama, 0.0});

        garis();

        if (!input_lagi())
            break;
    }
}

void input_transaksi(ListPelanggan &list_pelanggan)
{
    while (true)
    {
        garis();
        if (list_pelanggan.size() == 0)
        {
            cout << "Belum ada pelanggan yang terdaftar!" << endl;
            return;
        }

        int max_pelanggan = list_pelanggan.size();
        int kode = input<int>("Pilih kode(1" + (max_pelanggan == 1 ? "" : "-" + to_string(list_pelanggan.size())) + "): ");

        if (kode > max_pelanggan || kode < 1)
        {
            continue;
        }

        int jumlah = input<int>("Input jumlah transaksi yang ingin dimasukkan: ");
        Pelanggan &pelanggan = list_pelanggan.at(kode - 1);

        for (int i = 0; i < jumlah; i++)
        {
            pelanggan.total_transaksi += input<double>("Input total transaksi ke-" + to_string(i + 1) + ": ");
        }
        pelanggan.poin = static_cast<int>(pelanggan.total_transaksi) / 100000 * 10;
        cout << "Total transaksi: " << pelanggan.total_transaksi << endl;

        garis();

        if (!input_lagi())
            break;
    }
}

void daftar_pelanggan(ListPelanggan &list_pelanggan)
{
    garis();

    if (list_pelanggan.size() == 0)
    {
        cout << "Belum ada pelanggan yang terdaftar!" << endl;
        enter_lanjut();
        return;
    }

    for (int i = 0; i < list_pelanggan.size(); i++)
    {
        Pelanggan pelanggan = list_pelanggan[i];

        cout << "Kode: " << i + 1 << endl;
        cout << "Nama: " << pelanggan.nama << endl;
        cout << "Jumlah Transaksi: " << pelanggan.total_transaksi << endl;
        cout << "Poin: " << pelanggan.poin << endl;
        cout << "Level: ";
        if (pelanggan.poin <= 50)
            cout << "Bronze";
        else if (pelanggan.poin > 50 && pelanggan.poin <= 100)
            cout << "Silver";
        else if (pelanggan.poin > 100 && pelanggan.poin <= 150)
            cout << "Gold";
        else
            cout << "Platinum";
        cout << endl;

        garis();
    }

    enter_lanjut();
}
