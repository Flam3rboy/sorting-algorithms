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

	for (int i = 1; i < Size; i++) {
		int key = Feld[i];
		int j = i - 1;

		while (j >= 0 && Feld[j] > key)
		{
			Feld[j + 1] = Feld[j];
			j = j - 1;
		}
		Feld[j + 1] = key;
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

