#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Структура дерево
struct Node {
    char key;
    Node* left;
    Node* right;
    int height;
};

// Получение высоты дерева 
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Нахождение максимального значения
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Создание нового дерева
Node* new_node(char key) {
    Node* node = new Node();

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// Поворот вправо  
Node* turn_right(Node* root) {
    Node* child = root->left;
    Node* temp = child->right;
  
    // Выполнение поворота 
    child->right = root;
    root->left = temp;

    // Обновление высоты  
    root->height = max(height(root->left), height(root->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    return child;
}

// Поворот влево  
Node* turn_left(Node* root) {
    Node* child = root->right;
    Node* temp = child->left;
 
    // Выполнение поворота 
    child->left = root;
    root->right = temp;

    // Update heights  
    root->height = max(height(root->left), height(root->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;
 
    return child;
}

// Получение фактора баланса
int get_balance(Node* node) {
    if (node == NULL) return 0;

    return (height(node->left) - height(node->right));
}

// Добавление элемента в дерево c балансировкой при добавлении
Node* insert(Node* node, char key) {
    if (node == NULL) return(new_node(key));

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else { // Одинаковые ключи не допустимы
        return node;
    }

    // Обновление высоты
    node->height = 1 + max(height(node->left), height(node->right));

    // Проверка баланса
    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key) {
        return turn_right(node);
    }

    if (balance < -1 && key > node->right->key) {
        return turn_left(node);
    }

    if (balance > 1 && key > node->left->key) {
        node->left = turn_left(node->left);

        return turn_right(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = turn_right(node->right);

        return turn_left(node);
    }

    return node;
}

// Функция получения строки, для печати
void get_line(const Node* root, int depth, vector<char>& vec) {
    if (depth <= NULL && root != NULL) {
        vec.push_back(root->key);

        return;
    }

    if (root->left != NULL) {
        get_line(root->left, depth - 1, vec);
    }
    else if (depth - 1 <= NULL) {
        vec.push_back(' '); // Вставка разделителя
    }

    if (root->right != NULL) {
        get_line(root->right, depth - 1, vec);
    }
    else if (depth - 1 <= NULL) {
        vec.push_back(' '); // Вставка разделителя
    }
}

// Функция печати дерева
void print(const Node* node, const int height, int depth) {
    vector<char> vec;

    get_line(node, depth, vec); // Получение строки

    cout << setw((height - depth) * 3); // Настройка параметров вывода относительно размера

    bool toggle = true; // Начало слева

    if (vec.size() > 1) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] != ' ') {
                if (toggle) {
                    cout << "/" << setw((height - depth) / 2);
                }
                else {
                    cout << "\\" << setw((height - depth) / 2);
                }
            }

            toggle = !toggle;
        }

        cout << endl << setw((height - depth) * 3);
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != ' ') {
            cout << vec[i] << setw((height - depth) / 2);
        }
    }

    cout << endl;
}

// Основной цикл печати дерева
void show_tree(Node* node) {
    int h = height(node) * 2;

    // можно подправить i для получения корректной глубины
    for (int i = 0; i < h; i++) {
        print(node, h, i);
    }
}

// Добавление элемента
Node* add_element(Node* node) {
    char key;

    cout << "Введите букву" << endl;
    cout << "> ";

    cin >> key;

    node = insert(node, key);

    return node;
}

// Создание дерева
Node* generate() {
    Node* node = NULL;
    char key;
    char answer;
    int size;

    cout << "Заполнить вручную?" << endl;
    cout << "> ";

    cin >> answer;

    if (answer == 'Y' || answer == 'y') {
        cout << "Введите количество элементов : ";
        cin >> size;

        for (int i = 0; i < size; i++) {
            node = add_element(node);
        }
    }
    else {
        cout << "Введите количество элементов : ";
        cin >> size;

        for (int i = 1; i <= size; i++) {

            switch (i) {
            case 1:
                key = 'a';
                break;
            case 2:
                key = 'b';
                break;
            case 3:
                key = 'c';
                break;
            case 4:
                key = 'd';
                break;
            case 5:
                key = 'e';
                break;
            case 6:
                key = 'f';
                break;
            case 7:
                key = 'g';
                break;
            case 8:
                key = 'h';
                break;
            case 9:
                key = 'i';
                break;
            case 10:
                key = 'j';
                break;
            case 11:
                key = 'k';
                break;
            case 12:
                key = 'l';
                break;
            case 13:
                key = 'm';
                break;
            case 14:
                key = 'n';
                break;
            case 15:
                key = 'o';
                break;
            case 16:
                key = 'p';
                break;
            case 17:
                key = 'q';
                break;
            case 18:
                key = 'r';
                break;
            case 19:
                key = 's';
                break;
            case 20:
                key = 't';
                break;
            case 21:
                key = 'u';
                break;
            case 22:
                key = 'v';
                break;
            case 23:
                key = 'w';
                break;
            case 24:
                key = 'x';
                break;
            case 25:
                key = 'y';
                break;
            case 26:
                key = 'z';
                break;
            default:
                break;
            }

            node = insert(node, key);
        }
    }

    return node;
}

// Подсчет по заданному ключу
void count(Node* node, int& counter, char key) {
    if (node != NULL) {
        if (node->key == key) {
            counter++;
        }

        count(node->right, counter, key);
        count(node->left, counter, key);
    }
}