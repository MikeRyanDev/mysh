#include "../classes/command.cpp"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#include <unistd.h>
#include <dirent.h>

using namespace std;

/** 
* ExternalCommand executes commands not built in shell 
*
* @class ExternalCommand
*/
class ExternalCommand : public Command{
public:
	/**
	* Contructor
	*
	* @param {string} cmd command name
	* @param {vector<string>} args arguments in the command
	* @param {vector<char>} flags flags in the command
	* @public
	*
	* @return {null}
	*/	
	ExternalCommand(string cmd, vector<string> args, vector<char> flags) : Command(args){
		setCmd(cmd);
		setFullArgs(args, flags);
	}

	/**
	* execute() method inherited from Command
	* Calls internal method executeCommand
	*
	* @public
	*
	* @return {null}
	*/	
	string execute(){
		executeCommand();

		string ret = "";

		return ret;
	}

private:
	/**
	* Forks new process and executes command _cmd with arguments _args
	*
	* @private
	*
	* @return {null}
	*/		
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

	/**
	* Sets private char array _cmd 
	*
	* @param {string} cmd command name
	* @private
	*
	* @return {null}
	*/	
	void setCmd(string cmd){
		_cmd = strdup(cmd.c_str());
	}

	/**
	* Sets private char pointer array _args 
	*
	* @param {vector<string>} args arguments in the command
	* @param {vector<char>} flags flags in the command
	* @private
	*
	* @return {null}
	*/	
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

	/**
	* Appends '-' to flag char. Returns char array  
	*
	* @param {const char &} c flag char
	* @private
	*
	* @return {char *}
	*/	
	char *makeFlagArg(const char &c){
		char *tmp = new char[3];
		tmp[0] = '-';
		tmp[1] = c;
		tmp[2] = '\0';
		return tmp;
	}

	/**
	* Gets private char array _cmd 
	*
	* @private
	*
	* @return {char *}
	*/	
	char * const getCmd(){
		return _cmd;
	}

	/**
	* Gets private char pointer array _args 
	*
	* @private
	*
	* @return {char * const*}
	*/	
	char * const* getFullArgs(){
		return _args;
	}

private:
	/**
	* Internal char array of command name
	*
	* @private
	*/
	char *	_cmd;

	/**
	* Internal char array array of arguments
	*
	* @private
	*/
	char ** 	_args;
};
