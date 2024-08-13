// 2. P45第3题//顺序表逆置
// 题目要求：以顺序表作为存储结构，写一个实现线性表的就地(即使用尽可能少的附加空间)逆置的算法，
// 在原表的存储空间内将线性表(a1，a2,.. .,an)逆置为(an,.. .,a2,a1)。
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef char datatype;
#define MAXSIZE 1024
typedef struct
{
    datatype data[MAXSIZE];
    int last;
} sequenlist;
sequenlist *create();
void print(sequenlist *L);
void invert(sequenlist *L);

int main(void)
{
    sequenlist *L;
    printf("***************请创建顺序表(输入#代表结尾)*****************\n");
    L = create(); // 建立顺序表
    printf("****************输出顺序表******************\n");
    print(L);  // 输出顺序表
    invert(L); // 调用顺序表逆值的函数
    printf("************输出逆置后的顺序表**************\n");
    print(L); // 输出顺序表
    system("pause");
    return 0;
}
sequenlist *create()
{
    sequenlist *L = (sequenlist *)malloc(sizeof(sequenlist));
    L->last = -1;
    char ch;
    while ((ch = (char)getchar()) != '#')
    {
        L->data[++(L->last)] = ch;
    }
    return L;
}
void print(sequenlist *L)
{
    for (int i = 0; i <= L->last; i++)
    {
        printf("%c", L->data[i]);
    }
    puts("\n");
}
void invert(sequenlist *L)
{
    datatype new[MAXSIZE];
    for (int i = 0; i <= L->last; i++)
    {
        new[i] = L->data[L->last - i];
    }
    for (int i = 0; i <= L->last; i++)
    {
        L->data[i] = new[i];
    }
}