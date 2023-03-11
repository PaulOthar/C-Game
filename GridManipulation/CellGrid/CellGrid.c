#include "CellGrid.h"

CellGrid* new_CellGrid(int width,int height){
    CellGrid* output = (CellGrid*)malloc(sizeof(CellGrid));
    int* cellValue = (int*)malloc(sizeof(int)*width*height);

    if(output != NULL){
        output->width = width;
        output->height = height;
        output->cellValue = cellValue;
    }
    else if(cellValue == NULL){
        free(output);
    }

    return output;
}

void free_CellGrid(CellGrid* input){
    if(input != NULL){
        if(input->cellValue != NULL){
            free(input->cellValue);
        }
        free(input);
    }
}

int readSlot_CellGrid(CellGrid* input,int x,int y){
    return input->cellValue[x+y*input->width];
}

int readAreaVacancy_CellGrid(CellGrid* input,int x1,int y1,int x2,int y2,int emptyValue){
    int x = 0;
    int y = 0;

    for(x = x1;x<x2;x++){
        for(y = y1;y<y2;y++){
            if(input->cellValue[x+y*input->width] != emptyValue){
                return 0;
            }
        }
    }

    return 1;
}

void writeSlot_CellGrid(CellGrid* input,int x,int y,int value){
    input->cellValue[x+y*input->width] = value;
}

void writeArea_CellGrid(CellGrid* input,int x1,int y1,int x2,int y2,int value){
    int x = 0;
    int y = 0;

    for(x = x1;x<x2;x++){
        for(y = y1;y<y2;y++){
            input->cellValue[x+y*input->width] = value;
        }
    }
}