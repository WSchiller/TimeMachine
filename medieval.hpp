/*HPP****************************************************************
** FILENAME: medieval.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains member function prototypes for medieval.cpp
*********************************************************************/

#ifndef MEDIEVAL_HPP	
#define MEDIEVAL_HPP
#include "space.hpp"

class Medieval : public Space
{
public:
	Medieval();
	void displayEraInfo();
	void displayQuestion();
	bool checkAnswer(string answer);
	~Medieval();
};

#endif
