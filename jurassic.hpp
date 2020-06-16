/*HPP****************************************************************
** FILENAME: jurassic.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains member function prototypes for jurassic.cpp
*********************************************************************/

#ifndef JURASSIC_HPP	
#define JURASSIC_HPP
#include "space.hpp"

class Jurassic : public Space
{
public:
	Jurassic();
	void displayEraInfo();
	void displayQuestion();
	bool checkAnswer(string answer);
	~Jurassic();
};

#endif
