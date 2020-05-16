#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc); // Открыть для записи

	if (!stream) return -1; // Ошибка открытия файла

	Time t;
	int n;

	cout << "Введите количество записей: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t; // Ввод атрибутов объекта
		stream << t << endl; // Запись в файловый поток
	}

	stream.close(); // Закрытие файлового потока

	return n; // Возврат количества записаных объектов
}

int print_file(const char* f_name) {
	fstream stream(f_name, ios::in); // Открыть для чтения

	if (!stream) return -1; // Ошибка открытия файла

	Time t;
	int i = 0;

	while (stream >> t) {
		cout << t << endl;
		i++;
	}

	stream.close();

	return i; // Возврат количества прочитаных объектов 
}

int del_file(const char* f_name, int k) {
	fstream temp("temp", ios::out); // Открыть для записи временный файл
	fstream stream(f_name, ios::in); // Отркыть файл для чтения

	if (!stream) return -1; // Ошибка открытия файла

	Time t;
	int i = 0;

	while (stream >> t) {
		i++;
		if (i != k) temp << t; // Если номер объекта не равен k то пишем его во временный файл
	}

	stream.close();
	temp.close();

	remove(f_name); // Удаление старого файла
	rename("temp", f_name); // Переименование временного файла в заданный

	return i; // Количество переписаных элементов
}

int add_file(const char* f_name, int k, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);

	if (!stream) return -1;

	Time t;
	int i = 0;
	int l = 0;

	while (stream >> t) {
		i++;

		if (i == k)	{
			temp << tt;
			l++;
		}

		temp << t;
	}

	stream.close();
	temp.close();

	remove(f_name);
	rename("temp", f_name);

	return l;
}

int add_end(const char* f_name, Time tt) {
	fstream stream(f_name, ios::app);

	if (!stream) return -1;

	stream << tt;

	return 1;
}

int change_file(const char* f_name, int k, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);

	if (!stream) return -1;

	Time t;
	int i = 0;
	int l = 0;
	char x;

	while (stream >> t) {
		i++;

		if (i == k) {
			temp << tt;
			l++;
		}
		else temp << t;
	}

	stream.close();
	temp.close();

	remove(f_name);
	rename("temp", f_name);

	return l;
}

int del_compare(const char* f_name) {
	fstream temp("temp", ios::out); // Открыть для записи временный файл
	fstream stream(f_name, ios::in); // Отркыть файл для чтения

	if (!stream) return -1; // Ошибка открытия файла

	Time t1, t2;
	int i = 0;

	cout << "Введите значение удаляемых элементов:" <<endl;
	cin >> t2;

	while (stream >> t1) {
		i++;

		if (!(t1 == t2)) temp << t1;
	}

	stream.close();
	temp.close();

	remove(f_name); // Удаление старого файла
	rename("temp", f_name); // Переименование временного файла в заданный

	return i; // Количество переписаных элементов
}

int add_time(const char* f_name, const Time& t) {
	fstream temp("temp", ios::out); // Открыть для записи временный файл
	fstream stream(f_name, ios::in); // Отркыть файл для чтения

	if (!stream) return -1; // Ошибка открытия файла

	Time t1, t2, t3;
	int i = 0;

	cout << "Введите значение элемента для добавления константы:" << endl;
	cin >> t2;

	while (stream >> t1) {
		i++;

		if (t1 == t2) {
			t1 = t1 + t;
			temp << t1;
		}
		else temp << t1;
	}

	stream.close();
	temp.close();

	remove(f_name); // Удаление старого файла
	rename("temp", f_name); // Переименование временного файла в заданный

	return i; // Количество переписаных элементов
}

int add_after(const char* f_name, int k) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);

	if (!stream) return -1;

	int i = 0;
	int l = 0;

	Time t1, t2;
	int n;

	while (stream >> t1) {
		i++;

		if (i == k) {
			cout << "Введите количество записей: ";
			cin >> n;

			temp << t1;

			for (int iter = 0; iter < n; iter++) {
				cin >> t2; // Ввод атрибутов объекта
				temp << t2; // Запись в файловый поток
				l++;
			}
		}
		else temp << t1;
	}

	stream.close();
	temp.close();

	remove(f_name);
	rename("temp", f_name);

	return l;
}