#include "CommandBatch.h"
#include <vector>
#include "Parser.h"
#include "CommandTime.h"
#include "CommandDate.h"
#include "CommandEcho.h"
#include "CommandTouch.h"
#include "CommandWc.h"
#include "CommandPrompt.h"
#include "CommandTruncate.h"
#include "CommandRm.h"
#include "CommandHead.h"
#include "Simulator.h"

string CommandBatch::execute()
{
	vector <string> lines = getArgLines(cmdArg);
	string output = "";

	for (int i = 0; i < lines.size(); i++)
	{
		int inBatch = 1;
		// command batch has its own parser that parses already finished lines
		Parser* myParser = new Parser(new LineReader(), new LineChecker(), inBatch);
		Printer* myPrinter = new Printer(myParser);
		string txt = Simulator::cmdSimulation(myParser, myPrinter, lines[i]);
		// we are executing the comand inside batch, maybe it has its own redirection 
		// so we dont need to return that part of string 
		if (myParser->cmdOutRed == "" && myParser->cmdOutRedAppend == "") {
			output += txt;
			if (i != lines.size() - 1)
				output += '\n';
		}
		delete myPrinter;
	}

	return output;
}
