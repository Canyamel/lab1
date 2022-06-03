#ifndef OPERATION
#define OPERATION

Vector3* Sum(Vector3* vect1, Vector3* vect2);
void* MultV(Vector3* vect1, Vector3* vect2);
Vector3* MultSc(Vector3* vect, void* scalar);
double GetNorm(Vector3* vect);


// Целое число
void* SumInt(void* a, void* b);
void* MultInt(void* a, void* b);


// Вещественное число
void* SumFloat(void* a, void* b);
void* MultFloat(void* a, void* b);

#endif