#pragma once

#include "base-command.cpp"
#include "../classes/shell.cpp"
#include "../classes/shell-error.cpp"
#include <string>
#include <vector>

using namespace std;

extern Shell mysh;

/**
* Command to source batch files and execute them
*
* @class sourceCommand
* @extends Command
* @module commands
*/
class sourceCommand : public Command{
public:
	sourceCommand( vector<string> args ) : Command(args){

	};

	virtual string execute(){
		string output = "";

		if(this->arguments.empty())
		{
			throw ShellError();
		}
		else
		{
			mysh.runBatchFile(this->arguments[0]);
		}

		return output;
	};

	static Command *create(vector<string> args){
		return new sourceCommand(args);
	};
};