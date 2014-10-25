#include "classes/command.h"
#include "classes/commander.h"
#include "classes/parser.h"
#include "classes/shell.h"
#include "commands/cd-command.h"
#include <string>

int main()
{
	Shell mysh;

	mysh.commands.enlist("cd", &cdCommand::create);
	
	/*
	mysh->run();
	*/
}