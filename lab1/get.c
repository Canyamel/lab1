#include "vector.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>

/*
int GetInt()
{
    char buf[256];
    fgets(buf, sizeof(buf), stdin);

    int n;
    while(sscanf(buf, "%d", &n) != 1)
    {
        printf("Ошибка. Введите целочисленное число\n");
        fgets(buf, sizeof(buf), stdin);
    }

    return n;
}

float GetFloat()
{
    char buf[256];
    fgets(buf, sizeof(buf), stdin);

    float n;
    while(sscanf(buf, "%f", &n) != 1)
    {
        printf("Ошибка. Введите вещественное число\n");
        fgets(buf, sizeof(buf), stdin);
    }

    return n;
}
*/

int GetInt(Error* error)
{
    char buf[256];
    fgets(buf, sizeof(buf), stdin);

    int n;
    if(sscanf(buf, "%d", &n) != 1)
    {
        *error = WRONGINPUTINT;
    }

    return n;
}

float GetFloat(Error* error)
{
    char buf[256];
    fgets(buf, sizeof(buf), stdin);

    float n;
    if(sscanf(buf, "%f", &n) != 1)
    {
        *error = WRONGINPUTFLOAT;
    }

    return n;
}

