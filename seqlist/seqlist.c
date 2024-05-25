#include "seqlist.h"

void SLInit(SL* ps){
    ps->arr=NULL;
    ps->capacity=0;
    ps->size=0;
}

void SLDestroy(SL* ps){
    if(ps->arr != NULL)
        free(ps->arr);
    ps->capacity=0;
    ps->size=0;
}

void SLCheckCapacity(SL* ps){
    if(ps->capacity==ps->size){
        int Newcapacity = ps->capacity ==0 ? INIT_CAPACITY:ps->capacity*2;
        SLDataType *tmp = (SLDataType*) realloc(ps->arr,Newcapacity * sizeof(SLDataType));
        if(tmp==NULL){
            perror("realloc fail");
            exit(1);
        }
        ps->arr=tmp;
        ps->capacity=Newcapacity;
    }
}

void SLPushBack(SL* ps,SLDataType x){
    assert(ps);
    SLCheckCapacity(ps);
    ps->arr[ps->size]=x;
    ps->size++;
}
void SLPushFront(SL* ps ,SLDataType x){
    assert(ps);
    SLCheckCapacity(ps);
    for(int i =0;i<ps->size;i++){
        ps->arr[i+1]=ps->arr[i];
    }
    ps->arr[0]=x;
    ps->size++;
}

void SLPopBack(SL* ps){
    assert(ps->arr);
    assert((ps->size));
    ps->size--;

}

void SLPopFront(SL* ps){
    assert(ps->arr);
    assert(ps->size);
    for(int i =0;i<ps->size-1;i++)
        ps->arr[i]=ps->arr[i+1];
    ps->size--;
}

void SLPrint(SL* ps){
    assert(ps);
    for(int i=0;i<ps->size;i++)
        printf("%d ",ps->arr[i]);
    printf("\n");
}

void SLInsert(SL* ps,int position,SLDataType x){
    assert(ps->arr);
    assert(ps->size>=position && position>=0);
    SLCheckCapacity(ps);
    for(int i =position;i<ps->size;i++)
        ps->arr[i+1]=ps->arr[i];
    ps->arr[position]=x;
    ps->size++;
}

void SLErace(SL* ps,int pos){
    assert(ps);
    assert(pos>=0 && pos<ps->size);
    for(int i=pos;i<ps->size-1;i++)
        ps->arr[i]=ps->arr[i+1];
    ps->size--;

}
