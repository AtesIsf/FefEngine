#include <stdlib.h>
#include <math.h>

#include "vector.h"

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

double dotProduct(vector_t u, vector_t v)
{
    if (u.dimensions != v.dimensions)
        return;

    double result = 0;
    for (int i = 0; i<u.dimensions; i++)
        result += u.vals[i] * v.vals[i];
    
    return result;
}

vector_t * crossProduct(vector_t u, vector_t v)
{
    // Only implemented for 2D & 3D vectors
    if (u.dimensions != v.dimensions || u.dimensions != 2 && u.dimensions != 3)
        return 0x0;

    vector_t *result = createVector(3);

    if (u.dimensions == 2)
    {
        // i, j = 0
        result->vals[0] = 0;
        result->vals[1] = 0;

        result->vals[2] = (u.vals[0] * v.vals[1]) - (u.vals[1] * v.vals[0]);
    }

    else if(u.dimensions == 3)
    {
        /*
        i  j  k
        u1 u2 u3
        v1 v2 v3

        u x v = {(u2*v3-u3*v2)i, (u1*v3-u3*v1)j, (u1*v2-u2*v1)k}
        */
        result->vals[0] = (u.vals[1] * v.vals[2] - u.vals[2] * v.vals[1]);
        result->vals[1] = (u.vals[0] * v.vals[2] - u.vals[2] * v.vals[0]);
        result->vals[2] = (u.vals[1] * v.vals[1] - u.vals[1] * v.vals[0]);
    }

    return result;
}

double vectorMagnitude(vector_t u)
{
    double temp = 0;
    for (int i = 0; i<u.dimensions; i++)
        temp+=(u.vals[i] * u.vals[i]);
    return sqrt(temp);
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

vector_t * vectorCopy(vector_t *u)
{
    vector_t *v = createVector(u->dimensions);
    for (int i = 0; i<u->dimensions; i++)
        v->vals[i] = u->vals[i];
    return v;
}

// The program will die if you try to reference u later
void vectorFree(vector_t *u)
{
    free(u->vals);
    free(u);
}
