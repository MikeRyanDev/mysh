#pragma once

#include "command.cpp"
#include "commander.cpp"
#include "shell-error.cpp"
#include <string>
#include <vector>
#include <queue>
#include <cstring> //needed for linux
#define MAX_CHAR 257 //defines the max chars in a char array


using namespace std;

extern Commander commands;

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
                    cmdArgs.push_back(front);
                    cmdQueue.pop();
                    break;
                case '>':
                    if(front == ">" || front == ">>")
                    {
                        append = ( front == ">>" );
                        cmdQueue.pop();

                        outputFile = cmdQueue.front();
                        cmdQueue.pop();
                        keepResolving = false;
                        isredirect = true;
                    }
                    else
                    {
                        cmdArgs.push_back(front);
                        cmdQueue.pop();
                    }
                    break;
                default:
                    cmdArgs.push_back(front);
                    cmdQueue.pop();
            }
        }
    }
        
public:
    /**
    * The resolved command
    *
    * @property {Command} command
    */
    Command *command;

    /**
    * Determine whether or not the command is a redirection
    *
    * @property {boolean} isredirect
    */
    bool isredirect;

    /**
    * Determine whether redirection output should append or overwrite file
    *
    * @property {boolean} append
    */
    bool append;

    /**
    * Name of the file to redirect output to
    *
    * @property {string} outputFile
    */
    string outputFile;

    /**
    * Determine whether or not the command is a C/CPP file
    *
    * @property {boolean} iscfile
    */
    bool iscfile;

    
    Parser(string cmdBlock){
        strcpy(line, cmdBlock.c_str()); // converts cmdBlock into line array
        splcmd = strtok(line," "); // assigns a word from the command input to the splcmd

        while(splcmd != NULL)
        {
            cmdQueue.push(splcmd);
            splcmd = strtok(NULL," ");
        };

        resolveQueue();
        resolveCommand();        
    }
    
    void resolveCommand(){
        this->command = commands.resolve(this->cmdName, this->cmdArgs);
    }

    ~Parser(){
        this->splcmd = NULL;
    }
};
