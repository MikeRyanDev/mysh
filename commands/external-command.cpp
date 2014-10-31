// Note: Here's my rough draft for the external command feature.
// I have not compiled this yet. Let me know if there's anything 
// that should be changed design-wise or syntax-wise. -Julian

#include <unistd.h>
#include <dirent.h>

using namespace std;

class ExternalCommand: public Command{
public:
	//Initializes attributes with the corresponding arguments
	ExternalCommand(string cmd, vector<string> args, vector<char> flags) : _cmd(cmd), _args(args), _flags(flags){
		setPaths();

		//executes command
		execute();
	}
private:
void execute(){
	//Gets strings for command
	string path = getPath(), args = getArgs(), flags = getFlags();
	//Checks if path was found by getPath()
	if(path.empty()){
		cout << "_cmd" << ": command not found\n";
		return;
	}
	string fullCommand = path + _cmd + " " + args + flags; 

	//forks process
	int id = fork();

	//if process is child, execute full command
	if(fork == 0) execlp(fullCommand, _cmd, NULL);
}

string getPath(){
	//gets correct path to executable into a string
	string ps;	
	//Iterate through _paths vector
	vector<string>::iterator i;
	for(i = _paths.begin() ; i != _paths.end() ; i++){
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir (*i)) != NULL) {
		 	//look at each file in dir 
		  	while ((ent = readdir (dir)) != NULL) {
		    	//check if executable is there
		    	if(_cmd.compare(ent->d_name)){
		    		//copies path to return
		    		ps = (*i);
		    		break;
		    	}
	 	  	}
  		closedir (dir);
		}
	}
	return ps;
}

string getArgs(){
	//gets all arguments into a single string
	string as;
	vector<string>::iterator i;
	for(i = _args.begin() ; i != _args.end() ; i++){
		as.push_back(*i);
		as.push_back(' ');
	}
	return as;
}

string getFlags(){
	//gets all flags into a single string	
	string fs;
	if(_flags.empty()) return "";

	//I'm assuming flags look like "-a" or "-flag"
	vector<string>::iterator i;
	for(i = _flags.begin() ; i != _flags.end() ; i++){
		fs.push_back(*i);
		fs.push_back(' ');
	}
	return fs;	
}

void setPaths(){
	string ps = getenv("PATH"));
	string *p = new string();
	char dl = ":"; //delimiter

	_paths.push_back(*p);
	//Iterates through PATH 
	for(int i = 0; i != '\0'; i++){
		//If delimiter found create new string and push back to _paths
		if(i == dl){
			p = new string();
			_paths.push_back(*p);
		//If non-delimiter, push char back to current string
		} else{
			p->push_back(*i);
		}
	}
}

private:
string		 	_cmd;
vector<string> 	_paths;	
vector<string> 	_args;
vector<char>   	_flags;
};
