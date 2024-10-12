typedef struct 
{
    ElemType list[MaxSize];
    int size;
}SequenceList;

void ListInitialize(SequenceList *L)  /*初始化顺序表*/
{
    L->size = 0;    /*定义初始数据的元素个数*/
}

int ListLength(SequenceList L)  /*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}

int ListInsert(SequenceList *L, int i, ElemType x)  /*在顺序表L的位置i(0<=i<=size)前插入数据元素值x，插入成功返回1，插入失败返回0*/
{
    int j;
    if (L->size >= MaxSize)
    {
        printf("The sequential table is full and cannot be inserted!\n");
        return 0;
    }
    else if (i < 0 || i > L->size)
    {
        printf("Parameter i is invalid!\n");
        return 0;
    }
    else
    {
        for (j = L->size; j > i; j--)   /*为插入做准备*/
        {
            L->list[j] = L->list[j - 1];
        }
        L->list[i] = x; /*插入*/
        L->size++;  /*元素个数加1*/
        return 1;
    }
}

/*删除顺序表L中位置i(0<=i<=size-1)的数据元素并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
int ListDelete(SequenceList *L, int i, ElemType *x)  
{
    int j;
    if (L->size <= 0)
    {
        printf("The sequential table is empty and there is no data to delete!\n");
        return 0;
    }
    else if (i < 0 || i > L->size - 1)
    {
        printf("Parameter i is invalid!\n");
        return 0;
    }
    else
    {
        *x = L->list[i];    /*保存删除的元素到参数x中*/
        for (j = i + 1; j <= L->size - 1; j++)
        {
            L->list[j - 1] = L->list[j];    /*依次前移*/
        }
        L->size--;  /*数据元素个数减1*/
        return 1;
    }
}

/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
int ListGet(SequenceList L, int i, ElemType *x) 
{
    if (i < 0 || i> L.size - 1)
    {
        printf("Parameter i is invalid!\n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}

