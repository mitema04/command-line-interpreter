#include "CommandPrompt.h"
#include "Parser.h"
#include "Simulator.h"
#include "Errors.h"

string CommandPrompt::execute()
{
	if (!hasMultilineArg && !hasFileNameArg)
		Simulator::Instance()->setStartSign(cmdArg);
	else
		throw EWrongArgType();
	return "";

}
