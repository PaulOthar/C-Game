#ifndef ELEMENT_TABLE
#define ELEMENT_TABLE

extern const int 
EARTH_INDEX = 0,
AIR_INDEX = 1,
COLD_INDEX = 2,
HEAT_INDEX = 3,
LIFE_INDEX = 4,
DEATH_INDEX = 5,
LIGHT_INDEX = 6,
DARK_INDEX = 7,

NICKEL_INDEX = 8,
COPPER_INDEX = 9,
IRON_INDEX = 10,
COBALT_INDEX = 11,
SILVER_INDEX = 12,
GOLD_INDEX = 13,
PLATNUM_INDEX = 14;

extern const char* ELEMENT_NAME[] = {
    "Earth",
    "Air",
    "Cold",
    "Heat",
    "Life",
    "Death",
    "Light",
    "Dark",
    "Nickel",
    "Copper",
    "Iron",
    "Cobalt",
    "Silver",
    "Gold",
    "Platnum"
};

extern const int ELEMENT_VALENCE[] = {
    -4, // Earth
	-4, // Air
	-3, // Cold
	-3, // Heat
	-2, // Life
	-2, // Death
	-1, // Light
	-1, // Dark

	+3, // Nickel
	+3, // Copper
	+3, // Iron
	+2, // Cobalt
	+2, // Silver
	+1, // Gold
	+1// Platnum
};



#endif