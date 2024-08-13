// 交换左右子树的递归算法实现（二叉树翻转）
//  题目要求： 已知二叉树采用二叉链表存储结构，编写一个算法交换二叉树所有左、右子树的
//  位置，即结点的左子树变为结点的右子树，右子树变为左子树。
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
void preorder(bitree *pb);
void inorder(bitree *pb);
void swap(bitree *pb);
int main(void)
{
    bitree *pb;
    printf("**********按层次输入二叉树，虚结点输入'@'，以'#'结束输入********\n");
    pb = creattree();
    printf("******************交换之前的原二叉树先序遍历序列为： ");
    preorder(pb);
    printf("\n");
    printf("******************交换之前的原二叉树中序遍历序列为： ");
    inorder(pb);
    printf("\n");
    swap(pb);
    printf("******************交换之后的二叉树先序遍历序列为： ");
    preorder(pb);
    printf("\n");
    printf("******************交换之后的二叉树中序遍历序列为： ");
    inorder(pb);
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
void preorder(bitree *pb)
{
    if (pb == NULL)
        return;
    printf("%c", pb->data);
    preorder(pb->lchild);
    preorder(pb->rchild);
}
void inorder(bitree *pb)
{
    if (pb == NULL)
        return;
    inorder(pb->lchild);
    printf("%c", pb->data);
    inorder(pb->rchild);
}
void swap(bitree *pb)
{
    if (pb == NULL)
        return;
    bitree *tmp = pb->lchild;
    pb->lchild = pb->rchild;
    pb->rchild = tmp;
    swap(pb->lchild);
    swap(pb->rchild);
}
/*
假设构造的二叉树如图所示：
A
B
C
D E
F
H
I
G
交换左右子树后的二叉树如图所示：
输出如下结果：
交换之前的原二叉树先序遍历序列为： A B C D E F H I G
交换之前的原二叉树中序遍历序列为： D C E B A F H G I
交换之后的二叉树先序遍历序列为： A F H I G B C E D
交换之后的二叉树先序遍历序列为： I G H F A B E C D


abfc@@hde@i@@@@g#


*/