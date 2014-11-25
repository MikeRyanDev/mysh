// #include "classes/commander.cpp"
// #include "classes/parser.cpp"
#include "classes/shell.cpp"
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