#ifndef ELEMENT_MATERIAL
#define ELEMENT_MATERIAL

typedef struct /**/{
    int size;
    int* elementCount;
}ElementMaterial;

extern ElementMaterial* new_ElementMaterial(int size);

extern void free_ElementMaterial(ElementMaterial* input);

extern void incrementElement_ElementMaterial(int index,int amount);

#endif