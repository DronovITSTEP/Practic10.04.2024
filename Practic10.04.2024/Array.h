#pragma once
#include <iostream>

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
		new char[sizeString] {"���� ������ ������. ������ ������ �������\n"},
		new char[sizeString] {"������� ������� ����������. ��������� �������\n"},
		new char[sizeString] {"������: ���� ����� �� ����������, ���� �� ����� ������ ���������\n"},
		new char[sizeString] {"������: ���������� ������� ����!\n"}
	};

enum Menu { CONTINUE_GAME, NEW_GAME, TOURNAMENT, EXIT, FINISHED_GAME };
enum Error { ERROR_ENTER, ERROR_MOVE, ERROR_COORDINATE, ERROR_READ_FILE, ERROR_WRITE_FILE };