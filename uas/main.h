#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

struct Pelanggan
{
    std::string nama;
    double total_transaksi;
    int poin;
};

typedef std::vector<Pelanggan> ListPelanggan;

template <typename T = std::string>
T input(const std::string pesan);

std::string input_line(const std::string pesan);
void enter_lanjut(const std::string pesan);
void garis();
int main_menu();
bool input_lagi(std::string text);
void tambah_pelanggan(ListPelanggan &list_pelanggan);
void input_transaksi(ListPelanggan &list_pelanggan);
void daftar_pelanggan(ListPelanggan &list_pelanggan);