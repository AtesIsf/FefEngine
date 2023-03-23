#ifndef FEF_VECTOR_H
#define FEF_VECTOR_H

typedef struct Vector
{
    int dimensions;
    double *vals;
} vector_t;

vector_t * createVector(int dimensions);

void vectorAdd(vector_t *u, vector_t *v);

void vectorSub(vector_t *u, vector_t *v);

void vectorScalarMul(vector_t *u, double scalar);

double dotProduct(vector_t *u, vector_t *v);

double vectorMagnitude(vector_t u);

void normalizeVector(vector_t *u);

vector_t * vectorCopy(vector_t *u);

void vectorFree(vector_t *u);

#endif