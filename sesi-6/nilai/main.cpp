#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const double kehadiran = 0.1;
const double ujian_harian = 0.2;
const double uts = 0.35;
const double uas = 0.35;

double hitung_nilai_akhir(int total_kehadiran, double nilai_ujian_harian, double nilai_uts, double nilai_uas);
char hitung_mutu(double nilai_akhir);

int main()
{
    int total_kehadiran;
    double nilai_ujian_harian, nilai_uts, nilai_uas;

    cout << "Masukkan Total Kehadiran: ";
    cin >> total_kehadiran;

    cout << "Masukkan Nilai Ujian Harian: ";
    cin >> nilai_ujian_harian;

    cout << "Masukkan Nilai UTS: ";
    cin >> nilai_uts;

    if (total_kehadiran >= 13)
    {
        cout << "Masukkan Nilai UAS: ";
        cin >> nilai_uas;
    }
    else
    {
        nilai_uas = 0;
    }

    double nilai_akhir = hitung_nilai_akhir(total_kehadiran, nilai_ujian_harian, nilai_uts, nilai_uas);
    char mutu = hitung_mutu(nilai_akhir);

    cout << "Nilai Akhir: " << nilai_akhir << endl;
    cout << "Huruf Mutu: " << mutu << endl;
}

double hitung_nilai_akhir(int total_kehadiran, double nilai_ujian_harian, double nilai_uts, double nilai_uas)
{
    return (((double)total_kehadiran / 16.0 * 100.0) * kehadiran) + (ujian_harian * nilai_ujian_harian) + (uts * nilai_uts) + (uas * nilai_uas);
}

char hitung_mutu(double nilai_akhir)
{
    if (nilai_akhir >= 85)
    {
        return 'A';
    }
    else if (nilai_akhir >= 70 && nilai_akhir < 85)
    {
        return 'B';
    }
    else if (nilai_akhir >= 60 && nilai_akhir < 70)
    {
        return 'C';
    }
    else if (nilai_akhir >= 50 && nilai_akhir < 60)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}