#include "CommandTouch.h"
#include "Errors.h"
#include <fstream>

string CommandTouch::execute()
{
	ifstream oldFile = ifstream(cmdArg);
	if (oldFile) {
		throw EFileAlreadyExists();
		oldFile.close();
	}
	else {
		ofstream newFile = ofstream(cmdArg);
		newFile.close();
	}
	return "";
}