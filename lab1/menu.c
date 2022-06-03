#include "menu.h"

void FuncError(Error error)
{
    switch(error)
    {
        case 1:
            printf("Ошибка. Введите целочисленное число\n");
            break;

        case 2: 
            printf("Ошибка. Введите вещественное число\n");
            break;

        case 3: 
            printf("Ошибка. Вектор не создан\n");
            break;  
    }
}

int CheckInt()
{
    int sc;
    Error error;

    do
    {
    error = NOT;
    sc = GetInt(&error);
    FuncError(error);
    }while(error == WRONGINPUTINT);

    return sc;
}

float CheckFloat()
{
    float sc;
    Error error;

    do
    {
    error = NOT;
    sc = GetFloat(&error);
    FuncError(error);
    }while(error == WRONGINPUTFLOAT);

    return sc;
}

void OutputInt(Vector3* vect)
{
    printf("Координата X: %d\n", *((int*)vect->x));
    printf("Координата Y: %d\n", *((int*)vect->y));
    printf("Координата Z: %d\n", *((int*)vect->z));
}

void OutputFloat(Vector3* vect)
{
    printf("Координата X: %d\n", *((float*)vect->x));
    printf("Координата Y: %d\n", *((float*)vect->y));
    printf("Координата Z: %d\n", *((float*)vect->z));
}

Vector3* CreateVectInt(Vector3* vect, RingInfo* r)
{
    Error error;

    if(vect == NULL)
    {
        vect = (Vector3*)malloc(sizeof(Vector3));
        vect->ring = r;
    }    
    printf("Введите координату X\n");
    int x = CheckInt(); 
    void* ix = &x;
    vect->x = InputInt(vect->x, ix);

    printf("Введите координату Y\n");
    int y = CheckInt(); 
    void* iy = &y;
    vect->y = InputInt(vect->y, iy);

    printf("Введите координату Z\n");
    int z = CheckInt(); 
    void* iz = &z;
    vect->z = InputInt(vect->z, iz);

    return vect;
}

Vector3* CreateVectFloat(Vector3* vect, RingInfo* r)
{
    Error error;

    if(vect == NULL)
    {
        vect = (Vector3*)malloc(sizeof(Vector3));
        vect->ring = r;
    }    
    printf("Введите координату X\n");
    float x = CheckFloat(); 
    void* ix = &x;
    vect->x = InputFloat(vect->x, ix);

    printf("Введите координату Y\n");
    float y = CheckFloat(); 
    void* iy = &y;
    vect->y = InputFloat(vect->y, iy);

    printf("Введите координату Z\n");
    float z = CheckFloat(); 
    void* iz = &z;
    vect->z = InputFloat(vect->z, iz);

    return vect;
}

void* CreateScInt() 
{
    Error error;

    printf("Введите скаляр\n");
    int nsc = CheckInt(); 
    void* sc = &nsc; 
    return sc; 
}

void* CreateScFloat() 
{
    Error error;

    printf("Введите скаляр\n");
    float nsc = CheckFloat(); 
    void* sc = &nsc; 
    return sc; 
}


Vector3* MenuSupport(RingInfo* r, Vector3* v1, Vector3* v2)
{
    Vector3* v = NULL;
    int menu = 0;
    int b = 0;
    while(b != 1)
    {
        system("clear");
        printf("------------ТЕРМИНАЛ------------\n");
        printf("1. Первый вектор\n");
        printf("2. Второй вектор\n");
        printf("3. Нулевой вектор\n");
        printf("4. Единичный вектор X\n");
        printf("5. Единичный вектор Y\n");
        printf("6. Единичный вектор Z\n");
        printf("--------------------------------\n");
        printf("Введите номер пункта:\n");
        menu = CheckInt();
        switch(menu)
        {
            case 1:
                v = v1;
                b = 1;
                break;

            case 2:
                v = v2;
                b = 1;
                break;

            case 3:
                v = CreateZero(r);
                b = 1;
                break;

            case 4:
                v = CreateEx(r);
                b = 1;
                break;

            case 5:
                v = CreateEy(r);
                b = 1;
                break;

            case 6:
                v = CreateEz(r);
                b = 1;
                break; 

            default:
                printf("Такого пункта нет\n");                       
            }
        }

    return v;        
}

void FuncMenu()
{   
    system("clear");
    printf("------------ТЕРМИНАЛ------------\n"); 
    printf("1. Целое число\n");
    printf("2. Вещественное число\n");
    printf("--------------------------------\n");

    int menu; 
    printf("Введите номер пункта:\n");
    menu = CheckInt();
    RingInfo* r = NULL;
    StPut* pt = NULL;
    switch(menu)
    {   
        case 1:
            int ia = 0;
            int ib = 1;
            void* izero = &ia;
            void* ione = &ib; 
            r = CreateRing(sizeof(int), SumInt, MultInt, izero, ione);
            pt = CreatePut(OutputInt, CreateVectInt, CreateScInt);
            break; 

        case 2:
            float fa = 0;
            float fb = 1;
            void* fzero = &fa;
            void* fone = &fb; 
            r = CreateRing(sizeof(float), SumFloat, MultFloat, fzero, fone);
            pt = CreatePut(OutputFloat, CreateVectFloat, CreateScFloat);
            break;

        default:  
            printf("Такого пункта нет\n");     
    }

    Vector3* v1 = NULL;
    Vector3* v2 = NULL;
    Vector3* v3 = NULL;
    Vector3* va = NULL;
    Vector3* vb = NULL; 
    while(menu != 4)
    {
        menu = 0;
        system("clear");
        printf("------------ТЕРМИНАЛ------------\n");
        printf("1. Создать вектор\n");
        printf("2. Операции над векторами\n");
        printf("3. Вывод векторов на экран\n");
        printf("4. Выход\n");
        printf("--------------------------------\n");
        
        printf("Введите номер пункта:\n");
        menu = CheckInt();
        switch(menu)
        {
            case 1:
                menu = 0;
                while(menu != 3)
                {

                    system("clear");
                    printf("------------ТЕРМИНАЛ------------\n");
                    printf("1. Первый вектор\n");
                    printf("2. Второй вектор\n");
                    printf("3. Назад\n");
                    printf("--------------------------------\n");
                        
                    printf("Введите номер пункта:\n");
                    menu = CheckInt();
                    switch(menu)
                    {
                        case 1:

                            v1 = pt->createVect(v1, r);
                            break;

                        case 2:
                            v2 = pt->createVect(v2, r);
                            break;
                            
                            case 3:
                                break;

                            default:
                                printf("Такого пункта нет\n");    
                        }    
                    }
                break;

            case 2:
                menu = 0;
                while(menu != 5)
                {
                    void* sc;
                    system("clear");
                    printf("------------ТЕРМИНАЛ------------\n");
                    printf("1. Векторное сложение\n");
                    printf("2. Скалярное произведение\n");
                    printf("3. Произведение вектора на число\n");
                    printf("4. Норма вектора\n");
                    printf("5. Назад\n");
                    printf("--------------------------------\n");
                    
                    Error error;
                    printf("Введите номер пункта:\n");
                    menu = CheckInt();                    
                    switch(menu)
                    {
                        case 1:
                            va = MenuSupport(r, v1, v2);
                            vb = MenuSupport(r, v1, v2);
                            system("clear");
                            if(va == NULL || vb == NULL)
                            {
                                error = NOTCREATE;
                                FuncError(error);
                            }
                            else
                            {   
                                v3 = Sum(va, vb);
                                pt->output(v3);
                                free(v3);
                            }    
                            va = NULL;
                            vb = NULL;
                            printf("Нажмите любую клавишу, чтобы продолжить\n");
                            system("read");
                            break;

                        case 2:
                            va = MenuSupport(r, v1, v2);
                            vb = MenuSupport(r, v1, v2);
                            system("clear");
                            if(va == NULL || vb == NULL)
                            {
                                error = NOTCREATE;
                                FuncError(error);
                            }
                            else
                            {
                                sc = MultV(va, vb);
                                printf("Результат: %d\n", *((int*)sc));
                            }
                            va = NULL;
                            vb = NULL;
                            printf("Нажмите любую клавишу, чтобы продолжить\n");
                            system("read");
                            break;

                        case 3:
                            va = MenuSupport(r, v1, v2);
                            system("clear");
                            if(va == NULL)
                            {
                                error = NOTCREATE;
                                FuncError(error);
                            }
                            else
                            {
                                sc = pt->createSc();
                                v3 = MultSc(va, sc);
                                pt->output(v3);
                                free(v3);
                            }
                            va = NULL;
                            printf("Нажмите любую клавишу, чтобы продолжить\n");
                            system("read");
                            break;

                        case 4:
                            va = MenuSupport(r, v1, v2);
                            system("clear");
                            if(va == NULL)
                            {
                                error = NOTCREATE;
                                FuncError(error);
                            }
                            else
                            {
                                double norm = GetNorm(va);
                                printf("Результат: %f\n", norm);
                            }
                            va = NULL;
                            printf("Нажмите любую клавишу, чтобы продолжить\n");
                            system("read");
                            break;

                        case 5:
                            break;

                        default:
                            printf("Такого пункта нет\n");
                    }
                }
                break;

            case 3:
                menu = 0;
                while(menu != 3)
                {
                    system("clear");
                    printf("------------ТЕРМИНАЛ------------\n");
                    printf("1. Первый вектор\n");
                    printf("2. Второй вектор\n");
                    printf("3. Назад\n");
                    printf("--------------------------------\n");
                    
                    printf("Введите номер пункта:\n");
                    menu = CheckInt();
                    switch(menu)
                    {
                        case 1:
                            pt->output(v1);
                            printf("Нажмите любую клавишу, чтобы продолжить\n");
                            system("read");
                            break;

                        case 2:
                            pt->output(v2);
                            printf("Нажмите любую клавишу, чтобы продолжить\n");
                            system("read");
                            break;
                        
                        case 3:
                            break;

                        default:
                            printf("Такого пункта нет\n");    
                    }    
                }
                break;   

            case 4:
                printf("Конец работы программы\n");
                free(v1);
                free(v2);
                break;

            default:
                printf("Такого пункта нет\n"); 
        }
    }
}