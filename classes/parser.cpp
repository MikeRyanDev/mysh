#pragma once

#include "command.cpp"
#include "commander.cpp"
#include "shell-error.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <cstring> //needed for linux
#define MAX_CHAR 257 //defines the max chars in a char array


using namespace std;

class Parser
{
private:
    /**
    * The entire line entered at the shell
    *
    * @property {string} cmdBlock
    */
    string cmdBlock;

    /**
    * Parsed name of the command
    *
    * @property {string} cmdName
    */
    string cmdName;

    /**
    * Parsed list of the command's arguments
    *
    * @property {vector<string>} cmdArgs
    */
    vector<string> cmdArgs;

    /**
    * Parsed list of the command's flags
    *
    * @property {vector<string>} cmdFlags
    */
    vector<string> cmdFlags;

    /**
    * Queue of each 'word' in the command block
    *
    * @property {queue<string>} cmdQueue
    */
    queue<string> cmdQueue;

    /**
    * Pointer that will point to one "string" at a time
    *
    * @property {c string} splcmd
    */
    char *splcmd;

    /**
    * The input line (redundant)
    *
    * @property {c str} line
    */
    char line[MAX_CHAR];

    /**
    * Flag determining whether the parser should keep resolving the queue
    *
    * @property {boolean} keepResolving
    */
    bool keepResolving;
    void resolveQueue(){
        this->cmdName = cmdQueue.front();
        cmdQueue.pop();

        keepResolving = true;
        isredirect = false;
        iscfile = false;

        while(cmdQueue.size() > 0 && keepResolving)
        {
            string front = cmdQueue.front();

            switch(front.front())
            {
                case '-':
                    cmdFlags.push_back(front);
                    cmdQueue.pop();
                    break;
                case '>':
                    cmdFlags.push_back(front);
                    cmdQueue.pop();

                    cmdArgs.push_back(cmdQueue.front());
                    keepResolving = false;
                    isredirect = true;
                    break;
                default:
                    cmdArgs.push_back(front);
                    cmdQueue.pop();
            }

            strcpy(line, cmdName.c_str());
            strtok(line, ".");
            splcmd = strtok(NULL, ".");

            if((splcmd = "c") || (splcmd = "cpp"))
                iscfile = true;
        }
    }
        
public:
    /**
    * The resolved command
    *
    * @property {Command} command
    */
    Command command;

    /**
    * Error object
    *
    * @property {ShellError} error
    */
    ShellError error;

    /**
    * Whether or not the parser has encountered an error
    *
    * @property {boolean} hasError
    */
    bool hasError;

    /**
    * Determine whether or not the command is a redirection
    *
    * @property {boolean} isredirect
    */
    bool isredirect;

    /**
    * Determine whether or not the command is a C/CPP file
    *
    * @property {boolean} iscfile
    */
    bool iscfile;

    
    Parser(string cmdBlock, Commander &commands){
        strcpy(line, cmdBlock.c_str()); // converts cmdBlock into line array
        splcmd = strtok(line," "); // assigns a word from the command input to the splcmd

        while(splcmd != NULL)
        {
            cmdQueue.push(splcmd);
            splcmd = strtok(NULL," ");
        };

        resolveQueue();

        try{
            this->command = commands->resolve( this->cmdName, this->cmdArgs, this->cmdFlags );
        }
        catch(const ShellError& resolutionError){
            this->hasError = true;
            this->error = resolutionError;
        }
    }
    ~Parser(){
        this->splcmd = NULL;
    }
};
