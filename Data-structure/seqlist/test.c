#include "seqlist.h"
void menu()
{
    printf("******************通讯录******************\n");
    printf("*******1.增加联系人   2.删除联系人********\n");
    printf("*******3.修改联系人   4.查找联系人********\n");
    printf("*******5.展示联系人   0.   退出  *********\n");
    printf("******************************************\n");
}

int main()
{
    int op = -1;
    contact con;
    InitContact(&con);
    do {
        menu();
        printf("请选择您的操作：\n");
        scanf("%d", &op);

        //要根据对应的op执行不同的操作
        switch (op)
        {
            case 1:
                AddContact(&con);
                break;
            case 2:
                DelContact(&con);
                break;
            case 3:
                ModifyContact(&con);
                break;
            case 4:
                FindContact(&con);
                break;
            case 5:
                ShowContact(&con);
                break;
            case 0:
                printf("退出通讯录....\n");
                break;
            default:
                printf("输入错误，请重新选择您的操作！\n");
                break;
        }
    } while (op != 0);

    DestroyContact(&con);
    return 0;
}