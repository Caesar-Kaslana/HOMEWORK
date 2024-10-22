#include <stdio.h>
#include <malloc.h>

int **Get2DArray(int row, int col);
void Destroy2DArray(int **a, int row);
void multiplyArray(int *arrayA, int *arrayB, int **arrayC, int n);
void printCompressedArray_to2D(int *array, int n);

int main(void)
{
    /*定义三阶对称矩阵*/
    int n = 3;  
    /*对称矩阵A的压缩存储 */
    int ArraycompressedA[] = {1, 2, 3, 4, 5, 6};
    /*对称矩阵B的压缩存储 */
    int ArraycompressedB[] = {7, 8, 9, 10, 11, 12};

    int** C = Get2DArray(n, n);
    /*矩阵C = 矩阵A * 矩阵B*/  
    multiplyArray(ArraycompressedA, ArraycompressedB, C, n);  

    /*将压缩矩阵A按矩阵方式输出*/
    printf("Matrix A:\n");  
    printCompressedArray_to2D(ArraycompressedA, n);  
  
    /*将压缩矩阵B按矩阵方式输出*/
    printf("Matrix B:\n");  
    printCompressedArray_to2D(ArraycompressedB, n);  
    
    /*输出矩阵C*/
    printf("Matrix C (A * B):\n");  
    for (int i = 0; i < n; i++) 
    {  
        for (int j = 0; j < n; j++) 
        {  
            printf("%5d", C[i][j]);  
        }  
        printf("\n");  
    }  

    /*释放内存*/
    Destroy2DArray(C, n);
}

/*创建row行col列的二维动态数组，函数返回其首地址*/
int **Get2DArray(int row, int col)
{
    int **a;
    a = (int **)calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        a[i] = (int *)calloc(col, sizeof(int));
    }

    return a;
}

/*销毁二维数组*/
void Destroy2DArray(int **a, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(a[i]);
    }
    free(a);
}

void multiplyArray(int *arrayA, int *arrayB, int **arrayC, int n)
{
    /*temp用于临时存储压缩矩阵转为n阶矩阵的值*/
    int **tempA =Get2DArray(n, n);
    int **tempB =Get2DArray(n, n);

    /*k为一维数组(存储压缩矩阵)的下标序号*/
    int k;
    /*数学中，n阶对称矩阵元素的下标满足条件：1<=i<=n和1<=j<=n*/
    for (int i = 1, row = 0; i <= n; i++, row++)
    {
        for (int j = 1, col = 0; j <= n; j++, col++)
        {
            if (i >= j)
            {
                k = i * (i - 1) / 2 + j - 1;
            }
            else
            {
                k = j * (j - 1) / 2 + i - 1;
            }
            tempA[row][col] = arrayA[k];
            tempB[row][col] = arrayB[k];
        }
    }
    
    /*将矩阵A乘矩阵B，结果存储在矩阵C*/
    for (int row = 0; row < n; row++)
    {   
        for (int col = 0; col < n; col++)
        {
            for (int k = 0; k < n; k++)
            {   
                /*矩阵C的第i行第j列的元素是A的第i行与B的第j列对应元素乘积的和*/
                arrayC[row][col] +=  tempA[row][k] * tempB[k][col];
            }
        }    
    }

    /*释放内存*/
    Destroy2DArray(tempA, n);
    Destroy2DArray(tempB, n);       
}

/*将一个压缩矩阵以矩阵方式输出元素*/
void printCompressedArray_to2D(int *array, int n)
{
    /*k为一维数组(存储压缩矩阵)的下标序号*/
    int k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                k = i * (i - 1) / 2 + j - 1;
            }
            else
            {
                k = j * (j - 1) / 2 + i - 1;
            }            
            printf("%5d", array[k]);
        }
        printf("\n");
    }
}