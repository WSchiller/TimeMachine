#ifndef ROMAN_HPP	
#define ROMAN_HPP
#include "space.hpp"

class Roman : public Space
{
public:
	Roman();
	void displayEraInfo();
	void displayQuestion();
	bool checkAnswer(string answer);
	~Roman();
};

#endif
