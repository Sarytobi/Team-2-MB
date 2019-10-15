﻿
#include <iostream>
#include "ioarray.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 12;
	int** gameBoard1 = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		gameBoard1[i] = new int[SIZE];
	}
	int** gameBoard2 = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		gameBoard2[i] = new int[SIZE];
	}

	CreateBoard(gameBoard1, SIZE);
	CreateBoard(gameBoard2, SIZE);
	cout << "Доска первого игрока " << endl;
	OutputBoard(gameBoard1, SIZE);
	cout << "Доска второго игрока " << endl;
	OutputBoard(gameBoard2, SIZE);
	cout << "Расставим корабли первого игрока " << endl;
	InitBoard(gameBoard1, SIZE);
	cout << "Расставим кораболи второго игрока " << endl;
	InitBoard(gameBoard2, SIZE);
	system("cls");
	cout << "Доска первого игрока " << endl;
	OutputBoard(gameBoard1, SIZE);
	cout << "Доска второго игрока " << endl;
	OutputBoard(gameBoard2, SIZE);



	for (int i = 0; i < SIZE; i++)
	{
		delete[] gameBoard1[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		delete[] gameBoard2[i];
	}
}
