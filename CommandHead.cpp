#include "CommandHead.h"
#include <string>
#include <vector>
#include "Errors.h"

using namespace std;

string CommandHead::execute()
{
	string text = "";
	vector<string> lines;
	if (cmdOpt.length() < 3) {
		throw EUknownOption();
	}
	else if (cmdOpt.substr(0, 2) == "-n") {
		for (int i = 0; i < cmdOpt.length() - 2; i++)
			if (!isdigit(cmdOpt[i + 2])) {
				return text;    
			}
		int number = stoi(cmdOpt.substr(2, cmdOpt.length() - 2));
		if (number > 99999)     // maximum is 5 digits for head command
			throw EExistsWrongValue();
		lines = getArgLines(cmdArg);
		int linesCount = min(number, (int)lines.size());
		for (int i = 0; i < linesCount; i++) {
			text += lines[i];
			if (i != linesCount - 1)
				text += '\n';
		}
	}
	else throw EUknownOption();
	return text;
}
