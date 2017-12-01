#include <iostream>
#include <string>

using namespace std;

char grid[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
	int player(1);
	char symbol('X');
	int square;

	bool checkWin(char);
	bool checkHorizontalWin(char);
	bool checkVerticleWin(char);
	bool checkDiagonolWin(char);
	void displayGrid();
	void updateGrid(int, char);
	bool checkValidMove(int);

	//cout << "Tic Tac Toe\n";
	//cout << "Press P tp play, Q to quit\n";

	displayGrid();
	
	do
	{

		cout << "Player " << player << "'s turn!\n";


		cout << "Enter a square: ";
		cin >> square;

		while (!checkValidMove(square))
		{
			cout << "Invalid move! Choose another square: ";
			cin >> square;
		}
		updateGrid(square, symbol);
		system("CLS");
		displayGrid();

		if (!checkWin(symbol))
		{
			if (player == 1)
			{
				player = 2;
				symbol = 'O';
			}
			else
			{
				player = 1;
				symbol = 'X';
			}
		}

	} while (!checkWin(symbol));

	cout << "\nPlayer " << player << " won! \n";
	system("pause");
}


bool checkWin(char symbol)
{
	bool checkHorizontalWin(char);
	bool checkVerticalWin(char);
	bool checkDiagonolWin(char);
	if (checkHorizontalWin(symbol) || checkVerticalWin(symbol) || checkDiagonolWin(symbol))
	{
		return true;
	}
	else
		return false;
}
bool checkHorizontalWin(char symbol)
{
	if (grid[0] == symbol && grid[1] == symbol && grid[2] == symbol)
	{
		return true;
	}

	else
	{
		if (grid[3] == symbol && grid[4] == symbol && grid[5] == symbol)
		{
			return true;
		}
		else
		{
			if (grid[6] == symbol && grid[7] == symbol && grid[8] == symbol)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool checkVerticalWin(char symbol)
{
	if (grid[0] == symbol && grid[3] == symbol && grid[6] == symbol)
	{
		return true;
	}

	else
	{
		if (grid[1] == symbol && grid[4] == symbol && grid[7] == symbol)
		{
			return true;
		}
		else
		{
			if (grid[2] == symbol && grid[5] == symbol && grid[8] == symbol)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool checkDiagonolWin(char symbol)
{
	if (grid[0] == symbol && grid[4] == symbol && grid[8] == symbol)
	{
		return true;
	}

	else
	{
		if (grid[2] == symbol && grid[4] == symbol && grid[6] == symbol)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void displayGrid()
{
	cout << "\n\n\n\n";
	cout << "\t\t\t\t" << grid[0] << "     |     " << grid[1] << "     |     " << grid[2] << "\n";
	cout << "\t\t\t_____________________________________________\n";
	cout << "\t\t\t\t" << grid[3] << "     |     " << grid[4] << "     |     " << grid[5] << "\n";
	cout << "\t\t\t_____________________________________________\n";
	cout << "\t\t\t\t" << grid[6] << "     |     " << grid[7] << "     |     " << grid[8] << "\n";
}

void updateGrid(int square, char symbol)
{
	grid[square - 1] = symbol;
}

bool checkValidMove(int square)
{
	if ((grid[square - 1] == 'X') || (grid[square - 1] == 'O'))
	{
		return false;
	}
	else
		return true;
}