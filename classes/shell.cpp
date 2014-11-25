#include "commander.cpp"
#include "parser.cpp"
#include "file-output.cpp"
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
			cout << "mysh> ";
			getline(cin, cmdBlock);

			if(cmdBlock.length() == 0)
			{
				
			}
			else if(cmdBlock == "exit")
			{
				stop = true;
				cout << "Goodbye!" << endl;
			}
			else
			{
				Parser parsedCmd(cmdBlock, this->commands);

				if(parsedCmd.hasError)
				{
					cout << "mysh: Error detected" << endl;
				}
				else if(parsedCmd.isredirect)
				{
					FileOutput out(parsedCmd.outputFile, parsedCmd.append);

					out.write( parsedCmd.command->execute() );
				}
				else
				{
					cout << parsedCmd.command->execute() << endl;
				}
			}
		}
	};
};
