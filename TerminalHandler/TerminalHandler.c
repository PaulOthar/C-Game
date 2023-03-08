#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TerminalHandler.h"

const char* TERMINAL_HANDLER_RUN = "-r";
const char* TERMINAL_HANDLER_VERSION = "-v";
const char* TERMINAL_HANDLER_HELP = "-h";
const char* TERMINAL_HANDLER_MANUAL = "-m";

int handleArgs(int argc,char *argv[]){
    if(argc <= 1){
        return noArgument();
    }

    if(strcmp(argv[1],TERMINAL_HANDLER_RUN) == 0){
        return run();
    }
    if(strcmp(argv[1],TERMINAL_HANDLER_VERSION) == 0){
        return printVersion();
    }
    if(strcmp(argv[1],TERMINAL_HANDLER_HELP) == 0){
        return printHelp();
    }
    if(strcmp(argv[1],TERMINAL_HANDLER_MANUAL) == 0){
        return printManual(argv[2]);
    }

    return unknownArgument(argv[1]);

    /*
    switch(argv[1]){
        case TERMINAL_HANDLER_RUN:
            return run();
        default:
            return 
    }
    */
}

int noArgument(){
    printf("Please, use an argument:\n'%s' to run the program\n'%s' to see all avaliable basic commands",TERMINAL_HANDLER_RUN,TERMINAL_HANDLER_HELP);
    return -1;
}

int unknownArgument(char* arg){
    printf("Argument '%s' Does not Exist.\nPlease use '%s' to list all basic commands.",arg,TERMINAL_HANDLER_HELP);
    return -1;
}

int run(){
    printf("Running\n");
    return 0;
}

int printVersion(){
    printf("Version:\nAlpha 0.1\n\nAuthor:PaulOthar\n\nSpecial Thanks To:\nnempk1(Vulgo Helder)(AKA adm Saphado)\nDouglet Gameplays e Tutoriais");
    return 1;
}

int printHelp(){
    printf("'%s'\tRuns The Program\n",TERMINAL_HANDLER_RUN);
    printf("'%s'\tShows the Current Version\n",TERMINAL_HANDLER_VERSION);
    printf("'%s'\tShows this Screen\n",TERMINAL_HANDLER_HELP);
    printf("'%s ?'\tShows the Details of Something",TERMINAL_HANDLER_MANUAL);
    return 1;
}

int printManual(char* arg){
    printf("Non conhezo '%s'",arg);
    return 2;
}
