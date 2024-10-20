#include <stdio.h>  
#include <string.h>  

#define MAX_LEN 255  
  
typedef struct   
{  
    char ch[MAX_LEN];  
    int len;  
} String;  
  
// 初始化s为空串。  
void InitStr(String *S)  
{  
    S->len = 0;    
    S->ch[0] = '\0';     
}  
  
// 将chars的值赋给S。chars的实际参数是串变量。  
void StrAssign(String *T, String chars)  
{  
    strcpy(T->ch, chars.ch);    
    T->len = chars.len;    
}  
  
// 比较s和t。若s>t，返回值>0；若s=t，返回值=0；若s<t，返回值<0。  
int StrCompare(String S, String T)  
{  
    int minLen = S.len < T.len ? S.len : T.len;    
    for (int i = 0; i < minLen; i++) {    
        if (S.ch[i] != T.ch[i]) {    
            return S.ch[i] - T.ch[i];    
        }    
    }    
    return S.len - T.len;    
}  
  
// 返回s中的元素个数，即该串的长度。  
int StrLength(String S)  
{  
    return S.len;    
}  
  
// 返回由s和t联接而成的新串。  
int Concat(String *S, String T)  
{  
    if (StrLength(*S) + StrLength(T) > MAX_LEN - 1)  
    {    
        // 溢出处理    
        return 0;    
    }    
    strcat(S->ch, T.ch);    
    S->len += StrLength(T);    
    return 1;    
}  
  
// 当1<=pos<=StrLength(s)且0<=len<=StrLength(s)- pos+1时，  
// 返回s中第pos个字符起长度为len的子串，否则返回空串。  
void SubString(String *Sub, String S, int pos, int len)  
{  
    if (pos < 1 || pos > S.len || len < 0 || pos + len - 1 > S.len)   
    {    
        InitStr(Sub);    
    }   
    else  
    {    
        strncpy(Sub->ch, S.ch + pos - 1, len);    
        Sub->ch[len] = '\0';    
        Sub->len = len;    
    }    
}  
  
// 查找并替换子串  
int Replace(String *S, String T, String V)  
{  
    char temp[MAX_LEN]; // 临时存储替换后的字符串  
    char *pos = S->ch;  
    int replaced = 0;  
    int len_T = T.len;  
    int len_V = V.len;  
    int original_len = S->len;  
  
    // 遍历主串，查找子串T  
    while ((pos = strstr(pos, T.ch)) != NULL)  
    {  
        int index = pos - S->ch; // 当前匹配到的子串T在主串S中的起始索引  
        int remaining_space = MAX_LEN - 1 - (index + len_T - original_len); // 剩余空间  
  
        if (len_V > remaining_space) // 检查替换后是否溢出  
        {  
            break; // 如果溢出，则不进行替换  
        }  
  
        // 拷贝替换前的部分到新字符串  
        strncpy(temp, S->ch, index);  
        temp[index] = '\0';  
  
        // 拼接替换后的子串V  
        strcat(temp, V.ch);  
  
        // 拷贝替换后的剩余部分到新字符串  
        strcat(temp, pos + len_T);  
  
        // 更新主串  
        strcpy(S->ch, temp);  
        S->len = strlen(S->ch);  
  
        // 更新查找位置  
        pos = S->ch + index + len_V;  
        replaced = 1; // 表示进行了替换  
    }  
  
    return replaced;  
}  
  
int main(void)  
{    
    String S = {"hello world, hello everyone", strlen("hello world, hello everyone")};    
    String T = {"hello", strlen("hello")};    
    String V = {"hi", strlen("hi")};    
      
    printf("Before Replace: %s\n", S.ch);    
    int flag = Replace(&S, T, V);    
    printf("After Replace: %s\n", S.ch);    
    if (flag)   
    {    
        printf("Replace occurred.\n");    
    }   
    else  
    {    
        printf("No replace.\n");    
    }    
      
    return 0;    
}