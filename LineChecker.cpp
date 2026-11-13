#include "LineChecker.h"

void LineChecker::calcCheckerLine()
{
	bool insideQuotes = false;
	for (char c : inputLine) {
		if (c == '\"') {
			insideQuotes = !insideQuotes;
			checkerLine += ' ';
		}
		else if (!insideQuotes && !isalnum(c) and c != '|' && !isspace(c) && c != '/' && c != '<' && c != '>' && c != '.' && c != '-') {
			checkerLine += '^';
			hasInvalidChars = true;
		}
		else checkerLine += ' ';
	}
}

void LineChecker::resetParametres()
{
	inputLine = "";
	checkerLine = "";
	hasInvalidChars = false;
}

