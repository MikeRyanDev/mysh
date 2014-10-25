#incude "shell-error.h"
#include <string>

ShellError::ShellError(string errorName, string errorMessage){
	this->name = errorName;
	this->message = errorMessage;
}