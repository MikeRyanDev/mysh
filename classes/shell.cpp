#include "shell.h"

void Shell::run(){
	Parser newCommand(args);

	newCommand->command->excute();
}