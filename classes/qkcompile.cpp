//***********************************************************//
//	File: qkcompile.cpp
//	Author: Landan M Young Jackson
//
//***********************************************************//

#include "qkcompile.h"






//***********************************************************//
//	qkcompile Class Constructor - qkcompile()
//	args: none
//	return: none
//	description: basic constructor
//***********************************************************//
qkcompile::qkcompile()
{


}




//***********************************************************//
//	qkcompile Class Overloaded Constructor - qkcompile()
//	args: none
//	return: none
//	description: will assign values to the member vars
//	command, vec_args, vec_flgs.
//***********************************************************//
qkcompile::qkcompile(string command, vector<string> arguments, vector<string> flags)
{
	set_base_name(command);
	get_flgs(flags);
	get_args(arguments);
	
	script_call();

}


//***********************************************************//
//	qkcompile Class Deconstructor - ~qkcompile()
//	args: none
//	return: none
//	description: decontructor
//***********************************************************//
qkcompile::~qkcompile()
{

}




//***********************************************************//
//	qkcompile Class function - set_base_name()
//	args: string command
//	return: none
//	description: strips the extension from a file name and assigns
//	it to the member var base_name.
//***********************************************************//
void qkcompile::set_base_name(string command)
{
	char str[MAX_CHARS] = {'\0'};
	string temp_name;

	strcpy(str,command.c_str());
	base_name = strtok(str,".");
	c_type = strtok(NULL,".");

}


//***********************************************************//
//	qkcompile Class function - get_args()
//	args: vector<string> arguments
//	return: none
//	description: combines all arguments from passed vector into 
//	a single string.
//***********************************************************//
void qkcompile::get_args(vector<string> arguments)
{
	string as;
	if(arguments.empty()) return;

	vector<string>::iterator i;
	for(i = arguments.begin() ; i != arguments.end() ; i++){
		as.append(*i);
		as.push_back(' ');
	}
	all_args = as;


}

//***********************************************************//
//	qkcompile Class function - get_flgs()
//	args: vector<string> flags
//	return: none
//	description: combines all flags from passed vector into
//	a single string
//***********************************************************//
void qkcompile::get_flgs(vector<string> flags)
{

	//gets all flags into a single string	
	string fs;
	if(flags.empty()) return;

	
	vector<string>::iterator i;
	for(i = flags.begin() ; i != flags.end() ; i++){
		fs.append(*i);
		fs.push_back(' ');
	}
	all_flags = fs;

}





void qkcompile::script_call()
{
	pid_t pid = fork();

	if (pid==0)
	{
		/*child process*/
		execlp("./qkcompile.sh","qkcompile.sh",base_name.c_str(),c_type.c_str(),all_flags.c_str(),all_args.c_str(),NULL);

	}
	else /*pid != 0; parent process*/
	{
		waitpid(pid,0,0);

	}

	return;

}
