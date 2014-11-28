#pragma once
#include "parser.cpp"
#include "file-output.cpp"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

/**
* Class that reads commands from the shell or a batch file and handles
* their lifecycle
*
* @class Shell
* @module classes
*/
class Shell
{
public:
	/**
	* The name of the currently active shell, default is `mysh`
	*
	* @property {string} shellName
	*/
	string shellName = "mysh";

	/**
	* Runs the shell. If there is not a batch file supplied to the shell at the beginning
	* of execution, the shell runs interactively.
	*
	* @method run
	* @param {int} argc The count of arguments supplied to mysh. Always at least one.
	* @param {array} argv The arguments supplied to mysh. First argument is always the name of the executable.
	*/
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
	
	/**
	* Provides a very simple REPL to the user at the shell
	*
	* @method runInteractively
	*/
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

	/**
	* Loops through a batchfile and executes each line
	*
	* @method runBatchFile
	* @param {string} fileName The name of the batchfile to execute
	*/
	void runBatchFile(string fileName){
		string output = "";
		string line;
		ifstream infile(fileName);
		bool stop = false;

		if(! infile)
		{
			cout << "mysh: Error detected" << endl;
			stop = true;
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

	/**
	* Takes a line of semi-colon delimitted commands and creates parsers for each of them.
	* Then, executes each command and either prints the result to the screen or to an output
	* file
	*
	* @method executeCommand
	* @param {string} cmdBlock The line of semi-colon delimitted commands
	* @return {bool} Whether any of the executed commands returned an exit signal
	*/
	bool executeCommand(string cmdBlock){
		regex re("[;]+");
		sregex_token_iterator it(cmdBlock.begin(), cmdBlock.end(), re, -1);
		sregex_token_iterator reg_end;
		bool foundExit = false;

		for(; it != reg_end; ++it)
		{
			string trimmed = it->str();
			const auto strBegin = it->str().find_first_not_of(" \t");
			if (strBegin != string::npos){

				const auto strEnd = trimmed.find_last_not_of(" \t");
				const auto strRange = strEnd - strBegin + 1;

				trimmed = trimmed.substr(strBegin, strRange);
			}

			try{
				Parser parsedCmd(trimmed);
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
