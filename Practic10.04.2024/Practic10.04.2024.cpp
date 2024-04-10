﻿#include <iostream>
#include "Menu.h"


using namespace std;

void main() 
{
	/*
	открытие файла: fopen_s()
	закрытие файла: fclose()
	*/
	/*
	режимы открытия:
	r - для чтения
	w - для записи
	a - для добавления
	*/

	/*
	для чтения:
	fgetc() - для чтения только одного символа
	fgets() - для чтения по строкам
	fscanf("%s") - для чтения форматированной строки (только слово)
	fread() - для чтения всего содержимого (для режима rb, rb+)
	*/

	/*
	для записи:
	fputc() - для записи только одного символа
	fputs() - для записи одной строки
	fprintf() - для записи форматированной строки
	fwrite() - для записи всего содержимого (для режима wb, wb+, ab, ab+)
	*/

	setlocale(LC_ALL, "");

	startMenu();
}