/*HPP********************************************************************
** FILENAME: information.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains member function prototypes for information.cpp
*************************************************************************/

#ifndef INFORMATION_HPP
#define INFORMATION_HPP
#include "space.hpp"

class Information : public Space
{
public:
	Information();
	void displayEraInfo();
	void displayQuestion();
	bool checkAnswer(string answer);
	~Information();
};

#endif