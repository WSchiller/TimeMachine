/*CPP****************************************************************************************************
** FILENAME: egypt.cpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: This file is for the Ancient Egypt era.  It includes a brief introduction to the era,
				displays a random trivia question to the user, then grades the user's answer against
				the answer key.
*********************************************************************************************************/

#include "egypt.hpp"

/* ----------------------------------------------------------Egypt--------
| Function: Egypt
| Purpose: constructor sets the string name, description, and relic
| Parameters: none
| Returns: none
*-----------------------------------------------------------------------*/
Egypt::Egypt()
{
	name = "Ancient Egypt";
	description = "Ancient Egypt was a civilization of ancient Northeastern Africa, concentrated along\n" +
		description += "the lower reaches of the Nile River in the place that is now the country Egypt. It is one of six\n" +
		description += "historic civilizations to arise independently.  It took roughly 20 years to build the Great Pyramid of Giza.\n" +
		description += "It is the oldest and largest of the 3 pyramids.\n";
	relic = "mummy mask";
	obtainedRelic = false;
}

/* ----------------------------------------------------displayEraInfo------
| Function: displayEraInfo
| Purpose: prints the era info - name and description
| Parameters: none
| Returns: none
*------------------------------------------------------------------------*/
void Egypt::displayEraInfo()
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
void Egypt::displayQuestion()
{
	questionNumber = rand() % 4 + 1;
	setQuestionNumber(questionNumber);

	switch (questionNumber)
	{
		case 1:
			cout << "Egyptians believed the god Anubis weighed what body part after death to decide\n" << "whether the deceased would be allowed into the afterlife?" << endl << endl;
			cout << "a) Eyes" << endl
				<< "b) Heart" << endl
				<< "c) Liver" << endl
				<< "d) Brain" << endl << endl;
			break;
		case 2:
			cout << "What did ancient Egyptians call their land?" << endl << endl;
			cout << "a) Along the River" << endl
				<< "b) Kingdom of Ra" << endl
				<< "c) The Black Land" << endl
				<< "d) Blessed by Waters" << endl << endl;
			break;
		case 3:
			cout << "How did ancient Egyptians remove the brain from a body before mummifying it?" << endl << endl
				<< "a) They cut off the head, removed the brain, and reattached the head" << endl
				<< "b) They sucked the brain out through a hole above the ear" << endl
				<< "c) They picked the brain out through the nose" << endl
				<< "d) We don't know" << endl << endl;
			break;
		case 4:
			cout << "Which Pharaoh built more statues and monuments than any other Pharaoh?" << endl << endl
				<< "a) Ramses II" << endl
				<< "b) Hathesput" << endl
				<< "c) Cleopatra VII" << endl
				<< "d) King Tut" << endl << endl;
			break;
		case 5:
			cout << "The ancient Egyptians worshipped many gods. Who was the god of darkness, chaos, and confusion?"
				<< "a) Osiris" << endl
				<< "b) Seth" << endl
				<< "c) Anubis" << endl
				<< "d) Nephythys" << endl << endl;
			break;
	}
}

/* -------------------------------------------------------------------checkAnswer--------
| Function: checkAnswer
| Purpose: grades the answer pertaining to the trivia question
| Parameters:
|            string answer -- string of the user answer for the given question number
| Returns: a boolean true if answer is correct, and false if incorrect
*---------------------------------------------------------------------------------------*/
bool Egypt::checkAnswer(string answer)
{
	string answerKey[]{ "b", "c", "c", "a", "b" };

	if (answerKey[getQuestionNumber() - 1] == answer)
	{
		cout << "Correct answer! You have collected a mummy mask!" << endl;
		cout << "Historical Facts: Ancient Egypt had a successful society that lasted over 3,000 years.\n"
			<< "The priests of ancient Egypt developed ways to preserve or mummify a body so that it would last.\n"
			<< "The ancient Egyptians believed that when someone died, their soul left their body. The soul would then\n"
			<< "return and be reunited with the body after it was buried. However, the soul needed to be able to find and\n"
			<< "recognize the body in order to live forever.\n";

		return true;
	}
	else
	{
		cout << "Incorrect answer, try again" << endl;

		return false;
	}
}

/* -------------------------------------------------------------------~Egypt--------
| Function: ~Egypt
| Purpose : frees the dynamically allocated memory
| Parameters : none
| Returns : none
*---------------------------------------------------------------------------------------*/
Egypt::~Egypt()
{

}


