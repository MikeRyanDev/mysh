#ifndef PARSER_H
#define PARSER_H
#include "command.h"
#include "commander.h"
#include <string>
#include <vector>
#include "shell-error.h"
#include <queue>

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
public:
	Command command;
	bool hasError;
	ShellError error;
	string errorMessage;
	Parser(string cmdBlock, Commander &commands);
};

#endif