#include "medieval.hpp"


Medieval::Medieval()
{
	name = "Middle Ages";
	description = "Lasted from the 5th to the 15th century.It began with the fall of the\n" +
	description += "Western Roman Empire and merged into the Renaissance and the Age of Discovery.\n";
	relic = "knight's helmet";
	obtainedRelic = false;
}

void Medieval::displayEraInfo()
{
	cout << "Time Period: " << name << endl
		<< "=======================================================================================================================" << endl
		<< "Era Description: " << description << endl;
}

void Medieval::displayQuestion()
{
	int questionNumber = rand() % 4 + 1;
	setQuestionNumber(questionNumber);

	switch (questionNumber)
	{
		case 1:
			cout << "This English King was forced to sign the Magna Carta giving rights to the people?" << endl << endl
				<< "a) King James" << endl
				<< "b) King John" << endl
				<< "c) King Richard" << endl
				<< "d) King Henry" << endl << endl;
			break;
		case 2:
			cout << "The Old Roman Architecture gave way to this new architecture during this time period." << endl << endl
				<< "a) Greek" << endl
				<< "b) Gothic" << endl
				<< "c) Germanic" << endl
				<< "d) Romantic" << endl << endl;
			break;
		case 3:
			cout << "Which of the following is considered a literary masterpiece of the Middle Ages?" << endl << endl
				<< "a) The Anglo Saxon Chronicles" << endl
				<< "b) Canterbury Tales" << endl
				<< "c) Beowulf" << endl
				<< "d) History of the English Land and People" << endl << endl;
			break;
		case 4:
			cout << "Which religion became dominant and strongly tied to the throne, in Western Europe?" << endl << endl
				<< "a) Protestant" << endl
				<< "b) Catholic" << endl
				<< "c) Lutheran" << endl
				<< "d) Mormonism" << endl << endl;
			break;
		case 5:
			cout << "At the end of the medieval age, what did Johannes Gutenburg invent that changed the world?" << endl << endl
				<< "Gunpowder" << endl
				<< "b) Crossbow" << endl
				<< "c) Compass" << endl
				<< "d) Moveable Type Printing" << endl << endl;
			break;
	}
}

bool Medieval::checkAnswer(string answer)
{
	string answerKey[]{ "b", "c", "b", "b", "d" };

	if (answerKey[getQuestionNumber() - 1] == answer)
	{
		cout << "Correct answer!  You have collected a knights helmet!" << endl;
		cout << "Historical Facts: Knight's were titled as elite warriors subject to certain responsibilities and expectations.\n"
			<< "The Code of Chivalry dictated that a Knight should be brave and fearless in battle but would also\n"
			<< "exhibit cultured Knightly qualities showing themselves to be devout, loyal, courteous and generous.\n";

		return true;
	}
	else
	{
		cout << "Incorrect answer, try again" << endl;

		return false;
	}
}

Medieval::~Medieval()
{
	
}
