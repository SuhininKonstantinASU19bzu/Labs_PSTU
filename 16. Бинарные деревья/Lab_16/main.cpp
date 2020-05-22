#include <iostream>
#include <locale>
#include "Node.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    Node* root = NULL;
    int menu;

    do {
        cout << "1. Создать новое дерево" << endl;
        cout << "2. Добавить элемент" << endl;
        cout << "3. Просмотр дерева" << endl;
        cout << "4. Подсчет количества элементов с заданным ключем" << endl;
        cout << "0. Выход" << endl;
        cout << "> ";
        cin >> menu;

        switch (menu) {
        case 1:
            root = generate();

            break;

        case 2:
            root = add_element(root);

            break;

        case 3:
            show_tree(root);

            break;

        case 4:
            char key;
            int counter = 0;

            cout << "Для подсчета элементов с указанным ключем" << endl;
            cout << "Введите ключ поиска" << endl;
            cout << "> ";

            cin >> key;

            count(root, counter, key);

            // Максимально возможное значение равно 1, так как ключем являеься сам элемент,
            // а в сбалансированном дереве ключи уникальны
            cout << "Количество найденых элементов равно: " << counter << endl;

            break;
        }
    } while (menu != 0);

    return 0;
}