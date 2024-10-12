#include <stdio.h>

typedef int ElemType;
#define MaxStackSize 100
#include "SequenceStack.h"

void conversion();

int main(void)
{
    conversion();
    return 0;
}

/*将十进制数转化为二进制数*/
void conversion()
{
    int decimal;
    SequenceStack myStack;
    StackInitiate(&myStack);
    scanf("%d", &decimal);  /*输入一个十进制数*/

    while (decimal)
    {
        StackPush(&myStack, decimal % 2);   /*每次将余数压进栈中*/
        decimal /= 2;
    }
    
    while (StackNotEmpty(myStack))
    {
        StackPop(&myStack, &decimal);   /*依次弹出栈中的元素就是相应的二进制的值*/
        printf("%d", decimal);
    }
}

