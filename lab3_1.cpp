#include "pch.h"
#include <iostream>
#include <locale>


using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите целое число в диапазоне от 0 до 100." << endl;

	int number;
	cin >> number;
	if (number >10 && number < 15) 
		cout << "В караване было " << number << " верблюдов." << endl;
	if (number / 10 == 1) cout << "В караване был " << number << " верблюд." << endl;
	if ((number % 10 >= 2) && (number % 10 <= 4)) { 
		cout << "В караване было " << number << " верблюда." << endl;
	} else {
		cout << "В караване было " << number << " верблюдов." << endl;
	}

	return 0;
}
