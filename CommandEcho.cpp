#include "CommandEcho.h"
#include <fstream>
#include <sstream>
#include "Simulator.h"

string CommandEcho::execute()
{
	return cmdArg;
}
