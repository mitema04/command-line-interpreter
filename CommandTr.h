#ifndef COMMANDTR_H
#define COMMANDTR_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandTr : public Command {
public:

	CommandTr(string name, string arg, string what, string with, string inRedFileName);
	~CommandTr() {}

	string execute() override;


private:
	string cmdArg, cmdWhat, cmdWith;
};

#endif