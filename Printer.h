#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Command.h"

using namespace std;

class Printer {
public: 

	string text;
	bool inOutputRedirection = false;

	void print(string txt);

	friend class Simulator;

	Printer(Parser *p) : text(""), m_parser(p) {};

	~Printer();


private:
	Parser* m_parser;
	void printStdOutput();
	void printInFile();
	void appendInFile();
};

#endif