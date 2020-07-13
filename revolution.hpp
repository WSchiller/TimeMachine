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
