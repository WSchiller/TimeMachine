/*CPP****************************************************************************************************
** FILENAME: jurassic.cpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: This file is for the Age of Dinosaur era.  It includes a brief introduction to the era,
				displays a random trivia question to the user, then grades the user's answer against
				the answer key.
*********************************************************************************************************/

#include "jurassic.hpp"

/* ----------------------------------------------------------Jurassic--------
| Function: Jurassic
| Purpose: constructor sets the string name, description, and relic
| Parameters: none
| Returns: none
*--------------------------------------------------------------------------*/
Jurassic::Jurassic()
{
	name = "Age of the Dinosaur";
	description = "Geologic Period about 65 million years ago when a diverse group of reptiles called\n" +
	description += "dinosaurs roamed the earth.\n";
	relic = "velociraptor claw";
	obtainedRelic = false;
}

/* ----------------------------------------------------displayEraInfo------
| Function: displayEraInfo
| Purpose: prints the era info - name and description
| Parameters: none
| Returns: none
*------------------------------------------------------------------------*/
void Jurassic::displayEraInfo()
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
*-------------------------------------------------------------------------*/
void Jurassic::displayQuestion()
{
	int questionNumber = rand() % 4 + 1;
	setQuestionNumber(questionNumber);

	switch (questionNumber)
	{
		case 1:
			cout << "Which animal's ancestors did not live during the time of dinosaurs?" << endl << endl;
			cout << "a) Jellyfish" << endl
				<< "b) Crocodile" << endl
				<< "c) Bear" << endl
				<< "d) Shark" << endl << endl;
			break;
		case 2:
			cout << "Which of these dinosaurs was a meat eater?" << endl << endl;
			cout << "a) Spinosaurus" << endl
				<< "b) Apatosaurus" << endl
				<< "c) Triceratops" << endl
				<< "d) Stegosaurus" << endl << endl;
			break;
		case 3:
			cout << "The meteor that many scientists believe killed the dinosaurs struck in what modern-day country?" << endl << endl
				<< "a) Mexico" << endl
				<< "b) United States" << endl
				<< "c) South Africa" << endl
				<< "d) Russia" << endl;
			break;
		case 4:
			cout << "The most intact Tyrannosaurus Rex skeleton, 'Sue', discovered in 1990 was found in which U.S. state?" << endl << endl
				<< "a) Arizona" << endl
				<< "b) New Mexico" << endl
				<< "c) Montana" << endl
				<< "d) South Dakota" << endl << endl;
			break;
		case 5:
			cout << "What time period did the Tyrannosaurus live in?"
				<< "a) Jurassic" << endl
				<< "b) Triassic" << endl
				<< "c) Cretaceous" << endl
				<< "d) None of the above" << endl << endl;
			break;
	}
}

/* -------------------------------------------------------------------checkAnswer--------
| Function: checkAnswer
| Purpose: grades the answer pertaining to the trivia question
| Parameters:
|            string answer -- string of the user answer for the given question number
| Returns: a boolean true if answer is correct, and false if incorrect
*----------------------------------------------------------------------------------------*/
bool Jurassic::checkAnswer(string answer)
{
	string answerKey[]{ "c", "a", "a", "d", "c" };

	if (answerKey[getQuestionNumber() - 1] == answer)
	{
		cout << "Correct answer! You have collected a velociraptor claw!" << endl;
		cout << "Historical Facts: The Velociraptor is one of the most bird-like dinosaurs ever discovered.\n"
			<< "It was small and fast, and the sickle-shaped claw on the second toe of each foot made it a formidable predator.\n";

		return true;
	}
	else
	{
		cout << "Incorrect answer, try again" << endl;

		return false;
	}
}

/* --------------------------------------------------------------------~Jurassic--------
| Function: ~Jurassic
| Purpose : frees the dynamically allocated memory
| Parameters : none
| Returns : none
*---------------------------------------------------------------------------------------*/
Jurassic::~Jurassic()
{

}






