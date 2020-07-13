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
