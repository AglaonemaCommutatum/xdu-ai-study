// 有条件交换左右子树（仅当左子树非空且左子树根的值小于非空右子树根值时交换，否则不交换） ， 建议算法采用先序遍历递归实现交换。
#include <stdio.h>
#include <malloc.h>
// 二叉链表的结构类型定义
const int maxsize = 1024;
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *lchild, *rchild;
} bitree;
bitree *creattree();
void preorder(bitree *t);
void swap(bitree *t);
int main(void)
{
    bitree *pb;
    pb = creattree();
    printf("******************交换之前的原二叉树的先序遍历序列为： \n");
    preorder(pb);
    printf("\n");
    swap(pb);
    printf("******************交换之后的原二叉树的先序遍历序列为： \n");
    preorder(pb);
    printf("\n");
    system("pause");
    return 0;
}
bitree *creattree()
{
    char a;
    scanf("%c", &a);
    bitree *head = (bitree *)malloc(sizeof(bitree));
    head->data = a;
    head->lchild = NULL;
    head->rchild = NULL;
    bitree *list[1000];
    list[0] = head; // 进队
    int front = 1;
    int rear = 0;
    while (1)
    {
        scanf("%c", &a);
        if (a == '#')
            break;
        if (a == '@')
        {
        }
        else
        {
            bitree *newnode = (bitree *)malloc(sizeof(bitree));
            newnode->data = a;
            list[rear]->lchild = newnode;
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            list[front++] = newnode;
        }
        scanf("%c", &a);
        if (a == '#')
            break;
        if (a == '@')
        {
        }
        else
        {
            bitree *newnode = (bitree *)malloc(sizeof(bitree));
            newnode->data = a;
            list[rear]->rchild = newnode;
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            list[front++] = newnode;
        }
        rear++;
    }
    return head;
}
void preorder(bitree *t)
{
    if (!t)
        return;
    printf("%c ", t->data);
    preorder(t->lchild);
    preorder(t->rchild);
}
void swap(bitree *t)
{
    if (!t)
        return;
    if (t->lchild && t->rchild && t->lchild->data < t->rchild->data)
    {
        bitree *tmp = t->rchild;
        t->rchild = t->lchild;
        t->lchild = tmp;
    }
    swap(t->lchild);
    swap(t->rchild);
}
/*
    ABFC@@HDE@I@@@@G@#
*/