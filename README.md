mysh
====

Project for Unix Programming.

## Authors

* Landan Young Jackson <lmj0011@uah.edu>

* Andrew Webb <adw0022@uah.edu>

* Jacob <jak0013@uah.edu>

* Julian Sy <jns0019@uah.edu>

* Mike Ryan <mar0018@uah.edu>

## Concepts

This take on the mysh project employs a number of different concepts to meet the project requirements:

### No Regular Expressions

Instead of using regular expressions to parse commands entered in our shell, commands are broken into words and pushed onto a queue where each word is resolved one by one. For instance, the following command:

    ls ~ -l >> output.txt

would create a queue that looks like this:

1. ls
2. ~
3. -l
4. >>
5. output.txt

During parsing, we assume that the top of the queue is the command name. Then, as we resolve the queue we determine whether the string being parsed is a flag, argument, or operator by looking at the first two characters.

### Specific classes for each command

To keep code clean, maintainable, and most importantly testable, we have broken each command out into their own classes. Each of these inherit from a parent Command class.

### Use inversion of control to resolve command classes

In order to make our shell extensible, we have implemented a very basic IOC container. Basically, when we implement a new Command class, we register it with the command IOC. When a command is parsed in our shell, we first try to resolve a command class from this IOC. If we haven't implemented the class yet, the command is instead executed externally.
