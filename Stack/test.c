#include "stack.h"
int main(){
    Stack s;
    StackInit(&s);
    StackPush(&s,1);
    StackPush(&s,3);
    StackPush(&s,2);
    StackPush(&s,4);
    StackPush(&s,5);
    StackPop(&s);
    //StackPop(&s);
    int a= StackTop(&s);
    //printf("%d\n",a);
    int len= StackSize(&s);
    //printf("%d\n",len);
    int check = StackEmpty(&s);
    printf("%d\n",check);
    while(StackSize(&s)!=0){
        printf("%d ", StackTop(&s));
        StackPop(&s);
    }
    StackDestroy(&s);
    return 0;
}