//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <math.h>

using namespace std;

unsigned long int Feld[100];

int Random(int Size) {

	return rand() % Size;
}

void Initalize() {

	for (int i = 0; i < 100; i++) {
		Feld[i] = Random(INT_MAX);
		Feld[i] = Feld[i] << 16;
		Feld[i] += Random(INT_MAX);
		Feld[i] = Random(100);
	}
}

int DecimalPlace(long int Zahl, long int decimalPlace) {
	return ((Zahl / decimalPlace) % 10);
}

void Sort(int Size) {

	unsigned long int Count[10];
	unsigned long int Feld2[100];
	unsigned long int n = sizeof(Feld) / sizeof(Feld[0]);
	unsigned long int mx = Feld[0];
	//Get highest Number from Feld
	for (unsigned long int i = 1; i < n; i++) {
		if (Feld[i] > mx) {
			mx = Feld[i];
		}
	}
	

	unsigned long int j;
	for (j = 1; j < mx; j *= 10) {
		//Initalize Count
		for (unsigned long int i = 0; i < 10; i++) {
			Count[i] = 0;
		}
		//for size of FELD
		for (unsigned long int i = 0; i < n; i++) {
			Count[DecimalPlace(Feld[i], j)]++;
		}
		//Sum all Count together
		for (unsigned long int i = 0; i < 9; i++) {
			Count[i + 1] += Count[i];
		}
		//for size of Feld
		for (int i = n -1 ; i >= 0; i--) {
			Count[DecimalPlace(Feld[i], j)]--;
			Feld2[Count[DecimalPlace(Feld[i], j)]] = Feld[i];
			if (i < 50) {
				n = n + 0;
			}
		}
		//copy Feld2 to Feld
		for (unsigned long int i = 0; i < n; i++) {
			Feld[i] = Feld2[i];
		}
	}
}

int main()
{
	srand(time(NULL));
	int j = 0;
	while (1) {
		Initalize();
		cout << "\nFeld1:\n";

		for (int i = 0; i < 100; i++) {
			cout << Feld[i] << "\n";
		}

		Sort(99);

		cout << "\nFeld2:\n";
		for (int i = 0; i < 100; i++) {
			cout << Feld[i] << "\n";
		}

		char test[10];
		cin >> test;

		if (test[0] == '\x18') {// '\x18' is for strg-c
			break;
		}
	}
	system("pause");

	return 0;
}

