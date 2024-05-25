#include "slist.h"

SLTNode *FindByName(contact* con,char name[]){
    while(con->next!= NULL){
        if(con->data.name == name){
            return con;
        }
        con=con->next;
    }
    return NULL;
}

void AddContact(contact** con){

    PeoInfo info;
    printf("请输入要添加的联系人姓名:\n");
    scanf("%s", info.name);

    printf("请输入要添加的联系人性别:\n");
    scanf("%s", info.sex);

    printf("请输入要添加的联系人年龄:\n");
    scanf("%d", &info.age);

    printf("请输入要添加的联系人电话:\n");
    scanf("%s", info.tel);

    printf("请输入要添加的联系人住址:\n");
    scanf("%s", info.addr);

    SLTPushBack(con,info);
}

void DelContact(contact** con){
    char name[NAME_MAX];
    printf("请输入要删除的联系人姓名:\n");
    scanf("%s", name);
     SLTNode *pos = FindByName(*con,name);
    if (pos==NULL)
    {
        printf("要删除的联系人数据不存在！\n");
        return;
    }
    SLTErase(con,pos);
    printf("删除成功！\n");
}

void ShowContact(contact* con){
    printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
    while(con->next!=NULL)
    {
        printf("%3s %3s %3d %3s %3s\n", //手动调整一下格式
               con->data.name,
               con->data.sex,
               con->data.age,
               con->data.tel,
               con->data.addr);
    }
}


void FindContact(contact* con){
    char name[NAME_MAX];
    printf("请输入要查找的联系人姓名\n");
    scanf("%s", name);
    SLTNode *find = FindByName(con, name);
    if (find==NULL)
    {
        printf("要查找的联系人数据不存在！\n");
        return;
    }
    printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
    printf("%3s %3s %3d %3s %3s\n",
           con->data.name,
           con->data.sex,
           con->data.age,
           con->data.tel,
           con->data.addr);
    }

void ModifyContact(contact** con){
    char name[NAME_MAX];
    printf("请输入要修改的用户姓名：\n");
    scanf("%s", name);

    SLTNode *find = FindByName(con, name);
    if (find == NULL)
    {
        printf("要修改的联系人数据不存在！\n");
        return;
    }
    printf("请输入新的姓名：\n");
    scanf("%s", (*con)->data.name);

    printf("请输入新的性别：\n");
    scanf("%s", (*con)->data.sex);

    printf("请输入新的年龄：\n");
    scanf("%d", (*con)->data.age);

    printf("请输入新的电话：\n");
    scanf("%s", (*con)->data.tel);

    printf("请输入新的住址：\n");
    scanf("%s", (*con)->data.addr);

    printf("修改成功！\n");
}


void DestroyContact(contact** con){
    SListDesTroy(con);
}

