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
	string input = "deb http ://mirror.mephi.ru/debian/ stretch main contrib non-free\nsrc http ://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http ://security.debian.org/ stretch/updates main contrib non-free\ndeb - src http ://security.debian.org/ stretch/updates main contrib non-free\ndeb http ://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb - src http ://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http ://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb - src http ://mirror.mephi.ru/debian stretch-backports main contrib non-free\n";
	//string input[8] = parse(input, "debug");


	string * array = parse(input, "\n");
	//for (int i = 0; i < 8; i++) cout << array[i] << endl;

	for (int i = 0; i < 8; i++) {
		string str = array[i];
		int index = str.find("mephi");
		if (index != -1) str.replace(index, 5, "yandex");
		cout << str << endl;
	}
	return 0;
}