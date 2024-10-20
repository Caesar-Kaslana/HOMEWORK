//SString.h

typedef struct
{
	char str[MaxSize];
	int length;
} String;
int Insert(String *S, int pos, String T)
/*在串S的pos位置插入子串T*/
{
	int i;
	if(pos < 0)
	{
		printf("参数pos出错！");
		return 0;
	}
	else if(S->length + T.length > MaxSize)
	{
		printf("数组空间不足无法插入！");
		return 0;
	}
	else
	{
		for(i = S->length-1; i >= pos; i--)
			S->str[i+T.length] = S->str[i];		/*为插入做准备*/
		for(i = 0; i < T.length; i++)
			S->str[pos+i] = T.str[i];				/*插入*/
		S->length += T.length;	
		return 1;
	}
}
int Delete(String *S, int pos, int len)
{
	int i;
	if(S->length <= 0)
	{
		printf("数组中未存放字符无元素可删! \n");
		return 0;
	}
	else if(pos < 0 || len < 0 || pos+len > S->length)
	{
		printf("参数pos和len出错");
		return 0;
	}
	else
	{
		for(i = pos+len; i <= S->length-1; i++)
			S->str[i-len] = S->str[i];				/*依次前移*/
		S->length -= len;						/*产生新的长度值*/
		return 1;
	}
}