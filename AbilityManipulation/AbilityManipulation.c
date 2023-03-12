#include "StatsManipulation.h"

AbilityBearer* new_AbilityBearer(){
    AbilityBearer* output = (AbilityBearer*)malloc(sizeof(AbilityBearer));

    if(output != NULL){
        output->level = 0;
        output->pointsPerLevel = 0;

        int i = 0;

        for(i = 0;i<ABILITY_MANIPULATION_MATERIAL_SIZE;i++){
            output->material[i] = 0;
        }

        for(i = 0;i<ABILITY_MANIPULATION_ABILITY_SIZE;i++){
            output->aptitudes[i] = 0;
            output->abilities[i] = 0;
        }
    }

    return output;
}

void free_AbilityBearer(AbilityBearer* input){
    if(input != NULL){
        free(input);
    }
}