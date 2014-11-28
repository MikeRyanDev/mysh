#pragma once

#include <string>
#include <vector>

using namespace std;

/**
* Base abstract command class that acts like an interface
* for all other commands to implement
*
* @class Command
* @module commands
*/
class Command
{
public:
	/**
	* The list of arguments supplied to the command
	*
	* @property {vector<string>} arguments
	*/
	vector<string> arguments;

	/**
	* Commands can send an exit signal to the shell by setting
	* this value to true.
	*
	* @property {boolean} shouldExit
	*/
	bool shouldExit;

	/**
	* Instantiates a base command
	*
	* @constructor
	* @param {vector<string>} args The list of arguments supplied to the command
	*/
	Command( vector<string> args ){
		this->arguments = args;
		this->shouldExit = false;
	}

	/**
	* Method where command logic is imlemented. 
	*
	* @method execute
	* @return {string} output The output of the command
	*/
	virtual string execute() = 0;
};
