#pragma once

#include "../classes/command.cpp"
#include "../classes/shell-error.cpp"
#include <string>
#include <vector>
#include "unistd.h"
#include <sys/types.h>
#include <pwd.h>

using namespace std;

/**
* Command to change the current directory during shell execution
*
* @class cdCommand
* @extends Command
* @module commands
*/
class cdCommand : public Command{
public:
	cdCommand( vector<string> args ) : Command(args){

	};

	virtual string execute(){
		int error;

		if(this->arguments.empty())
		{
			struct passwd *pw = getpwuid(getuid());

			string directory(pw->pw_dir);

			chdir(directory.c_str());
		}
		else
		{
			error = chdir(this->arguments[0].c_str());

			if(error == -1)
			{
				throw ShellError();
			}
		}

		return "";
	};

	static Command *create(vector<string> args){
		return new cdCommand(args);
	};
};