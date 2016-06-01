#include "Checkers.h"

namespace GameNS
{
	void Checkers::init()
	{
		for (int i = 0; i < DIMENTION; i++)
		{
			for (int j = 0; j < DIMENTION; j++)
			{
				if (i < 2)
				{
					board[i][j] = BoardStates::FIRST;
				}
				else if (i >= DIMENTION - 2)
				{
					board[i][j] = BoardStates::SECOND;
				}
				else
				{
					board[i][j] = BoardStates::EMPTY;
				}
			}
		}
	}
	
	void Checkers::play()
	{
		init();
		BoardGame::play();
	}

	int Checkers::getFirst()
	{
		return 0;
	}

	int Checkers::getNextPlayer(int playerIndex)
	{
		return 1 - playerIndex;
	}

	bool Checkers::isWin(int playerIndex)
	{
		BoardStates boardState = (playerIndex == 0) ? BoardStates::FIRST : BoardStates::SECOND;
		int i_isFirst = (int)(boardState == BoardStates::FIRST);

		
		for (int j = 0; j < DIMENTION;j++)
		{
			int i= i_isFirst*(DIMENTION - 1);
			if (board[i][j] == boardState)
			{
				board[i][j] = (BoardStates)((int)board[i][j]^2);
			}
		}
		
		return false;
	}

	bool Checkers::isLost(int playerIndex)
	{
		BoardStates boardState = (playerIndex == 0) ? BoardStates::FIRST : BoardStates::SECOND;
		for (int i = 0; i < Checkers::DIMENTION; i++)
		{
			for (int j = 0; j < Checkers::DIMENTION; j++)
			{
				if (board[i][j] != boardState && board[i][j] != BoardStates::EMPTY)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool Checkers::isTie(int playerIndex)
	{
		for (int i = 0; i < Checkers::DIMENTION; i++)
		{
			for (int j = 0; j < Checkers::DIMENTION; j++)
			{
				if (board[i][j] == BoardStates::EMPTY)
				{
					return false;
				}
			}
		}
		return true;
	}

	void Checkers::getCordinate(int &x, int &y, bool isSetStep)
	{
		bool isOk = false;

		while (!isOk)
		{
			cout << "Enter x,y coordinate" <<(isSetStep?" to set:":" to get:")<< endl;
			cin >> x >> y;
			x--;
			y--;
			isOk = (x>=0 && y>=0 && x<DIMENTION && y<DIMENTION && (isSetStep ^ (board[x][y] != BoardStates::EMPTY)));
		}
	}
	void Checkers::setCoordinate( int x,  int y, BoardStates boardState)
	{
		board[x][y] = boardState;
	}

	bool Checkers::isValidStep(int xFrom, int yFrom, int xTo, int yTo, BoardStates boardState)
	{
		bool canEatRight = (board[xFrom - (int)boardState][yFrom - 1] == (BoardStates)(-(int)boardState)); 
		bool canEatLeft = (board[xFrom - (int)boardState][yFrom + 1] == (BoardStates)(-(int)boardState)) ;

		if (canEatRight || canEatLeft)
		{
			
			int canEat = 2 * ((int)canEatRight) - 1;

			if ((xFrom - xTo == (int)boardState * 2) && ((yFrom - yTo) == 2 * canEat))
			{
				board[xFrom - (int)boardState][yFrom - canEat] = BoardStates::EMPTY;
				return true;
			}
		}

		return ((xFrom - xTo == (int)boardState) && (abs(yFrom-yTo)==1));
	}

	ostream& operator<<(ostream& os, const Checkers& game)
	{
		for (int i = 0; i < Checkers::DIMENTION + 1; i++)
		{
			if (i == 0) { cout << " |"; }
			else { cout << i << "|"; }
		}

		cout << "\n";

		for (int i = 0; i < Checkers::DIMENTION; i++)
		{
			cout << i + 1<<"|";
			for (int j = 0; j < Checkers::DIMENTION; j++)
			{
				string output="";
				switch ((Checkers::BoardStates)((int)game.board[i][j]%2))
				{
				case Checkers::BoardStates::EMPTY:
					output="_";
					break;
				case Checkers::BoardStates::FIRST:
					output= "x";
					break;
				case Checkers::BoardStates::SECOND:
					output= "y";
					break;
				default:
					output= "WRONG!";
				}
				if ((int)game.board[i][j] &0x2)
				{
					output[0] += 'A' - 'a';
				}
				os << output.c_str()<<"|";
			}
			os << "\n";
		}
		os << endl;
		return os;
	}


	bool Checkers::isValidStep(int xFrom, int yFrom, int xTo, int yTo, int playerIndex)
	{
		BoardStates boardState = (playerIndex == 0) ? BoardStates::FIRST : BoardStates::SECOND;

		return isValidStep(xFrom, yFrom, xTo, yTo, boardState);
	 }
	void Checkers::setCoordinates(int xFrom, int yFrom, int xTo, int yTo, int playerIndex)
	{
		BoardStates boardState = (playerIndex == 0) ? BoardStates::FIRST : BoardStates::SECOND;
		setCoordinate(xFrom, yFrom, BoardStates::EMPTY);

		setCoordinate(xTo, yTo, boardState);
	 }

	void Checkers::getCoordinates(int&  xFrom, int &yFrom, int& xTo, int &yTo, int playerIndex)
	{
		getCordinate(xFrom, yFrom, false);
		getCordinate(xTo, yTo, true);
	 }

	void Checkers::nextStep(int playerIndex)
	{
		BoardGame::nextStep(playerIndex);
		cout << (*this);
	}
}

