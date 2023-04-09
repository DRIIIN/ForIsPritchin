#include "vectorVoid.h"

void errorMemoryV() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int* a = (void*) malloc(baseTypeSize * n);

    if (a == NULL) {
        errorMemoryV();
    }

    vectorVoid v = {n ? a : NULL, 0, n, baseTypeSize};

    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
    else if (newCapacity > v->capacity) {
        v->data = (void*) realloc(v->data, v->baseTypeSize * newCapacity);
        v->capacity = newCapacity;
        if (v->data == NULL) {
            errorMemoryV();
        }
    }
    else if (newCapacity < v->capacity) {
        if (newCapacity < v->size) {
            v->size = newCapacity;
        }
        v->capacity = newCapacity;
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    v->data = (void*) realloc(v->data, v->baseTypeSize * v->size);
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}