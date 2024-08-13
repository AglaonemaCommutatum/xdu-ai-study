// 二叉树后序遍历非递归算法实现
#include <malloc.h>
#include <stdio.h>
#define maxsize 1024
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *lchild, *rchild;
} bitree;
bitree *creattree();
void postorderNo(bitree *t); // 后序遍历非递归算法
int main()
{
    bitree *root;
    printf("按层次输入二叉树，虚结点输入'@'，以'#'结束输入： \n");
    root = creattree(); // 建立二叉树
    printf("************输出后序遍历序列： ");
    postorderNo(root); // 后序遍历二叉树（非递归）
    printf("\n");
    system("pause"); //
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
void postorderNo(bitree *t)
{
    bitree *stack[100], *cur = t, *prev = NULL;
    int top = -1;
    stack[++top] = t;

    while (cur || top != 0)
    {
        while (cur)
        {
            stack[++top] = cur;
            cur = cur->lchild;
        }

        if (!stack[top]->rchild || stack[top]->rchild == prev)
        {
            prev = stack[top];
            printf("%c", stack[top--]->data);
        }
        else
        {
            cur = stack[top]->rchild;
        }
    }
    return;
}
/*
AB@C#
A@B@C#
AB@@C#
A@BC#
ABC@@D#
ABFC@@HDE@I@@@@G#
*/