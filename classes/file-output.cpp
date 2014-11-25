#include <fstream>
#include <string>

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

		fs << endl << output;

		fs.close();
	}
};