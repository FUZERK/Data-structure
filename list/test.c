#include "list.h"

int main(){
    LTNode *plist = LTInit();
    LTPushFront(plist,4);
    LTPrint(plist);
    return 0;
}