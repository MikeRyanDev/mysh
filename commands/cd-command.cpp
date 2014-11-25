#import "cd-command.h"
#import <string>

string cdCommand::execute(){
	string output = "Changed directory";
	// edit
	return output;
}

static cdCommand cdCommand::create(vector<string> args, vector<string> flags){
	return new cdCommand(args, flags);
}
