#ifndef COMMANDHEAD_H
#define COMMANDHEAD_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandHead : public Command {
public:

	CommandHead(string name, string opt, string arg, string inRedFileName) : Command(name), cmdOpt(opt) {
		cmdArg = getArgument(arg, inRedFileName);
	}

	~CommandHead() {}

	string execute() override;

private:
	string cmdArg, cmdOpt;
};

#endif