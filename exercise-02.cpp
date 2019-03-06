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

struct Theater{
	int room;
	char seat[3];
	char movieTitle[30];
};

int main (){
	Theater theater;
	theater.room = 7;
	
	strcpy (theater.seat, " J9 " );
	strcpy (theater.movieTitle, " Adit & Jarwo " );
	
	cout << theater.room << endl; //output room
	cout << theater.seat << endl; // output seat
	cout << theater.movieTitle << endl; // output movietitle
	
}
