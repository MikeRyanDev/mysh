#include <fstream>
#include <string>

using namespace std;

class FileOutput
{
public:
	string outf;
	boolean append;

	FileOutput( string outputFile, boolean appendOutputToFile ){
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

		fs << output;

		fs.close();
	}
}