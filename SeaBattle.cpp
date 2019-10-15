
#include <iostream>
#include "ioarray.h"
#include "play.h"

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

	int lifeCounter1 = 0;
	int lifeCounter2 = 0;

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

	do
	{
		//Стреляет первый игрок
		do
		{
			if (Shoot(gameBoard2, SIZE) == 0)
			{
				break;
			}
			else
			{
				lifeCounter2++;
				if (lifeCounter2 >= 20)
				{
					break;
				}
			}

		} while (true);
		
		//Стреляет второй игрок
		do
		{
			if (Shoot(gameBoard1, SIZE) == 0)
			{
				break;
			}
			else
			{
				lifeCounter1++;
				if (lifeCounter1 >= 20)
				{
					break;
				}
			}

		} while (true);

		if (lifeCounter1 >= 20 || lifeCounter2 >= 20)
		{
			break;
		}
	} while (true);

	if (lifeCounter1 >= 20)
	{
		system("cls");
		cout << "Победа второго игрока " << endl;
	}
	else if (lifeCounter2 >= 20)
	{
		system("cls");
		cout << "Победа первого игрока " << endl;
	}
	else
	{
		cout << "Что-то не так с жизнями игроков " << endl;
	}

	for (int i = 0; i < SIZE; i++)
	{
		delete[] gameBoard1[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		delete[] gameBoard2[i];
	}
}
