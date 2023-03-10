#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TerminalHandler.h"

const char* TERMINAL_HANDLER_RUN = "-r";
const char* TERMINAL_HANDLER_VERSION = "-v";
const char* TERMINAL_HANDLER_HELP = "-h";
const char* TERMINAL_HANDLER_MANUAL = "-m";

const char* TERMINAL_HANDLER_VERSION_CURRENT = "Pre-Alpha 0.0.1";

char* TERMNAL_HANDLER_MANUAL_INDEX = "index";
const char* TERMINAL_HANDLER_MANUAL_FOLDER = "manual/";
const char* TERMINAL_HANDLER_MANUAL_EXTENTION = ".txt";
const int TERMINAL_HANDLER_MANUAL_LINE_MAX_SIZE = 150;

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
        if(argc <= 2){
            return printManual(TERMNAL_HANDLER_MANUAL_INDEX);
        }
        return printManual(argv[2]);
    }

    return unknownArgument(argv[1]);
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
    printf("\nVersion:%s",TERMINAL_HANDLER_VERSION_CURRENT);
    printf("\n");
    printf("\nProgrammer/Artist/Writter\n\tPaulOthar : github.com/PaulOthar");
    printf("\n");
    printf("\nSpecial Contributors\n");
    printf("\nC Syntax Mentor\n\tHelder(Nempk1) = ADM Saphado : github.com/nempk1 | twitch.tv/nempk1");
    printf("\n");
    printf("\nIdea Validation & Creative Consultant\n\tDouglet(Gameplays & tutorials) : ???");

    //printf("\nVersion:\nAlpha 0.1\n\nAuthor:PaulOthar\n\nSpecial Thanks To:\nHelder(Vulgo nempk1)(AKA adm Saphado)\nDouglet Gameplays e Tutoriais");
    return 1;
}

int printHelp(){
    printf("'%s'\tRuns The Program\n",TERMINAL_HANDLER_RUN);
    printf("'%s'\tShows the Current Version\n",TERMINAL_HANDLER_VERSION);
    printf("'%s'\tShows this Screen\n",TERMINAL_HANDLER_HELP);
    printf("'%s ?'\tShows the Details of Something",TERMINAL_HANDLER_MANUAL);
    printf("\n\nKeep in mind that the '%s' argument draws information from the local '%s' folder.",TERMINAL_HANDLER_MANUAL,TERMINAL_HANDLER_MANUAL_FOLDER);
    printf("\nIf you want to include a new information, make sure to update the '%s%s' file, and have it as '%s'",TERMNAL_HANDLER_MANUAL_INDEX,TERMINAL_HANDLER_MANUAL_EXTENTION,TERMINAL_HANDLER_MANUAL_EXTENTION);
    return 1;
}

int printManual(char* arg){
    FILE *fptr;

    char pth[20];

    strcpy(pth,TERMINAL_HANDLER_MANUAL_FOLDER);

    char* path = strcat(pth,arg);
    path = strcat(path,TERMINAL_HANDLER_MANUAL_EXTENTION);

    fptr = fopen(path, "r");

    if (fptr == NULL) {
        printf("There is no Manual for %s",arg);
        return 2;
    }

    char mymanual[TERMINAL_HANDLER_MANUAL_LINE_MAX_SIZE];

    while(!feof(fptr)){
    fgets(mymanual,TERMINAL_HANDLER_MANUAL_LINE_MAX_SIZE,fptr);

    printf("%s",mymanual);
    }

    fclose(fptr);

    return 2;
}
