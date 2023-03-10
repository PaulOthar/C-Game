#include <stdlib.h>
#include <stdio.h>

#include "TerminalHandler/TerminalHandler.h"

int main(int argc, char *argv[]){
    if(handleArgs(argc,argv) != 0){
        printf("\n");
        return 0;
    }

    int i = 0;
    for(i = 0;i<argc;i++){
        printf("%s\n",argv[i]);
    }

    return 0;
}