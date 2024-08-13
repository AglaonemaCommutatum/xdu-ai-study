// 已知 A、 B 和 C 为三个元素值递增有序排列的链表，现要求对表 A 作如下运算：删除那些既在 B 中出现又在 C 中出现的元素。
#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *next;
} LinkList;
LinkList *create(); /*函数声明*/
void ListDelete(LinkList *La, LinkList *Lb, LinkList *Lc);
void Print(LinkList *sb);
int main(void)
{ /*功能：建立单链表 A,B,C，并且删除 A 中均在 B 和 C 中出现的数据。 */
    LinkList *headA, *headB, *headC;
    headA = create(); /*建立链表*/
    headB = create();
    headC = create();
    printf("*********************删除之前的 3个表分别为: *********************\n");
    Print(headA); /*输出显示链表数据*/
    Print(headB);
    Print(headC);
    ListDelete(headA, headB, headC); /*删除 A 中满足条件的节点*/
    printf("********************删除之后的 LA 表为: ***********************\n");
    Print(headA);
    system("pause");
    return 0;
}
LinkList *create()
{
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    head->next = NULL;
    int chr;
    LinkList *tail = head;
    while (1)
    {
        scanf("%d", &chr);
        if (chr == -1)
            break;
        LinkList *newnode = (LinkList *)malloc(sizeof(LinkList));
        newnode->next = NULL;
        newnode->data = chr;
        tail->next = newnode;
        tail = tail->next;
    }
    return head;
}
void Print(LinkList *sb)
{
    LinkList *cur = sb->next;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    puts("\n");
}
void ListDelete(LinkList *La, LinkList *Lb, LinkList *Lc)
{
    LinkList *cop = (LinkList *)malloc(sizeof(LinkList));
    cop->next = NULL;
    LinkList *cur = cop;
    LinkList *bcur = Lb->next;
    LinkList *ccur = Lc->next;
    LinkList *acur = La->next;
    while (bcur != NULL && ccur != NULL)
    {
        if (bcur->data == ccur->data)
        {
            cur->next = bcur;
            bcur = bcur->next;
            cur = cur->next;
            cur->next = NULL;
        }
        else if (bcur->data > ccur->data)
        {
            ccur = ccur->next;
        }
        else
        {
            bcur = bcur->next;
        }
    }
    cur = cop->next;
    LinkList *prev = La;
    while (acur != NULL && cur != NULL)
    {
        if (acur->data == cur->data)
        {
            acur = acur->next;
            prev->next = acur;
        }
        else if (acur->data > cur->data)
        {
            cur = cur->next;
        }
        else
        {
            acur = acur->next;
            prev = prev->next;
        }
    }
}

/*测试样例
1 2 3 4 5 6 7 8 9 -1
1 3 5 7 9 -1
1 4 6 8 9 -1
*/