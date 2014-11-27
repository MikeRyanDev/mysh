#pragma once

#include "../classes/command.cpp"
#include <string>
#include <vector>

using namespace std;

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