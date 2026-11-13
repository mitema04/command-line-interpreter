#ifndef COMMANDDATE_H
#define COMMANDDATE_H

#include<iostream>
#include<string>
#include "Command.h"

using namespace std;

class CommandDate : public Command {
public:

	CommandDate(string name) : Command(name) {};

	~CommandDate() {}   // nepotrebno?

	string getArgument() = delete;

	string getArgLines() = delete;  // novo

	string readMultilineArg() = delete; // novo

	string execute() override;

};
#endif