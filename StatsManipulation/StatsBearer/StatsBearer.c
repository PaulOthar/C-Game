#include <stdlib.h>
#include <stdio.h>

#include "StatsBearer.h"

StatsBearer* new_StatsBearer(char* Name_Reference/*,int inv_width,int inv_height,int dim_width,int dim_heigth*/){
    StatsBearer* output = (StatsBearer*)malloc(sizeof(StatsBearer));
    int* apt = (int*)malloc(sizeof(int)*8);
    int* sts = (int*)malloc(sizeof(int)*8);
    /*
    CellGrid* cg = new_CellGrid(int inv_width,int inv_height);
    CellDimensions* cd = new_CellDimensions(int dim_width,int dim_heigth,0);
    StatsBearer** slt = (StatsBearer**)malloc(sizeof(StatsBearer*)*inv_width*inv_height);
    */

    if(output != NULL && apt != NULL && sts != NULL /*&& cg != NULL && cd != NULL && slt != NULL*/){
        output->name = Name_Reference;

        output->level = 0;
        output->pointsPerLevel = 0;
        output->aptitudes = apt;
        output->stats = sts;

        int empty[] = {0,0,0,0,0,0,0,0};

        set_StatsBearer_Aptitudes(output,empty);
        set_StatsBearer_Stats(output,empty);

        output->inventory = cg;
        output->occupation = cd;
        output->slotted = slt;

        output->slottedSize = inv_width*inv_height;
    }
    else{
        if(apt != NULL){
            free(apt);
        }
        if(sts != NULL){
            free(sts);
        }
        /*
        if(cg != NULL){
            free_CellGrid(cg);
        }
        if(cd != NULL){
            free_CellDimensions(cd);
        }
        if(slt != NULL){
            free(slt);
        }
        */
        if(output != NULL){
            free(output);
        }
    }

    return output;
}

void free_StatsBearer(StatsBearer* input){
    if(input != NULL){
        if(input->aptitudes != NULL){
            free(input->aptitudes);
        }
        if(input->stats != NULL){
            free(input->stats);
        }
        /*
        if(cg != NULL){
            free_CellGrid(cg);
        }
        if(cd != NULL){
            free_CellDimensions(cd);
        }
        if(slt != NULL){
            int i = 0;
            for(i = 0;i<input->slottedSize;i++){
                if(input->slotted[i] != NULL){
                    free(input->slotted[i]);
                }
            }
            free(slt);
        }
        */
        free(input);
    }
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