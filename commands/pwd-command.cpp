#include "../classes/command.cpp"
#include <string>
#include <vector>
#include <iostream>
#ifdef _WIN32
	#include <direct.h>
	#define getcwd _getcwd
#elif
	#include <unistd.h>
#endif

class pwdCommand : public Command{
public:
	string execute(){
		string cwd(getcwd(NULL,0));

		return cwd;
	}
};