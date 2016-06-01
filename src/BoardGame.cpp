#include "BoardGame.h"

using namespace std;

namespace GameNS
{

	void BoardGame::play()
	{
		int playerIndex = getFirst();
		bool isGameEnded = false;

		while (!isGameEnded)
		{
			nextStep(playerIndex);
			isGameEnded = isWin(playerIndex) || isLost(playerIndex) || isTie(playerIndex);
			playerIndex = getNextPlayer(playerIndex);
		}

		return;
	}
	BoardGame::~BoardGame()
	{
		for (int i = 0; i < DIMENTION; i++)
		{
			delete[]board[i];
		}
		delete[]board;
	}

	void BoardGame::nextStep(int playerIndex)
	{
		int xFrom, yFrom, xTo, yTo;

		do
		{
			getCoordinates(xFrom, yFrom, xTo, yTo, playerIndex);
		} while (!isValidStep(xFrom, yFrom, xTo, yTo, playerIndex));
		setCoordinates(xFrom, yFrom, xTo, yTo, playerIndex);
		return;
	}

	void BoardGame::setCoordinate(int x, int y, BoardStates boardState)
	{
		board[x][y] = boardState;
	}
}