#include <stdio.h>

typedef char ElemType;
#define MaxStackSize 100
#include "SequenceStack.h"

int bracketMatching(char *expression);

int main(void)
{
    char *expr1 = "[(1+2)*3-1]+[((1+2]*3)-1]";
    char *expr2 = "[(1+2)*3-1]+[(1+2)*3-1]";

    if (bracketMatching(expr1))
        printf("[(1+2)*3-1]+[((1+2]*3)-1] is True\n");
    else
        printf("[(1+2)*3-1]+[((1+2]*3)-1] is False\n");

    if (bracketMatching(expr2))
        printf("[(1+2)*3-1]+[(1+2)*3-1] is True\n");
    else
        printf("[(1+2)*3-1]+[(1+2)*3-1] is False\n");

    return 0;
}

int bracketMatching(char *expression)
{
    SequenceStack tempStack;
    StackInitiate(&tempStack);  /*初始化栈*/
    char popchar;

    for (int i = 0; expression[i] != '\0'; i++) /*遍历并匹配括号，失败返回0*/
    {
        char expr = expression[i];
        switch (expr)
        {
        case '(':
        case '[':
        case '{':
            StackPush(&tempStack, expr);
            break;
        case ')':
            StackPop(&tempStack, &popchar);
            if (popchar != '(')
            {   
                return 0;
            }
            break;
        case ']':
            StackPop(&tempStack, &popchar);
            if (popchar != '[')
            {   
                return 0;
            }
            break;
        case '}':
            StackPop(&tempStack, &popchar);
            if (popchar != '{')
            {   
                return 0;
            }
            break;        
        default:
            break;
        }       
    }

    /*判断栈是否还存在左括号*/
    if (StackNotEmpty(tempStack))
    {
        return 0;
    }

    return 1;
}