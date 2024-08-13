// 4. 算法功能：删除一个带头结点的递增单链表中的所有重复结点。

// #include

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
// void invert(linklist*);
void DelRedundant(linklist *head);
void main()
{
	linklist *head;
	head = create();
	printf("****************原递增链表如下****************\n");
	print(head);
	DelRedundant(head); // 调用单链表去重的函数
	printf("****************去重后的链表如下****************\n");
	print(head);
}

// 采用尾插法建立具有头结点的单链表
linklist *create()
{
	datatype num;
	linklist *head = (linklist *)malloc(sizeof(linklist));
	scanf("%d", &num);
	head->data = num;
	head->next = NULL;
	linklist *tail = head;
	while ((scanf("%d", &num)) != EOF)
	{
		linklist *new_node = (linklist *)malloc(sizeof(linklist));
		new_node->data = num;
		new_node->next = NULL;
		tail->next = new_node;
		tail = tail->next;
	}
	return head;
}

// 输出单链表
void print(linklist *head)
{
	linklist *current = head;
	while (current->next != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	printf("%d\n", current->data);
}

// 单链表去重
void DelRedundant(linklist *head)
{
	linklist *current = head;
	while ((current->next)->next != NULL)
	{
		if (current->data != current->next->data)
		{
			current = current->next;
		}
		else
		{
			current->next = current->next->next;
		}
	}
	if (current->data == current->next->data)
	{
		current->next = NULL;
	}
} // 时间复杂度为O(n)
