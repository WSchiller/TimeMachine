/*CPP****************************************************************************************************
** FILENAME: revolution.cpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: This file is for the Age of Revolution era.  It includes a brief introduction to the era,
				displays a random trivia question to the user, then grades the user's answer against
				the answer key.
*********************************************************************************************************/

#include "revolution.hpp"

/* ----------------------------------------------------------Revolution----
| Function: Revolution
| Purpose: constructor sets the string name, description, and relic
| Parameters: none
| Returns: none
*-----------------------------------------------------------------------*/
Revolution::Revolution()
{
	name = "Age of Revolution";
	description = "period from approximately 1774 to 1849 in which a number of significant revolutionary movements\n" +
	description += "occurred in many parts of Europe and the Americas. The period is noted for the change in government\n" +
	description += "from absolutist monarchies to constitutionalist states and republics.\n";
	relic = "musket";
	obtainedRelic = false;
}

/* ----------------------------------------------------displayEraInfo------
| Function: displayEraInfo
| Purpose: prints the era info - name and description
| Parameters: none
| Returns: none
*------------------------------------------------------------------------*/
void Revolution::displayEraInfo()
{
	cout << "Time Period: " << name << endl
		<< "=======================================================================================================================" << endl
		<< "Era Description: " << description << endl;
}

/* ---------------------------------------------------displayQuestion-----
| Function: displayQuestion
| Purpose: prints a randomly selected trivia question
| Parameters: none
| Returns: none
*----------------------------------------------------------------------*/
void Revolution::displayQuestion()
{
	int questionNumber = rand() % 4 + 1;
	setQuestionNumber(questionNumber);

	switch (questionNumber)
	{
		case 1:
			cout << "How many of the American colonies were part of the revolution?" << endl << endl
				<< "a) 11" << endl
				<< "b) 13" << endl
				<< "c) 15" << endl
				<< "d) 17" << endl << endl;
			break;
		case 2:
			cout << "What year did the United States issue the Declaration of Independence" << endl << endl
				<< "a) 1773" << endl
				<< "b) 1776" << endl
				<< "c) 1779" << endl
				<< "d) 1781" << endl << endl;
			break;
		case 3:
			cout << "The First Continental Congress met in what city?" << endl << endl
				<< "a) Philadelphia" << endl
				<< "b) Boston" << endl
				<< "c) New York" << endl
				<< "d) Washinton DC" << endl << endl;
			break;
		case 4:
			cout << "Who was the first person to sign the Declaration of Indepedence?" << endl << endl
				<< "a) Thomas Jefferson" << endl
				<< "b) George Washington" << endl
				<< "c) John Hancock" << endl
				<< "d) Samuel Adams" << endl << endl;
			break;
		case 5:
			cout << "Which battle was the first major American vitory of the revolutionary war?" << endl << endl
				<< "a) Brandywine Crek, Pennsylvania" << endl
				<< "b) Princeton, New Jersey" << endl
				<< "c) Saratoga, New York" << endl
				<< "d) Monmouth, New Jersey" << endl << endl;
			break;
	}
}

/* -------------------------------------------------------------------checkAnswer--------
| Function: checkAnswer
| Purpose: grades the answer pertaining to the trivia question
| Parameters:
|            string answer -- string of the user answer for the given question number
| Returns: a boolean true if answer is correct, and false if incorrect
*-------------------------------------------------------------------------------------*/
bool Revolution::checkAnswer(string answer)
{
	string answerKey[]{ "b", "b", "a", "c", "c" };

	if (answerKey[getQuestionNumber() - 1] == answer)
	{
		cout << "Correct answer! You have collected a musket from the American Revolution!" << endl;
		cout << "Historical Facts: The war of independence waged by the American colonies against Britain influenced political ideas\n"
			<< "and revolutions around the globe, as a fledgling, largely disconnected nation won its freedom from\n"
			<< "the greatest military force of its time.\n";

		return true;
	}
	else
	{
		cout << "Incorrect answer, try again" << endl;

		return false;
	}
}

/* -------------------------------------------------------------------~Revolution--------
| Function: ~Revolution
| Purpose : frees the dynamically allocated memory
| Parameters : none
| Returns : none
*---------------------------------------------------------------------------------------*/
Revolution::~Revolution()
{
	
}