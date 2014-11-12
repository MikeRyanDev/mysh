#include "parser.h"

Parser::~Parser(){
	
splcmd = NULL; // sets pointer back to NULL
}

Parser::Parser(string cmdBlock, Commander &commands){
	
	strcpy(line, cmdBlock.c_str()); //converts cmdBlock into line array
        splcmd = strtok(line," "); // assigns a word from the command input to splcmd

	 // Goes through cmdBlock and add each word to the queue
                while(splcmd != NULL)   //each loop cycle assigns a word to the queue
        {
                cmdQueue.push(splcmd);
                splcmd = strtok(NULL," ");
        };


        // Resolve the queue by building out cmdName, cmdArgs, and cmdFlags
         resolveQueue();

	// Try to resolve the command from the cmd IOC
	try{
		this->command = commands->resolve( this->cmdName, this->cmdArgs, this->cmdFlags );
	}
	catch(const ShellError& resolutionError){
		this->hasError = true;
		this->error = resolutionError;
	}
}

void Parser::resolveQueue(){
	cmdName = cmdQueue.front(); //first element is popped and assigned to cmdName
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
                                // Must be a set of flags. Add element to cmdFlags vector
                                cmdFlags.push_back(front);
                                cmdQueue.pop();

                                break;
                        case '>':
                                // Must be one of the output redirectors. Will add to cmdFlags vector
                                cmdFlags.push_back(front);
                                cmdQueue.pop();

                                // assume the next word on the queue is the filename
                                cmdArgs.push_back(cmdQueue.front());
                                keepResolving = false;
                                isredirect = true;
                                break;

                        //case '"':
                                // For fun, keep popping until you get to the
                                // closing string. Treat that as an argument.

                        default:
                                // Must be an argument
                                cmdArgs.push_back(front);
                                cmdQueue.pop();
                }
        }
        
        /* The check for a C program as the command*/

        strcpy(line, cmdName.c_str());  //converts cmdName into line array
        strtok(line,".");
        splcmd = strtok(NULL,".");      //gets the extension of the file; if there is one

        if((splcmd = "c")||(splcmd = "cpp"))
                iscfile = true;
        


}
