#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int minta_jawaban(const string arr_pertanyaan[4]);
string ubah_simbol(const char simbol);

int main()
{
    string pertanyaan_pilihan[5][4] = {
        // nomor 1
        {"A\e[1mpa yang Anda lakukan di akhir pekan?\e[0m",
         "Menghabiskan waktu dengan teman-teman.",
         "Menikmati waktu sendirian di rumah.",
         "Beraktivitas di luar ruangan."},
        // nomor 2
        {"\e[1mBagaimana Anda menyelesaikan masalah di tempat kerja?\e[0m",
         "Berdasarkan intuisi dan perasaan.",
         "Dengan mempertimbangkan fakta dan data.",
         "Mengikuti pendapat orang lain."},
        // nomor 3
        {"\e[1mBagaimana perasaan Anda saat bertemu orang baru?\e[0m",
         "Antusias dan ingin mengenal lebih jauh.",
         "Canggung dan memanfaatkan waktu.",
         "Tenang dan santai, tidak ada masalah."},
        // nomor 4
        {"\e[1mApa yang lebih Anda sukai?\e[0m",
         "Bekerja dalam tim.",
         "Bekerja sendiri.",
         "Kombinasi keduanya, tergantung situasi."},
        // nomor 5
        {"\e[1mBagaimana Anda merencanakan liburan?\e[0m",
         "Saya membuat rencana detail.",
         "Saya lebih suka spontan dan fleksibel.",
         "Saya mengikuti saran teman."}};

    string bobot_jawaban[5][3] = {
        {"ES", "IM", "ES"},
        {"IM", "EM", "ES"},
        {"ES", "IM", "AS"},
        {"ES", "IM", "AS"},
        {"IM", "AM", "ES"},
    };

    unordered_map<char, string> kategori_deskripsi = {
        {'E', "Ekstrovert: Anda suka berinteraksi dengan orang banyak, senang berpetualang, dan merasa energik saat berada dalam keramaian. Anda cenderung mengutamakan pengalaman sosial."},
        {'I', "Introvert: Anda lebih suka menikmati waktu sendiri atau bersama teman dekat, dan cenderung merasa lelah saat berada dalam keramaian. Anda lebih cenderung merenung."},
        {'A', "Ambivert: Anda memiliki keseimbangan antara keinginan untuk bersosialisasi dan membutuhkan waktu sendirian. Anda dapat beradaptasi dengan berbagai situasi sosial."},
        {'S', "Sosial: Anda sangat menyukai interaksi sosial dan merasa nyaman saat berbicara dengan banyak orang. Anda cenderung menyukai pekerjaan yang melibatkan kolaborasi."},
        {'M', "Mandiri: Anda lebih suka bekerja sendirian dan menyelesaikan tugas secara mandiri. Anda menghargai kebebasan dan sering kali bekerja lebih produktif tanpa gangguan."}};

    // E, I, A, S, M
    unordered_map<char, int> hasil = {{'E', 0}, {'I', 0}, {'A', 0}, {'S', 0}, {'M', 0}};

    for (int i = 0; i < 5; i++)
    {
        int jawaban = minta_jawaban(pertanyaan_pilihan[i]);

        for (char c : bobot_jawaban[i][jawaban])
        {
            hasil[c]++;
        }

        cout << "=============================================" << endl;
    }

    cout << "Hasil: " << endl;

    for (auto val : hasil)
    {
        cout << ubah_simbol(val.first) << ": " << val.second << endl;
    }

    vector<pair<char, int>> hasil_vector(hasil.begin(), hasil.end());
    sort(hasil_vector.begin(), hasil_vector.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return b.second < a.second; });

    cout << "\e[1mHasil: Anda adalah seorang yang ";
    for (int i = 0; i < 2; i++)
    {
        cout << ubah_simbol(hasil_vector[i].first) << (i == 0 ? " dan " : "");
    }

    cout << endl;
    cout << kategori_deskripsi[hasil_vector[0].first];
    cout << endl;
    cout << kategori_deskripsi[hasil_vector[1].first];

    cout << "\e[0m" << endl;

    return 0;
}

int minta_jawaban(const string arr_pertanyaan[4])
{
    char jawaban;
    cout << arr_pertanyaan[0] << endl;
    cout << "A. " << arr_pertanyaan[1] << endl;
    cout << "B. " << arr_pertanyaan[2] << endl;
    cout << "C. " << arr_pertanyaan[3] << endl;

    while (true)
    {
        cout << "\e[1mPilih jawaban yang paling menggambarkan Anda (A, B, C):\e[0m ";
        cin >> jawaban;
        jawaban = (char)toupper(jawaban);

        if (jawaban != 'A' && jawaban != 'B' && jawaban != 'C')
        {
            cout << "Jawaban anda tidak valid! Silahkan input ulang" << endl;
            continue;
        }

        break;
    }

    return (int)jawaban - 65;
}

string ubah_simbol(const char simbol)
{
    switch (simbol)
    {
    case 'E':
        return "Ekstrovert";
    case 'I':
        return "Introvert";
    case 'A':
        return "Ambivert";
    case 'S':
        return "Sosial";
    case 'M':
        return "Mandiri";
    default:
        return "Tidak diketahui";
    }
}