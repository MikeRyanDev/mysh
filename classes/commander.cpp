#include "commander.h"
#include "command.h"
#include <functional>
#include <string>
#include <vector>
#include "shell-error.h"

using namespace std;

void Commander::enlist(string cmdName, Command(*creator)(vector<string>, vector<char>) ){
	this->container[cmdName] = creator;
}

Command Commander::resolve(string cmdName, vector<string> args, vector<char> flags){
	auto search = this->container.find(cmdName);

	if( search != this->container.end() )
		return (*this->container[cmdName])(args, flags);
	else
		return new ExternalCommand(args, flags);
}