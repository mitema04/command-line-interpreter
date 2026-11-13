#include "CommandWc.h"
#include <sstream>
#include <string>
#include "Errors.h"
string CommandWc::execute()
{
	int number = 0;
	if (cmdOpt == "-w") {
		bool inWord = false;
		for (char c : cmdArg)
		{
			if (!isspace(c) && !inWord) {
				inWord = true;
				number++;
			}
			else if (isspace(c) && inWord)
				inWord = false;
		}
	}
	else if (cmdOpt == "-c") {
		for (char c : cmdArg)
		{
			number++;
		}
	}
	else
		throw EUknownOption();
	string output = to_string(number);
	return output;
}
