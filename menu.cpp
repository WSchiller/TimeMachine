/*CPP****************************************************************************************************
Description: menu.cpp displays game description and rules.  It allows the user to interact
with the game flow by presenting options and getting player choices.  The user choice
is validated to be an acceptable answer selection.
*********************************************************************************************************/

#include "menu.hpp"

/* ----------------------------------------------------displayIntro------
| Function: displayIntro
| Purpose: Prints the game introduction and objective.
| Parameters: none
| Returns: none
*------------------------------------------------------------------------*/
void Menu::displayIntro()
{
	cout << "The Time Machine History Trivia Game!" << endl << endl;

	cout << "The year is 2500 and you've been hired by the Museum of Natural History to travel back in time using their\n"
		<< "newly invented time machine.  The museum has dealt you the task of collecting specific relics from prominent\n"
		<< "eras in history.  You must travel back in time to these eras and collect the relics required before time expires!\n"
		<< "If you fail, you will be lost in time forever!\n" << endl;
}

/* ----------------------------------------------------displayMenu------
| Function: displayMenu
| Purpose: Prints the menu options
| Parameters: none
| Returns: none
*------------------------------------------------------------------------*/
void Menu::displayMenu()
{
	cout << "1. Play Game" << endl;
	cout << "2. Game Rules" << endl;
	cout << "3. References Used" << endl;
	cout << "4. Exit Game" << endl;
}

/* ----------------------------------------------------getMenuInput------
| Function: getMenuInput
| Purpose: Gets the menu selection from the user and validates it.
|          User can play game, list game rules, or exit.
| Parameters: none
| Returns: integer selection choice from the three presented options.
*------------------------------------------------------------------------*/
int Menu::getMenuInput()
{
	int selection;
	displayMenu();
	inputValidation(selection, "menuRange");
	return selection;
}

/* ----------------------------------------------------displayRules------
| Function: displayRules
| Purpose: Prints the game rules and game objective.
| Parameters: none
| Returns: none
*------------------------------------------------------------------------*/
void Menu::displayRules()
{
	cout << "The objective of this text based game is to travel back in time to specific time periods and\n"
		<< "complete the task the museum has assigned you. Collect 6 specific relics; 1 relic from each era.\n"
		<< "Below is a list the museum has provided you.  You must travel to and collect the following:\n\n"
		<< "Relic Collection List\n"
		<< "-----------------------\n"
		<< "1) Age of the Dinosaurs (65 million years ago): Velociraptor claw" << endl
		<< "2) Ancient Egypt (2500 BC): Mummy mask" << endl
		<< "3) Roman Empire (100 AD): Gladius of Julius Caesar" << endl
		<< "4) Middle Ages (1200 AD): Knight's helmet" << endl
		<< "5) Age of Revolution (1780 AD): Musket" << endl
		<< "6) Age of Information (2050 AD): Artifical Intelligence microchip" << endl << endl
		<< "To obtain the relics you will be presented with answering trivia questions pertaining to the current time period.\n"
		<< "You must successfully answer the question to collect the relic before traveling to another era.\n"
		<< "Answer incorrectly, and you will be presented with another trivia question.\n"
		<< "Each asked trivia question will incur a 1 hour run-off in time.\n"
		<< "The time machine only has the capacity to operate for 12 hours. You must collect all 6 relics\n"
		<< "before time expires, or be lost in time forever!" << endl << endl;
}

/* ------------------------------------------------displayReferences------
| Function: displayReferences
| Purpose: Prints the references used to create game trivia questions.
| Parameters: none
| Returns: none
*------------------------------------------------------------------------*/
void Menu::displayReferences()
{
	cout << "References used to research era information and create trivia questions:\n\n"
		<< "1) Website Title : ProProfs - Knowledge Management Software\n"
		<< "URL: https://www.proprofs.com/quiz-school/" << endl << endl
		<< "2) Website Title : Wikipedia\n"
		<< "URL: https://www.wikipedia.org/" << endl << endl
		<< "3) Website Title : Science Kids - Fun Science & Technology for Kids!\n"
		<< "URL: http ://www.sciencekids.co.nz/quizzes.html" << endl << endl
		<< "4) Website Title : Encyclopedia Britannica\n"
		<< "URL: https://www.britannica.com/quiz/browse" << endl << endl
		<< "5) Website Title : Fun Trivia Quizzes - World's Largest Trivia and Quiz Site\n"
		<< "URL: https ://www.funtrivia.com" << endl << endl
		<< "6) Website Title : Ducksters Educational Site\n"
		<< "URL: http://www.ducksters.com/history/" << endl << endl
		<< "7) Website Title : History.com\n"
		<< "URL: http://quiz.history.com/" << endl << endl;
}

/* ----------------------------------------------------displayTimePeriods------
| Function: displayTimePeriods
| Purpose: Prints the six eras the user can travel to.
| Parameters: none
| Returns: none
*----------------------------------------------------------------------------*/
void Menu::displayTimePeriods()
{
	cout << "What space in time do you want to travel to?" << endl << endl
		<< "1) Jurassic" << endl
		<< "2) Ancient Egypt" << endl
		<< "3) Roman Empire" << endl
		<< "4) Middle Ages" << endl
		<< "5) Age of Revolution" << endl
		<< "6) Age of Information" << endl << endl;
}

/* ----------------------------------------------------getTimePeriods----------------
| Function: getTimePeriods
| Purpose: Gets the era the user wants to travel to begin the game and validates
|          the selection.
| Parameters: none
| Returns: integer selection from the six presented eras.
*----------------------------------------------------------------------------------*/
int Menu::getTimePeriod()
{
	int selection;
	displayTimePeriods();
	inputValidation(selection, "timePeriodRange");
	return selection;
}

/* ----------------------------------------------------displayAdjacentEras------
| Function: displayAdjacentEras
| Purpose: Prints the eras adjacent to the era(space) the player is currently
is occupying.
| Parameters: none
| Returns: none
*----------------------------------------------------------------------------*/
void Menu::displayAdjacentEras()
{
	for (unsigned int j = 0; j < adjacentEraVec.size(); j++)
	{
		cout << to_string(j + 1) << ") " << adjacentEraVec.at(j)->getName() << endl;
	}
}

/* ----------------------------------------------------getNextEra--------------
| Function: getNextEra
| Purpose: Gets the adjacent era the user wants to travel to from the current
|          era(space) vector and validates the selection.
| Parameters:
|            adjacentEraVec -- vector that contains the eras adjacent to the
|                              current space.
| Returns: integer selection from presented eras available to travel to.
*----------------------------------------------------------------------------*/
int Menu::getNextEra(Space *currentSpace)
{
	int selection;
	this->adjacentEraVec = currentSpace->getAdjacentEras();
	displayAdjacentEras();
	inputValidation(selection, "nextEraRange");
	return selection;
}

/* ----------------------------------------------------promptAnswer-----------
| Function: promptAnswer
| Purpose: Ask the user to enter their answer for the trivia question.
| Parameters: none
| Returns: none
*----------------------------------------------------------------------------*/
void Menu::promptAnswer()
{
	cout << "Enter your answer (a, b, c, or d): ";
}

/* ----------------------------------------------------getAnswer----------------
| Function: getAnswer
| Purpose: Gets the players answer for the trivia queston and validates that it
was a viable answer choice.
| Parameters: none
| Returns: a string of the user answer. All answers will either be (a,b,c,d).
*----------------------------------------------------------------------------------*/
string Menu::getAnswer()
{
	string answer;
	promptAnswer();
	answerInputValidation(answer);
	return answer;
}

/* ----------------------------------------------------inputValidation-----------------
| Function: inputValidation
| Purpose: Gets user input, and validates it to be within acceptable range
| Parameters:
|            &selection -- integer is passed by reference and initialized by user input;
|                          then validated to be viable selection choice
|            validateRange -- string that is used to find the appropriate validation
|                             check for the selection
| Returns: none
*-------------------------------------------------------------------------------------*/
void Menu::inputValidation(int &selection, string validateRange)
{
	string line;
	while (getline(cin, line))
	{
		stringstream ss(line);

		//check if stream converts to an integer
		if (!(ss >> selection))
		{
			if (validateRange == "menuRange")
			{
				cout << "Invalid data type, please enter an integer value: " << endl;
				displayMenu();
			}
			else if (validateRange == "timePeriodRange")
			{
				cout << "Invalid data type, please enter an integer value: " << endl;
				displayTimePeriods();
			}
			else if (validateRange == "nextEraRange")
			{
				cout << "Invalid data type, please enter an integer value: " << endl;
				displayAdjacentEras();
			}
		}
		else
		{
			if (validateRange == "menuRange" && (selection < 1 || selection > 4))
			{
				cout << "Invalid selection, please select a menu option below" << endl;
				displayMenu();
			}
			else if (validateRange == "timePeriodRange" && (selection < 1 || selection > 6))
			{
				cout << "Invalid selection, please select a menu option below" << endl;
				displayTimePeriods();
			}
			else if (validateRange == "nextEraRange" && (selection < 1 || selection > this->adjacentEraVec.size()))
			{
				cout << "Invalid selection, please select a menu option below" << endl;
				displayAdjacentEras();
			}
			else
			{
				break;
			}
		}
	}
}

/* -----------------------------------------------------------------answerInputValidation-----------------
| Function: answerInputValidation
| Purpose: Gets user input answer for trivia questions, and validates it to be within acceptable range
| Parameters:
|            &answer -- integer is passed by reference and initialized by user input;
|                       then validated to be viable selection choice
| Returns: none
*---------------------------------------------------------------------------------------------------------*/
void Menu::answerInputValidation(string &answer)
{
	string line;

	while (getline(cin, line))
	{
		stringstream ss(line);
		ss >> answer;

		if (answer != "a" && answer != "b" && answer != "c" && answer != "d")
		{
			cout << "That is not a valid answer!  Please enter a character from the choices below" << endl;
			promptAnswer();
		}
		else
		{
			break;
		}
	}
}
