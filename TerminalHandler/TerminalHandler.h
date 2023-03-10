#ifndef TERMINAL_HANDLER
#define TERMINAL_HANDLER

/*
it will call other functions, if there is an argument.
if the user desires to run the program,
this function must return 0, othewise,
it will not run anything exept the specificed commands.
*/
int handleArgs(int argc,char *argv[]);

/*
Prints that the user need to use a argument, and prints the Help argument, then returns -1.
*/
int noArgument();

/*
Prints that the argument does not exist, and returns -1.
*/
int unknownArgument(char* arg);

/*
the only purpose of this function is to return 0.
*/
int run();

/*
Prints the current version on the console.
returns 1.
*/
int printVersion();

/*
Prints all avaliable Commands
returns 2.
*/
int printHelp();

/*
prints the details of one command
returns 3.
*/
int printManual(char* arg);

#endif