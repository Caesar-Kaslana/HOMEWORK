#include <stdio.h>
#include<string.h>
#define MaxSize 100
#include"SString.h"
/*int BFIndex(String *S, int start, String T)
{ int i=start,j=0;
  while(i<S->length && j<T.length)
  {
	  if(S->str[i]==T.str[j])  
	  {
		  i++;j++;
	  }
	  else
	  { 
		  i=i-j+1;j=0;
	  }
  }
  if(j==T.length) return i-j;
  return -1;
 }*/
void GetNext(String T, int next[])
/*求模式串t的next[j]值存于next[]中*/
{	int j = 1, k = 0;
	next[1] = 0;
	while(j <= T.length)
	{
		if(k==0 || T.str[j] == T.str[k])
		{        j++;k++;next[j] = k;
		}	
		else 
			k = next[k];
	}
}

int Index_KMP(String S,String T,int pos)
/*利用子串T的next函数，求T在主串S中第pos个字符之后的位置的KMP算法。*/
/*若不存在，则函数值为0。其中，T非空，1≤pos≤S.length*/
{   void GetNext(String T, int next[]);
	int i=pos;		/*i表示主串S中当前位置下标*/
	int j=1;		/*j表示子串T中当前位置下标*/
	int next[20];
	GetNext(T,next);
	while(i<S.length && j<T.length)
	{
		if(j==0 || S.str[i]==T.str[j]) 	/*注意，增加了j==0的判断*/
		  {  i++;		    j++; }
          else 
             j=next[j];    	/*若字符不相等，i不用回溯，只j值回溯*/
	}
	if(j>=T.length)	   
		return i-T.length+1; 		    /*匹配成功*/
	else
	    return 0;     }

int Replace(String *s,int start,String t,String v)
{
	int i;
    //i=BFIndex(s,start,t);
	i=Index_KMP(*s,t,start);	
	printf("模式串位置为：%d\n",i);
	if(i==0) return 0;
	else
	{  
		Delete(s,i-1,t.length);
		Insert(s,i-1,v);
	}
	return 1;
}

void main(void)
{
	String	myString1 , myString2 ,	myString3;
	int i,start=1;
	printf("请输入主串myString1\n");
	scanf("%s",myString1.str );
	printf("请输入被替换的子串myString2\n");
	scanf("%s",myString2.str);
	printf("请输入替换的子串myString3\n");
	scanf("%s",myString3.str);
	myString1.length=strlen(myString1.str);
	myString2.length=strlen(myString2.str);
	myString3.length=strlen(myString3.str);
	if(Replace(&myString1,start,myString2,myString3)==0)
		printf("不成功\n");
	else
	    for(i=0;i<myString1.length ;i++)
			printf("%c",myString1.str[i]);
}
