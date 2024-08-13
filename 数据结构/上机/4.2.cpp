// 题目要求： 将二叉树中数值为 x 的结点及其子树从二叉树中删除，并以先序遍历的方式输出被删除的子树。（假定二叉树上所有结点均不重复）
#include <stdio.h>
#include <malloc.h>
const int maxsize = 1024;
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *lchild, *rchild;
} bitree;
bitree *del;
bitree *creattree();
bitree *preorder_delete(bitree *t, datatype data);
void preorder(bitree *t);
int main(void)
{
    bitree *pa, *pb;
    datatype x;
    printf("***************请构建二叉树:\n");
    pa = creattree();
    printf("***************原二叉树的先序遍历序列为： ");
    preorder(pa);
    printf("\n***************请输入待删除的结点 x: ");
    getchar();
    x = getchar();
    pb = preorder_delete(pa, x);
    printf("***************删除子树后的二叉树的先序遍历序列:");
    preorder(pa);
    printf("\n");
    printf("***************被删除子树的先序遍历序列为:");
    preorder(pb);
    printf("\n");
    system("pause");
    return 0;
}
void preorder(bitree *t)
{
    if (!t)
        return;
    printf("%c ", t->data);
    preorder(t->lchild);
    preorder(t->rchild);
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
bitree *preorder_delete(bitree *t, datatype data)
{
    bitree *node[1000];
    node[0] = t;
    int rear = 0;
    int front = 1;
    while (1)
    {
        if (node[rear]->rchild->data == data)
        {
            del = node[rear]->rchild;
            node[rear]->rchild = NULL;
            return del;
        }
        if (node[rear]->lchild->data == data)
        {
            del = node[rear]->lchild;
            node[rear]->lchild = NULL;
            return del;
        }
        if (node[rear]->lchild)
            node[front++] = node[rear]->lchild;
        if (node[rear]->rchild)
            node[front++] = node[rear]->rchild;
        rear++;
    }
}
/*
    ABFC@@HDE@I@@@@G@#
*/