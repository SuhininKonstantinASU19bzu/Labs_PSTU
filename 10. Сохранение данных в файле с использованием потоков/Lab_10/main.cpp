#include <iostream>
#include <locale>
#include "Time.h"
#include "File_work.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    Time t, t1, t2;
    Time A(1, 30);
    int k, c;
    char file_name[30];

    do {
        cout << "1. Создать файл" << endl;
        cout << "2. Прочитать файл" << endl;
        cout << "3. Удалить элемент из файла" << endl;
        cout << "4. Добавление элемента в файл" << endl;
        cout << "5. Изменить элемент в файле" << endl;
        cout << "6. Удаление элементов соответствующих заданному значению" << endl;
        cout << "7. Увеличение всех элементов с заданным значением на 1:30" << endl;
        cout << "8. Добавить K записей после элемента с заданным номером" << endl;
        cout << "0. Выход" << endl;
        cout << "> ";
        cin >> c;

        switch (c) {
        case 1:
            cout << "Введите имя файла: ";
            cin >> file_name;

            k = make_file(file_name);

            if (k < 0) cout << "Невозможно создать файл";

            break;

        case 2:
            cout << "Введите имя файла: ";
            cin >> file_name;

            k = print_file(file_name);

            if (k == 0) cout << "Файл пуст" << endl;
            if (k < 0) cout << "Невозможно прочитать файл" << endl;

            break;

        case 3:
            cout << "Введите имя файла: ";
            cin >> file_name;

            int nom;

            cout << "Введите номер элемента для удаления: ";
            cin >> nom;

            k = del_file(file_name, nom);

            if (k < 0) cout << "Невозможно прочитать файл" << endl;

            k = print_file(file_name);

            if (k < 0) cout << "Невозможно прочитать файл" << endl;

            break;

        case 4:
            cout << "Введите имя файла: ";
            cin >> file_name;

            int nom1;

            cout << "Введите номер элемента для добавления: ";
            cin >> nom1;

            cout << "Новый элемент: " << endl;
            cin >> t1;

            k = add_file(file_name, nom1, t1);

            if (k < 0) cout << "Невозможно прочитать файл" << endl;
            if (k == 0) k = add_end(file_name, t1);

            break;

        case 5:
            cout << "Введите имя файла: ";
            cin >> file_name;

            int nom2;

            cout << "Номер элемента: ";
            cin >> nom2;

            cout << "Новый элемент: ";
            cin >> t2;

            k = change_file(file_name, nom2, t2);

            if (k < 0) cout << "Невозможно прочитать файл" << endl;
            if (k == 0) cout << "Нет такой записи" << endl;

            break;

        case 6:
            cout << "Введите имя файла: ";
            cin >> file_name;

            k = del_compare(file_name);

            if (k == 0) cout << "Файл пуст" << endl;
            if (k < 0) cout << "Невозможно прочитать файл" << endl;

            break;

        case 7:
            cout << "Введите имя файла: ";
            cin >> file_name;

            k = add_time(file_name, A);

            if (k == 0) cout << "Файл пуст" << endl;
            if (k < 0) cout << "Невозможно прочитать файл" << endl;

            break;

        case 8:
            cout << "Введите имя файла: ";
            cin >> file_name;

            int k2;

            cout << "Номер элемента после которого добавить: ";
            cin >> k2;

            k = add_after(file_name, k2);

            if (k == 0) cout << "Нет такой записи" << endl;
            if (k < 0) cout << "Невозможно прочитать файл" << endl;

            break;
        }

    } while (c != 0);

    return 0;
}