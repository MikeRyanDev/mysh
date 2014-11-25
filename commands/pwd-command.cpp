#pragma once

#include "../classes/command.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>

class pwdCommand : public Command{
public:
	pwdCommand( vector<string> args ) : Command(args){

	};
	virtual string execute(){
		string cwd(getcwd(NULL,0));

		return cwd;
	}

	static Command create(vector<string> args){
		return pwdCommand(args);
	};
};