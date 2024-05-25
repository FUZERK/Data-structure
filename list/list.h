#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode*prev;
    struct ListNode*next;

}LTNode;


LTNode* LTInit();
void LTDestroy(LTNode* phead);
void LTPrint(LTNode* phead);


void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);
//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);
LTNode *LTFind(LTNode* phead,LTDataType x);