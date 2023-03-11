#include "ElementMaterial.h"

ElementMaterial* new_ElementMaterial(int size){
    ElementMaterial* output = (ElementMaterial*)malloc(sizeof(ElementMaterial));
    int* ec = (int*)malloc(sizeof(int)*size);

    if(output != NULL && ec != NULL){
        output->size = size;
        output->elementCount = ec;

        int i = 0;
        for(i = 0;i<size;i++){
            output->elementCount[i] = 0
        }
    }
    else{
        if(ec != NULL){
            free(ec);
        }
        if(output != NULL){
            free(output);
        }
    }

    return output;
}

void free_ElementMaterial(ElementMaterial* input){
    if(input != NULL){
        if(input->elementCount != NULL){
            free(input->elementCount);
        }
        free(input);
    }
    
    
}

void incrementElement_ElementMaterial(ElementMaterial* input,int index,int amount){
    input->elementCount[index] += amount;
}