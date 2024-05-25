#include "quene.h"
void test01(){
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    //printf("%d ", QueueFront(&q));
    QueuePop(&q);

    QueuePush(&q, 3);
    QueuePush(&q, 4);

    while (!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");
}


int main(){
    test01();
    return 0;
}