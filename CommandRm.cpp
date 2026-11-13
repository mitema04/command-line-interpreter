#include "CommandRm.h"
#include <fstream>
#include <cstdio>
#include "Errors.h"
#include <iostream>

using namespace std;

string CommandRm::execute()
{
    if (!(remove(cmdArg.c_str()) == 0)) {
        throw EFileNotFound();
    }
    return "";
}
