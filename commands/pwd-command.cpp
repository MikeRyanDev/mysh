#pragma once

#include "base-command.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>

/**
* Command to print the path of the current working directory
*
* @class pwdCommand
* @extends Command
* @module commands
*/
class pwdCommand : public Command{
public:
	pwdCommand( vector<string> args ) : Command(args){

	};
	virtual string execute(){
		string cwd(getcwd(NULL,0));

		return cwd + "\n";
	}

	static Command *create(vector<string> args){
		return new pwdCommand(args);
	};
};