#include "parser.h"
#include "commander.h"
#include <string>
#include <vector>
#include "shell-error.h"
#include <regex>
#include <queue>

using namespace std;

Parser::Parser(string cmdBlock, Commander &commands){
	regex parserRegex("[^\\s]+");

	auto begin = sregex_iterator(cmdBlock.begin(), cmdBlock.end(), parserRegex);
	auto end = sregex_iterator();

	for(sregex_iterator i = begin; i != end; ++i)
	{
		smatch match = *i;
		this->cmdQueue.push(match.str());
	}

	this->resolveQueue();

	try{
		this->command = commands->resolve( this->cmdName, this->cmdArgs, this->cmdFlags );
	}
	catch(const ShellError& resolutionError){
		this->hasError = true;
		this->error = resolutionError;
	}
}

void Parser::resolveQueue(){
	this->cmdName = this->cmdQueue.front();
	this->cmdQueue.pop();
	bool keepResolving = true;

	while(this->cmdQueue.size() > 0 && keepResolving)
	{
		string front = this->cmdQueue.front();
		switch(front.front())
		{
			case '-':
				// Must be a set of flags
				// Add each individual character
				// to the flags vector
				break;
			case '<':
				// Must be one of the output redirectors.
				// Stop resolving the queue, determine which
				// kind of redirection is occuring, and then
				// assume the next word on the queue is the
				// filename
				keepResolving = false;
				break;
			case '"':
				// For fun, keep popping until you get to the
				// closing string. Treat that as an argument.
			default:
				// Must be an argument
				this->cmdArgs.push_back(front);
				this->cmdQueue.pop();
		}
	}
}