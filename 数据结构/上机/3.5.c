// 利用 C 的库函数 strlen、 strcpy 和 strncpy 写一算法 void
// StrDelete(char *S, int i, int m)，删去串 S 中从位置 i 开始的连续 m 个字符。若
// i≥strlen(S)，则没有字符被删除；若 i + m≥strlen(S)，则将 S 中从位置 i 开始直至末尾的字符均删去。
#include <stdio.h>
#include <string.h>
#include <malloc.h>
// 顺序串的结构类型定义
#define maxsize 100
typedef struct
{
    char str[maxsize];
    int len;
} seqstring;
void strPut(seqstring *s);
void strDelete(seqstring *s, int i, int m);
int main(void)
{
    seqstring *S;
    int i, m;
    S = (seqstring *)malloc(sizeof(seqstring));
    printf("*********************请输入字符串*********************： ");
    gets(S->str);
    S->len = strlen(S->str);
    printf("*********************输入的字符串显示如下*********************");
    strPut(S);
    printf("****************输入字符串的长度为： %d \n", S->len);
    printf("********************* 请 输 入 删 除 字 符 的 开 始 位 置 :********************\n");
    scanf("%d", &i);
    printf("\n********************* 请 输 入 要 删 除 的 字 符 个 数*********************\n");
    scanf("%d", &m);
    strDelete(S, i, m);
    printf("*****************删除子串后的字符串为*****************\n");
    strPut(S);
    puts("\n");
    system("pause");
    return 0;
}
void strPut(seqstring *s)
{
    printf("%s", s->str);
}
void strDelete(seqstring *s, int i, int m)
{
    if (i >= strlen(s->str))
        memset(s->str, 0, sizeof(s->str));
    else if (m + i >= strlen(s->str))
        strcpy(s->str + i - 1, s->str + strlen(s->str));
    else
        strcpy(s->str + i - 1, s->str + i + m - 1);
}
// 测试用例参考：（ 13 个字符为例）
// 输入字符串： abdeuyqwxzkjk
// 删除的开始位置： 9
// 删除的字符个数： 2
// 删除子串后的字符串: abdeuyqwkjk
// 测试用例参考：（ 13 个字符为例）
// 输入字符串： abdeuyqwxzkjk
// 删除的开始位置： 9
// 删除的字符个数： 8
// 删除子串后的字符串: abdeuyqw10
