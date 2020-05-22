#include <iostream>
#include <locale>
#include <list>
#include "Weather.h"
#include "File_work.h"
#include "List.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    List mainL;
    List backupL;
    Weather key, element;
    char file_name[30];
    char answer;
    int num, k, menu;
    bool cheange = false;

    do {
        cout << "1. Создать новую базу данных" << endl;
        cout << "2. Открыть сушествующую базу данных" << endl;
        cout << "3. Просмотр содержимого" << endl;
        cout << "4. Удаление элемента" << endl;
        cout << "5. Редактирование элемента" << endl;
        cout << "6. Добавление нового элемента" << endl;
        cout << "7. Расчетные действия" << endl;
        cout << "8. Сохранить изменения" << endl;
        cout << "0. Выход" << endl;
        cout << "> ";
        cin >> menu;

        switch (menu) {
        case 1: // Создание базы данных
            if (cheange) {
                cout << "Сохранить изменения в текущей базе данных?" << endl;
                cout << "> ";

                cin >> answer;

                if (answer == 'Y' || answer == 'y') {
                    k = save_file(file_name, mainL, cheange);
                    cout << " Изменения сохранены" << endl;
                }
            }

            cout << "Введите имя файла: ";
            cin >> file_name;

            k = make_file(file_name, mainL);

            if (k < 0) cout << "Невозможно создать файл";

            break;

        case 2: // Открытие базы данных
            if (cheange) {
                cout << "Сохранить изменения в текущей базе данных?" << endl;
                cout << "> ";

                cin >> answer;

                if (answer == 'Y' || answer == 'y') {
                    k = save_file(file_name, mainL, cheange);
                    cout << " Изменения сохранены" << endl;
                }
            }

            cout << "Введите имя открываемого файла: ";
            cin >> file_name;


            k = open_file(file_name, mainL);

            if (k == 0) cout << "Файл пуст" << endl;
            if (k < 0) cout << "Невозможно прочитать файл" << endl;

            break;

        case 3: // Просмотр содержимого
            print_list(mainL);

            break;

        case 4: // Удаление элемента
            int sub_menu_4;

            do {
                cout << "1. Удаление элемента по номеру" << endl;
                cout << "2. Удаление элемента по ключу" << endl;
                cout << "3. Отменить последнюю операцию удаления" << endl;
                cout << "0. Назад" << endl;
                cout << "> ";
                cin >> sub_menu_4;

                switch (sub_menu_4) {
                case 1:
                    backup(mainL, backupL);

                    cout << "введите номер" << endl;
                    cout << "> ";

                    cin >> num;

                    del_pos(mainL, num, cheange);

                    break;

                case 2:
                    backup(mainL, backupL);

                    cout << "введите ключ" << endl;
                    cout << "> ";

                    cin >> key;

                    del_key(mainL, key, cheange);

                    break;

                case 3:
                    cout << "Отменить последнюю операцию удаления?" << endl;
                    cout << "> ";

                    cin >> answer;

                    if (answer == 'Y' || answer == 'y') {
                        rewind(mainL, backupL);
                        cout << "Удаление отменено" << endl;
                        cheange = false;
                    }

                    break;
                }

            } while (sub_menu_4 != 0);

            if (sub_menu_4 == 0 && cheange) del_operation(mainL, backupL);

            break;

        case 5: // Редактирование элемента
            int sub_menu_5;

            do {
                cout << "1. Редактирование элемента по номеру" << endl;
                cout << "2. Редактирование элемента по ключу" << endl;
                cout << "3. Отменить последнюю операцию редактирования" << endl;
                cout << "0. Назад" << endl;
                cout << "> ";
                cin >> sub_menu_5;

                switch (sub_menu_5) {
                case 1:
                    backup(mainL, backupL);

                    cout << "введите номер" << endl;
                    cout << "> ";

                    cin >> num;

                    cout << "введите новый элемент" << endl;
                    cout << "> ";

                    cin >> element;


                    change_pos(mainL, element, num, cheange);

                    break;

                case 2:
                    backup(mainL, backupL);

                    cout << "введите ключ" << endl;
                    cout << "> ";

                    cin >> key;

                    cout << "введите новый элемент" << endl;
                    cout << "> ";

                    cin >> element;


                    change_key(mainL, element, key, cheange);

                    break;

                case 3:
                    cout << "Отменить последнюю операцию редактирования?" << endl;
                    cout << "> ";

                    cin >> answer;

                    if (answer == 'Y' || answer == 'y') {
                        rewind(mainL, backupL);
                        cout << "Редактирование отменено" << endl;
                        cheange = false;
                    }

                    break;
                }

            } while (sub_menu_5 != 0);

            break;

        case 6: // Добавление нового элемента
            int sub_menu_6;

            do {
                cout << "1. Добавление элемента в начало" << endl;
                cout << "2. Добавление элемента в конец" << endl;
                cout << "3. Добавление элемента в позицию с указанным номером" << endl;
                cout << "3. Отменить последнюю операцию добавления" << endl;
                cout << "0. Назад" << endl;
                cout << "> ";
                cin >> sub_menu_6;

                switch (sub_menu_6) {
                case 1:
                    backup(mainL, backupL);

                    cout << "введите новый элемент" << endl;
                    cout << "> ";

                    cin >> element;

                    add_begin(mainL, element, cheange);

                    break;

                case 2:
                    backup(mainL, backupL);

                    cout << "введите новый элемент" << endl;
                    cout << "> ";

                    cin >> element;

                    add_end(mainL, element, cheange);

                    break;

                case 3:
                    backup(mainL, backupL);

                    cout << "введите номер" << endl;
                    cout << "> ";

                    cin >> num;

                    cout << "введите новый элемент" << endl;
                    cout << "> ";

                    cin >> element;

                    add_pos(mainL, element, num, cheange);

                    break;

                case 4:
                    cout << "Отменить последнюю операцию добавления?" << endl;
                    cout << "> ";

                    cin >> answer;

                    if (answer == 'Y' || answer == 'y') {
                        rewind(mainL, backupL);
                        cout << "Добавление отменено" << endl;
                        cheange = false;
                    }

                    break;
                }

            } while (sub_menu_6 != 0);

            break;

        case 7: // Расчетные действия
            int sub_menu_7;

            do {
                cout << "1. Вывести дни в которые температура поднималась выше средней" << endl;
                cout << "2. Самый длинный отрезок между днями с отрицательной температурой" << endl;
                cout << "0. Назад" << endl;
                cout << "> ";
                cin >> sub_menu_7;

                switch (sub_menu_7) {
                case 1:
                    average_day(mainL);

                    break;
                case 2:
                    cout << "Самый длинный отрезок: " << min_range(mainL) << endl;

                    break;
                }

            } while (sub_menu_7 != 0);

            break;

        case 8: // Сохранение базы данных
            k = save_file(file_name, mainL, cheange);

            break;
        }

    } while (menu != 0);

    if (menu == 0 && cheange) {
        cout << "Сохранить изменения в текущей базе данных?" << endl;
        cout << "> ";

        cin >> answer;

        if (answer == 'Y' || answer == 'y') {
            k = save_file(file_name, mainL, cheange);
            cout << " Изменения сохранены" << endl;
        }
    }

    return 0;
}