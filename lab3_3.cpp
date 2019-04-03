#include "pch.h"
#include <iostream>
#include <locale>

using namespace std;
string * parse(string split, string key) {
	int ARRAY_SIZE = 0;
	for (int i = 0; i < (split.length() - key.length() + 1); i++) {
		if (split.substr(i, key.length())._Equal(key)) {
			ARRAY_SIZE++;
		}

	}

	static string * out = new string[ARRAY_SIZE];
	for (int i = 0, j =0, index_conter = 0; j < ARRAY_SIZE; i++) {
		if (split.substr(i, key.length())._Equal(key)) {
			out[j++] = split.substr(index_conter, i- index_conter);
			index_conter = i + key.length();
		}
	}
	return out;
}

int main() {
	setlocale(LC_ALL, "Russian");
	string input = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\nsrc http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb - src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb - src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb - src http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n";

	string * array = parse(input, "\n");
	int char_count = 0, number_count = 0, other_count = 0;

	for (int i = 0; i < 8; i++) {
		string str = array[i];
		for (char c : str) {
			if (c == ' ') {
				continue;
			} else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
				char_count++;
			} else if ('0' <= c && c <= '9') {
				number_count++;
			} else {
				other_count++;
			}
		}
	}
	cout << "Количество букв "            << char_count   << endl;
	cout << "Количество цифр "            << number_count << endl;
	cout << "Количество других символов " << other_count  << endl;

	delete[] array;
	return 0;
}