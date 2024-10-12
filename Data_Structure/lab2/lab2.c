#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType;
#include "Linkedlist.h"

int main(void)
{
    SingleLinkedList *head;
    int x;
    ListInitialize(&head);  /*初始化链表*/

    for (int i = 0; i < 20; i++)
        ListInsert(head, i);    /*生成一个整型递增有序链表*/
    printf("Initial list:\n");
    for (int i = 0; i < ListLength(head); i++)      /*打印初始链表*/
    {
        ListGet(head, i, &x);
        printf("%d ", x);
    }
    printf("\n");   

    printf("\nEnter delete number:");     /*输入需要删除的元素*/
    scanf("%d", &x);
    ListDelete(head, x);
    printf("After delete list:\n");     /*打印删除后的链表*/
    for (int i = 0; i < ListLength(head); i++)
    {
        ListGet(head, i, &x);
        printf("%d ", x);
    }
    printf("\n");

    printf("\nEnter insert number:");       /*输入需要插入的元素*/
    scanf("%d", &x);
    ListInsert(head, x);
    printf("After insert list:\n");
    for (int i = 0; i < ListLength(head); i++)      /*打印插入后的链表*/
    {
        ListGet(head, i, &x);
        printf("%d ", x);
    }

    Destroy(&head);     /*释放内存*/
    return 0;
}