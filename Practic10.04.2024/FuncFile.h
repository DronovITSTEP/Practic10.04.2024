#pragma once
#include <iostream>
#include "Array.h"

FILE* file = nullptr;
const char path[25] = "tournament.bin";

char* lose = nullptr;
char* win = nullptr;

bool closeFile();

char* readFile();

void readText(char*, int);

char* writeFile(char*);

void writeText(int, int );


