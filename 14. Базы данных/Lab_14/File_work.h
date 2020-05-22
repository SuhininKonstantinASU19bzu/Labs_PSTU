#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Weather.h"
#include "List.h"

using namespace std;

int make_file(const char* f_name, List& l) {
	fstream stream(f_name, ios::out | ios::trunc); // Открыть для записи

	if (!stream) return -1; // Ошибка открытия файла

	int n = 30;

	l.clear();

	for (int i = 0; i < n; i++) {
		int t = rand() % 60 - 30;

		Weather w(i + 1, t);

		l.push_back(w);

		stream << w << endl; // Запись в файловый поток
	}

	stream.close(); // Закрытие файлового потока

	return n; // Возврат количества записаных объектов
}

int save_file(const char* f_name, List& l, bool& cheange) {
	if (!cheange) {
		cout << "Нет изменений для сохранения" << endl;
		return 1;
	}

	fstream stream("temp", ios::out);
	
	if (!stream) return -1;

	int n = 0;
	Weather temp;

	for (Lit i = l.begin(); i != l.end(); i++, n++) {
		temp = (*i);
		stream << temp;
	}

	stream.close();

	remove(f_name);
	rename("temp", f_name);

	cheange = false;

	return n;
}

int open_file(const char* f_name, List& l) {
	fstream stream(f_name, ios::in);
	Weather temp;
	int n = 0;

	if (!stream) return -1;

	if (l.size() > 0) l.clear();

	while (stream >> temp) {
		l.push_back(temp);
		n++;
	}

	return n;
}