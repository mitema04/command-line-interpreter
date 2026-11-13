#define _CRT_SECURE_NO_WARNINGS
#include "CommandTime.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

string CommandTime::execute()
{
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    stringstream output;
    output << put_time(localtime(&now_time), "%H:%M:%S");
    return output.str();

}
