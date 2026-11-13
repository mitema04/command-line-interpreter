#define _CRT_SECURE_NO_WARNINGS
#include "CommandDate.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

string CommandDate::execute()
{
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    stringstream output;
    output << put_time(localtime(&now_time), "%A, %B %d, %Y");
    return output.str();
}
