#pragma once

#include "../commands/base-command.cpp"
#include "commander.cpp"
#include "shell-error.cpp"
#include <string>
#include <vector>
#include <queue>
#include <regex>
#include <cstring> //needed for linux
#define MAX_CHAR 257 //defines the max chars in a char array


using namespace std;

extern Commander commands;

/**
* A class that takes a command block and parses it into a command name,
* arguments, and output redirection
*
* @class Parser
*/
class Parser
{
private:
	/**
	* The entire line entered at the shell
	*
	* @property {string} cmdBlock
	* @private
	*/
	string cmdBlock;

	/**
	* Parsed name of the command
	*
	* @property {string} cmdName
	* @private
	*/
	string cmdName;

	/**
	* Parsed list of the command's arguments
	*
	* @property {vector<string>} cmdArgs
	* @private
	*/
	vector<string> cmdArgs;

	/**
	* Queue of each 'word' in the command block
	*
	* @property {queue<string>} cmdQueue
	* @private
	*/
	queue<string> cmdQueue;

	/**
	* Flag determining whether the parser should keep resolving the queue
	*
	* @property {boolean} keepResolving
	* @private
	*/
	bool keepResolving;

	/**
	* Method to resolve the qeueue, separating out flags, arguments, command
	* names, and operators
	*
	* @method resolveQueue
	* @private
	*/
	void resolveQueue(){
		this->cmdName = cmdQueue.front();
		cmdQueue.pop();

		keepResolving = true;
		isRedirect = false;

		while(cmdQueue.size() > 0 && keepResolving)
		{
			string front = cmdQueue.front();

			if(front == ">" || front == ">>")
			{
				this->append = ( front == ">>" );
				cmdArgs.push_back(front);
				cmdQueue.pop();
				if(cmdQueue.empty()) throw ShellError();

				this->outputFile = cmdQueue.front();
				cmdArgs.push_back(this->outputFile);
				cmdQueue.pop();
				keepResolving = false;
				this->isRedirect = true;
			}
			else
			{
				cmdArgs.push_back(front);
				cmdQueue.pop();
			}
		}
	}

	/**
	* Uses the command name to resolve a command from the IoC container
	*
	* @method resolveCommand
	* @private
	*/
	void resolveCommand(){
		this->command = commands.resolve(this->cmdName, this->cmdArgs);
	}
		
public:
	/**
	* The resolved command
	*
	* @property {Command} command
	*/
	Command *command;

	/**
	* Determine whether or not the command is a redirection
	*
	* @property {boolean} isRedirect
	*/
	bool isRedirect;

	/**
	* Determine whether redirection output should append or overwrite file
	*
	* @property {boolean} append
	*/
	bool append;

	/**
	* Name of the file to redirect output to
	*
	* @property {string} outputFile
	*/
	string outputFile;

	/**
	* Instantiates a new parser given a string that represents a full
	* command block
	*
	* @method Parser
	* @param {string} cmdBlock The commnad block to be parsed out
	* @constructor
	*/
	Parser(string cmdBlock){
		regex re("[\\s]+");
		sregex_token_iterator it(cmdBlock.begin(), cmdBlock.end(), re, -1);
		sregex_token_iterator reg_end;
		for (; it != reg_end; ++it) {
			this->cmdQueue.push(it->str());
		}

		this->resolveQueue();
		this->resolveCommand();        
	}
};
