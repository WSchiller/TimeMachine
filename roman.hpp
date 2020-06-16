/*HPP**********************************************************
** FILENAME: roman.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains function prototypes for roman.cpp
***************************************************************/

#ifndef ROMAN_HPP	
#define ROMAN_HPP
#include "space.hpp"

class Roman : public Space
{
public:
	Roman();
	void displayEraInfo();
	void displayQuestion();
	bool checkAnswer(string answer);
	~Roman();
};

#endif