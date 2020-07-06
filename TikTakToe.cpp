#include <iostream>

class Game
{
	bool Player;//true - 1Player , False - 2Player
	int Matrix[3][3];//Stolbec stroka, -1 (Empty) , 0(Nolik) , 1(Krestik)
	void Turn()
	{
		int x;
		int y;
		if (Player)
		{
			std::cout << "Player 1 turn" << std::endl;
			std::cin >> x >> y;
			if (x > -1 && x <= 2 && y > -1 && y <= 2 && Matrix[x][y] == -1)
			{
				std::cout << "Player 1 put a cross" << std::endl;
				Matrix[x][y] = 1;
				Player = false;
			}

		}
		else
		{
			std::cout << "Player 2 turn" << std::endl;
			std::cin >> x >> y;
			if (x > -1 && x <= 2 && y > -1 && y <= 2 && Matrix[x][y] == -1)
			{
				std::cout << "Player 2 put a Circle" << std::endl;
				Matrix[x][y] = 0;
				Player = true;
			}
		}
	}
public:
	Game()
	{
		Player = true;
		for ( int m = 0; m < 3; m++)
		{
			for ( int n = 0; n < 3; n++)
			{
				Matrix[m][n] = -1;
			}
		}
	}
private:
	bool Winner_Winner_Chiken_Dinner()
	{
		for ( int i = 0; i <= 1; i++)
		{
			for (int x = 0;x < 3; x++)
			{
				if (Matrix[0][x] == i && Matrix[1][x] == i && Matrix[2][x] == i)
				{
					if (i == 1)
					{
						std::cout << "Player 1 Wins" << std::endl;
					}
					else
					{
						std::cout << "Player 2 Wins" << std::endl;
					}

					return true;
				}
			}
			for (int  x = 0; x < 3; x++)
			{
				if (Matrix[x][0] == i && Matrix[x][1] == i && Matrix[x][2] == i)
				{
					if (i == 1)
					{
						std::cout << "Player 1 Wins" << std::endl;
					}
					else
					{
						std::cout << "Player 2 Wins" << std::endl;
					}
					return true;
				}
			}
			if (Matrix[0][0] == i && Matrix[1][1] == i && Matrix[2][2] == i)
			{
				if (i == 1)
				{
					std::cout << "Player 1 Wins" << std::endl;
				}
				else
				{
					std::cout << "Player 2 Wins" << std::endl;
				}
				return true;
			}
			if (Matrix[2][0] == i && Matrix[1][1] == i && Matrix[0][2] == i)
			{
				if (i == 1)
				{
					std::cout << "Player 1 Wins" << std::endl;
				}
				else
				{
					std::cout << "Player 2 Wins" << std::endl;
				}
				return true;
			}

		}
		return false;
		

	
	}
public:
	void Start_Game()
	{
		do
		{
			Turn();
		} while (Winner_Winner_Chiken_Dinner() == false);
	}
};

int main()
{
	Game game;
	game.Start_Game();
	std::cout << "Hello World" << std::endl;
}