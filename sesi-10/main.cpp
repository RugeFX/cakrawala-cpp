#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
 Sebuah sekolah ingin membuat sistem untuk menghitung nilai akhir dari sejumlah siswa berdasarkan nilai ujian dan tugas. Nilai akhir dihitung dengan cara:

60% dari nilai ujian (ujian terdiri dari 5 mata pelajaran).
40% dari nilai tugas (tugas terdiri dari 4 tugas).
Program yang dibuat harus dapat menghitung nilai akhir siswa berdasarkan input yang diberikan, dan menentukan apakah siswa tersebut lulus atau tidak. Siswa dianggap lulus jika nilai akhir mereka lebih dari atau sama dengan 60.

Langkah-langkah yang harus dilakukan:

Program meminta input nama siswa dan nilai ujian serta nilai tugas untuk setiap mata pelajaran dan tugas.
Program menghitung nilai rata-rata ujian dan tugas.
Program menghitung nilai akhir menggunakan rumus di atas.
Program menentukan apakah siswa tersebut lulus atau tidak berdasarkan nilai akhir.
*/

const int TOTAL_TUGAS_PER_MATPEL = 4;
string list_matpel[5];

void ambil_nilai(double nilai_arr[size(list_matpel)][TOTAL_TUGAS_PER_MATPEL + 1])
{
	for (int i = 0 ; i < size(list_matpel); ++i)
	{
		string matpel = list_matpel[i];
		double nilai_ujiam;

		cout << "Masukkan nilai ujian untuk mapel " << matpel << ": ";
		cin >> nilai_ujiam;

		nilai_arr[i][0] = nilai_ujiam;

		for (int j = 1; j < TOTAL_TUGAS_PER_MATPEL; j++)
		{
			double nilai_tugas;

			cout << "Masukkan nilai tugas " << matpel <<" ke-" << j+1 << ": ";
			cin >> nilai_tugas;

			nilai_arr[i][j] = nilai_tugas;
		}
	}

}

int main()
{
	string nama;
	double nilai_arr[size(list_matpel)][TOTAL_TUGAS_PER_MATPEL + 1];
	double total_nilai_ujian;
	double total_nilai_tugas;
	double ukuran = (double) size(list_matpel);

	cout << fixed << setprecision(2);

	cout << "Masukkan nama siswa: ";
	getline(cin, nama);

	for (int i = 0; i < size(list_matpel); i++)
	{
		cout << "Masukkan nama matpel ke-" << i << ": ";
		getline(cin, list_matpel[i]);

	}

	ambil_nilai(nilai_arr);
	
	for (int i = 0 ; i < ukuran; i++)
	{
		string matpel = list_matpel[i];
		double nilai_ujian = 0;
		double nilai_tugas = 0;

		for (int j = 0; j < TOTAL_TUGAS_PER_MATPEL; j++)
		{
			double nilai = nilai_arr[i][j];

			if (j == 0)
			{
				total_nilai_ujian += nilai;
				nilai_ujian = nilai;
			}
			else 
			{
				total_nilai_tugas += nilai;
				nilai_tugas += nilai;
			}
		}

		double rata_tugas = (nilai_ujian * 0.6) + ((nilai_tugas / TOTAL_TUGAS_PER_MATPEL) * 0.4);

		cout << "Nilai rata-rata matpel " << matpel << ": " << rata_tugas << endl; 
		cout << "Status lulus: " << (rata_tugas < 60.0 ? "Tidak Lulus" : "Lulus") << endl;
	}

	double rata_ujian = total_nilai_ujian / ukuran;
	double rata_tugas = total_nilai_tugas / (ukuran * 4.0);
	double nilai_akhir = (total_nilai_ujian / ukuran  * 0.6) + (total_nilai_tugas / (ukuran * 4.0) * 0.4);

	cout << "Nilai rata-rata semua ujian: " << rata_ujian << endl; 
	cout << "Nilai rata-rata semua tugas: " << rata_tugas << endl; 
	cout << "Nilai akhir: " << nilai_akhir << ", yang berarti anda" << (nilai_akhir < 60.0 ? " tidak " : " ") << "lulus" << endl; 
}


