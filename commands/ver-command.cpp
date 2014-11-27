#pragma once

#include "../classes/command.cpp"
#include <string>
#include <vector>

/**
* Command to print the current version of mysh
*
* @class verCommand
* @extends Command
* @module commands
*/
class verCommand : public Command{
public:
	verCommand( vector<string> args ) : Command(args){

	}

	virtual string execute(){
		string version = "mysh version 1.0.0 Copyright 2014\n";

		return version;
	}

	static Command *create(vector<string> args){
		return new verCommand(args);
	};
};