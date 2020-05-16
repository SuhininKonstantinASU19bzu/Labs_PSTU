#include "Dialog.h"

// Конструктор без параметров
Dialog::Dialog() :Vector() {
	EndState = 0;
}

// Деструктор
Dialog::~Dialog() {

}

// Получение события
void Dialog::GetEvent(TEvent& event) {
	string OpInt = "+-?/qsmh"; // Строка содержит коды операций
	string s;
	string param;
	char code;

	cout << "> ";

	cin >> s;

	code = s[0]; // Первый символ команды

	if (OpInt.find(code) >= 0) { // Является ли символ кодом операции // Похоже это условие не работает
		event.what = evMessage;

		// Выделяем числовой параметр комманды, если он есть.
		if (s.length() >= 1) {
			param = s.substr(1, s.length() - 1); // Переписывание строки без первого символа

			int A = atoi(param.c_str()); // Преобразование числового параметра из строки в число

			event.a = A; // Запись параметра в сообщение
		}

		switch (code) { // Куда делись / и a ???
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'q': event.command = cmQuit; break;
		case '/': event.command = cmGet; break;
		case '?': event.command = cmGett; break;
		case 'h':
			cout << "Список доступных комманд:" << endl;
			cout << "m№ - Make(№ - размер группы)" << endl;
			cout << "+ - Add" << endl;
			cout << "- - Del" << endl;
			cout << "s - Show" << endl;
			cout << "q - Quit" << endl;
			cout << "?№ - Get(№ - позиции)" << endl;
			cout << "/ - Get" << endl;
		}
	}
	else event.what = evNothing; // Пустое событие
}

// Главный цикл обработки события
int Dialog::Execute() {
	TEvent event;

	do
	{
		EndState = 0;
		GetEvent(event); // Получить событие
		HandleEvent(event); // Обработать событие

	} while (!Valid());

	return EndState;
}

// Проверка атрибута EndState
int Dialog::Valid() {
	if (EndState == 0) return 0;
	else return 1;
}

// Обработка события
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake: // Создание группы
			Make(event.a);
			ClearEvent(event); // Очистка событий
			break;

		case cmAdd: // Добавление
			Add();
			ClearEvent(event);
			break;

		case cmDel: // Удаление
			Del();
			ClearEvent(event);
			break;

		case cmShow: // Просмотр
			Show();
			ClearEvent(event);
			break;

		case cmQuit: // Выход
			EndExec();
			ClearEvent(event);
			break;

		case cmGett:
			Get(event.a);
			ClearEvent(event);
			break;

		default: Vector::HandleEvent(event);
		}
	}
}

// Очистка событий
void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing; // Пустое событие
}

// Обработка события конец работы
void Dialog::EndExec() {
	EndState = 1;
}