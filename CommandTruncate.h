#ifndef COMMANDTRUNCATE_H
#define COMMANDTRUNCATE_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandTruncate : public Command {
public:

	CommandTruncate(string name, string arg, string inRedFileName) : Command(name), cmdArg(arg) {};

	~CommandTruncate() {}

	string readInput() = delete;

	string getArgument() = delete;

	string execute() override;

private:
	string cmdArg;
};

#endif