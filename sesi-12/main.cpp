#include <iostream>
#include <vector>

using namespace std;

struct Pegawai
{
    int no_induk;
    string nama;
    string jabatan;
    // SMP, SMA, S1, S2, S3
    string jenjang_pendidikan[5];

    int rating;
};

const string list_jenjang[5]{
    "SMP",
    "SMA",
    "S1",
    "S2",
    "S3"};

int main()
{
    vector<Pegawai> list_pegawai;
    bool ulang = true;

    while (ulang)
    {
        Pegawai pegawai;
        pegawai.rating = 0;

        cout << "=== Pegawai ke-" << list_pegawai.size() + 1 << " ===" << endl;
        cout << "No Induk: ";
        cin >> pegawai.no_induk;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, pegawai.nama);

        cout << "Institut Pendidikan (input nama / isi \"-\" jika tidak ada): " << endl;
        for (int i = 0; i < size(list_jenjang); i++)
        {
            string nama_institut = "";

            cout << i + 1 << ". " << list_jenjang[i] << ": ";
            getline(cin, nama_institut);
            pegawai.jenjang_pendidikan[i] = nama_institut;

            if (nama_institut != "-")
                pegawai.rating++;
        }

        pegawai.jabatan = pegawai.rating < 3
                              ? "Staf"
                          : pegawai.rating == 3 ? "Spv"
                                                : "Manager";

        list_pegawai.push_back(pegawai);

        cout << "Hi " << pegawai.nama << ", jabatanmu " << pegawai.jabatan << endl;

        char tambah_lagi;
        cout << "Tambah lagi? (y/n): ";
        cin >> tambah_lagi;

        if (tambah_lagi == 'n' || tambah_lagi == 'N')
            ulang = false;
    }

    return 0;
}