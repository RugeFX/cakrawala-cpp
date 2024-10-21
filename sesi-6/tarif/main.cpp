#include <iostream>
#include <string>

using namespace std;

const int anak = 3500 / 5;
const int remaja = 4500 / 5;
const int dewasa = 5500 / 5;
const int lainnya = 10000;

int hitung_tarif(string kategori, int jarak_tempuh);

int main()
{
    string kategori;
    int jarak_tempuh;

    cout << "Kategori usia (anak, remaja, dewasa): ";
    cin >> kategori;

    cout << "Kategori jarak tempuh: ";
    cin >> jarak_tempuh;

    int hasil = hitung_tarif(kategori, jarak_tempuh);

    cout << "Hasil perhitungan tarif: " << hasil;

    return 0;
}

int hitung_tarif(string kategori, int jarak_tempuh)
{
    if (kategori == "anak")
    {
        return anak * jarak_tempuh;
    }
    else if (kategori == "remaja")
    {
        return remaja * jarak_tempuh;
    }
    else if (kategori == "dewasa")
    {
        return dewasa * jarak_tempuh;
    }
    else
    {
        return lainnya;
    }
}