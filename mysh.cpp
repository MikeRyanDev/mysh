// #include "classes/commander.cpp"
// #include "classes/parser.cpp"
#include "classes/shell.cpp"
#include "commands/cd-command.cpp"
#include "commands/pwd-command.cpp"
#include <string>

int main()
{
	Shell mysh;

	mysh.commands.enlist("cd", &cdCommand::create);
	mysh.commands.enlist("pwd", &pwdCommand::create);
	
	mysh.run();

	return 0;
}