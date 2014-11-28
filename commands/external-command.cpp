#pragma once

#include "base-command.cpp"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <string>
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
	ExternalCommand(string cmd, vector<string> args) : Command(args){
		// setCmd(cmd);
		// setFullArgs(args, flags);
		createCommandBlock(cmd, args);
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
		system(cmdBlock.c_str());

		string ret = "";

		return ret;
	}

private:

	void createCommandBlock(string name, vector<string> args){
		
		this->cmdBlock = name + " ";

		for(size_t i = 0; i != args.size(); ++i)
		{
			cmdBlock = cmdBlock + args[i] + " ";
		}
	};

private:

	string cmdBlock;
};
