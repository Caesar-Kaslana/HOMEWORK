#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAX_STR_LEN 100  
#define SIZE 6  
  
// 学生信息结构体  
typedef struct
{  
    int id;  
    char name[50];  
    float grade;  
} StuInfo;  
  
//输入多个字符串并保存到file1.txt  
void inputStr() 
{  
    char str[MAX_STR_LEN];  
    FILE *file = fopen("file1.txt", "w");  
    if (file == NULL) 
    {  
        perror("Failed to open file1.txt");  
        exit(EXIT_FAILURE);  
    }  
  
    printf("Enter strings (type 'end' to finish):\n");  
    while (1) 
    {  
        printf("> ");  
        if (gets(str) == NULL || strcmp(str, "end") == 0) 
        {  
            break;  
        }  
        fputs(str, file);  
        fputs("\n", file);  // 保存每个字符串后添加换行符  
    }  
  
    fclose(file);  
  
    // 读取并显示文件中的字符串  
    file = fopen("file1.txt", "r");  
    if (file == NULL) 
    {  
        perror("Failed to open file1.txt");  
        exit(EXIT_FAILURE);  
    }  
  
    printf("\nStrings from file1.txt:\n");  
    while (fgets(str, MAX_STR_LEN, file) != NULL) 
    {  
        printf("%s", str);  
    }  
  
    fclose(file);  
}  
  
// 将结构体数组数据保存到file2.dat  
void save(StuInfo v_aStu[], int v_iN) 
{  
    FILE *file = fopen("file2.dat", "wb");  
    if (file == NULL) 
    {  
        perror("Failed to open file2.dat");  
        exit(EXIT_FAILURE);  
    }  
  
    fwrite(v_aStu, sizeof(StuInfo), v_iN, file);  
    fclose(file);  
}  
  
// 从文件中读取并显示结构体数组数据  
void print(char v_cStr[]) 
{  
    StuInfo students[SIZE];  
    FILE *file = fopen(v_cStr, "rb");  
    if (file == NULL) 
    {  
        perror("Failed to open file");  
        exit(EXIT_FAILURE);  
    }  
  
    size_t count = fread(students, sizeof(StuInfo), SIZE, file);  
    fclose(file);  
  
    printf("\nData from %s:\n", v_cStr);  
    for (size_t i = 0; i < count; i++) 
    {  
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);  
    }  
}  
  
// 将file2.dat中奇数编号的学生数据写入到file3.dat  
void writeOddIndexedStudents() 
{  
    StuInfo students[SIZE];  
    FILE *file2 = fopen("file2.dat", "rb");  
    if (file2 == NULL) 
    {  
        perror("Failed to open file2.dat");  
        exit(EXIT_FAILURE);  
    }  
  
    FILE *file3 = fopen("file3.dat", "wb");  
    if (file3 == NULL) 
    {  
        perror("Failed to open file3.dat");  
        fclose(file2);  
        exit(EXIT_FAILURE);  
    }  
  
    size_t count = fread(students, sizeof(StuInfo), SIZE, file2);  
    for (size_t i = 0; i < count; i++) 
    {  
        if (students[i].id % 2 != 0)
        {
            fwrite(&students[i], sizeof(StuInfo), 1, file3);  
        }
    }  
  
    fclose(file2);  
    fclose(file3);  
}  
  
int main(void) 
{  
    // 输入多个字符串并保存到file1.txt  
    inputStr();  
  
    // 初始化学生信息结构体数组并保存到file2.dat  
    StuInfo students[SIZE] = 
    {  
        {1, "Alice", 85.5},  
        {2, "Bob", 78.0},  
        {3, "Charlie", 92.3},  
        {4, "David", 65.8},  
        {5, "Eve", 88.0},  
        {6, "Frank", 76.5}  
    };  
    save(students, SIZE);  
  
    // 显示file2.dat中的数据  
    print("file2.dat");  
  
    // 将file2.dat中奇数编号的学生数据写入到file3.dat并显示  
    writeOddIndexedStudents();  
    print("file3.dat");  
  
    return 0;  
}