# mysh design implementation
### By Alex, Jacob, Julian, Landan, and Mike

---

# Software Engineering Approach for the Shell's Design

* Larger group let us focus on code structure and maintanability when creating our implementation of mysh
* We took an object-oriented approach and wrote our implementation in C++11

---

# Core Concepts

* Dependency Injection
* Inversion of Control
* Separation of Concerns

---

# Dependency Injection

* To put it simply, dependency injection (DI) let us write our application modularly
* Instead, a single, cental component knows about all other components
* If a component depends on other components, it can resolve these dependencies via the central component

---

# Inversion of Control

* The concept powering that "central component"
* We call this component our IoC container, and we register all available internal commands with the IoC container
* Our Parsers and Shell classes resolve commands from this IoC container
* Registering commands is really simple:

        class MyCommand : Command { /* Class Logic */ }
    
        int main(){
            // Register a command with the IoC
            IoC.commands.enlist("mycommand", MyCommand);
            
            // Resolving a command from the IoC
            IoC.commands.resolve("mycommand", /* constructor arguments */);
        }

---

# Separation of Concerns
* We knew that a solid, object-oriented approach to the software requirements would let us solve "hard" problems with ease
* Four main classes compose the core of our implementation of mysh:
    1. Shell
    2. Parser
    3. Command _(Parent class that all commands inherit form)_
    4. IoC Container
    5. Shell Error

---

# Shell Class
* Provides a very simple Read-Evaluate-Print Loop (REPL)
* When a user types in a command, the Shell creates a Parser to execute the typed command
* That's it! No more than 30 lines of code

---

# Parser Class
* This is where the bulk of our implementation's complexity exists
* Takes a command string like `ls -l >> files.txt` and parses it into blocks
* Instead of writing a regular expression for each command, we take a simpler approach
* Each "block" in the command string is added to a queue. After being parsed into a queue, the above command string would look like this:
    1. `ls`
    2. `-l`
    3. `>>`
    4. `files.txt`

* Top of the queue is expected to be the name of the command
* Each subsequent element in the queue is expected to be an argument and is added to a string vector
* When the parser hits an output operator like `>>`, it halts adding arguments to the string vector and changes output mode occordingly
* After parsing is completed, the parser sends the command name and arguments to the IoC container to resolve the command as an object, then executes it

---

# Command Class
* A template / parent class that forces a command to adhere to a standard API
* All commands implement the same constructor signature, where the constructor accepts a string vector of arguments as well as the original command string
* All commands implement an execute method that returns a string where that string is the output of executing the method
* Returning a string let's other parts of the application handle output, rather than the command objects

---

# IoC Container Class
* Implementation really isn't as complex as you would expect
* Each command is enlisted by storing the command name and the constructor of the class in a map
* Command resolution happens like this:
    1. Does the command name end in '.cpp' or '.c' ? Return a QuickCompile command
    2. Does the command name end in '.sh' ? Return a ShellScript command
    3. Does the map of internal commands contain the command name? Return the correct command
    4. If the command name does not satisfy any of the above conditions, return an External command

---

# Shell Error Class
* We heavily use C++'s `try`, `catch`, and `throw` syntax to make error handling clear and easy to use
* Normally, there would be a class for each error type the command might encounter
* Software requirements for mysh only required one error, and the output is the same for all errors, thus only one error handling class

---

# Reflections on Design
* Worked well for us when developing mysh
* Makes the codebase easy to ready and -- if required -- makes adding new functionality to the shell rather straightforward

---

# Regarding our Development Process
* Ended up using git as our version control system instead of Google Drive
* Git let us easily work on the same body of code without worrying about overwrites or merging
* Hosted our git repository on Github. Full source code and slides for our shell can be found at https://github.com/MikeRyanDesigns/mysh
* Github let us visually view changes in the source code as well as create issues that were assigned to team members throughout the lifecycle of the development process

---

# Demo
