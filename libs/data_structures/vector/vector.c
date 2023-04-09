#include "vector.h"

vector createVector(size_t n) {
    int* a = (int*) malloc(sizeof(int) * n);

    if (a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    vector v = {NULL, 0, n};
    if (n) {
        v.data = a;
    }

    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
    else if (newCapacity > v->capacity) {
        v->data = (int*) realloc(v->data, sizeof(v->data[0]) * newCapacity);
        v->capacity = newCapacity;
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    else if (newCapacity < v->capacity) {
        if (newCapacity < v->size) {
            v->size = newCapacity;
        }
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int*) realloc(v->data, sizeof(v->data[0]) * v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}