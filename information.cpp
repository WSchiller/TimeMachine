/*CPP****************************************************************************************************
** FILENAME: information.cpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: This file is for the Information Age era.  It includes a brief introduction to the era,
				displays a random trivia question to the user, then grades the user's answer against
				the answer key.
*********************************************************************************************************/

#include "information.hpp"

/* -----------------------------------------------------Information--------
| Function: Information
| Purpose: constructor sets the string name, description, and relic
| Parameters: none
| Returns: none
*-------------------------------------------------------------------------*/

Information::Information()
{
	name = "Age of Information";
	description = "period in human history characterized by the shift from traditional industry that the\n" +
	description += "Industrial Revolution brought through industrialization, to an economy based on information computerization.";
	relic = "artifical intelligence microchip";
	obtainedRelic = false;
}

/* ----------------------------------------------------displayEraInfo------
| Function: displayEraInfo
| Purpose: prints the era info - name and description
| Parameters: none
| Returns: none
*-------------------------------------------------------------------------*/
void Information::displayEraInfo()
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
*-----------------------------------------------------------------------*/
void Information::displayQuestion()
{
	int questionNumber = rand() % 4 + 1;
	setQuestionNumber(questionNumber);

	switch (questionNumber)
	{
		case 1:
			cout << "Which of the following are used in gene cloning?" << endl << endl
				<< "a) lomasomes" << endl
				<< "b) mesosomes" << endl
				<< "c) nucleoids" << endl
				<< "d) plasmids" << endl << endl;
			break;
		case 2:
			cout << "Who designed the 'first' small computer for home use?" << endl << endl
				<< "a) John Blankenbaker" << endl
				<< "b) Steve Wozniak" << endl
				<< "c) Chuck Peddle" << endl
				<< "d) Steve Leininger" << endl << endl;
			break;
		case 3:
			cout << "When did the World Wide Web become publicly available" << endl << endl
				<< "a) 1986" << endl
				<< "b) 1989" << endl
				<< "c) 1991" << endl
				<< "d) 1994" << endl << endl;
			break;
		case 4:
			cout << "What type of malware can self replicate and shut down a computer system in the process?" << endl << endl
				<< "a) worm" << endl
				<< "b) botnet" << endl
				<< "c) Trojan Horse" << endl
				<< "d) virus" << endl << endl;
			break;
		case 5:
			cout << "What is the binary equivalent of 29?" << endl << endl
				<< "a) 11001" << endl
				<< "b) 10111" << endl
				<< "c) 111000" << endl
				<< "d) 11101" << endl << endl;
			break;
	}
}

/* -------------------------------------------------------------------checkAnswer--------
| Function: checkAnswer
| Purpose: grades the answer pertaining to the trivia question
| Parameters:
|            string answer -- string of the user answer for the given question number
| Returns: a boolean true if answer is correct, and false if incorrect
*--------------------------------------------------------------------------------------*/
bool Information::checkAnswer(string answer)
{
	string answerKey[]{ "d", "a", "c", "a", "d" };

	if (answerKey[getQuestionNumber() - 1] == answer)
	{
		cout << "Correct answer! You have collected an artificial intelligence microchip!" << endl;
		cout << "Historical Facts: From SIRI to self - driving cars, artificial intelligence(AI) is progressing rapidly.\n"
			<< "While science fiction often portrays AI as robots with human - like characteristics,\n"
			<< "AI can encompass anything from Google search algorithms to IBM’s Watson to autonomous weapons.\n";

		return true;
	}
	else
	{
		cout << "Incorrect answer, try again" << endl;
		return false;
	}
}

/* ------------------------------------------------------------------~Information--------
| Function: ~Information
| Purpose : frees the dynamically allocated memory
| Parameters : none
| Returns : none
*---------------------------------------------------------------------------------------*/
Information::~Information()
{
	
}
