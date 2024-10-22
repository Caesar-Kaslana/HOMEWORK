#include <stdio.h>

#define MaxQueueSize 100
typedef int ElemType;
#include "SequenceQueue.h"

void YangHuiTriangle(int n);

int main(void)
{
    /*验证所设计的顺序循环队列的正确性*/
    SequenceQueue Q;
    //初始化队列
    QueueInitiate(&Q);

    //入队列操作
    QueueAppend(&Q, 10);  
    QueueAppend(&Q, 20);  
    QueueAppend(&Q, 30); 

    // 判断队列是否非空  
    if (QueueNotEmpty(Q)) 
    {  
        printf("Queue is not empty.\n");  
    } 
    else 
    {  
        printf("Queue is empty.\n");  
    }

    //获取队头元素
    int a;
    QueueGet(&Q, &a);
    printf("Queue head num is %d\n", a);

    // 出队列操作  
    int d;  
    while (QueueNotEmpty(Q)) 
    {  
        if (QueueDelete(&Q, &d)) 
        {  
            printf("Dequeued: %d\n", d);  
        }  
    }  

    // 判断队列是否非空  
    if (QueueNotEmpty(Q)) 
    {  
        printf("Queue is not empty.\n");  
    } 
    else 
    {  
        printf("Queue is empty.\n");  
    }

    int N;
    printf("Input the num of line:");
    scanf("%d", &N);    /*用户输入需要打印杨辉三角的行数*/
    YangHuiTriangle(N);
    return 0;
}

void YangHuiTriangle(int n)
{
    int temp, x;    /*temp用于临时存储队列中的元素，x用于获取队列中的元素*/
    SequenceQueue myQueue;
    QueueInitiate(&myQueue);    /*初始化的队列*/
    QueueAppend(&myQueue, 1);   /*第一行第一个元素1加入队列*/
    for (int m = 2; m <= n; m++)
    {
        QueueAppend(&myQueue, 1);   /*每行的第一个元素总是1*/
        /*打印和计算除了每行首尾元素之外的其他元素*/
        for (int i = 1; i <= m - 2; i++)
        {
            QueueDelete(&myQueue, &temp);   /*取出队列的第一个元素(上一行的元素)*/
            printf("%6d", temp);
            QueueGet(&myQueue, &x);     /*获取队列的当前第一个元素(下一行需要计算的元素之一)*/
            temp += x;      /*计算当前元素的值(上一行的两个元素之和)*/
            QueueAppend(&myQueue, temp);    /*将计算后的元素加入队列*/
        }
        /*打印每行的最后一个元素(它总是1的前一个元素)*/
        QueueDelete(&myQueue, &x);
        printf("%6d", x);
        /*每行的最后一个元素总是1*/
        QueueAppend(&myQueue, 1);
        printf("\n");
    }
    
    /*打印队列中的剩余元素*/
    while (QueueNotEmpty(myQueue))
    {
        QueueDelete(&myQueue, &x);
        printf("%6d", x);
    }
}