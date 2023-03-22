#include <stdlib.h>
#include "vector.h"

/*
TODO: cross product
*/

vector_t * createVector(int dimensions)
{
    vector_t *u = (vector_t *) malloc(sizeof(vector_t));
    u->vals = (double *) malloc(sizeof(double) * dimensions);
    u->dimensions = dimensions;

    return u;
}

void vectorAdd(vector_t *u, vector_t *v)
{
    if (u->dimensions != v->dimensions)
        return; // Only add if the dimensions are the same
    
    for (int i = 0; i<u->dimensions; i++)
        u->vals[i]+=v->vals[i];
}

void vectorSub(vector_t *u, vector_t *v)
{
    if (u->dimensions != v->dimensions)
        return; // Only subtract if the dimensions are the same
    
    for (int i = 0; i<u->dimensions; i++)
        u->vals[i]-=v->vals[i];
}

void vectorScalarMul(vector_t *u, double scalar)
{
    for (int i = 0; i<u->dimensions; i++)
        u->vals[i]*=scalar; 
}

double dotProduct(vector_t *u, vector_t *v)
{
    if (u->dimensions != v->dimensions)
        return;

    double result = 0;
    for (int i = 0; i<u->dimensions; i++)
        result += u->vals[i] * v->vals[i];
    
    return result;
}

void normalizeVector(vector_t *u)
{
    double max = u->vals[0];
    int i;

    for (i = 1; i<u->dimensions; i++)
        if(u->vals[i] > max)
            max = u->vals[i];

    for (i = 0; i<u->dimensions; i++)
        u->vals[i]/=max;
}

// The program will die if you try to reference u later
void vectorFree(vector_t *u)
{
    free(u->vals);
    free(u);
}
