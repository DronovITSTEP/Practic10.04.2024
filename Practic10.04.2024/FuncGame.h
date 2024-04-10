#pragma once
#include <iostream>
#include "FuncGame.h"

using namespace std;

struct Player {
	char user;
	char comp;
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
///������� ������� ����� � ������� � ������������ ���� ������ � ����������
/// </summary>
void printBoard();
/// <summary>
/// ������ ����
/// </summary>
void startGame();
/// <summary>
/// ��� ������������
/// </summary>
/// <returns>true ���� ��� ��� ��������</returns>
bool moveUser();
/// <summary>
/// ��� ����������
/// </summary>
/// <returns>true ���� ��� ��� ��������</returns>
bool moveComputer();
/// <summary>
/// ���������� �������� �� ������ ������ �� �������
/// </summary>
/// <param name="symb">������ ������</param>
/// <returns>true ���� ������</returns>
bool isWin(char);
/// <summary>
/// ����� ����� �� ��������� ��������
/// </summary>
void restartBoard();
