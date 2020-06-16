/*HPP****************************************************************************************
** FILENAME: menu.hpp
** Author: Wesley Schiller
** Date: December 4, 2017
** Description: Contains member function prototypes and a private vector member for menu.cpp 
*********************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "space.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Menu
{
private:
	vector<Space*> adjacentEraVec; // vector to store adjacent era spaces

public:
	void displayIntro();
	void displayMenu();
	int getMenuInput();
	void displayRules();
	void displayReferences();
	void displayTimePeriods();
	int getTimePeriod();
	void promptAnswer();
	string getAnswer();
	int getNextEra(Space *currentSpace);
	void displayAdjacentEras();
	void inputValidation(int &selection, string validateRange);
	void answerInputValidation(string &answer);
};

#endif