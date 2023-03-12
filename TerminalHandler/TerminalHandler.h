#ifndef TERMINAL_HANDLER
#define TERMINAL_HANDLER

int handleArgs(int argc,char *argv[]);

int noArgument();

int unknownArgument(char* arg);

int run();

int printHelp();

int printVersion();

int printManual(char* arg);

#endif