#include "roman.hpp"


Roman::Roman()
{
	name = "Roman Empire";
	description = "The Roman Empire was period of the ancient Roman civilization, characterized by government headed\n" +
	description += "by emperors and large territorial holdings around the Mediterranean Sea in Europe, Africa and Asia.\n";
	relic = "gladius of Julius Caesar";
	obtainedRelic = false;
}

void Roman::displayEraInfo()
{
	cout << "Time Period: " << name << endl
		<< "=======================================================================================================================" << endl
		<< "Era Description: " << description << endl;
}

void Roman::displayQuestion()
{
	int questionNumber = rand() % 4 + 1;
	setQuestionNumber(questionNumber);

	switch (questionNumber)
	{
		case 1:
			cout << "In ancient Roman cities, what was the marketplace and meeting area called?" << endl << endl;
			cout << "a) Forest" << endl
				<< "b) Forelock" << endl
				<< "c) Forearm" << endl
				<< "d) Forum" << endl << endl;
			break;
		case 2:
			cout << "Which one of these was not implicated in the assassination of Julius Caesar?" << endl << endl;
			cout << "a) Brutus" << endl
				<< "b) Nero" << endl
				<< "c) Marc Antony" << endl
				<< "d) Cassius" << endl << endl;
			break;
		case 3:
			cout << "What did Romes economy stay mainly focused on?" << endl << endl
				<< "a) War" << endl
				<< "b) Politics" << endl
				<< "c) Farming and Trade" << endl
				<< "d) Education" << endl << endl;
			break;
		case 4:
			cout << "The Roman Republic used what type of government?" << endl << endl
				<< "a) Democracy" << endl
				<< "b) Fascism" << endl
				<< "c) Dictatorship" << endl
				<< "d) Monarchy" << endl << endl;
			break;
		case 5:
			cout << "What was Caesar Augustus famous for?"
				<< "a) Conquering the Eastern Roman Empire" << endl
				<< "b) He was the last emperor of the Western Roman Empire" << endl
				<< "c) Becoming the first emperor of Rome" << endl
				<< "d) Killing Julius Caesar" << endl << endl;
			break;
	}
}

bool Roman::checkAnswer(string answer)
{
	string answerKey[]{ "d", "b", "c", "a", "c" };

	if (answerKey[getQuestionNumber() - 1] == answer)
	{
		cout << "Correct answer!  You have collected the Gladius of Julius Ceasar!" << endl;
		cout << "Historical Facts: Julius Caesar was a general and dictator who turned the Rome into a powerful Empire by expanding its\n"
			<< "geographic reach and establishing its imperial system. His reign ended when he was assasinated by a group of senators.\n";

		return true;
	}
	else
	{
		cout << "Incorrect answer, try again" << endl;

		return false;
	}
}

Roman::~Roman()
{
	
}

