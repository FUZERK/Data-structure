#include "quene.h"

void QueueInit(Queue* q){
    q->_front=q->_rear=NULL;
    q->size=0;
}

void QueuePush(Queue* q, QDataType data){
    assert(q);
    QNode * newnode = (QNode*) malloc(sizeof (QNode));
    if(newnode==NULL){
        perror("malloc fail");
        return;
    }
    newnode->_data=data;
    newnode->_next=NULL;
    if(q->_rear==NULL){
        q->_rear=q->_front=newnode;
    }
    else{
        q->_rear->_next=newnode;
        q->_rear=q->_rear->_next;
    }
    q->size++;
}

void QueuePop(Queue* q){
    assert(q);
    assert(q->size!=0);

    if(q->size==1){
        free(q->_rear);
        q->_front=q->_rear=NULL;
    }
    else{
        QNode *next=q->_front->_next;
        free(q->_front);
        q->_front=next;
    }
    q->size--;
}

QDataType QueueFront(Queue* q){
    assert(q);
    assert(q->size!=0);
    return q->_front->_data;
}

QDataType QueueBack(Queue* q){
    assert(q);
    assert(q->size!=0);
    return q->_rear->_data;
}

int QueueSize(Queue* q){
    assert(q);
    return q->size;
}

int QueueEmpty(Queue* q){
    assert(q);
    if(q->size)return 0;
    else return -1;
}

void QueueDestroy(Queue* q){
    assert(q);
    QNode *pcur=q->_front;
    while (pcur){
        QNode* next = pcur->_next;
        free(pcur);
        pcur=next;
    }
    q->size=0;
    q->_front=q->_rear=NULL;
}