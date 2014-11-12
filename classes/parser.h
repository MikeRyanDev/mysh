#pragma once

#include "command.h"
#include "commander.h"
#include "shell-error.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <cstring> //needed for linux
#define MAX_CHAR 257 //defines the max chars in a char array


using namespace std;

class Parser
{
private:
	string cmdBlock;
	string cmdName;
	vector<string> cmdArgs;
	vector<string> cmdFlags;
	queue<string> cmdQueue;
	void resolveQueue();
	char *splcmd; //pointer that will point to one "string" at a time
        char line[MAX_CHAR];
        bool keepResolving;
        
public:
	Command command;
	ShellError error;
	string errorMessage;
	Parser(string cmdBlock, Commander &commands);
	~Parser();
	bool hasError;
        bool isredirect; //will tell us if the command is a redirection
        bool iscfile;	//will tell us if the command is for quick compile
};
