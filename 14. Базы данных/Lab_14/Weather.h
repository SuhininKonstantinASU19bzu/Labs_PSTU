#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Weather {
	int dayW;
	int tempW;
	bool del;

public:
	Weather() { dayW = 0; tempW = 0; del = false; }
	Weather(int d, int t) { dayW = d; tempW = t; del = false; }
	Weather(const Weather& t) { dayW = t.dayW; tempW = t.tempW; del = t.del; }
	~Weather() {}
	int get_date() { return dayW; }
	int get_temp() { return tempW; }
	int get_del() { return del; }
	void set_date(int d) { dayW = d; }
	void set_temp(int t) { tempW = t; }
	void set_del(bool d) { del = d; }

	// Перегруженные операции
	// Префиксные операции
	Weather& operator =(const Weather&);
	Weather& operator ++();

	// Постфиксные операции
	Weather operator +(const Weather&);
	Weather operator +(const int&);
	Weather operator /(const Weather&);
	Weather operator /(const int&);

	// Операция сравнения
	bool operator ==(const Weather&);
	bool operator !=(const Weather&);
	bool operator >(const Weather&);
	bool operator >(const int&);
	bool operator <(const Weather&);
	bool operator <(const int&);

	// Глобальные функции ввода-вывода
	friend istream& operator >>(istream& in, Weather& t);
	friend ostream& operator <<(ostream& out, const Weather& t);
	
	friend fstream& operator >>(fstream& fin, Weather& t);
	friend fstream& operator <<(fstream& fout, const Weather& t);
};

