#pragma once

#include "../classes/command.cpp"
#include <string>
#include <vector>

using namespace std;

class cdCommand : public Command{
public:
	cdCommand( vector<string> args ) : Command(args){
		cout << endl << "creating cd command" << endl;

	};

	virtual string execute(){
		string output = "Changed directory";

		return output;
	};

	static Command create(vector<string> args){
		return cdCommand(args);
	};
};