#include "pch.h"
#include <iostream>
#include <locale>

using namespace std;

wstring encrypt(const wstring& text, const int key);
wstring toUpperCase(const wstring& input);

int main() {
	setlocale(LC_ALL, "Russian");
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	
	wstring str = L"Функция должна вернуть строку с зашифрованным текстом";
	wcout << L"Введите ключ шифровки" << endl;
	int key;
	cin >> key;
	str = toUpperCase(str);
	str = encrypt(str, key);
	wcout << str << endl;
	return 0;
}

wstring encrypt(const wstring & text, const int key) {
	locale loc("ru_RU.UTF-8");
	
	wstring output = L"";
	const int LAUNGUAGE_SIZE = 32;

	for (wchar_t c : text) {
		if (L'А' <= c && c <= L'Я') {
			if (c + key > L'Я') {
				c -= LAUNGUAGE_SIZE - key;
			} else {
				c += key;
			}
			output += c;
		}
	}

	return output;
}

wstring toUpperCase(const wstring & input) {	
	locale loc("ru_RU.UTF-8");

	wstring output = L"";
	for (wchar_t c : input) {
		if (L'а' <= c && c <= L'я') {
			output += toupper(c, loc);
		} else {
			output += c;
		}
	}
	return output;
}
