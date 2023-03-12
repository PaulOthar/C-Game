#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TerminalHandler.h"

const char* TERMINAL_HANDLER_RUN = "-r";
const char* TERMINAL_HANDLER_HELP = "-h";
const char* TERMINAL_HANDLER_VERSION = "-v";
const char* TERMINAL_HANDLER_MANUAL = "-m";

const char* TERMINAL_HANDLER_EXTENTION = ".txt";

const char* TERMINAL_HANDLER_DATA_FOLDER = "data/";
const char* TERMINAL_HANDLER_MANUAL_FOLDER = "manual/";

const char* TERMINAL_HANDLER_VERSION_FILE = "version";
const char* TERMINAL_HANDLER_CREDITS = "credits";
char* TERMINAL_HANDLER_INDEX = "index";

const int TERMINAL_HANDLER_LINE_MAX_SIZE = 150;

const char* TERMINAL_HANDLER_NO_ARGUMENT = "Please, use an argument:\n'%s' to run the program\n'%s' to see all avaliable basic arguments";
const char* TERMINAL_HANDLER_UNKNOWN_ARGUMENT = "Argument '%s' does not exist.\nPlease use '%s' to list all basic arguments.";
const char* TERMINAL_HANDLER_HELP_RUN = "'%s'\tRuns the program\n";
const char* TERMINAL_HANDLER_HELP_HELP = "'%s'\tPrints this screen\n";
const char* TERMINAL_HANDLER_HELP_VERSION = "'%s'\tPrints the current version, and its contributors\n";
const char* TERMINAL_HANDLER_HELP_MANUAL = "'%s ?'\tPrints the manual for something\n";

int handleArgs(int argc,char *argv[]){
    if(argc <= 1){
        return noArgument();
    }

    if(strcmp(argv[1],TERMINAL_HANDLER_RUN) == 0){
        return run();
    }
    if(strcmp(argv[1],TERMINAL_HANDLER_HELP) == 0){
        return printHelp();
    }
    if(strcmp(argv[1],TERMINAL_HANDLER_VERSION) == 0){
        return printVersion();
    }
    if(strcmp(argv[1],TERMINAL_HANDLER_MANUAL) == 0){
        if(argc <= 2){
            return printManual(TERMINAL_HANDLER_INDEX);
        }
        return printManual(argv[2]);
    }

    return unknownArgument(argv[1]);
}

int noArgument(){
    printf(TERMINAL_HANDLER_NO_ARGUMENT,TERMINAL_HANDLER_RUN,TERMINAL_HANDLER_HELP);
    return -1;
}

int unknownArgument(char* arg){
    printf(TERMINAL_HANDLER_UNKNOWN_ARGUMENT,arg,TERMINAL_HANDLER_HELP);
    return -1;
}

int run(){
    printf("Running\n");
    return 0;
}

int printHelp(){
    printf(TERMINAL_HANDLER_HELP_RUN,TERMINAL_HANDLER_RUN);
    printf(TERMINAL_HANDLER_HELP_HELP,TERMINAL_HANDLER_HELP);
    printf(TERMINAL_HANDLER_HELP_VERSION,TERMINAL_HANDLER_VERSION);
    printf(TERMINAL_HANDLER_HELP_MANUAL,TERMINAL_HANDLER_MANUAL);
    return 1;
}

int printFile(char* path,char* notFound){
    FILE *fptr;

    fptr = fopen(path, "r");

    int status = 0;

    if(fptr != NULL){
        status = 1;
        char content[TERMINAL_HANDLER_LINE_MAX_SIZE];

        printf("\n");
        while(!feof(fptr)){
            fgets(content,TERMINAL_HANDLER_LINE_MAX_SIZE,fptr);

            printf("%s",content);
        }
        printf("\n");
    }
    else{
        if(notFound != NULL){
            printf("%s",notFound);
        }
    }

    fclose(fptr);
    return status;
}

int printVersion(){
    char pth[200];

    strcpy(pth,TERMINAL_HANDLER_DATA_FOLDER);
    strcat(pth,TERMINAL_HANDLER_VERSION_FILE);
    strcat(pth,TERMINAL_HANDLER_EXTENTION);

    printFile(pth,"\nVersion file not found :(\n");

    strcpy(pth,TERMINAL_HANDLER_DATA_FOLDER);
    strcat(pth,TERMINAL_HANDLER_CREDITS);
    strcat(pth,TERMINAL_HANDLER_EXTENTION);

    printFile(pth,"\nCredits file not found :(\n");

    return 1;
}

int printManual(char* arg){
    char pth[200];

    strcpy(pth,TERMINAL_HANDLER_DATA_FOLDER);
    strcat(pth,TERMINAL_HANDLER_MANUAL_FOLDER);
    strcat(pth,arg);
    strcat(pth,TERMINAL_HANDLER_EXTENTION);

    if(printFile(pth,NULL) == 0){
        strcpy(pth,TERMINAL_HANDLER_DATA_FOLDER);
        strcat(pth,TERMINAL_HANDLER_MANUAL_FOLDER);
        strcat(pth,arg);
        strcat(pth,"/");
        strcat(pth,TERMINAL_HANDLER_INDEX);
        strcat(pth,TERMINAL_HANDLER_EXTENTION);

        printFile(pth,"\nNo manual file or folder found :(\n");
    }

    return 1;
}