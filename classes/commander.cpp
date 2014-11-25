#ifndef COMMANDER_CPP
#define COMMANDER_CPP
#include <map>
#include <string>
#include <vector>
#include "command.cpp"
#include "../commands/external-command.cpp"

using namespace std;

/**
* A (very) simple representation of an IOC container. Maps command names to
* creator functions. 
*
* @class Commander
*/
class Commander
{
private:
	/**
	* Internal map of command names to constructors
	*
	* @param {map<string, Command function>} map
	* @private
	*/
	map<string,Command(*)(vector<string>)> container;
public:
	/**
	* Method to register a constructor and a command name with the Commander IOC
	*
	* @param {string} cmdName The name of the command that is being registered
	* @param {Command Returning Function} creator The constructor function that creates 
	* the command
	*
	* @return {null}
	*/
	void enlist( string cmdName, Command(*creator)(vector<string>) ){
		this->container[cmdName] = creator;
	}

	/**
	* Method to resolve a command from the command IOC. If the command is not found,
	* it returns an external command.
	*
	* @parma {string} cmdName The name of the command to resolve
	* @param {vector<string>} args Vector string of the arguments to supply to the command
	* @param {vector<string>} flags Vector string of the flags to supply to the command
	*
	* @return {Command}
	*/
	Command resolve(string cmdName, vector<string> args){
		auto search = this->container.find(cmdName);

		if( search != this->container.end() )
		{
			return (*this->container[cmdName])(args);
		}
		else
		{
			vector<char> flags;
			ExternalCommand external(cmdName, args, flags);
			return external;
		}
	}
};

#endif
