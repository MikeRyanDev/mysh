#pragma once
#include "commander.cpp"
#include "parser.cpp"
#include "file-output.cpp"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

class Shell
{
public:
	Commander commands;
	string shellName = "mysh";

	void run(int argc, char* argv[]){
		if(argc >= 2)
		{
			string inputFile(argv[1]);

			this->runBatchFile( inputFile.substr(1, inputFile.length() - 2) );
		}
		else
		{
			this->runInteractively();
		}
	};
	
	
	void runInteractively(){
		
		string cmdBlock;
		bool stop = false;

		while(! stop){
			cout << this->shellName << "> ";
			getline(cin, cmdBlock);

			if(cmdBlock.length() != 0)
			{
				stop = this->executeCommand(cmdBlock);
			}
		}
	};

	void runBatchFile(string fileName){
		string output = "";
		string line;
		ifstream infile(fileName);
		bool stop = false;

		if(! infile)
		{
			cout << "mysh: Error detected" << endl;
			exit(0);
		}

		while(getline(infile, line) && ! stop)
		{
			if(line.length() != 0)
			{
				cout << line << endl;
				stop = this->executeCommand(line);
			}

		}
	};

	bool executeCommand(string cmdBlock){
		regex re("[;]+");
		sregex_token_iterator it(cmdBlock.begin(), cmdBlock.end(), re, -1);
		sregex_token_iterator reg_end;
		bool foundExit = false;

		for(; it != reg_end; ++it)
		{
			try{
				Parser parsedCmd(it->str());
				string output = parsedCmd.command->execute();

				if(parsedCmd.isRedirect)
				{
					FileOutput out(parsedCmd.outputFile, parsedCmd.append);

					out.write( output );
				}
				else
				{
					cout << output;
				}

				if( parsedCmd.command->shouldExit ){
					foundExit = true;
					break;
				}
			}
			catch(const ShellError& executionError)
			{
				cout << executionError.name << ": " << executionError.message << endl;
			}
		}

		return foundExit;
	};
};
