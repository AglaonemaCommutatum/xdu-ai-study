#include <bits/stdc++.h>
using namespace std;
const int maxsize = 1024;
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *lchild, *rchild;
} bitree;
vector<int> ch;
bitree *creattree();
void inorder(bitree *pb);
int main(void)
{
    char a;
    bitree *pb = creattree();
    puts("请输入待查找的结点\n");
    getchar();
    scanf("%c", &a);
    inorder(pb);
    int fal = 0;
    if (ch.back() == a)
        puts("无后继节点");
    for (int i = 1; i <= ch.size(); i++)
    {
        if (ch[i] == a)
        {
            printf("查找成功，后继节点是 %c\n", ch[i + 1]);
            fal++;
            break;
        }
    }
    if (fal == 0)
        puts("无后继节点");
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
void inorder(bitree *pb)
{
    if (pb == NULL)
        return;
    inorder(pb->lchild);
    ch.push_back(pb->data);
    inorder(pb->rchild);
}
/*

abcdef@@@g@@h#


*/