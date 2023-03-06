#ifndef CELL_GRID_DIMENSIONS
#define CELL_GRID_DIMENSIONS

typedef struct /*Dimensions*/{
    int width;
    int height;
    int rotation;
}CellDimensions;

extern CellDimensions* new_CellDimensions(int width,int height,int rotation);

extern void free_CellDimensions(CellDimensions* input);

extern int readWidth_CellDimensions(CellDimensions* input);

extern int readHeight_CellDimensions(CellDimensions* input);

extern int rotateClockwise_CellDimensions(CellDimensions* input,int amount);

#endif