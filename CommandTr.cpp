#include "CommandTr.h"
#include <string>


CommandTr::CommandTr(string name, string arg, string what, string with, string inRedFileName) : Command(name), cmdWhat(what), cmdWith(with) {
    cmdArg = getArgument(arg, inRedFileName);
    if (what != "")
        cmdWhat = getArgument(what);
    if (with != "")
        cmdWith = getArgument(with);
}

string CommandTr::execute()
{
    size_t pos = 0;
    if (cmdWith == "")
    {
        while ((pos = cmdArg.find(cmdWhat, pos)) != string::npos) {
            cmdArg.erase(pos, cmdWhat.length());
        }
    }
    else {
        pos = 0;
        while ((pos = cmdArg.find(cmdWhat, pos)) != string::npos) {
            cmdArg.replace(pos, cmdWhat.length(), cmdWith);
            pos += cmdWith.length();
        }
    }
    return cmdArg;
}
