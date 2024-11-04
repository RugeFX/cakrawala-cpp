#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int MAX_ATTEMPTS = 3;

bool username_exists(unordered_map<string, string> users, string username)
{
    return users.find(username) != users.end();
}

bool validate_user(unordered_map<string, string> users, string username, string password)
{
    return users[username] == password;
}

string take_input(string message)
{
    string result;

    cout << message;
    cin >> result;

    return result;
}

int main()
{
    unordered_map<string, string> users = {{"rugefx", "zacky123"},
                                           {"admin", "admin123"}};

    string username, password;
    while (true)
    {
        username = take_input("Masukkan Username: ");
        if (username_exists(users, username))
            break;

        cout << "Username tidak ditemukan." << endl;
    }

    int attempts = 0;
    for (; attempts <= MAX_ATTEMPTS; attempts++)
    {
        password = take_input("Masukkan Password: ");

        if (validate_user(users, username, password))
            break;

        cout << "Password salah. Coba lagi.(Sisa percobaan: " << 3 - attempts << ")" << endl;
    }

    if (attempts > MAX_ATTEMPTS)
    {
        cout << "Akun Anda telah terkunci. Silakan hubungi admin." << endl;
    }
    else
    {
        cout << "Login berhasil! Selamat datang." << endl;
    }
}