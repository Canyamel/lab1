#ifndef RINGINFO
#define RINGINFO

#include <string.h>

typedef struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*mult)(void*, void*);
    void* zero;
    void* one;
}RingInfo;

RingInfo* CreateRing
(
	size_t size,
	void* (*sum)(void*, void*),
    void* (*mult)(void*, void*),
    void* zero,
    void* one
);

#endif