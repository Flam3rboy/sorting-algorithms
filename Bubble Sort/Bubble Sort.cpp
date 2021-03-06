//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int Feld[100];

int Random(int Size) {

	return rand() % Size;
}

void Initalize() {

	for (int i = 0; i < 100; i++) {
		Feld[i] = Random(99);
	}
}

void Sort(int Size) {
	int Element = 0;
	int Tausch = 1;
	int buf;
	while (Tausch != 0) {
		Tausch = 0;
		for (int i = 0; i < Size; i++) {
			Element = Random(Size);
			if (Feld[Element - 1] > Feld[Element]) {
				buf = Feld[Element];
				Feld[Element] = Feld[Element - 1];
				Feld[Element - 1] = buf;
				Tausch++;
			}
			if (Feld[Element + 1] < Feld[Element]) {
				buf = Feld[Element];
				Feld[Element] = Feld[Element + 1];
				Feld[Element + 1] = buf;
				Tausch++;
			}
		}
	}
}

int main()
{
	srand(time(NULL));

	Initalize();

	for (int i = 0; i < 100; i++) {
		cout << Feld[i] << "\n";
	}

	Sort(99);

	cout << "\nFeld2:\n";
	for (int i = 0; i < 100; i++) {
		cout << Feld[i] << "\n";
	}

	system("pause");

	return 0;
}

