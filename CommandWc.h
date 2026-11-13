#ifndef COMMANDWC_H
#define COMMANDWC_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandWc : public Command {
public:

	CommandWc(string name, string opt, string arg, string inRedFileName) : Command(name), cmdOpt(opt){
		cmdArg = getArgument(arg, inRedFileName);
	}

	~CommandWc() {}

	string execute() override;


private:
	string cmdArg, cmdOpt;
};

#endif