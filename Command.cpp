#include "Command.h"
#include "Reader.h"
#include <fstream>
#include <vector>

// function that returns multiline argument as a string
string Command::readMultilineArg()
{
	string text = "";
	ConsoleReader* myReader = new ConsoleReader();
	while (true) {
		string curr = myReader->readLine();
		curr += '\n';
		if (!cin.eof())
			text += curr;
		else
			break;
	}
	cin.clear();
	delete myReader;
	return text.substr(0, text.length()-1);  // we have one extra '\n' 
}

// reads argument in three different ways
string Command::getArgument(const string& cmdArg, string inRedFileName)
{
	string text = "";
	if (cmdArg.size() == 0) {
		hasMultilineArg = true;
		// maybe the multilineArg is in file, not in console
		if (inRedFileName != "") {
			FileReader* myReader = new FileReader(inRedFileName);
			string line = "";
			while (!myReader->endOfRead()) {
				line += myReader->readLine();
				if (!myReader->endOfRead())
					line += '\n';
			}
			text = line.substr(0, line.length());
			return text;
		}
		text += readMultilineArg();
		//text = text.substr(0, text.length() - 1);
	}
	else if (cmdArg.length() > 1 && cmdArg[0] == '"' && cmdArg[cmdArg.length() - 1] == '"')
	{
		 text = cmdArg.substr(1, cmdArg.length() - 2);
	}
	else {
		FileReader* myReader = new FileReader(cmdArg);
		hasFileNameArg = true;
		string line = "";
		while (!myReader->endOfRead()) {
			line += myReader->readLine();
			if (!myReader->endOfRead())
				line += '\n';
		}
		text = line.substr(0, line.length()); // ovde je bilo -1
	}
	return text;
}

// useful for head and batch command, when we want our argLines to be splited into vector
vector<string> Command::getArgLines(const string& cmdArg)
{
	vector<string> lines;
	size_t start = 0, end = 0;
	while (start < cmdArg.length()) {
		end = cmdArg.find('\n', start);
		if (end == string::npos) {
			lines.push_back(cmdArg.substr(start));
			break;
		}
		else {
			lines.push_back(cmdArg.substr(start, end - start));
			start = end + 1;
		}
	}
	return lines;
}
