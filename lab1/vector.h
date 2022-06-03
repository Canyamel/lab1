#ifndef VECTOR
#define VECTOR

#include "ringinfo.h"

typedef struct Vector3
{
    RingInfo* ring;
    void* x;
    void* y;
    void* z;
}Vector3; 

typedef struct TStPut
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
);

void* InputInt(void*, void*);
void* InputFloat(void*, void*);

Vector3* CreateZero(RingInfo* ringInfo);
Vector3* CreateEx(RingInfo* ringInfo);
Vector3* CreateEy(RingInfo* ringInfo);
Vector3* CreateEz(RingInfo* ringInfo);

#endif