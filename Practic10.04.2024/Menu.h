#pragma once
#include <iostream>
#include "Game.h"
#include "File.h"
#include "Array.h"

using namespace std;



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