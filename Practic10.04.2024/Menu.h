#pragma once
#include <iostream>
#include "Game.h"
#include "File.h"

using namespace std;

const int sizeMenuRow = 4;
const int sizeMenuString = 50;

char** menu = new char* [sizeMenuRow]
	{
		new char[sizeMenuString] {"1. ���������� ����"},
		new char[sizeMenuString] {"2. ����� ����"},
		new char[sizeMenuString] {"3. ��������� �������"},
		new char[sizeMenuString] {"4. �����"}
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
		cout << "����� (�� 1 �� 4) -> ";
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
			cout << "������ ����. ��������� �������\n";
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
	}
}