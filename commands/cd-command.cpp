#pragma once

#include "../classes/command.cpp"
#include <string>
#include <vector>
#include "unistd.h"

using namespace std;

class cdCommand : public Command{
public:
	cdCommand( vector<string> args ) : Command(args){

	};

	virtual string execute(){
		string output;
		int error;

		if(this->arguments.empty())
			output = "Changed directory to home";
		else
		{
			error = chdir(this->arguments[0].c_str());

			if(error == -1)
			{
				output = "mysh: Error detected";
			}
			else
			{
				output = "";
			}
		}

		return output;
	};

	static Command create(vector<string> args){
		return cdCommand(args);
	};
};