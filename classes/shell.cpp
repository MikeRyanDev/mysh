#include "commander.cpp"
#include "parser.cpp"
#include <iostream>
#include <sstream>

using namespace std;

class Shell
{
public:
	Commander commands;
	
	
	void run(){
		
		string cmdBlock;
		bool stop = false;

		while(! stop){
			cout << "mysh > ";
			getline(cin, cmdBlock);
			if(cmdBlock.length() == 0)
			{
				cout << endl;
			}
			else if(cmdBlock == "exit")
			{
				stop = true;
				cout << endl << "Goodbye!" << endl << endl;
			}
			else
			{
				Parser parsedCmd = Parser(cmdBlock, this->commands);

				if(parsedCmd->hasError)
				{
					cout << "error" << endl;
				}
				else
				{
					cout << parsedCmd->command->execute();
				}
			}
		}
	};
};
