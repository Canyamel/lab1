#include "vector.h"
#include "ringinfo.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Vector3* Sum(Vector3* v1, Vector3* v2)
{   
    Vector3* res = (Vector3*)malloc(sizeof(Vector3));
    res->ring = v1->ring;
    res->x = res->ring->sum(v1->x, v2->x);
    res->y = res->ring->sum(v1->y, v2->y);
    res->z = res->ring->sum(v1->z, v2->z);
    
    return res;
}


void* MultV(Vector3* v1, Vector3* v2)
{   
    void* resx = v1->ring->mult(v1->x, v2->x); 
    void* resy = v1->ring->mult(v1->y, v2->y); 
    void* resz = v1->ring->mult(v1->z, v2->z); 

    void* res = v1->ring->sum(resx, resy);  
    res = v1->ring->sum(res, resz); 

    return res;
}


Vector3* MultSc(Vector3* v, void* sc)
{
    Vector3* res = (Vector3*)malloc(sizeof(Vector3));
    res->ring = v->ring;
    res->x = res->ring->mult(v->x, sc);
    res->y = res->ring->mult(v->y, sc);
    res->z = res->ring->mult(v->z, sc);

    return res;
}


double GetNorm(struct Vector3* v)
{
    void* resx = v->ring->mult(v->x, v->x);
    void* resy = v->ring->mult(v->y, v->y);
    void* resz = v->ring->mult(v->z, v->z);

    void* ires = v->ring->sum(resx, resy);
    ires = v->ring->sum(ires, resz);
    double res = *((int*)ires);
    res = sqrt(res);
    
    return res;
}


// Целое число

void* SumInt(void* a, void* b)
{
    int* ia = (int*)a;
    int* ib = (int*)b;
    int* res = malloc(sizeof(int));
    *res = *ia + *ib;
    return (void*)res;
}

void* MultInt(void* a, void* b)
{
    int* ia = (int*)a;
    int* ib = (int*)b;
    int* res = malloc(sizeof(int));
    *res = *ia * *ib;
    return (void*)res;
}

// Вещественное число

void* SumFloat(void* a, void* b)
{
    float* ia = (float*)a;
    float* ib = (float*)b;
    float* res = malloc(sizeof(float));
    *res = *ia + *ib;
    return (void*)res;
}

void* MultFloat(void* a, void* b)
{
    float* ia = (float*)a;
    float* ib = (float*)b;
    float* res = malloc(sizeof(float));
    *res = *ia * *ib;
    return (void*)res;
}

// Комплексное число
