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
