#pragma once
#include <iostream>
#include "Game.h"
#include "File.h"

using namespace std;

const int sizeMenuRow = 10;
const int sizeErrorRow = 5;
const int sizeString = 255;

char** menu = new char* [sizeMenuRow]
	{
		new char[sizeString] {"1. Продолжить игру"},
		new char[sizeString] {"2. Новая игра"},
		new char[sizeString] {"3. Турнирная таблица"},
		new char[sizeString] {"4. Выход"},
		new char[sizeString] {"Игра закончена!\n"},
		new char[sizeString] {}
	};

char** errors = new char* [sizeErrorRow] {
	new char[sizeString] {"Ошибка вода. Повторите попытку\n"},
	new char[sizeString]{"Сюда ходить нельзя. Выбери другую позицию\n"},
	new char[sizeString]{"Неверно указаны координаты. Повторите попытку\n"},
	new char[sizeString]{"Ошибка: либо файла не существует, либо он занят другим процессом\n"},
	new char[sizeString]{"Ошибка: Невозможно открыть файл!\n"}
	};

enum Menu { CONTINUE_GAME, NEW_GAME, TOURNAMENT, EXIT, FINISHED_GAME };
enum Error {ERROR_ENTER, ERROR_MOVE, ERROR_COORDINATE, ERROR_READ_FILE, ERROR_WRITE_FILE};

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
			readFile();
			cout << startGame();
			break;
		case TOURNAMENT:
			readFile();
			cout << "Побед: " << player.win << " Поражений: " << player.lose << endl;
			break;
		case EXIT:
			flag = false;
			break;
		default:
			cout << errors[ERROR_ENTER];
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
	}
}