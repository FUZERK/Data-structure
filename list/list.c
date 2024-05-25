#include "list.h"

LTNode *BuyNode(LTDataType x){
    LTNode * node = (LTNode*) malloc(sizeof(LTNode));
    node->data=x;
    node->next=node;
    node->prev=node;
    return node;
}

LTNode* LTInit(){
    LTNode *node = BuyNode(-1);
    return node;
}

void LTPrint(LTNode* phead){
    assert(phead);
    LTNode *pcur=phead->next;
    while(pcur != phead){
        printf("%d->",pcur->data);
        pcur=pcur->next;
    }
    printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x){
    assert(phead);
    LTNode *node = BuyNode(x);
    node->prev=phead->prev;
    node->next=phead;
    phead->prev->next=node;
    phead->prev=node;
}

void LTPopBack(LTNode* phead){
    assert(phead && phead->next!=phead);
    LTNode *del = phead->prev;
    del->prev->next=phead;
    phead->prev=del->prev;

    free(del);
    del=NULL;
}


void LTPushFront(LTNode* phead, LTDataType x){
    assert(phead);
    LTNode * node = BuyNode(x);
    phead->next->prev=node;
    node->next=phead->next;
    node->prev=phead;
    phead->next=node;
}

void LTPopFront(LTNode* phead){
    assert(phead && phead->next != phead);
    LTNode *del = phead->next;

    phead->next=del->next;
    del->next->prev=phead;

    free(del);
    del=NULL;
}


void LTInsert(LTNode* pos, LTDataType x){
    assert(pos);
    LTNode *node = BuyNode(x);
    node->prev=pos;
    node->next=pos->next;
    pos->next->prev=node;
    pos->next=node;
}

void LTErase(LTNode* pos){
    assert(pos);
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    free(pos);
    pos=NULL;
}

LTNode *LTFind(LTNode* phead,LTDataType x){
    LTNode *pcur = phead->next;
    while(pcur != phead){
        if(pcur->data == x){
            return pcur;
        }
        pcur=pcur->next;
    }
    return NULL;
}

void LTDestroy(LTNode* phead){
    assert(phead);
    LTNode *pcur = phead->next;
    while(pcur != phead){
        LTNode *next=pcur->next;
        free(pcur);
        pcur=next;
    }
    free(phead);
    phead=NULL;
}