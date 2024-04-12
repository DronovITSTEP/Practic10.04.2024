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
		new char[sizeString] {"1. ���������� ����"},
		new char[sizeString] {"2. ����� ����"},
		new char[sizeString] {"3. ��������� �������"},
		new char[sizeString] {"4. �����"},
		new char[sizeString] {"���� ���������!\n"},
		new char[sizeString] {}
	};

char** errors = new char* [sizeErrorRow] {
	new char[sizeString] {"������ ����. ��������� �������\n"},
	new char[sizeString]{"���� ������ ������. ������ ������ �������\n"},
	new char[sizeString]{"������� ������� ����������. ��������� �������\n"},
	new char[sizeString]{"������: ���� ����� �� ����������, ���� �� ����� ������ ���������\n"},
	new char[sizeString]{"������: ���������� ������� ����!\n"}
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
		cout << "����� (�� 1 �� 4) -> ";
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
			cout << "�����: " << player.win << " ���������: " << player.lose << endl;
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