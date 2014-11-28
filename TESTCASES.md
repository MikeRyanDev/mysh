# Test Cases

### Works as intended:
1. Shell prompt should always be in the form of `[shell name]> ` (note trailing whitespace)
2. Name of shell prompt should be changeable via `name [newName]`
3. Shell should support commands AT LEAST 256 characters long
4. Commands should be able to be run separately if semicolon delimitted: `cd; cd; pwd; exit;`
5. Whitespace at the beginning, in the middle, or at the end of a command should be ignored
6. Running `exit` in the shell exits the program
7. Using `exit` in a batch file should end batch mode
8. Running `ver` should output the version number and date
9. Running `cd` should change the current working directory to the user's $HOME directory
10. Running `cd [directory name]` should change the working directoy to the specified directory or throw an error
11. Running `pwd` should print the current working directory
12. Running `name` without specifying a new name should throw an error
13. Commands not recognized by the internal parser should be executed in a separate process as an external command
14. Shell should be able to parse output redirectors `>` and `>>`
15. If there is no argument after an output redirector, the shell should throw an error
16. If the argument after an output redirector cannot be read, the shell should throw an error
17. The output redirector `>` should overwrite the contents of the output file
18. The output redirector `>>` should append output to the output file
19. The quick compile command should be resolved for all `.C` and `.CPP` files
20. The quick compile command should attempt to compile `.C` files using `gcc`
21. The quick compile command should attempt to compile `.CPP` files using `g++` and the C++11 standard
22. Arguments specified after a `.C` or `.CPP` file should be passed as arguments to the compiled executable
23. When an error is detected, `mysh: Error detected` should be printed to the screen
24. Running mysh by specifying an input file should cause the shell to be run in batch mode


### Does not work / ignored
1. If the quick compile command does not successfully compile the C/C++ program, an internal shell error should be generated
2. If the quick compile command does not successfully compile the C/C++ program, it should not attempt to execute it