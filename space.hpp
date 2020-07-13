#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Space
{
protected:
	Space() {};
	string name, description, relic;
	Space *top, *right, *left, *bottom;
	int questionNumber;
	vector<Space*> adjacentEras;
	bool obtainedRelic;

public:
	virtual void displayEraInfo() {};
	virtual void displayQuestion() {};
	virtual bool checkAnswer(string answer) = 0;
	vector<Space*>& getAdjacentEras();
	void setTop(Space *space);
	void setRight(Space *space);
	void setLeft(Space *space);
	void setBottom(Space *space);
	void setQuestionNumber(int questionNumber);
	int getQuestionNumber();
	string getRelic();
	string getName();
	bool isRelicObtained();
	void setRelicObtained(bool obtained);
	virtual ~Space() = 0; // pure virtual destructor
};

#endif
