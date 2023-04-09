#ifndef FORISPRITCHIN_VECTOR_H
#define FORISPRITCHIN_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <malloc.h>

typedef struct vector {
    int *data;       // указатель на элементы вектора
    size_t size;     // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

#endif //FORISPRITCHIN_VECTOR_H
