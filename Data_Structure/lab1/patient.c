#include <stdio.h>
#include <string.h>
#define MaxSize 100
#define N 2

typedef struct 
{
    char number[5];
    char name[20];
    char symptom[50];
}patient;

typedef patient ElemType;
#include "SequenceList.h"

int ListFind(SequenceList L,char *x);

int main(void)
{
    patient s;
    SequenceList mylist;
    int i;
    ListInitialize(&mylist);    /*顺序表初始化*/

    for (i = 0; i < N; i++)     /*输入数据*/
    {
        printf("------Input %d Patient Information\n", i + 1);
        printf("Input %d Patient number:", i + 1);
        scanf("%s", s.number);
        printf("Input %d Patient name:", i + 1);
        scanf("%s", s.name);
        printf("Input %d Patient symptom:", i + 1);
        scanf("%s", s.symptom);
        ListInsert(&mylist, i, s);      /*插入到顺序表中*/
    }
    printf("\n*****Data in a sequential table*****\n");
    for (i = 0; i < ListLength(mylist); i++)
    {
        ListGet(mylist, i, &s);
        printf("%s %s %s\n", s.number, s.name, s.symptom);
    }

    char find_name[20];     /*存储要查找的患者姓民*/
    printf("\nPlease enter the name of the person you want to find:");
    scanf("%s", find_name);
    i = ListFind(mylist, find_name);
    if (i != -1)
    {
        ListGet(mylist, i, &s);     /*取出病人信息*/
        printf("%s %s %s\n", s.number, s.name, s.symptom);
    }
    else
    {
        printf("Not Found");
    }

    return 0;
}

/*在线性表L中查找数据元素x，如果存在则返回线性表中和x值相等的第1个数据元素的序号；如果不存在，则返回-1。*/
int ListFind(SequenceList L, char *x) 
{  
    int i;  
    for (i = 0; i < L.size; i++) 
    {  
        if (strcmp(L.list[i].name, x) == 0)
        {  
            return i;  
        }  
    }  
    return -1;  
}