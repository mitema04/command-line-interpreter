#ifndef COMMANDTIME_H
#define COMMANDTIME_H

#include<iostream>
#include<string>
#include "Command.h"

using namespace std;

class CommandTime : public Command {
public: 

	CommandTime(string name) : Command(name) {};

	~CommandTime() {}

	string getArgument() = delete;

	string getArgLines() = delete;  // novo

	string readMultilineArg() = delete; // novo

	string execute() override;

};
#endif