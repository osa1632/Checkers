#pragma once
#ifndef CHECKERS_H
#define CHECKERS_H

#include <iostream>
#include <cmath>

using namespace std;

#include "BoardGame.h"

namespace GameNS
{
	class Checkers : public BoardGame
	{
		const static int DIMENTION = 8;
		enum class BoardStates { FIRST = -1, SECOND = 1, EMPTY = 0 ,K_FIRST=-3,K_SECOND=3};
		BoardStates** board;
	protected:
		int getFirst();
		void nextStep(int);
		bool isWin(int);
		bool isLost(int);
		bool isTie(int);
		int getNextPlayer(int);

		void getCordinate(int &, int &, bool = false);
		void setCoordinate(const int x, const int y, const BoardStates);
		bool isValidStep(int, int, int, int, BoardStates);
		bool isValidStep(int, int, int, int, int) ;
		void setCoordinates(int, int, int, int, int) ;
		void getCoordinates(int&, int&, int&, int&, int) ;	
		void init();
		void play();
	public:
		Checkers() :BoardGame::BoardGame() { play(); }
		friend ostream& operator<<(ostream& , const Checkers& );
	};
}
#endif