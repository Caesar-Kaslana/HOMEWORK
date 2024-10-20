#include <stdio.h>  
#include <string.h>  

#define MAX_LEN 255  
  
typedef struct   
{  
    char ch[MAX_LEN];  
    int len;  
} String;

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