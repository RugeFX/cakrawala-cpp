#include <iostream>
#include <string>
#include "go_ride.h"
#include "go_food.h"
#include "go_send.h"

using namespace std;

int main()
{
    int layanan;

    cout << "===============================================" << endl;
    cout << "       Selamat datang di aplikasi GoJek!       " << endl;
    cout << "===============================================" << endl;

    while (true)
    {
        cout << "Pilih layanan (1. GoRide, 2. GoFood, 3. GoSend, 4. Quit): ";
        cin >> layanan;

        if (layanan == 1)
        {
            go_ride::proses();
        }
        else if (layanan == 2)
        {
            go_food::proses();
        }
        else if (layanan == 3)
        {
            go_send::proses();
        }
        else if (layanan == 4)
        {
            cout << "===============================================" << endl;
            cout << " Terimakasih telah menggunakan aplikasi GoJek! " << endl;
            cout << "===============================================" << endl;
            break;
        }
        else
        {
            cout << "===============================================" << endl;
            cout << "   Layanan tidak tersedia, mohon input ulang   " << endl;
            cout << "===============================================" << endl;
            continue;
        }
    }
}