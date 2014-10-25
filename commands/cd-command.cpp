#import "cd-command.h"
#import <string>

string cdCommand::execute(){
	string output = "Changed directory";

	return output;
}

static Command cdCommand::create(vector<string> args, vector<char> flags){
	return new cdCommand(args, flags);
}