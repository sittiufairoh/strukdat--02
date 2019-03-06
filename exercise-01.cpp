/*
Nama Program	: exercise-01
Nama			: SITTI UFAIROH AZZAHRA
NPM				: 140810180002
Deskriptif		: program ini dibuat untuk membuat kelipatan 3 dan 5 fizzbuzz
Tahun			: 2019
*/

#include <iostream>
#include <string.h>

using namespace std;

struct Orang {

	int umur;
	char nama[30];
	char goldar[2];
	char JK[1];

};

int main() {
	Orang orang;
	
	cout << "Umur : "; cin >> orang.umur;
	cout << "Nama : "; cin >> orang.nama;
	cout << "Goldar	: "; cin >> orang.goldar;
	cout << "Jenis Kelamin	: "; cin >> orang.JK;
	cout <<endl;

	cout << orang.umur << endl;
	cout << orang.nama << endl;
	cout << orang.goldar << endl;
	cout << orang.JK << endl;

}
