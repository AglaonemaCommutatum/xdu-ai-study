#include <stdio.h>
#include <malloc.h>
#include <string.h>
// 定义字符串类型
#define maxsize 256
typedef struct
{
    char ch[maxsize];
    int len;
} seqstring;
seqstring *makestr();
void print(seqstring *L);
int symmetry(seqstring *str); // 判字符串是否中心对称的函数声明
int main()
{
    seqstring *str;
    printf("请初始化字符串: ");
    str = makestr();
    // print(str);
    if (symmetry(str))
        printf("\n判定结果：该字符串\"%s\"是回文\n\n", str->ch);
    else
        printf("\n判定结果：该字符串\"%s\"不是回文\n\n", str->ch);
    system("pause");
    return 0;
}
seqstring *makestr()
{
    seqstring *str = (seqstring *)malloc(sizeof(seqstring));
    str->len = -1;
    char ch;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == '\n')
        {
            break;
        }
        str->ch[++str->len] = ch;
    }
    return str;
}
void print(seqstring *L)
{
    for (int i = 0; i <= L->len; i++)
    {
        printf("%c", L->ch[i]);
    }
    puts("\n");
}
int symmetry(seqstring *str)
{
    int flag = 1;
    int len = str->len; // length
    for (int i = 0; i <= len; i++)
    {
        if (str->ch[i] != str->ch[len - i])
            flag = 0;
    }
    return flag;
}
/*
测试用例 1:
输入：
abdkgdkg
输出：
判定结果： 该字符串"abdkgdkg"不是回文
测试用例 2:
输入：
abdkgdk
输出：
判定结果： 该字符串"abdkgdkg"不是回文
测试用例 3:
输入：
abdkkdba
输出：判定结果： 该字符串" abdkkdba"是回文
测试用例 4:
输入：
abdkukdba
输出：
判定结果： 该字符串" abdkukdba"是回文

*/