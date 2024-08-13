// P45第6题// 归并递减
// 题目要求：设A和B是两个递增有序的单链表。试编写一个算法将A和B归并成一个按元素值递减有序的单链表C，并要求辅助空间为O(1)，
// C表的头结点可另辟空间。请分析算法的时间复杂度。

#include <malloc.h>
#include <stdio.h>
// 单链表结构类型定义
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} linklist;

linklist *create();			//
void print(linklist *head); //
linklist *mergelist(linklist *list1, linklist *list2);
linklist *reverse(linklist *head);
void insert(linklist *list1, linklist *list2); // insert list1 into list2
int main(void)
{
	linklist *La, *Lb, *Lc;
	printf("****************请创建链表La******************\n");
	La = create();
	printf("****************请创建链表Lb******************\n");
	Lb = create();
	printf("***************输出显示链表La*****************\n");
	print(La);
	printf("***************输出显示链表Lb*****************\n");
	print(Lb);
	Lc = mergelist(La, Lb);
	printf("*****输出显示La表和Lb表归并递减后的链表Lc*****\n");
	print(Lc);
	return 0;
}

linklist *create()
{
	int num;
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

void insert(linklist *node1, linklist *node2)
{
	linklist *nxt2 = node2->next;
	node2->next = node1;
	node1->next = nxt2;
}

linklist *mergelist(linklist *list1, linklist *list2)
{
	linklist *tmp1 = list1;
	linklist *tmp2 = list2;
	linklist *new_head = (tmp1->data <= tmp2->data) ? tmp1 : tmp2;
	tmp1 = (tmp1 == new_head) ? tmp1->next : tmp1;
	tmp2 = (tmp2 == new_head) ? tmp2->next : tmp2;
	linklist *current = new_head;
	while (tmp1 && tmp2)
	{
		current->next = (tmp1->data < tmp2->data) ? tmp1 : tmp2;
		tmp1 = (tmp1 == current->next) ? tmp1->next : tmp1;
		tmp2 = (tmp2 == current->next) ? tmp2->next : tmp2;
		current = current->next;
	}
	current->next = tmp2 ? tmp2 : tmp1;
	return reverse(new_head);
}
linklist *reverse(linklist *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	else
	{
		linklist *new_head = reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return new_head;
	}
}

// linklist *mergelist(linklist *list1, linklist *list2)
// {
// 	list1 = reverse(list1);
// 	list2 = reverse(list2);
// 	linklist *currentlist1 = (list1->data >= list2->data) ? list1:list2;
// 	linklist *currentlist2 = (list1->data >= list2->data) ? list2:list1;
// 	//重排，将list2插入list1
// 	linklist *new_head = list1;
// 	while(1)
// 	{
// 		if(currentlist2->data>currentlist1->data)
// 		{
// 			currentlist2->next=
// 		}else if(currentlist2->data<currentlist1->data)
// 		{
// 			currentlist2->next=
// 		}else
// 		{
// 			currentlist2 = currentlist2->next;
// 		}
// 		currentlist2 = currentlist2->next;
// 		if(currentlist2==NULL)
// 		{
// 			break;
// 		}
// 	}
// 	return list1;
// }