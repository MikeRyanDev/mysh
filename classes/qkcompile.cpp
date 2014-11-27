//***********************************************************//
//	File: qkcompile.cpp
//	Author: Landan M Young Jackson
//***********************************************************//
#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h> /*for fork*/
#include <sys/types.h> /*for pid_t*/
#include <sys/wait.h> /*for wait*/
#include "command.cpp"
#include <string>
#include <vector>

#define MAX_CHARS 257

using namespace std;


class qkcompile : public Command{



private:

string cmd_blk1; 	//command block #1 - command for compiling with gcc/g++
string cmd_blk2; 	//command block #2 - command for calling the newly compiled program
string base_name;	// file name without the extension
string c_type;		//file type (c or cpp)
string all_args;	//string containing all arguments seperated by whitespace
string all_flags;	//string containing all arguments seperated by whitespace


public:

//***********************************************************//
//	qkcompile Class Overloaded Constructor - qkcompile()
//	args: none
//	return: none
//	description: will assign values to the member vars
//	command, vec_args, vec_flgs.
//***********************************************************//
qkcompile(string command, vector<string> arguments, vector<string> flags) : Command(arguments)
{
	set_base_name(command);
	get_flgs(flags);
	get_args(arguments);

	create_command_blocks(command, all_flags, all_args);

	
	script_call();

}


//***********************************************************//
//	qkcompile Class Deconstructor - ~qkcompile()
//	args: none
//	return: none
//	description: deconstructor
//***********************************************************//
~qkcompile()
{

}



private:


//***********************************************************//
//	qkcompile Class function - create_command_blocks()
//	args: string cmd, string flgs, string args
//	return: none
//	description: creates appropriate commands to compile C code
//***********************************************************//
void create_command_blocks(string cmd, string flgs, string args)
{
	if( c_type == "c")
	cmd_blk1 += "gcc "+ cmd +" -o "+ base_name; // the whitespaces are necessary here
	else
	cmd_blk1 += "g++ -std=c++11 "+ cmd +" -o "+ base_name; // the whitespaces are necessary here

	cmd_blk2 += "./"+ base_name + " " + flgs + " " + args;


}


//***********************************************************//
//	qkcompile Class function - set_base_name()
//	args: string command
//	return: none
//	description: strips the extension from a file name and assigns
//	it to the member var base_name.
//***********************************************************//
void set_base_name(string command)
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
void get_args(vector<string> arguments)
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
void get_flgs(vector<string> flags)
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





void script_call()
{

	system(cmd_blk1.c_str());
	system(cmd_blk2.c_str());
	
}

string execute()
{
	string output = "";

	return output;
}


}; //end of class
