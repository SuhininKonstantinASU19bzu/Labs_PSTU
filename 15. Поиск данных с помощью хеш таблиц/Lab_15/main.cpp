#include <iostream>
#include <string>
#include <locale>
#include "Table.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chsp 1251");
    system("cls");

    HashMapTable table;
    string key, group;
    char clear_line;
    int rating;
    int index;
    int menu;

    do {
        cout << endl << "1. Создать и заполнить таблицу" << endl;
        cout << "2. Просмотр таблицы" << endl;
        cout << "3. Добавить элемент" << endl;
        cout << "4. Отредактировать элемент" << endl;
        cout << "5. Удалить элемент" << endl;
        cout << "6. Подсчитать колличество коллизий" << endl;
        cout << "0. Выход" << endl;
        cout << "> ";
        cin >> menu;

        clear_line = cin.get();
        
        switch (menu) {
        case 1: // Создание и заполнение таблицы
            int size;

            cout << "Задайте размер таблицы" << endl;
            cout << "> ";

            cin >> size;

            table.generate_filled_table(size);

            break;

        case 2: // Просмотр таблицы
            table.show_table();

            break;

        case 3: // Добавление элемента в таблицу
            cout << "Если вводимый элемент уже существует, то он будет заменен" << endl;
            cout << "Введите новый элемент" << endl;
            cout << "Введите ФИО" << endl;
            cout << "> ";

            getline(cin, key);

            cout << "Введите Группу" << endl;
            cout << "> ";

            getline(cin, group);

            cout << "Введите Рейтинг" << endl;
            cout << "> ";

            cin >> rating;

            table.add(key, group, rating);

            break;

        case 4: // Редактирование элемента
            int sub_menu_4;

            do {
                cout << "1. Редактирование элемента по индексу" << endl;
                cout << "2. Редактирование элемента по ключу" << endl;
                cout << "0. Назад" << endl;
                cout << "> ";

                cin >> sub_menu_4;

                clear_line = cin.get(); // Очистка строки для корректной работы getline();

                switch (sub_menu_4) {
                case 1:
                    cout << "Введите индекс" << endl;
                    cout << "> ";

                    cin >> index;

                    table.edit_index(index);

                    break;

                case 2:
                    cout << "Введите ключ" << endl;
                    cout << "> ";

                    getline(cin, key);

                    table.edit_key(key);

                    break;
                }
            } while (sub_menu_4 != 0);

            break;

        case 5: // Удаление элемента
            int sub_menu_5;

            do {
                cout << "1. Удаление элемента по индексу" << endl;
                cout << "2. Удаление элемента по ключу" << endl;
                cout << "0. Назад" << endl;
                cout << "> ";

                cin >> sub_menu_5;

                clear_line = cin.get(); // Очистка строки для корректной работы getline();

                switch (sub_menu_5) {
                case 1:
                    cout << "Введите индекс" << endl;
                    cout << "> ";

                    cin >> index;

                    table.del_index(index);

                    break;

                case 2:
                    cout << "Введите ключ" << endl;
                    cout << "> ";

                    getline(cin, key);

                    table.del_key(key);

                    break;
                }
            } while (sub_menu_5 != 0);

            break;

        case 6: // Подсчет колличества коллизий
            cout << "Колличество коллизий равно: " << table.collision_count() << endl;

            break;
        }

    } while (menu != 0);

    return 0;
}