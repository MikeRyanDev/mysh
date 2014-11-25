#pragma once

#include "../classes/command.cpp"
#include <string>
#include <vector>
#include "unistd.h"
#include <sys/types.h>
#include <pwd.h>

using namespace std;

class cdCommand : public Command{
public:
	cdCommand( vector<string> args ) : Command(args){

	};

	virtual string execute(){
		string output;
		int error;

		if(this->arguments.empty())
		{
			struct passwd *pw = getpwuid(getuid());

			output = string(pw->pw_dir);

			chdir(output.c_str());

			output = "";
		}
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