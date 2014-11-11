// Note: Here's my rough draft for the external command feature.
// I have not compiled this yet. Let me know if there's anything 
// that should be changed design-wise or syntax-wise. -Julian
// #include "../classes/command.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#include <unistd.h>
#include <dirent.h>

using namespace std;

class ExternalCommand {
public:
	//Initializes attributes with the corresponding arguments
	ExternalCommand(string cmd, vector<string> args, vector<char> flags){
		setCmd(cmd);
		setFullArgs(args, flags);
	}

	void execute(){
		executeCommand();
	}

private:
	void executeCommand(){
		char * const cmd = getCmd();
		char * const * args = getFullArgs();

		//forks process
		int id = fork();

		//if process is child, execute full command
		if(id == 0) {
			execvp(cmd, args);
		}
	}

	void setCmd(string cmd){
		_cmd = strdup(cmd.c_str());
	}

	void setFullArgs(vector<string> args, vector<char> flags){
		_args  = new char*[args.size() + flags.size()];

		vector<string>::iterator i = args.begin();
		int count = 0;

		_args[0] = strdup(getCmd());

		for(; i != args.end(); i++){
			_args[count] = strdup((*i).c_str());
			count++;			
		}
		vector<char>::iterator k = flags.begin();
		for(; k != flags.end(); k++){
			_args[count] = strdup(makeFlagArg(*k));
			count++;
		}
	}

	char *makeFlagArg(const char &c){
		char *tmp = new char[3];
		tmp[0] = '-';
		tmp[1] = c;
		tmp[2] = '\0';
		return tmp;
	}

	char * const getCmd(){
		return _cmd;
	}

	char * const* getFullArgs(){
		return _args;
	}

private:
	char *	_cmd;
	char ** 	_args;
};
