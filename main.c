#include <stdlib.h>
#include <stdio.h>

#include "TerminalHandler/TerminalHandler.h"

int main(int argc, char *argv[]){
    if(handleArgs(argc,argv) != 0){
        printf("\n");
        return 0;
    }

    return 0;
}