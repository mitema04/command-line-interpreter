#include "CommandTruncate.h"
#include "Errors.h"
#include <fstream>

using namespace std;

string CommandTruncate::execute()
{
    ifstream check(cmdArg);
    if (!check)
        throw EFileNotFound();
    else {
        check.close();
        ofstream myFile(cmdArg, ios::trunc);
        myFile.close();
    }
    return "";
}
