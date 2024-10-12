typedef struct 
{
    ElemType stack[MaxStackSize];
    int top;
}SequenceStack;

/*初始化顺序栈S*/
void StackInitiate(SequenceStack *S)
{
    S->top = 0; /*定义初始栈顶的下标值*/
}

/*判断顺序栈S是否为空*/
int StackNotEmpty(SequenceStack S)
{
    if (S.top <= 0)
        return 0;
    else
        return 1;
}

/*进栈*/
int StackPush(SequenceStack *S, ElemType x)
{
    if (S->top >= MaxStackSize)
    {
        printf("Stack is full and cannot be inserted!\n");
        return 0;   /*操作失败返回0*/
    }
    else
    {
        S->stack[S->top] = x;
        S->top++;
        return 1;   /*入栈成功返回1*/
    }
}

/*出栈*/
int StackPop(SequenceStack *S, ElemType *d)
{
    if (S->top <= 0)
    {
        printf("Stack is empty and no data out!\n");
        return 0;   /*操作失败返回0*/
    }
    else
    {
        S->top--;
        *d = S->stack[S->top];  /*将栈顶元素值赋予参数d*/
        return 1;   /*出栈成功返回1*/
    }
}

/*取栈顶元素*/
int StackTop(SequenceStack S, ElemType *d)
{
    if (S.top <= 0)
    {
        printf("Stack is full!\n");
        return 0;
    }
    else
    {
        *d = S.stack[S.top - 1];    /*当前栈顶元素赋予参数d*/
        return 1;
    }
}