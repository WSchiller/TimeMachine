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
