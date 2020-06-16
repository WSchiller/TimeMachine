/*HPP*******************************************************************
** FILENAME: revolution.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains member function prototypes for revolution.cpp
************************************************************************/

#ifndef REVOLUTION_HPP	
#define REVOLUTION_HPP
#include "space.hpp"

class Revolution : public Space
{
public:
	Revolution();
	void displayEraInfo();
	void displayQuestion();
	bool checkAnswer(string answer);
	~Revolution();
};

#endif