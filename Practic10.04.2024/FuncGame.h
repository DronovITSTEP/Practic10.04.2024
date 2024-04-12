#pragma once
#include <iostream>

using namespace std;

struct Player {
	char user = 0;
	char comp = 0;
	int win = 0;
	int lose = 0;
} player;

const char x = 'X';
const char o = 'O';

const int sizeBoard = 3;

char** board = new char* [sizeBoard]
	{
		new char[sizeBoard] {'_', '_', '_'},
			new char[sizeBoard] {'_', '_', '_'},
			new char[sizeBoard] {'_', '_', '_'},
	};


/// <summary> 
///выводим игровую доску в консоль с отображением хода игрока и компьютера
/// </summary>
void printBoard();
/// <summary>
/// начало игры
/// </summary>
char* startGame();
/// <summary>
/// ход пользователя
/// </summary>
/// <returns>true если ход был победным</returns>
bool moveUser();
/// <summary>
/// ход компьютера
/// </summary>
/// <returns>true если ход был победным</returns>
bool moveComputer();
/// <summary>
/// происходит проверка на победу одного из игроков
/// </summary>
/// <param name="symb">символ игрока</param>
/// <returns>true если победа</returns>
bool isWin(char);
/// <summary>
/// сброс доски на начальные значения
/// </summary>
void restartBoard();
