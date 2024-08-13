#include <malloc.h>
#include <stdio.h>
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *next;
} linklist;
linklist *create();
void print(linklist *head);
void invert(linklist *head);
int main(void)
{
    linklist *head;
    printf("***************请创建链表*****************\n");
    head = create();
    printf("***************输出原链表*****************\n");
    print(head);
    invert(head); // 调用单链表逆置的函数
    printf("************输出逆置后的链表**************\n");
    print(head);
    return 0;
}
linklist *create()
{
    puts("请输入链表长度: ");
    int len;
    scanf("%d", &len);
    getchar();
    len--;
    datatype data;
    data = getchar();
    // scanf("%c", &data);
    linklist *head = (linklist *)malloc(sizeof(linklist));
    head->next = NULL;
    head->data = data;
    linklist *tail = head;
    while (len--)
    {
        // scanf(" %c", &data);
        data = getchar();
        linklist *new_node = (linklist *)malloc(sizeof(linklist));
        new_node->data = data;
        new_node->next = NULL;
        tail->next = new_node;
        tail = tail->next;
    }
    return head;
}

void print(linklist *head)
{
    linklist *current = head;
    while (current->next != NULL)
    {
        printf("%c", current->data);
        current = current->next;
    }
    printf("%c\n", current->data);
}

void invert(linklist *head)
{
    linklist *current = head;
    char num[99999]; //
    int len;
    for (len = 0; current != NULL; len++)
    {
        num[len] = current->data;
        current = current->next;
    }
    current = head;
    do
    {
        current->data = num[--len];
        current = current->next;
    } while (current != NULL);
}