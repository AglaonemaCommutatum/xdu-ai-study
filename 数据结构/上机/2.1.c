// P45 第 5 题， 删除单链表中介于 min-max 之间的结点
// #include "stdafx.h"
#include <malloc.h>
#include <stdio.h>
// 单链表结构类型定义
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
} linklist;
linklist *create();
void print(linklist *head);
void delete(linklist *head, datatype min, datatype max);
int main()
{
    linklist *head;
    int min, max;
    head = create();
    printf("原链表为： \n");
    print(head);
    puts("***************请 为 min 输 入 一 个 整 数******************");
    scanf("%d", &min);
    puts("***************请 为 max 输 入 一 个 整 数******************");
    scanf("%d", &max);
    delete (head, min, max); // 调用单链表删除函数
    printf("***********删除介于 min 和 max 之间的结点后的链表*********\n");
    print(head);
    system("pause");
    return 0;
}
linklist *create()
{
    datatype num;
    linklist *head = (linklist *)malloc(sizeof(linklist));
    linklist *tail = head;
    head->next = NULL;
    // head->data = NULL;
    while (scanf("%d", &num) != EOF)
    {
        linklist *newnode = (linklist *)malloc(sizeof(linklist));
        tail->next = newnode;
        newnode->data = num;
        newnode->next = NULL;
        tail = tail->next;
    }
    return head;
}
void print(linklist *head)
{
    linklist *current = head->next;
    while (current->next != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void delete(linklist *head, datatype min, datatype max)
{
    linklist *min_node, *max_node;
    linklist *current = head;
    while (current->next != NULL && current->next->data <= min)
    {
        current = current->next;
    }
    min_node = current;
    if (current == NULL)
    {
        return;
    }
    // printf("%d\n", current->data);
    current = head->next;
    while (current != NULL && current->data < max)
    {
        current = current->next;
    }
    max_node = current;
    min_node->next = max_node;
}
/**
 测试用例 1:
 输入： 2 6 9 10 15 23 38 45 50 56 67 89 100 136 138
 min: 23
 max:99
 输出： 2 6 9 10 15 23 100 136 138
 测试用例 2:
 输入： 3 5 8 19 25 34 38 49 60 83 120 150 180
 min:80
 max:200
 输出： 3 5 8 19 25 34 38 49 60
 测试用例 3:
 输入： 3 5 8 19 25 34 38 49 60 83 120 150 180
 min:1
 max:50
 输出： 60 83 120 150 180
 测试用例 4:
 输入： 3 5 8 19 25 34 38 49 60 83 120 150 180
 min:190
 max:500
 输出： 3 5 8 19 25 34 38 49 60 83 120 150 180
 */