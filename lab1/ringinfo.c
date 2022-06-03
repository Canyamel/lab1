#include "ringinfo.h"
#include <string.h>
#include <stdlib.h>
 
RingInfo* CreateRing
(	
	size_t size,
	void* (*sum)(void*, void*),
	void* (*mult)(void*, void*),
    void* zero,
    void* one
)
{
	RingInfo* ring = malloc(sizeof(RingInfo));
	ring->size = size;
	ring->sum = sum;
	ring->mult = mult;
    ring->zero = zero;
    ring->one = one;

    return ring;
}