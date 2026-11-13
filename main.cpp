#include "Simulator.h"
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <windows.h>

using namespace std;
int main() {
	Simulator::Instance();
	while (true)
	{
		Simulator::Instance()->simulate();
	}

	return 0;
	
}