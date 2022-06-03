#ifndef MENU
#define MENU

#include "vector.h"
#include "ringinfo.h"
#include "operation.h"
#include "get.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FuncError(Error);

int CheckInt();
float CheckFloat();

void OutputInt(Vector3*);
void OutputFloat(Vector3*);

Vector3* CreateVectInt(Vector3*);
Vector3* CreateVectFloat(Vector3*);

void* CreateScInt();
void* CreateScFloat();

Vector3* MenuSupport(RingInfo*, Vector3*, Vector3*);

void FuncMenu();

#endif