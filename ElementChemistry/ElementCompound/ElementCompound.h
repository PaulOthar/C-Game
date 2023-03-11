#ifndef ELEMENT_COMPOUND
#define ELEMENT_COMPOUND

#include "../ElementMaterial/ElementMaterial.h";

typedef struct /*ElementCompound*/{
    int cElement;
    int cValence;
    int relevantSize;
    int totalSize;
    int* connections;
    ElementMaterial* material;
}ElementCompound;

extern ElementCompound* new_ElementCompound(int relevantSize,int materialSize,int element,int valence);

extern void free_ElementCompound(ElementCompound* input);

extern int findCombination_ElementCompound(int element1,int element2,int hightest);

extern void addElement_ElementCompound(ElementCompound* input,int element,int valence);

#endif