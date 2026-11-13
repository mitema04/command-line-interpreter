#ifndef LINECKECKER_H
#define LINECHECKER_H
#include <string>

using namespace std;

class LineChecker {
public: 

	string inputLine = "";

	string checkerLine = "";

	bool hasInvalidChars = false;

	LineChecker() {}

	void calcCheckerLine();

	void resetParametres();

};

#endif