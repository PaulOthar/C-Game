#include "StatsManipulation.h"

const int Bx3 = 20;
const int Bx2 = 15;
const int Bx1 = 10;
const int nil = 0;
const int dBx1 = -5;
const int dBx2 = -10;
const int dBx3 = -15;

const int materialAptitudes[][]{
    //hp    sp      atk     def     arc     res     wg
    {Bx2    ,dBx2   ,nil    ,nil    ,nil    ,nil    ,Bx1    ,nil},//Earth
    {dBx2   ,Bx2    ,nil    ,nil    ,nil    ,nil    ,dBx1   ,nil},//Air
    {nil    ,nil    ,dBx2   ,Bx2    ,nil    ,nil    ,Bx1    ,nil},//Cold
    {nil    ,nil    ,Bx2    ,dBx2   ,nil    ,nil    ,dBx1   ,nil},//Heat
    {nil    ,nil    ,nil    ,nil    ,dBx2   ,Bx2    ,Bx1    ,nil},//Life
    {nil    ,nil    ,nil    ,nil    ,Bx2    ,dBx2   ,Bx1    ,nil},//Death
    {Bx3    ,nil    ,Bx3    ,nil    ,nil    ,dBx3   ,Bx3    ,nil},//Light
    {nil    ,Bx3    ,nil    ,dBx3   ,Bx3    ,nil    ,dBx3   ,nil},//Dark
    {Bx1    ,Bx1    ,nil    ,nil    ,nil    ,nil    ,Bx1    ,nil},//Nickel
    {Bx2    ,nil    ,Bx1    ,Bx2    ,nil    ,nil    ,Bx1    ,nil},//Copper
    {Bx2    ,nil    ,Bx2    ,Bx1    ,nil    ,nil    ,Bx2    ,nil},//Iron
    {nil    ,Bx2    ,nil    ,nil    ,Bx1    ,Bx2    ,Bx1    ,nil},//Cobalt
    {nil    ,Bx2    ,nil    ,nil    ,Bx2    ,Bx1    ,Bx2    ,nil},//Silver
    {dBx3   ,nil    ,Bx3    ,nil    ,Bx3    ,nil    ,Bx3    ,nil},//Gold
    {Bx3    ,Bx3    ,nil    ,nil    ,nil    ,nil    ,Bx3    ,nil}//Platnum

    /*
    Common:Earth,Air,Cold,Heat,Nickel,Copper
    Uncommon:Life,Death,Iron,Cobalt
    Rare:Light,Dark,Silver,Gold
    Ultra Rare:Platnum
    */
}

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

void processMaterial_AbilityBearer(AbilityBearer* input){
    int m = 0;
    int ab = 0;
    for(m = 0;m<ABILITY_MANIPULATION_MATERIAL_SIZE;m++){
        for(ab = 0;ab<ABILITY_MANIPULATION_ABILITY_SIZE;ab++){
            input->aptitudes[ab] += materialAptitudes[m][ab] * input->material[m];
        }
    }
}