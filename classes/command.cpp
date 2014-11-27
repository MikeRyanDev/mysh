#pragma once

#include <string>
#include <vector>

using namespace std;

class Command
{
public:
	vector<string> arguments;
	bool shouldExit;

	Command( vector<string> args ){
		this->arguments = args;
		this->shouldExit = false;
	}
	virtual string execute() = 0;
};
