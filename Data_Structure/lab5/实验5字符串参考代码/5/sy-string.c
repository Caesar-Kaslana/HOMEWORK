#include <stdio.h>
#include <string.h>
#define MaxSize 100
#include "SString.h"
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
/*��ģʽ��t��next[j]ֵ����next[]��*/
{
	int j = 1, k = 0;
	next[1] = 0;
	while (j <= T.length)
	{
		if (k == 0 || T.str[j] == T.str[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int Index_KMP(String S, String T, int pos)
/*�����Ӵ�T��next��������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨��*/
/*�������ڣ�����ֵΪ0�����У�T�ǿգ�1��pos��S.length*/
{
	void GetNext(String T, int next[]);
	int i = pos; /*i��ʾ����S�е�ǰλ���±�*/
	int j = 1;	 /*j��ʾ�Ӵ�T�е�ǰλ���±�*/
	int next[20];
	GetNext(T, next);
	while (i < S.length && j < T.length)
	{
		if (j == 0 || S.str[i] == T.str[j]) /*ע�⣬������j==0���ж�*/
		{
			i++;
			j++;
		}
		else
			j = next[j]; /*���ַ�����ȣ�i���û��ݣ�ֻjֵ����*/
	}
	if (j >= T.length)
		return i - T.length + 1; /*ƥ��ɹ�*/
	else
		return 0;
}

int Replace(String *s, int start, String t, String v)
{
	int i;
	// i=BFIndex(s,start,t);
	i = Index_KMP(*s, t, start);
	printf("ģʽ��λ��Ϊ��%d\n", i);
	if (i == 0)
		return 0;
	else
	{
		Delete(s, i - 1, t.length);
		Insert(s, i - 1, v);
	}
	return 1;
}

void main(void)
{
	String myString1, myString2, myString3;
	int i, start = 1;
	printf("����������myString1\n");
	scanf("%s", myString1.str);
	printf("�����뱻�滻���Ӵ�myString2\n");
	scanf("%s", myString2.str);
	printf("�������滻���Ӵ�myString3\n");
	scanf("%s", myString3.str);
	myString1.length = strlen(myString1.str);
	myString2.length = strlen(myString2.str);
	myString3.length = strlen(myString3.str);
	if (Replace(&myString1, start, myString2, myString3) == 0)
		printf("���ɹ�\n");
	else
		for (i = 0; i < myString1.length; i++)
			printf("%c", myString1.str[i]);
}
