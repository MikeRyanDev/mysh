#pragma once

#include "../classes/command.cpp"
#include <string>
#include <vector>

using namespace std;

/**
* Command to send an exit signal to the mysh shell
*
* @class exitCommand
* @extends Command
* @module commands
*/
class exitCommand : public Command{
public:
	exitCommand( vector<string> args ) : Command(args){

	}

	virtual string execute(){
		string output = "Goodbye! \n";
		this->shouldExit = true;
		return output;
	}

	static Command *create(vector<string> args){
		return new exitCommand(args);
	};
};