#pragma once

#include <string>
#include <vector>

using namespace std;

class Command
{
public:
	vector<string> arguments;
	vector<char> flags;

	Command( vector<string> args ){
		this->arguments = args;
	}
	virtual string execute(){
		string ret = "mysh: Error detected!";

		return ret;
	};
};
