#pragma once
#include "FuncGame.h"

void printBoard() {
	for (int i = 0; i < sizeBoard; i++) {
		for (int j = 0; j < sizeBoard; j++) {
			cout << '|' << board[i][j] << '|';
		}
		cout << endl;
	}
}
void restartBoard() {
	for (int i = 0; i < sizeBoard; i++) {
		for (int j = 0; j < sizeBoard; j++) {
			board[i][j] = '_';
		}
	}
}

char* startGame() {

	srand(time(0));
	int r = rand() % 2;

	int count = 0;

	while (count != 9) {
		printBoard();

		if (r) {
			player.user = x;
			player.comp = o;
			if (moveUser())
			{
				player.win++;
				break;
			}
			if (moveComputer()) 
			{
				player.lose++;
				break;
			}
		}
		else {
			player.user = o;
			player.comp = x;
			if (moveComputer()) 
			{
				player.lose++;
				break;
			}
			if (moveUser())
			{
				player.win++;
				break;
			}
		}
		count++;
	}

	writeText(player.win, player.lose);
	printBoard();
	
	restartBoard();
	return menu[FINISHED_GAME];
}

bool moveUser() {
	int x, y;
	cout << "Введите Х (1-3) -> ";
	cin >> x;
	cout << "Введите Y (1-3) -> ";
	cin >> y;
	if (x > 0 && x < 4 && y > 0 && y < 4)
	{
		if (board[x - 1][y - 1] == '_')
			board[x - 1][y - 1] = player.user;
		else {
			cout << errors[ERROR_MOVE];
			moveUser();
		}
	}
	else{
		cout << errors[ERROR_COORDINATE];
		moveUser();
	}

	return isWin(player.user);
}
bool moveComputer() {
	int x = rand() % 3;
	int y = rand() % 3;
	if (board[x][y] == '_')
		board[x][y] = player.comp;
	else
		moveComputer();

	return isWin(player.comp);
}

bool isWin(char symb) {
	int countRow = 0;
	int countCol = 0;

	// проверка по строкам и столбцам
	for (int i = 0; i < sizeBoard; i++) {
		countRow = 0;
		countCol = 0;
		for (int j = 0; j < sizeBoard; j++) {
			if (symb == board[i][j]) countRow++;
			if (symb == board[j][i]) countCol++;
		}
		if (countRow == 3) return true;
		if (countCol == 3) return true;
	}


	// проверка по диагоналям
	int count1 = 0;
	int count2 = 0;
	for (int i = 0, j = sizeBoard-1; i < sizeBoard; i++, j--) {
		if (symb == board[i][i]) count1++;
		if (symb == board[i][j]) count2++;
	}
	if (count1 == 3) return true;
	if (count2 == 3) return true;

	return false;
}

