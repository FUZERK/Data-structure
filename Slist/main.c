#include "slist.h"

void SLTPrint(SLTNode* phead){
    SLTNode* pcur = phead;
    while (pcur->next!=NULL){
        printf("%d->",pcur->data);
        pcur=pcur->next;
    }
    printf("NULL\n");
}

SLTNode* SLTBuyNode(SLTDataType x){
    SLTNode* newnode =(SLTNode*) malloc(sizeof (SLTNode));
    if(newnode==NULL){
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
}

void SLTPushBack(SLTNode** pphead, SLTDataType x) {
    assert(pphead);
    SLTNode* newnode= SLTBuyNode(x);
    if(*pphead==NULL){
        *pphead = newnode;
    }
    else{
        SLTNode* ptail= *pphead;
        while(ptail->next!=NULL){
            ptail=ptail->next;
        }
        ptail->next=newnode;
    }
}

void SLTPushFront(SLTNode** pphead, SLTDataType x){
    assert(pphead);
    SLTNode* newnode= SLTBuyNode(x);
    newnode->next=*pphead;
    *pphead=newnode;
}

void SLTPopBack(SLTNode** pphead){
    assert(pphead && *pphead);
    if((*pphead)->next==NULL){
        free(*pphead);
        *pphead=NULL;
    }
    else{
        SLTNode* prev=*pphead;
        SLTNode* ptai=*pphead;
        while(ptai->next){
            prev=ptai;
            ptai=ptai->next;
        }
        free(ptai);
        ptai=NULL;
        prev->next=NULL;
    }
}

void SLTPopFront(SLTNode** pphead){
    assert(pphead&&*pphead);
    SLTNode *next=(*pphead)->next;
    free(*pphead);
    *pphead=next;
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x){
    SLTNode *curnode= phead;
    while (curnode!=NULL){
        if(curnode->data==x){
            return curnode;
        }
        curnode=curnode->next;
    }

}
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x){
    SLTNode *insert= SLTBuyNode(x);
    assert(pphead&&*pphead);
    assert(pos);

    if(*pphead==pos)
        SLTPushFront(pphead,x);
    else{
        SLTNode *prev=*pphead;
        while(prev->next!=pos){
            prev=prev->next;
        }
        prev->next=insert;
        insert->next=pos;
    }
}

void SLTErase(SLTNode** pphead, SLTNode* pos){
    assert(pphead && *pphead);
    assert(pos);

    if(pos==*pphead){
        SLTPopFront(pphead);
    }
    else{
        SLTNode *prev=*pphead;
        while(prev->next!=pos){
            prev=prev->next;
        }
        prev->next=pos->next;
        free(pos);
        pos=NULL;

    }

}


void SLTInsertAfter(SLTNode* pos, SLTDataType x){
    assert(pos);
    SLTNode *insert= SLTBuyNode(x);
    insert->next=pos->next;
    pos->next=insert;
}

void SLTEraseAfter(SLTNode* pos){
    assert(pos && pos->next);
    SLTNode *del=pos->next;
    pos->next=del->next;
    free(del);
    del=NULL;

}

void SListDesTroy(SLTNode** pphead){
    assert(pphead && *pphead);
    SLTNode *pcur=*pphead;
    while (pcur){
        SLTNode *next=pcur->next;
        free(pcur);
        pcur=next;
    }
    *pphead=NULL;
}