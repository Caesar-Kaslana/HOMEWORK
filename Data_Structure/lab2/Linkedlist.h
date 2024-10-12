/*单链表结点的结构体定义*/
typedef struct SingleNode
{
    ElemType data;
    struct SingleNode *next;
}SingleLinkedList, *LinkList;

/*单链表初始化*/
void ListInitialize(SingleLinkedList **head)
/*如果有内存空间，申请头结点空间并使头指针head指向头结点*/
{
    if ((*head = (SingleLinkedList*)malloc(sizeof(SingleLinkedList))) == NULL)
        exit(1);
    (*head)->next = NULL;   /*置链尾标记NULL*/
}

/*求线性表的长度*/
int ListLength(SingleLinkedList *head)
{
    SingleLinkedList *p = head;     /*p指向头结点*/
    int size = 0;                   /*size初始为0*/
    while (p->next != NULL)         /*循环计数*/
    {
        p = p->next;
        size++;
    }

    return size;
}

/*取数据元素*/
int ListGet(SingleLinkedList *head, int i, ElemType *x)
/*取序号为i的数据元素的值*/
{
    SingleLinkedList *p;
    int j;
    p = head;
    j = -1;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }

    if (j != i)
    {
        printf("Get Error!");
        return 0;
    }
    *x = p->data;
    return 1;
}

/*插入数据元素操作*/
void ListInsert(SingleLinkedList *head, ElemType x)
{
    SingleLinkedList *curr, *pre, *q;
    pre = head;               /*pre指向头结点*/
    curr = head->next;

    while (curr != NULL && curr->data <= x)
    {
        pre = curr;
        curr = curr->next;
    }

    /*生成新结点由指针q指示*/
    if ((q = (SingleLinkedList *)malloc(sizeof(SingleLinkedList))) == NULL)
        exit(1);
    q->data = x;
    q->next = pre->next;      /*给指针q->next赋值*/
    pre->next = q;            /*给指针pre->next赋值*/
}

/*删除数据元素x操作*/
int ListDelete(SingleLinkedList *head, ElemType x)
{
    SingleLinkedList *p, *s;
    p = head;   /*p指向头结点*/

    while (p->next != NULL && p->next->data != x ) /*p指向需删除元素的前一个结点*/
    {
        p = p->next;
    }

    if (p->next != NULL)
    { 
        s = p->next;    /*指针s指向需删除元素的结点*/
        p->next = s->next;      /*删除数据元素x*/
        free(s);        /*释放指针s所指向结点的内存空间*/
        return 1;
    }
    else
    {
        printf("Delete Error!\n");    /*删除错误返回0*/
        return 0;
    }
}

/*单链表释放操作*/
void Destroy(SingleLinkedList **head)
{
    SingleLinkedList *p, *p1;
    p = *head;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}

// int ListDelete(SingleLinkedList *head, int i, ElemType *x)
// {
//     SingleLinkedList *p, *s;
//     int j = 0;
//     p = head;   /*p指向第一个结点*/
//     while (p->next != NULL && p->next->next != NULL && j < i - 1)
//     /*让指针p指向需删除元素的前一个结点*/
//     {
//         p = p->next;
//         j++;
//     }

//     if (j != i - 1)
//     {
//         printf("删除位置参数错误！");
//         return 0;
//     }
    
//     s = p->next;    /*指针s指向需删除元素的结点*/
//     *x = s->data;   /*将指针s所指结点的数据元素域值赋予x*/
//     p->next = s->next;  /*删除结点*/
//     free(s);    /*释放内存空间*/
//     return 1;
// }