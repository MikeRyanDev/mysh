#include "classes/shell.cpp"
#include "classes/commander.cpp"
#include "commands/cd-command.cpp"
#include "commands/pwd-command.cpp"
#include "commands/ver-command.cpp"
#include "commands/exit-command.cpp"
#include "commands/change-name-command.cpp"
#include <string>

Commander commands;
Shell mysh;

int main(int argc, char* argv[])
{

	commands.enable("cd", &cdCommand::create);
	commands.enable("pwd", &pwdCommand::create);
	commands.enable("ver", &verCommand::create);
	commands.enable("exit", &exitCommand::create);
	commands.enable("name", &changeNameCommand::create);
	
	mysh.run(argc, argv);

	return 0;
}