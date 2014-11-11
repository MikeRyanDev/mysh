#include "ExternalCommand.cpp"
#include <stdio.h>

int main(){


  string cmd;
  vector<string> args;
  vector<char> flags;

  cmd = "ls";
  args.push_back("~");
  flags.push_back('l');

  ExternalCommand *ec = new ExternalCommand(cmd, args, flags);
  ec->execute();
  return 0;
}