#ifndef STATS_BEARER
#define STATS_BEARER

typedef struct StsBrer{
    char* name;

    int level;
    int pointsPerLevel;

    //Arrays of Size 8
    int* aptitudes;
    int* stats;
} StatsBearer;

extern StatsBearer* new_StatsBearer(char* Name_Reference);

extern void free_StatsBearer(StatsBearer* input);

extern void set_StatsBearer_Aptitudes(StatsBearer* input,int apt[]);

extern void set_StatsBearer_Stats(StatsBearer* input,int stts[]);

extern void print_StatsBearer_StatsArray(int toPrint[],char* symbol);

extern void print_StatsBearer(StatsBearer* toPrint);

extern void calculateStatsTotal_StatsBearer(StatsBearer* input);

#endif