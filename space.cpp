#include "space.hpp"


void Space::setTop(Space *space)
{
	top = space;
}

void Space::setRight(Space *space)
{
	right = space;
}

void Space::setLeft(Space *space)
{
	left = space;
}

void Space::setBottom(Space *space)
{
	bottom = space;
}

vector<Space*>& Space::getAdjacentEras()
{
	return adjacentEras;
}

void Space::setQuestionNumber(int questionNumber)
{
	this->questionNumber = questionNumber;
}

int Space::getQuestionNumber()
{
	return questionNumber;
}

string Space::getRelic()
{
	return relic;
}

string Space::getName()
{
	return name;
}

bool Space::isRelicObtained()
{
	return obtainedRelic;
}

void Space::setRelicObtained(bool obtained)
{
	this->obtainedRelic = obtained;
}

Space::~Space() 
{

}
