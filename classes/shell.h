#ifndef SHELL_H
#define SHELL_H
#include "commander.h"

using namespace std;

class Shell
{
public:
	Commander commands;
	void run();
};

#endif