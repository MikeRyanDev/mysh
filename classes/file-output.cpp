#pragma once
#include <fstream>
#include <string>
#include "shell-error.cpp"

using namespace std;

/**
* Simple wrapper class that provides file output. Can be set to overwrite
* append contents to a text file.
*
* @class FileOutput
* @module classes
*/
class FileOutput
{
public:
	/**
	* The name of the output file
	*
	* @property {string} outf
	*/
	string outf;

	/**
	* Determines rather output should append or overwrite output file's contents
	*
	* @property {boolean} append
	*/
	bool append;

	/**
	* Instantiates the FileOutput class
	*
	* @constructor
	* @param {string} outputFile The name of the output file
	* @param {bool} appendOutputToFile Whether output should be appended or not
	*/
	FileOutput( string outputFile, bool appendOutputToFile ){
		outf = outputFile;
		append = appendOutputToFile;
	}

	/**
	* Method to cause the write operation
	*
	* @method write
	* @param {string} output The output string to write to the file
	*/
	void write( string output ){
		fstream fs;

		if(append)
		{
			fs.open(outf, fstream::in | fstream::out | fstream::app);
		}
		else
		{
			fs.open(outf, fstream::in | fstream::out | fstream::trunc);
		}

		if( fs.good() )
			fs << output;
		else
			throw ShellError();

		fs.close();
	}
};