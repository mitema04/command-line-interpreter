#ifndef COMMANDRM_H
#define COMMANDRM_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandRm : public Command {
public:

	CommandRm(string name, string arg) : Command(name), cmdArg(arg) {}

	~CommandRm() {}

	string readInput() = delete;

	string getArgument() = delete;

	string execute() override;


private:
	string cmdArg;
};

#endif