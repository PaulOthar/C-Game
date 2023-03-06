#include "ElementMaterial.h"

ElementMaterial* new_ElementMaterial(int size){
    ElementMaterial* output = (ElementMaterial*)malloc(sizeof(ElementMaterial));

    output->size = size;
    output->elementCount = (int*)malloc(sizeof(int)*size);

    int i = 0;
    for(i = 0;i<size;i++){
        output->elementCount[i] = 0
    }

    return output;
}

void free_ElementMaterial(ElementMaterial* input){
    free(input->elementCount);
    free(input);
}

void incrementElement_ElementMaterial(ElementMaterial* input,int index,int amount){
    input->elementCount[index] += amount;
}