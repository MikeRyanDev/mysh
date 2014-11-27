#pragma once

#include <string>

using namespace std;

/**
* Simple error class that gets thrown way too often. Example:
*
*     throw ShellError('Error Name', 'Description of error');
*
* or just:
*
*     throw ShellError();
*
* @class ShellError
* @module classes
*/
class ShellError
{
public:
	/**
	* The name of the error
	*
	* @property {string} name
	*/
	string name;

	/**
	* The error message
	*
	* @property {message} message
	*/
	string message;

	/**
	* Simple constructor that sets a default error name and message
	*
	* @constructor
	*/
	ShellError(){
		this->name = "mysh";
		this->message = "Error detected";
	};
	
	/**
	* Still simple constructor that lets you set a name and message
	*
	* @param {string} errorName The name of the error
	* @param {string} errorMessage A description of the error
	*/
	ShellError(string errorName, string errorMessage){
		name = errorName;
		message = errorMessage;
	};
};
