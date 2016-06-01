#pragma once
#include <iostream>
#include <cmath>
#include "Game.h"

using namespace std;
namespace GameNS
{


	class BoardGame : public Game
	{
		const static int DIMENTION = 0;
		enum class BoardStates;
		BoardStates** board;
	protected:
		virtual int getFirst() = 0;
		virtual void nextStep(int);
		virtual bool isWin(int) = 0;
		virtual bool isLost(int) = 0;
		virtual bool isTie(int) = 0;
		virtual int getNextPlayer(int) = 0;

		virtual void getCordinate(int &, int &, bool = false) = 0;
		virtual void setCoordinate(const int x, const int y, const BoardStates);
		virtual bool isValidStep(int, int, int, int, int) = 0;
		virtual void setCoordinates(int, int, int, int, int) = 0;
		virtual void getCoordinates(int&, int&, int&, int&, int) = 0;
		virtual ~BoardGame();
	public:

		virtual void play();
	};
}