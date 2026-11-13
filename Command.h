#ifndef COMMAND_H
#define COMMAND_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Command {
public:

	virtual ~Command() {}

	virtual string execute() = 0;

	inline string getCmdName() const {
		return cmdName;
	}
	// flag that is only used for blocking redirection if neccessary
	bool hasMultilineArg = false;

	bool hasFileNameArg = false; // novo

protected:
	Command(const string name) : cmdName(name) {}
	string cmdName;
	// there are commands that have multiline arguments
	string readMultilineArg();
	//
	string getArgument(const string& cmdArg, string inRedFileName="");

	vector <string> getArgLines(const string& cmdArg);
};

#endif