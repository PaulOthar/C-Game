#include <stdlib.h>
#include <stdio.h>

#include "StatsBearer/StatsBearer.h"

void main(){
    StatsBearer* sb = new_StatsBearer("Jorge");
    sb->level = 10;
    sb->pointsPerLevel = 5;

    int apt[] = {100,120,50,60,0,0,10,15};

    set_StatsBearer_Aptitudes(sb,apt);
    calculateStatsTotal_StatsBearer(sb);

    print_StatsBearer(sb);

    free_StatsBearer(sb);
}