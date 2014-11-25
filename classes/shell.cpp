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
				Parser parsedCmd(cmdBlock, this->commands);

				if(parsedCmd.hasError)
				{
					cout << "error" << endl;
				}
				else if(parsedCmd.isredirect)
				{
					FileOutput out(parsedCmd.outputFile, parsedCmd.append);

					out.write( parsedCmd.command->execute() );
				}
				else
				{
					cout << parsedCmd.command->execute();
				}
			}
		}
	};
};
