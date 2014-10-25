#ifndef CDCOMMAND_H
#define CDCOMMAND_H
#include "../classes/command.h"
#include <string>
#include <vector>

class cdCommand : public Command{
public:
	string execute();
	static Command create(vector<string> args, vector<char> flags);
};


#endif