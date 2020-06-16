/*CPP****************************************************************************************************
** FILENAME: main.cpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: The Time Machine game is a 1 player text-based game where the user is dealt the task of
				collecting relics by traveling back in time to six different eras of history.  The user
				has a 12 hour time limit to accomplish the task.  For each era the player will be asked
				trivia question(s) pertaining to that time period.  The player must answer correctly to
				obtain the relic. Each asked question incurrs a 1 hour time run-off.  Once the player
				answers successfully, they can travel to another time period to collect one of the
				remaining relics.  Collect all 6 relics before time expires and win!
*********************************************************************************************************/

#include "menu.hpp"
#include "game.hpp"
#include <iostream>
#include <iomanip>
int main()
{
	srand((unsigned)time(NULL));
	Menu menu;
	Game game;
	menu.displayIntro();

	int selection;
	do
	{
		selection = menu.getMenuInput();

		if (selection == 1) // Start game
		{
			int timePeriod;
			timePeriod = menu.getTimePeriod();
			game.setStartingSpace(timePeriod);
			game.startGame();
		}
		else if (selection == 2) // Game Rules
		{
			menu.displayRules();
		}
		else if (selection == 3) // References used for creating trivia questions
		{
			menu.displayReferences();
		}
	} while (selection != 4);

	return 0;
}