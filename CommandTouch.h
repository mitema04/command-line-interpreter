#ifndef COMMANDTOUCH_H
#define COMMANDTOUCH_H

#include<iostream>
#include<string>
#include "Command.h"
#include "Reader.h"

using namespace std;

class CommandTouch : public Command {
public:

	CommandTouch(string name, string arg) : Command(name), cmdArg(arg) {}

	~CommandTouch() {}

	string readInput() = delete;

	string getArgument() = delete;

	string execute() override;

private:
	string cmdArg;
};

#endif