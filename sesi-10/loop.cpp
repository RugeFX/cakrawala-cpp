#include <iostream>

using namespace std;

void satu();
int fibonacci(int n);
void dua();
void tiga();
void empat();
void lima();

int main()
{
	cout << "nomor 1 (deret angka):" << endl;
	satu();
	cout << endl;

	cout << "nomor 2 (fibonacci):" << endl;
	dua();
	cout << endl;

	cout << "nomor 3 (segitiga):" << endl;
	tiga();
	cout << endl;

	cout << "nomor 4 (jumlah angka):" << endl;
	empat();
	cout << endl;

	cout << "nomor 5 (prima):" << endl;
	lima();
	cout << endl;
}

// deret angka
void satu()
{
	int n;
	cout << "where's ur n bruv: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 != 0 && i != 1)
			cout << endl;
		cout << i << " ";
	}
}

// fibonacci
void dua()
{
	int a = 0, b = 1, curr, n;
	cout << "masukin angka bang buat fibonacci: ";

	cin >> n;
	cout << a << " " << b << " ";

	for (int i = 2; i < n; ++i)
	{
		curr = a + b;
		cout << curr << " ";
		a = b;
		b = curr;
	}
}

// segitiga
void tiga()
{
	int tinggi;
	cout << "tinggi segitiganya banh: ";
	cin >> tinggi;

	for (int i = 1; i <= tinggi; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}

// jumlah angka
void empat()
{
	int n;
	cout << "masukkan angka n bang: ";
	cin >> n;

	int hasil = 0;
	for (int i = 0; i < n; hasil += ++i)
		;

	cout << hasil;
}

// bilangan prima
void lima()
{
	int n;
	cout << "masukkan angka n bang: ";
	cin >> n;

	if (n < 2)
		return;

	for (int i = 2; i <= n; i++)
	{
		bool afkh_prima = true;

		for (int j = 2; j <= i; j++)
		{
			// cout << i << " % " << j << " == 0 ? " << (i % j == 0 ? "true" : "false") << endl;
			if (i % j == 0 && j != i)
				afkh_prima = false;
		}

		// cout << afkh_prima;
		if (afkh_prima == true)
			cout << i << " ";
	}
}