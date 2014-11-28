#pragma once
#include <map>
#include <string>
#include <vector>
#include "../commands/base-command.cpp"
#include "../commands/quick-compile-command.cpp"
#include "../commands/external-command.cpp"

using namespace std;

/**
* A (very) simple representation of an IOC container. Maps command names to
* creator functions. 
*
* Example of creator function:
*
* 	class exampleCommand{
* 		static Command *create(vector<string> args){
* 			return new exampleCommand(args);
* 		}
* 	};
*
* Registering the command with the IoC:
*
* 	Commander commands;
* 	commands.enable("example", &exampleCommand::create);
*
* Resolving the command later:
*
* 	Command *exampleCmd = commands.resolve("example", args);
*
* @class Commander
* @module classes
*/
class Commander
{
private:
	/**
	* Internal map of command names to constructors
	*
	* @property {map<string, Command function>} map
	* @private
	*/
	map<string,Command *(*)(vector<string>)> container;
public:
	/**
	* Method to register a constructor and a command name with the Commander IOC
	*
	* @method enable
	* @param {string} cmdName The name of the command that is being registered
	* @param {Command Returning Function} creator The constructor function that creates 
	* the command
	* @return {null}
	*/
	void enable( string cmdName, Command *(*creator)(vector<string>) ){
		this->container[cmdName] = creator;
	}

	/**
	* Method to resolve a command from the command IOC. If the command is not found,
	* it returns an external command.
	*
	* @method resolve
	* @param {string} cmdName The name of the command to resolve
	* @param {vector<string>} args Vector string of the arguments to supply to the command
	*
	* @return {*Command} command Pointer to the resolved command
	*/
	Command *resolve(string cmdName, vector<string> cmdArgs){
		auto search = this->container.find(cmdName);

		if(search != this->container.end())
		{
			return (*this->container[cmdName])(cmdArgs);
		}
		else
		{
			vector<char> flags;
			vector<string> moreFlags;

			size_t foundC = cmdName.find(".c");
			size_t foundCpp = cmdName.find(".cpp");

			if(foundC != string::npos || foundCpp != string::npos)
			{
				return new qkcompile(cmdName, cmdArgs, moreFlags );
			}
			else
			{
				return new ExternalCommand( cmdName, cmdArgs );
			} 
		}
	}
};