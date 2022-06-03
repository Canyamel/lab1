#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "ringinfo.h"
#include "get.h"

typedef struct Vector3
{
    RingInfo* ring;
    void* x;
    void* y;
    void* z;
}Vector3; 



typedef struct StPut
{
    void (*output)(Vector3*);
    Vector3* (*createVect)(Vector3*, RingInfo*);
    void* (*createSc)();
}StPut;

StPut* CreatePut
(	
    void (*output)(Vector3*),
    Vector3* (*createVect)(Vector3*, RingInfo*),
    void* (*createSc)()
)
{
	StPut* pt = (StPut*)malloc(sizeof(StPut));
	pt->output = output;
    pt->createVect = createVect;
    pt->createSc = createSc;

    return pt;
}

void* InputInt(void* sc, void* crd)
{ 
    int* nsc = malloc(sizeof(int));
    nsc[0] = *(int*)crd; 
    sc = ((void*)&nsc[0]); 

    return sc;  
}

void* InputFloat(void* sc, void* crd)
{ 
    float* nsc = malloc(sizeof(float));
    nsc[0] = *(float*)crd;
    sc = ((void*)&nsc[0]); 

    return sc;  
}



Vector3* the_zero;
Vector3* CreateZero(RingInfo* ringInfo)
{   
    if(!the_zero)
    {
        the_zero = (Vector3*)malloc(sizeof(Vector3));
        the_zero->ring = ringInfo;
        the_zero->x = ringInfo->zero;
        the_zero->y = ringInfo->zero;
        the_zero->z = ringInfo->zero;
    }
    return the_zero;
}


Vector3* Ex;
Vector3* CreateEx(RingInfo* ringInfo)
{
    if(!Ex)
    {
        Ex = (Vector3*)malloc(sizeof(Vector3));
        Ex->ring = ringInfo;
        Ex->x = ringInfo->one;
        Ex->y = ringInfo->zero;
        Ex->z = ringInfo->zero;
    }
    return Ex;
}

Vector3* Ey;
Vector3* CreateEy(RingInfo* ringInfo)
{
    if(!Ey)
    {
        Ey = (Vector3*)malloc(sizeof(Vector3));
        Ey->ring = ringInfo;
        Ey->x = ringInfo->zero;
        Ey->y = ringInfo->one;
        Ey->z = ringInfo->zero;
    }
    return Ey;
}

Vector3* Ez;
Vector3* CreateEz(RingInfo* ringInfo)
{
    if(!Ez)
    {
        Ey = (Vector3*)malloc(sizeof(Vector3));
        Ey->ring = ringInfo;
        Ey->x = ringInfo->zero;
        Ey->y = ringInfo->zero;
        Ey->z = ringInfo->one;
    }
    return Ez;
}

