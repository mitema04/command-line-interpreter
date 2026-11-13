#ifndef COMMANDBATCH_H
#define COMMANDBATCH_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandBatch : public Command {
public:

	CommandBatch(string name, string arg, string inRedFileName) : Command(name) {
		cmdArg = getArgument(arg, inRedFileName);
	}

	~CommandBatch() {}

	string execute() override;

private:
	string cmdArg;
};

#endif