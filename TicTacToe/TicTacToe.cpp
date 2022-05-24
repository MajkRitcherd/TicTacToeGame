#include "TicTacToe.h"

std::vector<char> createData()
{
	std::vector<char> data;
	data = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	return data;
}

void drawBoard(const std::vector<char>& data)
{
	std::cout << "-------------------" << std::endl;
	std::cout << "|     |     |     |" << std::endl;
	std::cout << "|  " << data[0] << "  |  " << data[1] << "  |  " << data[2] << "  |" << std::endl;
	std::cout << "|     |     |     |" << std::endl;
	std::cout << "|-----|-----|-----|" << std::endl;
	std::cout << "|     |     |     |" << std::endl;
	std::cout << "|  " << data[3] << "  |  " << data[4] << "  |  " << data[5] << "  |" << std::endl;
	std::cout << "|     |     |     |" << std::endl;
	std::cout << "|-----|-----|-----|" << std::endl;
	std::cout << "|     |     |     |" << std::endl;
	std::cout << "|  " << data[6] << "  |  " << data[7] << "  |  " << data[8] << "  |" << std::endl;
	std::cout << "|     |     |     |" << std::endl;
	std::cout << "|-----|-----|-----|" << std::endl;

}

bool rules(const std::vector<char>& data)
{
	return rowRules(data) || columnRules(data) || diagonalRules(data);
}

bool rowRules(const std::vector<char>& data)
{
	int pos = 0;
	for (int i = 0; i < 3; i++)
	{
		if (data[pos] == data[pos + 1] && data[pos] == data[pos + 2])
			return true;
		pos += 3;
	}
	return false;
}

bool columnRules(const std::vector<char>& data)
{
	int pos = 0;
	for (int i = 0; i < 3; i++)
	{
		if (data[pos] == data[pos + 3] && data[pos] == data[pos + 6])
			return true;
		pos++;
	}
	return false;
}

bool diagonalRules(const std::vector<char>& data)
{
	if (data[0] == data[4] && data[4] == data[8])
		return true;
	if (data[2] == data[4] && data[4] == data[6])
		return true;
	return false;
}

void playTicTac()
{
	auto game = createData();

	const char* player1 = "[PLAYER 1]";
	const char* player2 = "[PLAYER 2]";
	int input;

	bool pl1 = true;
	bool win = false;

	while (!win)
	{
		system("CLS");
		std::cout << "----- Tic Tac Toe Game -----" << std::endl << std::endl;
		drawBoard(game);
		std::cout << "Enter position ";

		if (pl1)
			std::cout << player1 << ": ";

		else
			std::cout << player2 << ": ";

		while (true)
		{
			std::cin >> input;
			if (input >= 1 && input <= 9)
			{
				if (isInGrid(input, game))
				{
					std::cout << "This position is already set! Enter another position: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
					break;
			}
			else
			{
				std::cout << "Wrong input. Enter a number between 1 - 9: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		if (pl1)
		{
			game[input - 1] = 'X';
		}
		else
		{
			game[input - 1] = 'O';
		}

		if (rules(game))
		{
			system("CLS");
			if (pl1)
				std::cout << "The winner is: " << player1 << std::endl;
			else
				std::cout << "The winner is: " << player2 << std::endl;
			break;
		}

		pl1 = !pl1;
	}
}

bool isInGrid(int input, const std::vector<char>& data)
{
	if (data[input - 1] == 'X' || data[input - 1] == 'O')
		return true;
	return false;
}