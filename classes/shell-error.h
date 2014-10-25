#ifndef SHELLERROR_H
#define SHELLERROR_H
#include <string>

using namespace std;

class ShellError
{
public:
	string name;
	string message;
	ShellError(string errorName, string errorMessage);
};

#endif