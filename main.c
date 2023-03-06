#include <stdlib.h>
#include <stdio.h>

#include "StatsBearer/StatsBearer.h"

int main(){
    StatsBearer* sb = new_StatsBearer("Jorge");
    if (!sb) {
        fprintf(stderr, "Uga.\n");
        return 1;
    }
    set_StatsBearer_Level(sb, 10);
    set_StatsBearer_PointsPerLevel(sb, 5);

    int apt[] = {100,120,50,60,0,0,10,15};

    if (!set_StatsBearer_Aptitudes(sb,apt)) {
        fprintf(stderr, "Bunga.\n");
        free_StatsBearer(sb);
        return 1;
    }

    calculateStatsTotal_StatsBearer(sb);

    print_StatsBearer(sb);

    free_StatsBearer(sb);
    return 0;
}
