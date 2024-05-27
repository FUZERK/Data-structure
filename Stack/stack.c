#include "stack.h"

void StackInit(Stack* ps){
    assert(ps);
    ps->_a=NULL;
    ps->_capacity=0;
    ps->_top=0;
};

void StackPush(Stack* ps, STDataType data){
    assert(ps);
    if(ps->_capacity==ps->_top){
        int NewCapacity =ps->_capacity==0 ? 4 : ps->_capacity*2;
        STDataType *tmp=(STDataType *) realloc(ps->_a,NewCapacity*sizeof(STDataType));
       if(tmp==NULL){
           perror("realloc fail");
           return;
       }
       else{
           ps->_a=tmp;
           ps->_capacity=NewCapacity;
       }
    }
    ps->_a[ps->_top]=data;
    ps->_top++;
};

void StackPop(Stack* ps){
    assert(ps);
    assert(ps->_top>0);
    ps->_top--;
};

STDataType StackTop(Stack* ps){
    assert(ps);
    assert(ps->_top > 0);
    return ps->_a[ps->_top-1];
}

int StackSize(Stack* ps){
    assert(ps);
    return ps->_top;
}

int StackEmpty(Stack* ps){
    assert(ps);
    int ret;
    if(ps->_top!=0)ret =-1;
    else ret=0;
    return ret;
}

void StackDestroy(Stack* ps){
    assert(ps);
    free(ps->_a);
    ps->_a=NULL;
    ps->_top=ps->_capacity=0;

}