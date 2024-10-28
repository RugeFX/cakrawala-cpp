#include <iostream>
#include <string>
#include "go_ride.h"
#include "go_food.h"
#include "go_send.h"

using namespace std;

int main()
{
    string layanan;

    while (true)
    {
        cout << "Pilih layanan (GoRide, GoFood, GoSend): ";
        cin >> layanan;

        if (layanan == "GoRide")
        {
            go_ride::proses();
        }
        else if (layanan == "GoFood")
        {
            go_food::proses();
        }
        else if (layanan == "GoSend")
        {
            go_send::proses();
        }
        else
        {
            cout << "Layanan tidak tersedia, mohon input ulang" << endl;
            continue;
        }
    }
}