typedef struct
{
    ElemType queue[MaxQueueSize];
    int front;   /*队头指针*/
    int count;  /*计数器*/
}SequenceQueue;

/*初始化循环队列Q*/
void QueueInitiate(SequenceQueue *Q)
{
    Q->front = 0;
    Q->count = 0;
}

/*判断队列是否为空*/
int QueueNotEmpty(SequenceQueue Q)
{
    /*空队列返回0，否则返回1*/
    if (Q.count == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*入队列，在队尾插入元素x*/
int QueueAppend(SequenceQueue *Q, ElemType x)
{
    /*成功入队返回1，否则返回0*/
    if (Q->count == MaxQueueSize)
    {
        printf("Queue is Full!");
        return 0;
    }
    else
    {
        Q->queue[(Q->front + Q->count) % MaxQueueSize] = x;
        Q->count++;
        return 1;
    }
}

/*出队列，把队列Q的队头元素删除并由参数d带回。*/
int QueueDelete(SequenceQueue *Q, ElemType *d)
{
    /*成功出队返回1，失败返回0*/
    if (Q->count == 0)
    {
        printf("Queue is emtpy!");
        return 0;
    }
    else
    {
        *d = Q->queue[Q->front];
        Q->front = (Q->front + 1) % MaxQueueSize;
        Q->count--;
        return 1;
    }
}

/*获取队头元素并赋值给d*/
int QueueGet(SequenceQueue *Q, ElemType *d)
{
    /*成功返回1,失败返回0*/
    if (Q->count == 0)
    {
        printf("Queue is emtpy, no data can get!");
        return 0;
    }
    else
    {
        *d = Q->queue[Q->front];
        return 1;
    }
}