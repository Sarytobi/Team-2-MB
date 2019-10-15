#include <iostream>
using namespace std;

void CreateBoard(int** gameBoard, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameBoard[i][j] = 0;
		}
	}
}

void OutputBoard(int** gameBoard, int size)
{
	cout << "    12345678910";
	cout << endl << "   ------------" << endl;
	for (int i = 1; i < size - 1; i++)
	{
		if (i == 10)
		{
			cout << i << " |";
		}
		else
		{
			cout << ' ' << i << " |";
		}
		for (int j = 1; j < size - 1; j++)
		{
			if (gameBoard[i][j] == 0)
			{
				cout << " ";
			}
			else if (gameBoard[i][j] == 5)
			{
				cout << "x";
			}
			else if (gameBoard[i][j] == 6)
			{
				cout << "X";
			}
			else if (gameBoard[i][j] == 10)
			{
				cout << "*";
			}
			else if (gameBoard[i][j] == 1 || gameBoard[i][j] == 2 || gameBoard[i][j] == 3 || gameBoard[i][j] == 4)
			{
				cout << "O";
			}
		}
		cout << "|" << endl;
	}
	cout << "   ------------" << endl;
}

void InitBoard(int** gameBoard, int size)
{
	char shipDirection;
	int startPointRow, startPointCol;
	bool chekShipNearby = true;
	cout << "Расположим четырехпалубник " << endl;
	do
	{
		cout << "Введите g - горизонтальное расположение корабля, v - вертикальное ";
		cin >> shipDirection; cout << endl;
		if (shipDirection == 'g' || shipDirection == 'G')
		{
			do
			{
				cout << "Введите начальную координату(строку) ";
				cin >> startPointRow; cout << endl;
				cout << "Введите начальную координату(столбец) ";
				cin >> startPointCol; cout << endl;
				if (startPointCol <= 7)
				{
					break;
				}
				else
				{
					cout << "Корабль выходит за пределы доски " << endl;
				}
			} while (true);
			
			for (int l = 0; l < 4; l++)
			{
				gameBoard[startPointRow][startPointCol + l] = 4;
			}
			break;
		}
		else if (shipDirection == 'v' || shipDirection == 'V')
		{
			do
			{
				cout << "Введите начальную координату(строку) ";
				cin >> startPointRow; cout << endl;
				cout << "Введите начальную координату(столбец) ";
				cin >> startPointCol; cout << endl;
				if (startPointRow <= 7)
				{
					break;
				}
				else
				{
					cout << "Корабль выходит за пределы доски " << endl;
				}
			} while (true);
			
			for (int l = 0; l < 4; l++)
			{
				gameBoard[startPointRow + l][startPointCol] = 4;
			}
			break;
		}
		else
		{
			cout << "Ошибка ввода " << endl;
		}
	} while (true);
	system("cls");
	OutputBoard(gameBoard, size);
	cout << "Расположим два трехпалубника " << endl;
	for (int i = 0; i < 2; i++)
	{
		do
		{
			cout << "Введите g - горизонтальное расположение корабля, v - вертикальное ";
			cin >> shipDirection; cout << endl;
			if (shipDirection == 'g' || shipDirection == 'G')
			{
				do
				{
					chekShipNearby = true;
					cout << "Введите начальную координату(строку) ";
					cin >> startPointRow; cout << endl;
					cout << "Введите начальную координату(столбец) ";
					cin >> startPointCol; cout << endl;
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 5; k++)
						{
							if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointCol <= 8 && chekShipNearby)
					{
						break;
					}
					else
					{
						cout << "Корабль выходит за пределы доски или залезает на другие корабли" << endl;
					}
				} while (true);

				for (int l = 0; l < 3; l++)
				{
					gameBoard[startPointRow][startPointCol + l] = 3;
				}
				break;
			}
			else if (shipDirection == 'v' || shipDirection == 'V')
			{
				do
				{
					chekShipNearby = true;
					cout << "Введите начальную координату(строку) ";
					cin >> startPointRow; cout << endl;
					cout << "Введите начальную координату(столбец) ";
					cin >> startPointCol; cout << endl;
					for (int j = 0; j < 5; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointRow <= 8 && chekShipNearby)
					{
						break;
					}
					else
					{
						cout << "Корабль выходит за пределы доски или залезает на другие корабли" << endl;
					}
				} while (true);

				for (int l = 0; l < 3; l++)
				{
					gameBoard[startPointRow + l][startPointCol] = 3;
				}
				break;
			}
			else
			{
				cout << "Ошибка ввода " << endl;
			}
		} while (true);
		system("cls");
		OutputBoard(gameBoard, size);
	}
	cout << "Расположим три двухпалубника " << endl;
	for (int i = 0; i < 3; i++)
	{
		do
		{
			cout << "Введите g - горизонтальное расположение корабля, v - вертикальное ";
			cin >> shipDirection; cout << endl;
			if (shipDirection == 'g' || shipDirection == 'G')
			{
				do
				{
					chekShipNearby = true;
					cout << "Введите начальную координату(строку) ";
					cin >> startPointRow; cout << endl;
					cout << "Введите начальную координату(столбец) ";
					cin >> startPointCol; cout << endl;
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 4; k++)
						{
							if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointCol <= 9 && chekShipNearby)
					{
						break;
					}
					else
					{
						cout << "Корабль выходит за пределы доски или залезает на другие корабли" << endl;
					}
				} while (true);

				for (int l = 0; l < 2; l++)
				{
					gameBoard[startPointRow][startPointCol + l] = 2;
				}
				break;
			}
			else if (shipDirection == 'v' || shipDirection == 'V')
			{
				do
				{
					chekShipNearby = true;
					cout << "Введите начальную координату(строку) ";
					cin >> startPointRow; cout << endl;
					cout << "Введите начальную координату(столбец) ";
					cin >> startPointCol; cout << endl;
					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointRow <= 9 && chekShipNearby)
					{
						break;
					}
					else
					{
						cout << "Корабль выходит за пределы доски или залезает на другие корабли" << endl;
					}
				} while (true);

				for (int l = 0; l < 2; l++)
				{
					gameBoard[startPointRow + l][startPointCol] = 2;
				}
				break;
			}
			else
			{
				cout << "Ошибка ввода " << endl;
			}
		} while (true);
		system("cls");
		OutputBoard(gameBoard, size);
	}
	cout << "Расположим четыре однопалубника " << endl;
	for (int i = 0; i < 4; i++)
	{
		do
		{
			chekShipNearby = true;
			cout << "Введите начальную координату(строку) ";
			cin >> startPointRow; cout << endl;
			cout << "Введите начальную координату(столбец) ";
			cin >> startPointCol; cout << endl;
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
					{
						chekShipNearby = false;
					}
				}
			}
			if (startPointCol <= 10  && startPointRow <= 10 && chekShipNearby)
			{
				break;
			}
			else
			{
				cout << "Корабль выходит за пределы доски или залезает на другие корабли" << endl;
			}
		} while (true);
		gameBoard[startPointRow][startPointCol] = 1;
		system("cls");
		OutputBoard(gameBoard, size);
	}
}