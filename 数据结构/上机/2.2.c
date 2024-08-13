#include <stdio.h>
#include <malloc.h>
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *next;
} linklist;
linklist *create();
void resolve(linklist *head, linklist *letter, linklist *digit, linklist *other);
void print1(linklist *head);
void print2(linklist *head);
int main()
{
    linklist *head, *letter, *digit, *other;
    head = create();
    printf("***************原链表为***************\n");
    print1(head);
    letter = (linklist *)malloc(sizeof(linklist)); // 建立 3 个空循环链表
    letter->next = letter;
    digit = (linklist *)malloc(sizeof(linklist));
    digit->next = digit;
    other = (linklist *)malloc(sizeof(linklist));
    other->next = other;
    resolve(head, letter, digit, other); // 调用分解单链表的函数
    printf("***************分解后的字母链表为***************\n");
    print2(letter); // 输出循环链表
    printf("***************分解后的数字链表为***************\n");
    print2(digit);
    printf("***************分解后的其它字符链表为***************\n");
    print2(other);
    system("pause");
    return 0;
}
linklist *create()
{
    datatype ch;
    scanf("%c", &ch);
    linklist *head = (linklist *)malloc(sizeof(linklist));
    linklist *tail = head;
    head->data = ch;
    head->next = NULL;
    while (scanf("%c", &ch) != EOF)
    {
        linklist *newnode = (linklist *)malloc(sizeof(linklist));
        newnode->data = ch;
        newnode->next = NULL;
        tail->next = newnode;
        tail = tail->next;
    }
    return head;
}
// print without head node
void print1(linklist *head)
{
    linklist *current = head;
    while (current->next != NULL)
    {
        printf("%c", current->data);
        current = current->next;
    }
    printf("%c\n", current->data);
}
// print with head node
void print2(linklist *head)
{
    linklist *current = head->next;
    while (current->next != NULL)
    {
        printf("%c", current->data);
        current = current->next;
    }
    printf("%c\n", current->data);
}
void resolve(linklist *head, linklist *letter, linklist *digit, linklist *other)
{
    linklist *current = head;
    linklist *latter = head->next;
    while (latter != NULL)
    {
        if ((current->data >= 'a' && current->data <= 'z') || (current->data >= 'A' && current->data <= 'Z')) // letter
        {
            letter->next = current;
            letter = letter->next;
            current->next = NULL;
        }
        else if (current->data >= '0' && current->data <= '9')
        {
            digit->next = current;
            digit = digit->next;
            current->next = NULL;
        }
        else
        {
            other->next = current;
            other = other->next;
            current->next = NULL;
        }
        current = latter;
        latter = latter->next;
    }
    if ((current->data >= 'a' && current->data <= 'z') || (current->data >= 'A' && current->data <= 'Z')) // letter
    {
        letter->next = current;
        letter = letter->next;
        current->next = NULL;
    }
    else if (current->data >= '0' && current->data <= '9')
    {
        digit->next = current;
        digit = digit->next;
        current->next = NULL;
    }
    else
    {
        other->next = current;
        other = other->next;
        current->next = NULL;
    }
}
/*
测试用例 1:
输入：
dgjakdg*&?,8543246dghj
输出：
分解后的字母链表为: dgjakdgdghj
分解后的数字链表为: 8543246
分解后的其它字符链表为: *&?,



测试用例 2:
输入：
&%#dgj*#34akdg*&3246
输出：
分解后的字母链表为:dgjakdg
分解后的数字链表为: 343246
分解后的其它字符链表为: &%#*#*&




测试用例 3:
输入：
7&%8dgj*kk#34ak@dg*&6
输出：
分解后的字母链表为: dgjkkakdg
分解后的数字链表为: 78346
分解后的其它字符链表为: &%*#@*&

*/
