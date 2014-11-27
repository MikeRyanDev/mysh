#pragma once

#include "../classes/command.cpp"
#include "../classes/shell.cpp"
#include "../classes/shell-error.cpp"
#include <string>
#include <vector>

using namespace std;

extern Shell mysh;

class changeNameCommand : public Command{
public:
	changeNameCommand( vector<string> args ) : Command(args){

	};

	virtual string execute(){
		string output = "";

		if(this->arguments.empty())
		{
			// throw ShellError("Cannot change name", "must supply a new name for the shell");
			throw ShellError();
		}
		else
		{
			mysh.shellName = this->arguments[0];
		}

		return output;
	};

	static Command *create(vector<string> args){
		return new changeNameCommand(args);
	};
};