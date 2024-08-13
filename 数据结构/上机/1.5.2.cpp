#include <malloc.h>
#include <stdio.h>
// #include <stdlib.h>
typedef struct node
{
	int coef;
	int exp;
	struct node *next;
} linklist;
struct in
{
	char ch;
	struct in *next;
};
linklist *create();
void print(linklist *head);
void SumofPoly(linklist *A, linklist *B);
int main()
{
	linklist *A, *B;
	printf("**************������ԭ����ʽA����Ϊ*****************\n");
	A = create();
	printf("**************������ԭ����ʽB����Ϊ*****************\n");
	B = create();
	printf("**************��ʾԭ����ʽA����Ϊ*****************\n");
	print(A);
	printf("**************��ʾԭ����ʽB����Ϊ*****************\n");
	print(B);
	SumofPoly(A, B);
	printf("**************��ʾ�������֮��Ķ���ʽA����Ϊ*****************\n");
	print(A);
	printf("**************��ʾ�������֮��Ķ���ʽB����Ϊ*****************\n");
	print(B);
	system("pause");
	return 0;
}
void SumofPoly(linklist *A, linklist *B)
{ // ��˫ָ�������кϲ�
	linklist *pre = A;
	linklist *p = A->next;
	linklist *qre = B;
	linklist *q = B->next;
	while (p != NULL && q != NULL)
	{
		if (p->exp < q->exp)
		{ // a��ָ��Сֱ�Ӻ���ָ��
			pre = pre->next;
			p = p->next;
		}
		else if (p->exp > q->exp)
		{ // a��ָ������ǰ��b����
			pre->next = qre->next;
			q = q->next;
			pre->next->next = p;
			qre->next = q;
			pre = pre->next;
		}
		else if (p->exp == q->exp)
		{ // ��������ϵ������Ϊ����ɾ���ýڵ�
			p->coef = p->coef + q->coef;
			if (p->coef == 0)
			{
				pre->next = p->next;
				p = p->next;
			}
			else
			{
				pre = pre->next;
				p = p->next;
			}
			qre->next = q->next; // ָ�����
			q = q->next;
		}
	}
	if (q != NULL)
	{
		pre->next = q;
	}
	B->next = NULL;
}
// linklist *create_node(int coef, int exp)
// {
//     linklist *node = (linklist *)malloc(sizeof(linklist));
//     node->coef = coef;
//     node->exp = exp;
//     node->next = NULL;
//     return node;
// }

// void insert_node(linklist **head, int coef, int exp)
// {
//     linklist *node = create_node(coef, exp);
//     if (*head == NULL)
//     {
//         *head = node;
//     }
//     else
//     {
//         linklist *curr = *head;
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         curr->next = node;
//     }
// }

// linklist *create()
// {
//     getchar();
//     getchar();
//     getchar();
//     getchar();
//     getchar();
//     linklist *head = NULL;
//     char polynomial[100];
//     scanf("%s", polynomial);
//     char *term = strtok(polynomial, "+");
//     while (term != NULL)
//     {
//         int coef, exp;
//         if (strstr(term, "x") != NULL)
//         {
//             if (strstr(term, "^") != NULL)
//             {
//                 char *p = strstr(term, "^");
//                 *p = '\0';
//                 sscanf(term, "%dx", &coef);
//                 sscanf(p + 1, "%d", &exp);
//             }
//             else if (strstr(term, "x") == term)
//             {
//                 coef = 1;
//                 exp = 1;
//             }
//             else
//             {
//                 sscanf(term, "%dx", &coef);
//                 exp = 1;
//             }
//         }
//         else
//         {
//             sscanf(term, "%d", &coef);
//             exp = 0;
//         }
//         if (term != polynomial && term[-1] == '-')
//         {
//             coef = -coef;
//         }
//         insert_node(&head, coef, exp);
//         term = strtok(NULL, "+");
//     }
//     if (head == NULL)
//     {
//         insert_node(&head, 0, 0);
//     }
//     return head;
// }

// void print(linklist *head)
// {
//     linklist *curr = head;
//     int isFirstTerm = 1;
//     while (curr != NULL)
//     {
//         if (curr->coef != 0)
//         {
//             if (isFirstTerm)
//             {
//                 if (curr->exp == 0)
//                 {
//                     printf("%d", curr->coef);
//                     isFirstTerm = 0;
//                 }
//                 else
//                 {
//                     printf("%dx^%d", curr->coef, curr->exp);
//                     isFirstTerm = 0;
//                 }
//             }
//             else
//             {
//                 if (curr->coef > 0)
//                 {
//                     printf("+");
//                 }
//                 else
//                 {
//                     printf("-");
//                 }
//                 if (curr->exp == 1)
//                 {
//                     printf("%dx", abs(curr->coef));
//                 }
//                 else
//                 {
//                     printf("%dx^%d", abs(curr->coef), curr->exp);
//                 }
//             }
//         }
//         curr = curr->next;
//     }
//     printf("\n");
// }

linklist *create()
{
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	char c;
	in *i = (in *)malloc(sizeof(in));
	i->next = NULL;
	in *ip = i;
	while ((c = getchar()) != '\n')
	{
		in *chch = (in *)malloc(sizeof(in));
		chch->ch = c;
		ip->next = chch;
		ip = ip->next;
	}
	ip->next = NULL;
	linklist *head = (linklist *)malloc(sizeof(linklist)); // ��ȡָ��ϵ��
	head->next = NULL;
	linklist *p = head;
	int coef = 0, exp = 0;
	ip = i->next;
	in *iq = ip;	// ˫ָ�룬ip��ǰ��iq�ں�
	int count = 1;	// ϵ��λ��
	int is_add = 1; // ��Ƿ���
	int isc = 1;	// �жϵ�һ���Ƿ�Ϊ����
	if (ip->ch == '-')
	{ // ���и���
		ip = ip->next;
		is_add = -1;
		iq = ip;
	}
	while (ip != NULL && ip->ch != '+' && ip->ch != '-')
	{ // ip��ǰ���������������x��˵����һ��ǳ���
		if (ip->ch == 'x')
		{
			isc = 0;
			ip = i->next;
			break;
		}
		ip = ip->next;
	}
	if (isc)
	{			 // �ǳ���
		ip = iq; // ����ip
		while (ip->next != NULL && ip->next->ch != '+' && ip->next->ch != '-')
		{ // ����λ��
			count++;
			ip = ip->next;
		}
		while (count > 0 && iq != NULL)
		{ // ����ϵ��
			int delta = 1;
			for (int i = 1; i < count; i++)
				delta *= 10;
			coef += ((iq->ch) - '0') * delta;
			iq = iq->next;
			count--;
		}
		coef *= is_add; // ���Ϸ���
		linklist *q = (linklist *)malloc(sizeof(linklist));
		p->next = q;
		q->coef = coef;
		q->exp = 0;
		p = q;
		count = 1; // ����
		coef = 0;
		if (ip != NULL)
			ip = ip->next; // ����
	}
	while (ip != NULL)
	{
		if (ip->ch == 'x')
		{ // ������x��Ҫ����ϵ��
			while (count > 0)
			{
				int delta = 1;
				for (int i = 1; i < count; i++)
					delta *= 10;
				coef += ((iq->ch) - '0') * delta;
				iq = iq->next;
				count--;
			}
			coef *= is_add;
			linklist *q = (linklist *)malloc(sizeof(linklist));
			p->next = q;
			q->coef = coef;
			count = 1; // ����
			coef = 0;
			ip = ip->next; // ����
			if (ip->ch == '+' || ip->ch == '-' || ip->ch == NULL)
			{
				q->exp = 1;
				p = q;
			}
		}
		else if (ip->ch == '^')
		{ // ������^��Ҫ����ָ��
			ip = ip->next;
			iq = ip; // ����ָ��
			while (ip->next != NULL && ip->next->ch != '+' && ip->next->ch != '-')
			{
				count++;
				ip = ip->next;
			}
			while (count > 0)
			{
				int delta = 1;
				for (int i = 1; i < count; i++)
					delta *= 10;
				exp += ((iq->ch) - '0') * delta;
				if (iq->next != 0)
					iq = iq->next;
				count--;
			}
			p->next->exp = exp; // �����ϴ�ֻ����ϵ���Ľڵ�
			exp = 0;
			count = 1;
			p = p->next; // ����
			ip = ip->next;
		}
		else if (ip->ch == '+')
		{ // ��¼���ţ���������ϵ����׼��
			is_add = 1;
			ip = ip->next;
			iq = ip; // ����ָ��
		}
		else if (ip->ch == '-')
		{ // ͬ��
			is_add = -1;
			ip = ip->next;
			iq = ip;
		}
		else if (ip->next->ch != '+' && ip->next->ch != '-' && ip->next != NULL && ip->next->ch != 'x')
		{
			count++; // ���������ּ�¼λ��
			ip = ip->next;
		}
		else
			ip = ip->next;
	}
	p->next = NULL;
	return head;
}

void print(linklist *head)
{
	linklist *tail = head;
	if (tail->next == NULL)
	{
		printf("0\n");
		return;
	}
	linklist *p = tail->next;
	while (p != NULL)
	{
		if (p == tail->next)
		{
			printf("%d", p->coef);
			if (p->exp == 1)
			{
				printf("x");
			}
			else if (p->exp != 0)
			{
				printf("x^%d", p->exp);
			}
		}
		else
		{
			if (p->coef > 0)
			{
				printf("+%d", p->coef);
			}
			else
				printf("%d", p->coef);
			if (p->exp == 1)
			{
				printf("x");
			}
			else if (p->exp != 0)
			{
				printf("x^%d", p->exp);
			}
		}
		p = p->next;
	}
	printf("\n");
}

// 测试用例：
// （1）A(x)=7+3x+9x^8+5x^17+2x^20;
// B(x)=8x+22x^7-9x^8-4x^18+30x^25+10x^35+19x^55;

// 结果：
// A(x)= 7+11x+22x^7+5x^17-4x^18+2x^20+30x^25+10x^35+19x^55;
// B表空

// 测试用例：
// （2）A(x)=19+3x+72x^7+6x^17+2x^28+10x^35+19x^55;
// B(x)=8x^4+22x^7-6x^17-2x^28

// 结果：
// A(x)= 19+3x+8x^4+94x^7+10x^35+19x^55;
// B表空

// 测试用例：
// （3）A(x)=23+3x+7x^6+16x^18+2x^23+10x^32;
// B(x)=-23-3x+17x^6-16x^18-2x^23-10x^32;

// 结果：
// A(x)= 24x^6;
// B表空

// 测试用例：
// （4）A(x)=23+3x+7x^6+16x^18+2x^23+10x^32;
//  B(x)=6x^12+16x^38-2x^42-10x^62;
// 结果：
// A(x)= 23+3x+7x^6+6x^12+16x^18+2x^23+10x^32+16x^38-2x^42-10x^62;
// B表空