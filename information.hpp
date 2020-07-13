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
