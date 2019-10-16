#include <iostream>
#include "conio.h"
#include "windows.h"
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
	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
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
				cout << " " << "|";
			}
			else if (gameBoard[i][j] == 5)
			{
				cout << "x" << "|";
			}
			else if (gameBoard[i][j] == 6)
			{
				cout << "X" << "|";
			}
			else if (gameBoard[i][j] == 10)
			{
				cout << "*" << "|";
			}
			else if (gameBoard[i][j] == 1 || gameBoard[i][j] == 2 || gameBoard[i][j] == 3 || gameBoard[i][j] == 4)
			{
				cout << "O" << "|";
			}
		}
		cout << endl;
	}
}

void OutputBoardDisguise(int** gameBoard, int size)
{
	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
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
				cout << " " << "|";
			}
			else if (gameBoard[i][j] == 5)
			{
				cout << "x" << "|";
			}
			else if (gameBoard[i][j] == 6)
			{
				cout << "X" << "|";
			}
			else if (gameBoard[i][j] == 10)
			{
				cout << "*" << "|";
			}
			else if (gameBoard[i][j] == 1 || gameBoard[i][j] == 2 || gameBoard[i][j] == 3 || gameBoard[i][j] == 4)
			{
				cout << " " << "|";
			}
		}
		cout << endl;
	}
}

void InitBoard(int** gameBoard, int size)
{
	char shipDirection;
	int startPointRow, startPointCol;
	bool chekShipNearby = true;
	cout << "Let arrange four-deckers ship " << endl;
	do
	{
		cout << "Enter g - gorizontal ship, v - vertical ship ";
		cin >> shipDirection; cout << endl;
		if (shipDirection == 'g' || shipDirection == 'G')
		{
			do
			{
				cout << "Enter the starting coordinate of the ship(row) ";
				cin >> startPointRow; cout << endl;
				cout << "Enter the starting coordinate of the ship(column) ";
				cin >> startPointCol; cout << endl;
				if (startPointCol <= 7)
				{
					break;
				}
				else
				{
					cout << "The ship is out of the game board " << endl;
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
				cout << "Enter the starting coordinate of the ship(row) ";
				cin >> startPointRow; cout << endl;
				cout << "Enter the starting coordinate of the ship(column) ";
				cin >> startPointCol; cout << endl;
				if (startPointRow <= 7)
				{
					break;
				}
				else
				{
					cout << "The ship is out of the game board " << endl;
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
			cout << "Input error " << endl;
		}
	} while (true);
	system("cls");
	OutputBoard(gameBoard, size);
	cout << "Let arrange two three-deckers ship " << endl;
	for (int i = 0; i < 2; i++)
	{
		do
		{
			cout << "Enter g - gorizontal ship, v - vertical ship ";
			cin >> shipDirection; cout << endl;
			if (shipDirection == 'g' || shipDirection == 'G')
			{
				do
				{
					chekShipNearby = true;
					cout << "Enter the starting coordinate of the ship(row) ";
					cin >> startPointRow; cout << endl;
					cout << "Enter the starting coordinate of the ship(column) ";
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
						cout << "The ship is out of the game board or srapes other ships " << endl;
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
					cout << "Enter the starting coordinate of the ship(row) ";
					cin >> startPointRow; cout << endl;
					cout << "Enter the starting coordinate of the ship(column) ";
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
						cout << "The ship is out of the game board or srapes other ships " << endl;
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
				cout << "Input error " << endl;
			}
		} while (true);
		system("cls");
		OutputBoard(gameBoard, size);
	}
	cout << "Let arrange three two-deckers ship " << endl;
	for (int i = 0; i < 3; i++)
	{
		do
		{
			cout << "Enter g - gorizontal ship, v - vertical ship ";
			cin >> shipDirection; cout << endl;
			if (shipDirection == 'g' || shipDirection == 'G')
			{
				do
				{
					chekShipNearby = true;
					cout << "Enter the starting coordinate of the ship(row) ";
					cin >> startPointRow; cout << endl;
					cout << "Enter the starting coordinate of the ship(column) ";
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
						cout << "The ship is out of the game board or srapes other ships " << endl;
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
					cout << "Enter the starting coordinate of the ship(row) ";
					cin >> startPointRow; cout << endl;
					cout << "Enter the starting coordinate of the ship(column) ";
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
						cout << "The ship is out of the game board or srapes other ships " << endl;
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
				cout << "Input error " << endl;
			}
		} while (true);
		system("cls");
		OutputBoard(gameBoard, size);
	}
	cout << "Let arrange four one-deckers ship " << endl;
	for (int i = 0; i < 4; i++)
	{
		do
		{
			chekShipNearby = true;
			cout << "Enter the starting coordinate of the ship(row) ";
			cin >> startPointRow; cout << endl;
			cout << "Enter the starting coordinate of the ship(column) ";
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
				cout << "The ship is out of the game board or srapes other ships " << endl;
			}
		} while (true);
		gameBoard[startPointRow][startPointCol] = 1;
		system("cls");
		OutputBoard(gameBoard, size);
	}
}

void OutputBoardPrototype(int** gameBoard, int** gameBoardTemp, int size, char shipDirection, int startPointRow, int startPointCol)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameBoardTemp[i][j] = gameBoard[i][j];
		}
	}

	if (shipDirection == 'g')
	{
		for (int l = 0; l < 4; l++)
		{
			gameBoardTemp[startPointRow][startPointCol + l] = 4;
		}
	}
	else if (shipDirection == 'v')
	{
		for (int l = 0; l < 4; l++)
		{
			gameBoardTemp[startPointRow + l][startPointCol] = 4;
		}
	}
	else
	{
		cout << "Что-то не так с направлением " << endl;
	}

	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
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
			if (gameBoardTemp[i][j] == 0)
			{
				cout << " " << "|";
			}
			else if (gameBoardTemp[i][j] == 5)
			{
				cout << "x" << "|";
			}
			else if (gameBoardTemp[i][j] == 6)
			{
				cout << "X" << "|";
			}
			else if (gameBoardTemp[i][j] == 10)
			{
				cout << "*" << "|";
			}
			else if (gameBoardTemp[i][j] == 1 || gameBoardTemp[i][j] == 2 || gameBoardTemp[i][j] == 3 || gameBoardTemp[i][j] == 4)
			{
				cout << "O" << "|";
			}
		}
		cout << endl;
	}
}

void InitBoardPrototype(int** gameBoard, int** gameBoardTemp, int size)
{
	char shipDirection;
	int startPointRow, startPointCol, pushButton;
	bool chekShipNearby = true;
	cout << "Let arrange four-deckers ship " << endl;
	
	startPointRow = 1;
	startPointCol = 1;
	shipDirection = 'g';
	do
	{	
		system("cls");
		OutputBoardPrototype(gameBoard, gameBoardTemp, size, shipDirection, startPointRow, startPointCol);
		pushButton = _getch();
		if (pushButton == 224) //push
		{
			pushButton = _getch();
		}
	
		if (pushButton == 72) //up
		{
			if (startPointRow > 1)
			{
				startPointRow--;
			}
		}
		else if (pushButton == 80) //down
		{
			if (startPointRow < 10)
			{
				if ((shipDirection == 'g') || (shipDirection == 'v' && startPointRow < 7))
				{
					startPointRow++;
				}
			}
		}
		else if (pushButton == 75) //left
		{
			if (startPointCol > 1)
			{
				startPointCol--;
			}
		}
		else if (pushButton == 77) //right
		{
			if (startPointCol < 10)
			{
				if ((shipDirection == 'v') || (shipDirection == 'g' && startPointCol < 7))
				{
					startPointCol++;
				}		
			}
		}
		else if (pushButton == 32) //space
		{
			if (shipDirection == 'g')
			{
				shipDirection = 'v';
				if (startPointRow > 7)
				{
					startPointRow = 7;
				}
			}
			else if (shipDirection == 'v')
			{
				shipDirection = 'g';
				if (startPointCol > 7)
				{
					startPointCol = 7;
				}
			}
		}
		else if (pushButton == 13) //enter
		{
			break;
		}
	} while (true);
}
