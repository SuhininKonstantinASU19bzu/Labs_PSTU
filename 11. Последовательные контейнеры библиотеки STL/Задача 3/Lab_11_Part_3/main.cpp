#include <iostream>
#include <locale>
#include <vector>
#include "Time.h"
#include "Vector.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	Vector<Time> vec(5);

	Time el;

	vec.Print();

	el = vec.average();

	cout << "Среднее арифметическое: " << el << endl;

	vec.add_all(el);

	vec.Print();

	return 0;
}