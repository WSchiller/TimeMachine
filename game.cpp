/*CPP****************************************************************************************************
** FILENAME: game.cpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: This file is for game play.  It initializes the default settings for the game and play
begins with a 12 hour time limit.  The player decides what time era they want to first
travel to.  They are presented with a brief description of the era and asked a trivia
question. If the player answers the trivia question successfully they collect a
relic representing the era.  If the player answers unsuccessfully, they will be provided
with another question. Each trivia question asked incurrs a 1 hour time run off. The
player is unable to travel to another time period until answering a question correctly.
To win the game, the player must travel to each of the 6 eras and collect all 6 relics
before time runs out!
*********************************************************************************************************/

#include "game.hpp"
#include "menu.hpp"

/*-------------------------------------------------------------------------------------Game--------
| Function: Game
| Purpose: A constructor. The new operator allocates and initializes the memory then
|          returns the address to the Space pointer variables that represent each of
|          the six eras.  The constructor then sets the top, right, left,
|          and bottom pointers to the adjacent spaces of the  eras, essentially
|          creating a map of spaces.  In this case a  3x2 grid of spaces.  The adjacent
|          eras of each space are next added to vectors that will be used later to present
|          available eras the player can travel to based on the current pace/era the player is in.
| Parameters: none
| Returns: none
*-------------------------------------------------------------------------------------------------*/
Game::Game()
{
	dinosaur = new Jurassic();
	egypt = new Egypt();
	roman = new Roman();
	medieval = new Medieval();
	revolution = new Revolution();
	information = new Information();

	medieval->setTop(dinosaur);
	medieval->setRight(revolution);
	medieval->setLeft(NULL);
	medieval->setBottom(NULL);
	medieval->getAdjacentEras().push_back(dinosaur);
	medieval->getAdjacentEras().push_back(revolution);

	dinosaur->setTop(NULL);
	dinosaur->setRight(egypt);
	dinosaur->setLeft(NULL);
	dinosaur->setBottom(medieval);
	dinosaur->getAdjacentEras().push_back(egypt);
	dinosaur->getAdjacentEras().push_back(medieval);

	revolution->setTop(egypt);
	revolution->setRight(information);
	revolution->setLeft(medieval);
	revolution->setBottom(NULL);
	revolution->getAdjacentEras().push_back(egypt);
	revolution->getAdjacentEras().push_back(information);
	revolution->getAdjacentEras().push_back(medieval);

	egypt->setTop(NULL);
	egypt->setRight(roman);
	egypt->setLeft(dinosaur);
	egypt->setBottom(revolution);
	egypt->getAdjacentEras().push_back(roman);
	egypt->getAdjacentEras().push_back(dinosaur);
	egypt->getAdjacentEras().push_back(revolution);

	information->setTop(roman);
	information->setRight(NULL);
	information->setLeft(revolution);
	information->setBottom(NULL);
	information->getAdjacentEras().push_back(roman);
	information->getAdjacentEras().push_back(revolution);

	roman->setTop(NULL);
	roman->setRight(NULL);
	roman->setLeft(egypt);
	roman->setBottom(information);
	roman->getAdjacentEras().push_back(egypt);
	roman->getAdjacentEras().push_back(information);

	setTime();
	setRelicsObtained();
}

/*--------------------------------------------------------------------timePeriod-------------
| Function: timePeriod
| Purpose: sets the era for the current space the player is in
| Parameters:
|            int timePeriod -- once the player selects the era they want to start the
|                              game in, the integer value timePeriod from the menu selection
|                               is passed to thePeriod function and sets the era for the
|                               current space.
| Returns: none
*-------------------------------------------------------------------------------------------*/
void Game::setStartingSpace(int timePeriod)
{
	if (timePeriod == 1)
	{
		currentSpace = dinosaur;
	}
	else if (timePeriod == 2)
	{
		currentSpace = egypt;
	}
	else if (timePeriod == 3)
	{
		currentSpace = roman;
	}
	else if (timePeriod == 4)
	{
		currentSpace = medieval;
	}
	else if (timePeriod == 5)
	{
		currentSpace = revolution;
	}
	else
	{
		currentSpace = information;
	}
}

/*--------------------------------------------------------------------displayMap---------------
| Function: displayMap
| Purpose: displays a 3x2 map of the 6 space eras.  The current space era the player is located
|          in is represented by an (*).  The space eras adjacent to the current location our
|          possible choices for next space to travel to.
| Parameters: none
| Returns: none
*----------------------------------------------------------------------------------------------*/
void Game::displayMap()
{
	cout << setw(33) << "Game Map" << endl << "|=============================================================|" << endl;

	string name = currentSpace->getName();

	if (name == "Middle Ages" || name == "Age of Revolution" || name == "Age of Information")
	{
		cout << "|     Jurassic     |       Egypt        |       Roman         |" << endl;
		cout << "|=============================================================|" << endl;

		if (name == "Middle Ages")
		{
			cout << "|     Medieval (*) |     Revolution     |     Information     |" << endl;
		}
		else if (name == "Age of Revolution")
		{
			cout << "|     Medieval     |     Revolution (*) |     Information     |" << endl;
		}
		else
		{
			cout << "|     Medieval     |     Revolution     |     Information (*) |" << endl;
		}
	}
	else
	{
		if (name == "Age of the Dinosaur")
		{
			cout << "|     Jurassic (*) |       Egypt        |       Roman         |" << endl;
		}
		else if (name == "Ancient Egypt")
		{
			cout << "|     Jurassic     |       Egypt (*)    |       Roman         |" << endl;
		}
		else
		{
			cout << "|     Jurassic     |       Egypt        |       Roman (*)     |" << endl;
		}
		cout << "|=============================================================|" << endl;
		cout << "|     Medieval     |     Revolution     |     Information     |" << endl;
	}
	cout << "|=============================================================|" << endl << endl;
}

/*--------------------------------------------------------------------startGame--------------------
| Function: startGame
| Purpose: Commences gameplay and contains game flow.  Game ends when time runs out (player loses)
|          or they successfully collect all 6 relics; 1 from each era (player wins).
| Parameters: none
| Returns: none
*-------------------------------------------------------------------------------------------------*/
void Game::startGame()
{
	Menu menu;
	vector<string> relicCollection(6); // declare a vector container that is capable of holding 6 collected relic strings
	while (time > 0)
	{
		displayMap();
		currentSpace->displayEraInfo();
		
		bool correctAnswer = false;
		do
		{
			if (currentSpace->isRelicObtained())
			{
				cout << "Relic already obtained in " << currentSpace->getName() << endl;
				int selection = menu.getNextEra(currentSpace);
				currentSpace = currentSpace->getAdjacentEras().at(selection - 1);
			}
			else
			{
				currentSpace->displayQuestion();
				string answer;
				answer = menu.getAnswer();
				correctAnswer = currentSpace->checkAnswer(answer);
				time--;
				cout << endl << "You have " << time << " hours remaining!" << endl;
				if (time == 0)
				{
					cout << "Sorry you have lost as time has expired! You are in stuck in the " << currentSpace->getName() << " for the\n"
						<< "remainder of your life." << endl << endl;
					break;
				}
			}
		} while (correctAnswer == false);
		if (time == 0)
		{
			break;
		}
		relicCollection.at(relicsObtained) = currentSpace->getRelic();
		currentSpace->setRelicObtained(true);
		relicsObtained++;
		cout << "Relics collected: ";
		for (int i = 0; i < relicsObtained; i++)
		{
			cout << relicCollection[i] << ", ";
		}
		if (relicsObtained == 6)
		{
			cout << endl << "Congratulations you have won! You have successfully obtained all 6 relics and may return to the present year 2500" << endl << endl;
			break;
		}

		cout << endl << "Select an adjacent era below that has a relic yet to be obtained:" << endl << endl;

		int selection = menu.getNextEra(currentSpace);
		currentSpace = currentSpace->getAdjacentEras().at(selection - 1);
	}

	setTime();
	setRelicsObtained();
	resetRelics();
}

/*---------------------------------------------------------------------setTime----------------------
| Function: setTime
| Purpose: resets the time to the initial starting value of 12 after game completes, so another
|           game may be played if the user chooses to do so.
| Parameters: none
| Returns: none
*--------------------------------------------------------------------------------------------------*/
void Game::setTime()
{
	time = 12;
}

/*---------------------------------------------------------------------setRelicsObtained------------
| Function: setRelicsObtained
| Purpose: resets the relic to the initial starting value of 0 after game completes, so another
|           game may be played if the user chooses to do so.
| Parameters: none
| Returns: none
*--------------------------------------------------------------------------------------------------*/
void Game::setRelicsObtained()
{
	relicsObtained = 0;
}

/*---------------------------------------------------------------------------resetRelics-------------
| Function: resetRelics
| Purpose: resets the relics obtained for each era to false after game completes,
|          meaning the relic has not been obtained for that era.
| Parameters: none
| Returns: none
*----------------------------------------------------------------------------------------------------*/
void Game::resetRelics()
{
	dinosaur->setRelicObtained(false);
	egypt->setRelicObtained(false);
	roman->setRelicObtained(false);
	medieval->setRelicObtained(false);
	revolution->setRelicObtained(false);
	information->setRelicObtained(false);
}

/*--------------------------------------------------------------------------------~Game-------------
| Function: ~Game()
| Purpose: frees the dynamically allocated memory for each of the six Space pointer eras
| Parameters: none
| Returns: none
*----------------------------------------------------------------------------------------------------*/
Game::~Game()
{
	delete dinosaur;
	delete egypt;
	delete roman;
	delete medieval;
	delete revolution;
	delete information;
}


