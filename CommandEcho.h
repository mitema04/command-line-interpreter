#ifndef COMMANDECHO_H
#define COMMANDECHO_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandEcho : public Command {
public:

	CommandEcho(string name, string arg, string inRedFileName): Command(name){
		cmdArg = getArgument(arg, inRedFileName);
	}

	~CommandEcho() {}

	string execute() override;

private:

	string cmdArg;
};

#endif