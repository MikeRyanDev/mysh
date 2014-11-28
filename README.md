<<<<<<< HEAD
Failsafe in case the overly ambitious shell doesn't work out
=======
mysh
====

Project for Unix Programming.

## Authors

* Landan Young Jackson <lmj0011@uah.edu>

* Andrew Webb <adw0022@uah.edu>

* Jacob <jak0013@uah.edu>

* Julian Sy <jns0019@uah.edu>

* Mike Ryan <mar0018@uah.edu>

## Building mysh

To build mysh, you'll need a version of G++ that has full support for the C++11 standard. If you want to build the docs, you'll need to have nodejs installed on your machine with access to npm.

### Building the shell

1. Pull the latest version of mysh: `git clone https://github.com/MikeRyan52/mysh.git mysh`
2. Change into the mysh directory: `cd mysh`
3. Run make: `make`
4. You'll be prompted to enter the directory where you want mysh to be built. Simply put `.` to select the current directory
5. Run `./mysh` to launch the shell

### Building the docs

1. From your mysh directory, run `make docs`
2. This will create a documentation web app in the `./docs` folder. 
3. To view the docs, simply launch `./docs/index.html` in your web browser

## More Information
For more information regarding the concepts of building our version of mysh, checkout the [project's homepage](https://mikeryan52.github.io/mysh) or a presentation [on the shell](https://mikeryan52.github.io/mysh/slides.html)

### Extra credit features

1. Change the name of the shell by running `name (newName)`. For example, running `name john` will result in `mysh> ` becoming `john> `
2. Batch file mode, executed by running `./mysh [batchFile]`
3. Semi-colon delimitted commands, like `cd; pwd; ver; exit`
>>>>>>> 9b4b047eca5c2ba0ba8db3e741b2501d99b9cc37
