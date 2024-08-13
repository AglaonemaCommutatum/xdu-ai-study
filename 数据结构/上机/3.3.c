// P74 第 4 题：利用栈的基本运算将栈 S 中值为 m 的元素全部删除。
#include <stdio.h>
#include <malloc.h>
#define maxsize 1024
typedef char datatype;
typedef struct stack
{
    datatype data[maxsize];
    int Top;
} seqstack;
seqstack *Initstack();
void Delete(seqstack *s, datatype m);
void Push(seqstack *s, datatype m);
datatype Pop(seqstack *s);
// int EmptyS(seqstack *s);
void Print(seqstack *s);
int main(void)
{
    seqstack *s;
    datatype m;
    printf("***********************请输入 m: ***********************\n");
    scanf("%c", &m);
    printf("***********************请初始化栈 s: ***********************\n");
    s = Initstack();
    printf("***********************输出栈 s: ***********************\n");
    Print(s);
    Delete(s, m); // 调用删除函数
    printf("\n******************** 输 出 删 除 m 之 后 的 栈 s:***********************\n");
    Print(s);
    system("pause");
    return 0;
}
void Delete(seqstack *s, datatype m)
{
    datatype m2;
    seqstack *ss = (seqstack *)malloc(sizeof(seqstack));
    ss->Top = 0;
    m2 = Pop(s);
    while (m2 != NULL)
    {
        if (m2 != m)
            Push(ss, m2);
        m2 = Pop(s);
    }
    // if (m2 != m)
    //     Push(ss, m2);
    m2 = Pop(ss);
    while (m2 != NULL)
    {
        Push(s, m2);
        m2 = Pop(ss);
    }
    // Push(s, m2);
}
seqstack *Initstack()
{
    seqstack *s;
    s = (seqstack *)malloc(sizeof(seqstack));
    s->Top = 0;
    char m;
    scanf("%c", &m);
    while (m != '#')
    {
        Push(s, m);
        scanf("%c", &m);
    }
    return s;
}
void Push(seqstack *s, datatype m)
{
    s->data[++(s->Top)] = m;
}

datatype Pop(seqstack *s)
{
    if (s->Top != 0)
        return s->data[(s->Top)--];
    else
        return NULL;
}
void Print(seqstack *s)
{
    for (int i = 1; i <= s->Top; i++)
    {
        printf("%c", s->data[i]);
    }
    puts("\n");
}
/*
f
affffffasdfdsa#
*/