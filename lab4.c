#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数声明  
void inv(int *x, int n);
char *seaBackStr(char *v_sS, char *v_s);
void OddEvenArrange(int v_iArr[], int n);

int main(void)
{
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    inv(num, 10);   // 调用反转数组函数  
    for (int i = 0; i < 10; i++)    // 打印反转后的数组  
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    char* mainStr = "Data Structure";   // 主字符串  
    char* subStr = "Stru";   // 子字符串 
    char* result = seaBackStr(mainStr, subStr);  // 查找子字符串后面的部分  
    if (result != NULL) 
    {  
        printf("Result: %s\n", result);  
        free(result);
    } 
    else 
    {  
        printf("Result: NULL\n");  
    }  

    OddEvenArrange(num, 10);    // 调用重新排列奇偶数的函数  
    for (int i = 0; i < 10; i++)    // 打印重新排列后的数组 
    {
        printf("%d ", num[i]);
    }

    return 0;
}

void inv(int *x, int n)
{
    int *left = x;  // 指向数组左端  
    int *right = x + n - 1;     // 指向数组右端
    int temp;

    while (left < right)    // 当左指针小于右指针时 
    {
        temp = *left;   // 交换左右指针指向的元素  
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

char *seaBackStr(char *v_sS, char *v_s)
{
    char *pos = strstr(v_sS, v_s);      // 在主字符串中查找子字符串 
    if (pos == NULL) 
    {  
        return NULL;  
    }  

    char *end_of_substr = pos + strlen(v_s);     // 子字符串结束的位置  
    if (*end_of_substr == '\0') 
    {  
        return NULL;  
    }  
      
    char *result = (char *)malloc(strlen(end_of_substr) + 1);  // 动态分配内存存储结果 
    if (result == NULL) 
    {  
        return NULL;  
    }  
      
    strcpy(result, end_of_substr);  // 复制子字符串后面的部分到结果字符串 
      
    return result;  
}

void OddEvenArrange(int v_iArr[], int n)
{
    int left = 0, right = n - 1;  // 左右指针初始化  
    while (left < right) 
    {  
        while (left < right && v_iArr[left] % 2 == 0) // 左指针指向偶数时右移 
            left++; 

        while (left < right && v_iArr[right] % 2 != 0) // 右指针指向奇数时左移 
            right--; 

        if (left < right) // 当左右指针未相遇时，交换奇偶数
        {  
            int temp = v_iArr[left];  
            v_iArr[left] = v_iArr[right];  
            v_iArr[right] = temp;  
        }
    }
}
