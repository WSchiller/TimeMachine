/*HPP*****************************************************************
** FILENAME: egypt.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains member function prototypes for Egypt.cpp
*********************************************************************/

#ifndef EGYPT_HPP
#define EGYPT_HPP
#include "space.hpp"

class Egypt : public Space
{
public:
	Egypt();
	void displayEraInfo();
	void displayQuestion();
	bool checkAnswer(string answer);
	~Egypt();
};

#endif



