#ifndef CELL_GRID
#define CELL_GRID

typedef struct /*Cell Grid*/{
    int width;
    int height;
    int* cellValue;
}CellGrid;

extern CellGrid* new_CellGrid(int width,int height);

extern void free_CellGrid(CellGrid* input);

extern int readSlot_CellGrid(CellGrid* input,int x,int y);

extern int readAreaVacancy_CellGrid(CellGrid* input,int x1,int y1,int x2,int y2,int emptyValue);

extern void writeSlot_CellGrid(CellGrid* input,int x,int y,int value);

extern void writeArea_CellGrid(CellGrid* input,int x1,int y1,int x2,int y2,int value);

#endif