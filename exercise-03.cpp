/*
Nama Program	: exercise-03
Nama			: SITTI UFAIROH AZZAHRA
NPM				: 140810180002
Deskriptif		: program ini dibuat untuk menampilkan Data pegawai unchpad dengan gaji terendah dan tertinggi
Tahun			: 2019
*/
#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct pegawai
{
  char nip[14];
  char nama[25];
  int gol;
};

typedef pegawai larikPegawai[100];
typedef int larik[5];

void inputPegawai(pegawai&);
void cetakDaftar(larikPegawai,int);
long rataGaji(larikPegawai,int);
long gajiTerendah(larikPegawai, int);
long gajiTertinggi(larikPegawai, int);
long hitungGolongan(int);
int searchNip(larikPegawai, larikPegawai&, int);
void sortData(larikPegawai&, larikPegawai&, int, int, int);
void reverseData(larikPegawai& peg, int n);
void cetakProperties(larikPegawai,int, larik);
void mainMenu(int&);
void outputMenu(int&);
void countGol(larikPegawai, int, larik&);


int main(int argc, char const *argv[])
{
  larikPegawai pegUnpad;
  int menu,x,index;
  larik golongan = {0};
  string message = "None for now";

  x = 0;
  while(1)
  {
    cout << "Message : " << message << endl;;
    mainMenu(menu);
    if (menu == 1) {
      inputPegawai(pegUnpad[x++]);
      system("CLS");
      message = "Data berhasil ditambahkan";
    } else if (menu == 2) {
      larikPegawai pegUnpadManip;
      outputMenu(menu);
      if (menu == 1) {
        cetakDaftar(pegUnpad,x);
        countGol(pegUnpad,x,golongan);
        cetakProperties(pegUnpad,x,golongan);
        message = "None for now";
      } else if (menu > 1 && menu <= 5) {
        switch (menu)
        {
          case 2:
            sortData(pegUnpad,pegUnpadManip,x,1,0);
            break;
          case 3:
            sortData(pegUnpad,pegUnpadManip,x,1,1);
            break;
          case 4:
            sortData(pegUnpad,pegUnpadManip,x,0,0);
            break;
          case 5:
            sortData(pegUnpad,pegUnpadManip,x,0,1);
            break;
        }
        cetakDaftar(pegUnpadManip,x);
        message = "None for now";
      } else {
        message = "Wrong Input";
      }
      system("PAUSE");
      system("CLS");
    } else if (menu == 3) {
      larikPegawai pegUnpadManip;
      int found;
      found = searchNip(pegUnpad,pegUnpadManip,x);
      if (found == -1)
        cout << endl << "Data tidak ditemukan" << endl << endl;
      else 
        cetakDaftar(pegUnpadManip,1);
      message = "None for now";
      system("PAUSE");
      system("CLS");
    } else if (menu == 4) {
      break;
    } else {
      message = "Wrong Input";
      system("CLS");
    }
  }

  return 0;
}

void inputPegawai(pegawai& peg)
{
  cout << "Nama \t\t : ";
  cin.getline(peg.nama,100);
  cout << "NIP \t\t : ";
  cin.getline(peg.nip,100);
  while (1) {
    cout << "Golongan \t : ";
    cin >> peg.gol;
    if ( ! (peg.gol < 1 || peg.gol > 4))
      break;
  }
}

void cetakDaftar(larikPegawai peg,int n)
{
  cout << endl
  << setw(4) << left << "No"
  << setw(25) << left << "Nama"
  << setw(14) << left << "NIP"
  << setw(5) << left << "Gol"
  << setw(10) << left << "Gaji"
  << endl
  ;
  for (int i = 0; i < n; ++i) {
    cout
    << setw(4)  << left << i+1
    << setw(25) << left << peg[i].nama
    << setw(14) << left << peg[i].nip
    << setw(5)  << left << peg[i].gol
    << setw(3)  << left << "Rp "
    << setw(10)  << left << hitungGolongan(peg[i].gol)
    << endl
    ;
  } 
  cout << endl;
}

long rataGaji(larikPegawai peg,int n)
{
  if (n > 0)
  {
    long sum = 0;
    for (int i = 0; i < n; ++i)
    {
      sum += hitungGolongan(peg[i].gol);
    }
    return sum/(long)n;
  } else {
    return 0;
  } 
}

long gajiTerendah(larikPegawai peg, int n)
{
  if (n > 0) {
    long min = peg[0].gol;
    for (int i = 0; i < n; ++i)
      if (min > peg[i].gol)
        min = peg[i].gol;
    return hitungGolongan(min);
  } else {
    return 0;
  } 
}

long gajiTertinggi(larikPegawai peg, int n)
{
  if (n > 0) {
    long max = peg[0].gol;
    for (int i = 0; i < n; ++i)
      if (max < peg[i].gol)
        max = peg[i].gol;
    return hitungGolongan(max);
  } else {
    return 0;
  } 
}

long hitungGolongan(int gol)
{
  long gaji;
  switch (gol)
  {
    case 1:
      gaji = 2000000;
      break;
    case 2:
      gaji = 3000000;
      break;
    case 3:
      gaji = 5000000;
      break;
    case 4:
      gaji = 8000000;
      break;
    default:
      gaji = 0;
      break;
  }
  return gaji;
}

int searchNip(larikPegawai peg, larikPegawai& pegtemp, int n)
{
  char key[100];
  cout << "Masukan NIP yang ingin dicari : ";
  cin >> key;
  int index = -1;
  for (int i = 0; i < n; ++i)
    if (strcmp(peg[i].nip,key) == 0)
    {
      index = i;
      break;
    }
  pegtemp[0] = peg[index];
  return index;
}

void sortData(larikPegawai& peg, larikPegawai &pegtemp, int n, int sortby, int order)
{
  for (int i = 0; i < n; ++i) {
    pegtemp[i] = peg[i];
  }

  for (int i = n-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (sortby == 0) {
        if (strcmp(pegtemp[j].nama,(pegtemp[j+1].nama)) > 0) {
          swap(pegtemp[j], pegtemp[j+1]);
        } 
      } else if (sortby == 1) {
        if (strcmp(pegtemp[j].nip,(pegtemp[j+1].nip)) > 0) {
          swap(pegtemp[j], pegtemp[j+1]);
        } 
      }
    }
  }

  if (order == 1) {
    reverseData(pegtemp, n);
  }
}

void countGol(larikPegawai peg, int n, larik& golongan)
{
  for (int i = 0; i < n; ++i)
    golongan[peg[i].gol] += 1;
}

void reverseData(larikPegawai& peg, int n)
{
  pegawai temp;
  int iter = n-1;
  for (int i = 0; i < n/2; ++i)
  {
    temp = peg[i];
    peg[i] = peg[iter];
    peg[iter--] = temp;
  }
}

void outputMenu(int& menu)
{
  cout << "[1] Tanpa Sort" << endl;
  cout << "[2] Sort NIP Asc" << endl;
  cout << "[3] Sort NIP Desc" << endl;
  cout << "[4] Sort Nama Asc" << endl;
  cout << "[5] Sort Nama Desc" << endl;
  cout << "============================" << endl;
  cout << "Input : ";
  cin >> menu;
  cin.ignore();
  cout << "============================" << endl;
}


void mainMenu(int& menu)
{
  cout << "  Data Pegawai UNCHPAD" << endl;
  cout << "============================" << endl;
  cout << "[1] Tambah Pegawai" << endl;
  cout << "[2] Tampilkan Data" << endl;
  cout << "[3] Search NIP" << endl;
  cout << "[4] Exit" << endl;
  cout << "============================" << endl;
  cout << "Input : ";
  cin >> menu;
  cin.ignore();

  cout << "============================" << endl;
}

void cetakProperties(larikPegawai peg, int n, larik golongan)
{
  cout << endl;
  cout << "Rata Rata Gaji : Rp " << rataGaji(peg,n) << endl;
  cout << "Gaji Tertinggi : Rp " << gajiTertinggi(peg,n) << endl;
  cout << "Gaji Terendah  : Rp " << gajiTerendah(peg,n) << endl;
  cout << "Golongan 1     : " << golongan[1] << " orang" << endl;
  cout << "Golongan 2     : " << golongan[2] << " orang" << endl;
  cout << "Golongan 3     : " << golongan[3] << " orang" << endl;
  cout << "Golongan 4     : " << golongan[4] << " orang" << endl;
  cout << endl;
}
