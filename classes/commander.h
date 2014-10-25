#ifndef COMMANDER_H
#define COMMANDER_H
#include <map>
#include <string>
#include <vector>
#include "command.h"

using namespace std;

class Commander
{
private:
	map<string,Command(*)(vector<string>, vector<char>)> container;
public:
	void enlist( string cmdName, Command(*creator)(vector<string>, vector<char>) );
	Command resolve(string cmdName, vector<string> args, vector<char> flags);
};

#endif