/*CPP**************************************************************************************************************
** FILENAME: space.cpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: This file is for the abstract Space class.  It contains 4 space pointers (top, right, left, bottom)
that are used to create a linked structure of spaces.  In simpler words, a map of spaces.  This map
is used to determine the adjacent spaces in relation to the current space the player is occupying
during the game.  A space represents an era of time in history.  This game implements 6 eras that
derive from the Space class.  There are virtual functions that allow the derived classes to create
their own trivia questions, answer key, unique description info and relic.
*******************************************************************************************************************/

#include "space.hpp"

/* ----------------------------------------------------------setTop--------
| Function: setTop
| Purpose: used to create a linked structure.  Receives a space pointer of
|          an era that is set to the top space.
| Parameters:
|            *space -- space pointer of an era
| Returns: none
*-----------------------------------------------------------------------*/
void Space::setTop(Space *space)
{
	top = space;
}

/* ----------------------------------------------------------setRight--------
| Function: setRight
| Purpose: used to create a linked structure.  Receives a space pointer of
|          an era that is set to the right space.
| Parameters:
|            *space -- space pointer of an era
| Returns: none
*-------------------------------------------------------------------------*/
void Space::setRight(Space *space)
{
	right = space;
}

/* ----------------------------------------------------------setLeft--------
| Function: setLeft
| Purpose: used to create a linked structure.  Receives a space pointer of
|          an era that is set to the left space.
| Parameters:
|            *space -- space pointer of an era
| Returns: none
*-----------------------------------------------------------------------*/
void Space::setLeft(Space *space)
{
	left = space;
}

/* ----------------------------------------------------------setBottom-----
| Function: setBottom
| Purpose: used to create a linked structure.  Receives a space pointer of
|          an era that is set to the bottom space.
| Parameters:
|            *space -- space pointer of an era
| Returns: none
*-----------------------------------------------------------------------*/
void Space::setBottom(Space *space)
{
	bottom = space;
}

/* ----------------------------------------------------getAdjacentEras---------------
| Function: getAdjacentEras
| Purpose: gets the adjacent eras of the current space/era.  The adjacentEras vector
|          contains the space pointers of the adjacent eras.  The contents of the
|          vector are returned.
| Parameters: none
| Returns: space pointers that the adjacentEra vector contains
*----------------------------------------------------------------------------------*/
vector<Space*>& Space::getAdjacentEras()
{
	return adjacentEras;
}

/* ----------------------------------------------------------setQuestionNumber-----------
| Function: setQuestionNumber
| Purpose: Sets the questionNumber variable to the integer number of the trivia question
|          question being asked.
| Parameters:
|            questionNumber -- an integer of the question number being asked
| Returns: none
*--------------------------------------------------------------------------------------*/
void Space::setQuestionNumber(int questionNumber)
{
	this->questionNumber = questionNumber;
}

/* ----------------------------------------------------------getQuestionNumber-----------
| Function: getQuestionNumber
| Purpose: gets the integer number of the question being asked. Used to compare the users
|          answer of the trivia question to the answer key.
| Parameters: none
| Returns: intger value of the question number being asked
*--------------------------------------------------------------------------------------*/
int Space::getQuestionNumber()
{
	return questionNumber;
}

/* ----------------------------------------------------------getRelic-----------
| Function: getRelic
| Purpose: When the user answers a question correctly, they collect the relic
|          for the era.  The relic can then be added to the vector container to
|          to store collected relics.
| Parameters: none
| Returns: a string of the relic name
*------------------------------------------------------------------------------*/
string Space::getRelic()
{
	return relic;
}

/* ----------------------------------------------------------getName-----------
| Function: getName
| Purpose: used for displaying the name of an era.
| Parameters: none
| Returns: a string of the era name
*------------------------------------------------------------------------------*/
string Space::getName()
{
	return name;
}

/* -----------------------------------------------------isRelicObtained-----------
| Function: isRelicObtained
| Purpose: determines if the relic of the current space has been obtained.
|          If the relic has not been obtained, they may puruse in collecting the
|          relic, otherwise the player moves to another space.
| Parameters: none
| Returns: a boolean true if the relic has been obtained and false if it hasn't.
*--------------------------------------------------------------------------------*/
bool Space::isRelicObtained()
{
	return obtainedRelic;
}

/* ---------------------------------------------------setRelicObtained-----------
| Function: setRelicObtained
| Purpose: When the relic is collected in the current space, the function sets
|          the object obtained to true so the player is unable to collect the same
|          relic again for the duration of the game.
| Parameters:
|            obtained -- boolean that is used to set the obtained relic to true,
|                        if relic has been collected.
| Returns: none
*------------------------------------------------------------------------------*/
void Space::setRelicObtained(bool obtained)
{
	this->obtainedRelic = obtained;
}

/* -------------------------------------------------------------------~Space------------
| Function: ~Space
| Purpose : frees the dynamically allocated memory
| Parameters : none
| Returns : none
*---------------------------------------------------------------------------------------*/
Space::~Space() 
{

}