#ifndef FORISPRITCHIN_VECTORVOID_H
#define FORISPRITCHIN_VECTORVOID_H

#include <stdlib.h>

typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора
    size_t size;         // размер вектора
    size_t capacity;     // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;

#endif //FORISPRITCHIN_VECTORVOID_H
