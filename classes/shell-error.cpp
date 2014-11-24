#include <string>

using namespace std;

class ShellError
{
public:
	string name;
	string message;
	
	ShellError(string errorName, string errorMessage){
		name = errorName;
		message = errorMessage;
	
	};
};
