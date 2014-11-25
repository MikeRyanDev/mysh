#include <string>
#include <vector>

using namespace std;

class Command
{
private:
	vector<string> arguments;
	vector<char> flags;
public:
	Command( vector<string> args ){

	}
	virtual string execute();
};
