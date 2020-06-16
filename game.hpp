/*HPP*************************************************************************
** FILENAME: game.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains member function prototypes and variables for game.cpp
******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "jurassic.hpp"
#include "egypt.hpp"
#include "roman.hpp"
#include "medieval.hpp"
#include "revolution.hpp"
#include "information.hpp"
#include <vector>
#include <iomanip>

class Game
{
private:
	Space *dinosaur, *egypt, *roman, *medieval, *revolution, *information;
	Space *currentSpace;
	int time, relicsObtained;

public:
	Game();
	void setStartingSpace(int timePeriod);
	void startGame();
	void setTime();
	void setRelicsObtained();
	void resetRelics();
	void displayMap();
	~Game();
};

#endif