#pragma once

#include <string>

using namespace std;

class ShellError
{
public:
	string name;
	string message;

	ShellError(){
		this->name = "mysh";
		this->message = "Error detected";
	};
	
	ShellError(string errorName, string errorMessage){
		name = errorName;
		message = errorMessage;
	
	};
};
