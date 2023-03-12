#ifndef ABILITY_MANIPULATION
#define ABILITY_MANIPULATION

const int ABILITY_MANIPULATION_MATERIAL_SIZE = 15;
const int ABILITY_MANIPULATION_ABILITY_SIZE = 8;

typedef struct /*AbilityBearer*/{
    char* name;

    int level;
    int pointsPerLevel;

    int material[ABILITY_MANIPULATION_MATERIAL_SIZE];

    int aptitudes[ABILITY_MANIPULATION_ABILITY_SIZE];
    int abilities[ABILITY_MANIPULATION_ABILITY_SIZE];
}AbilityBearer;

extern AbilityBearer* new_AbilityBearer();

extern void free_AbilityBearer(AbilityBearer* input);

#endif