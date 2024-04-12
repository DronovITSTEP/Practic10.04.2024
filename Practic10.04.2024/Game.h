#pragma once
#include "FuncGame.h"
#include "File.h"

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
	int count = 0;

	// проверка по строкам
	for (int i = 0; i < sizeBoard; i++) {
		count = 0;
		for (int j = 0; j < sizeBoard; j++) {
			if (symb == board[i][j]) count++;
		}
		if (count == 3) return true;
	}

	// проверка по столбцам
	for (int i = 0; i < sizeBoard; i++) {
		count = 0;
		for (int j = 0; j < sizeBoard; j++) {
			if (symb == board[j][i]) count++;
		}
		if (count == 3) return true;
	}

	// проверка по диагоналям
	count = 0;
	for (int i = 0, j = 0; i < sizeBoard; i++, j++) {
		if (symb == board[j][i]) count++;
	}
	if (count == 3) return true;

	count = 0;
	for (int i = sizeBoard - 1, j = 0; j < sizeBoard; i--, j++) {
		if (symb == board[j][i]) count++;
	}
	if (count == 3) return true;

	return false;
}

