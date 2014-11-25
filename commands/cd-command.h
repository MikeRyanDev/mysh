#ifndef CDCOMMAND_H
#define CDCOMMAND_H
#include "command.h"
#include <string>
#include <vector>

class cdCommand : public Command{
public:
	string execute();
	static cdCommand create(vector<string> args, vector<string> flags);
};


#endif
