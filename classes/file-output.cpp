#pragma once
#include <fstream>
#include <string>
#include "shell-error.cpp"

using namespace std;

class FileOutput
{
public:
	string outf;
	bool append;

	FileOutput( string outputFile, bool appendOutputToFile ){
		outf = outputFile;
		append = appendOutputToFile;
	}

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
			fs << endl << output;
		else
			throw ShellError();

		fs.close();
	}
};