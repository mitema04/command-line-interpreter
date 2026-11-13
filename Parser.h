#ifndef PARSER_H
#define PARSER_H

#include "Reader.h"
#include "LineChecker.h"
#include <vector>

class Parser {
public:
	Parser(Reader* reader, LineChecker* lineChecker, int existsString = 0);

	~Parser();

	string cmdName, cmdOption, cmdArg, cmdWhat, cmdWith, cmdOutRed, cmdOutRedAppend, cmdInRed;

	vector<string> splitLine(const string& line);

	vector<string> splitPipeLine(const string& line);

	void parse(string line="");

	vector <string> parsePipeLine(string line="");

	// flag for reading argLines, if we want to parse line that already exists
	int existsString;

protected:
	void getRedirectionArguments(vector<string>& args);
	Reader* m_reader;
	LineChecker* m_lineChecker;

};

#endif