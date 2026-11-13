#ifndef COMMANDPROMPT_H
#define COMMANDPROMPT_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

class Simulator;

using namespace std;

class CommandPrompt : public Command {
public:

	CommandPrompt(string name, string arg, string inRedFilename) : Command(name) {
		cmdArg = getArgument(arg, inRedFilename);
	}

	~CommandPrompt() {}

	string getArgLines() = delete;  // novo

	string readMultilineArg() = delete; // novo

	string execute() override;

private:
	string cmdArg;
};

#endif