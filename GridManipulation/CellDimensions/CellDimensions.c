#include "CellDimensions.h"

CellDimensions* new_CellDimensions(int width,int height,int rotation){
    CellDimensions* output = (CellDimensions*)malloc(sizeof(CellDimensions));

    if(output != NULL){
        output->width = width;
        output->height = height;
        output->rotation = rotation;
    }

    return output;
}

void free_CellDimensions(CellDimensions* input){
    if(input != NULL){
        free(input);
    }
}

int readWidth_CellDimensions(CellDimensions* input){
    if(input->rotation % 2 > 0){
        return input->height;
    }
    return input->width;
}

int readHeight_CellDimensions(CellDimensions* input){
    if(input->rotation % 2 > 0){
        return input->width;
    }
    return input->height;
}

int rotateClockwise_CellDimensions(CellDimensions* input,int amount){
    input->rotation = (input->rotation + amount) & 0b11;
}