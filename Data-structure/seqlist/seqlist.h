#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "contact.h"
#include <string.h>
#define INIT_CAPACITY 4

typedef PeoInfo SLDataType;

typedef struct SeqList{
    SLDataType* arr;
    int capacity;
    int size;
}SL;

void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPushBack(SL* ps,SLDataType x);
void SLCheckCapacity(SL* ps);
void SLErace(SL* ps,int pos);
