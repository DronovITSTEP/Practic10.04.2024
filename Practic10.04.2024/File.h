#pragma once
#include <iostream>
#include "FuncFile.h"

bool closeFile() {
	if (fclose(file) == EOF) return true;
	else return false;
}

void readText(char* tournamentText, int fileSize) 
{
	tournamentText[fileSize] = '\0';
	lose = strchr(tournamentText, ':');
	win = new char[strlen(tournamentText) - strlen(lose)];
	strncpy_s(win, strlen(tournamentText) - strlen(lose) + 1,
		tournamentText, strlen(tournamentText) - strlen(lose));
	
	player.win = atoi(win);
	player.lose = atoi(lose);
}

char* readFile(){
	if (file != nullptr) closeFile();

	if (!fopen_s(&file, path, "rb")) {
		fseek(file, 0, SEEK_END);
		long fileSize = ftell(file);
		fseek(file, 0, SEEK_SET);

		char* tournamentText = new char[fileSize + 1];
		fread(tournamentText, 1, fileSize+1, file);
		readText(tournamentText, fileSize);
		closeFile();
		return nullptr;
	}
	else {
		return errors[ERROR_READ_FILE];
	}
}

char* writeFile(char* tournamentText){
	if (file != nullptr) closeFile();

	if (!fopen_s(&file, path, "wb")) {
		fwrite(tournamentText, 1, strlen(tournamentText), file);
		closeFile();
		return nullptr;
	}
	else {
		return errors[ERROR_WRITE_FILE];
	}

}

void writeText(int win, int lose) {
	char* text = new char[10];
	sprintf_s(text, 10, "%d:%d\0", win, lose);
	writeFile(text);
}

