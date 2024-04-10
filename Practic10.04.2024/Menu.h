#pragma once
#include <iostream>
#include "Game.h"
#include "File.h"

using namespace std;

const int sizeMenuRow = 4;
const int sizeMenuString = 50;

char** menu = new char* [sizeMenuRow]
	{
		new char[sizeMenuString] {"1. Продолжить игру"},
		new char[sizeMenuString] {"2. Новая игра"},
		new char[sizeMenuString] {"3. Турнирная таблица"},
		new char[sizeMenuString] {"4. Выход"}
	};

enum Menu { CONTINUE_GAME, NEW_GAME, TOURNAMENT, EXIT };

void startMenu() {
	bool flag = true;
	while (flag) {
		cout << menu[CONTINUE_GAME] << endl;
		cout << menu[NEW_GAME] << endl;
		cout << menu[TOURNAMENT] << endl;
		cout << menu[EXIT] << endl;

		int choice;
		cout << "Выбор (от 1 до 4) -> ";
		cin >> choice;

		switch (choice - 1)
		{
		case CONTINUE_GAME:
			break;
		case NEW_GAME:
			startGame();
			break;
		case TOURNAMENT:
			break;
		case EXIT:
			flag = false;
			break;
		default:
			cout << "Ошибка вода. Повторите попытку\n";
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
	}
}