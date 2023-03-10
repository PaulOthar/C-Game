#include <stdlib.h>
#include <stdio.h>

#include "StatsBearer.h"

StatsBearer* new_StatsBearer(char* Name_Reference){
    StatsBearer* output = (StatsBearer*)malloc(sizeof(StatsBearer));

    output->name = Name_Reference;

    output->level = 0;
    output->pointsPerLevel = 0;

    output->aptitudes = (int*)malloc(sizeof(int)*8);
    output->stats = (int*)malloc(sizeof(int)*8);

    int empty[] = {0,0,0,0,0,0,0,0};

    set_StatsBearer_Aptitudes(output,empty);
    set_StatsBearer_Stats(output,empty);

    return output;
}

void set_StatsBearer_Aptitudes(StatsBearer* input,int apt[]){
    int i = 0;
    for(i = 0;i<8;i++){
        input->aptitudes[i] = apt[i];
    }
}

void set_StatsBearer_Stats(StatsBearer* input,int stts[]){
    int i = 0;
    for(i = 0;i<8;i++){
        input->aptitudes[i] = stts[i];
    }
}

void free_StatsBearer(StatsBearer* input){
    //free(input->name);
    //free(input->level);
    //free(input->pointsPerLevel);
    free(input->aptitudes);
    free(input->stats);
}

void print_StatsBearer_StatsArray(int toPrint[],char* symbol){
    int i = 0;
    char *tags[] = {"HP:","SP:","ATK:","DEF:","ARC:","RES:","WG:","MN:"};

    for(i=0;i<8;i++){
        if(i%2>0){
            printf("\t");
        }

        printf("%s%d%c",tags[i],toPrint[i],*symbol);
        
        if(i%2>0){
            printf("\n");
        }
    }
}

void print_StatsBearer(StatsBearer* toPrint){
    printf("Name:%s\nLevel:%d\nPoints Per Level:%d",toPrint->name,toPrint->level,toPrint->pointsPerLevel);
    printf("\n\nAptitudes:\n");
    print_StatsBearer_StatsArray(toPrint->aptitudes,"%%");
    printf("\n\nStats:\n");
    print_StatsBearer_StatsArray(toPrint->stats,".");
}

void calculateStatsTotal_StatsBearer(StatsBearer* input){
    int i = 0;
    int totalLevelPoints = (input->level) * (input->pointsPerLevel);

    int apt = 0;
    for(i = 0;i<8;i++){
        apt = input->aptitudes[i];
        input->stats[i] = ((apt) * (totalLevelPoints))/100;
    }
}