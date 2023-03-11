#include "ElementCompound.h"

ElementCompound* new_ElementCompound(int relevantSize,int materialSize,int element,int valence){
    ElementCompound* output = (ElementCompound*)malloc(sizeof(ElementCompound));

    int gaussSum = (relevantSize/2)*(relevantSize+1);
    int* con = (int*)malloc(sizeof(int)*gaussSum);

    ElementMaterial* em = new_ElementMaterial(int materialSize);

    if(output != NULL && con != NULL && em != NULL){
        output->cElement = element;
        output->cValence = valence;
        output->relevantSize = relevantSize;
        output->totalSize = gaussSum;

        output->connections = con;

        output->material = em;
    }
    else{
        if(con != NULL){
            free(con);
        }
        if(em != NULL){
            free_ElementMaterial(em);
        }
        if(output != NULL){
            free(output);
        }
    }

    return output;
}

void free_ElementCompound(ElementCompound* input){
    if(input != NULL){
        if(input->connections != NULL){
            free(input->connections);
        }
        if(input->material != NULL){
            free_ElementMaterial(input->material);
        }
        free(output);
    }
}

int findCombination_ElementCompound(int element1,int element2,int hightest){
    int e1 = element1;
    int e2 = element2;

    if(element1 > element2){
        e1 = element2;
        e2 = element1;
    }

    e1++;

    return ((-(e1 - hightest*2) * (e1 - 1)) / 2) + e2;
}

void addElement_ElementCompound(ElementCompound* input,int element,int valence){
    
}