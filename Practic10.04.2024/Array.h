#pragma once
#include <iostream>

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
		new char[sizeString] {"Сюда ходить нельзя. Выбери другую позицию\n"},
		new char[sizeString] {"Неверно указаны координаты. Повторите попытку\n"},
		new char[sizeString] {"Ошибка: либо файла не существует, либо он занят другим процессом\n"},
		new char[sizeString] {"Ошибка: Невозможно открыть файл!\n"}
	};

enum Menu { CONTINUE_GAME, NEW_GAME, TOURNAMENT, EXIT, FINISHED_GAME };
enum Error { ERROR_ENTER, ERROR_MOVE, ERROR_COORDINATE, ERROR_READ_FILE, ERROR_WRITE_FILE };