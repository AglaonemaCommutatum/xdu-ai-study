// 多项式求和运算：设单链表A和B分别存储不同的多项式，要求完成多项式的求和运算，求和结果存放在A表中（备注：B表清空，测试用例如下）。
// #include "stdafx.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 多项式单链表结构类型定义
typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} linklist;
linklist *create();
linklist *create_node(int coef, int exp);
void insert_node(linklist **head, int coef, int exp);
void print(linklist *head);
void SumofPoly(linklist *ha, linklist *hb);
void main()
{
    linklist *A, *B;
    printf("**************请输入原多项式A链表为*****************\n");
    A = create();
    printf("**************请输入原多项式B链表为*****************\n");
    B = create();
    printf("**************显示原多项式A链表为*****************\n");
    print(A);
    printf("**************显示原多项式B链表为*****************\n");
    print(B);
    SumofPoly(A, B); // 调用多项式求和的函数
    printf("**************显示求和运算之后的多项式A链表为*****************\n");
    print(A);
    printf("**************显示求和运算之后的多项式B链表为*****************\n");
    print(B);
    system("pause");
}

linklist *create_node(int coef, int exp)
{
    linklist *node = (linklist *)malloc(sizeof(linklist));
    node->coef = coef;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insert_node(linklist **head, int coef, int exp)
{
    linklist *node = create_node(coef, exp);
    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        linklist *curr = *head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = node;
    }
}

linklist *create()
{
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    linklist *head = NULL;
    char polynomial[100];
    scanf("%s", polynomial);
    char *term = strtok(polynomial, "+");
    while (term != NULL)
    {
        int coef, exp;
        if (strstr(term, "x") != NULL)
        {
            if (strstr(term, "^") != NULL)
            {
                char *p = strstr(term, "^");
                *p = '\0';
                sscanf(term, "%dx", &coef);
                sscanf(p + 1, "%d", &exp);
            }
            else if (strstr(term, "x") == term)
            {
                coef = 1;
                exp = 1;
            }
            else
            {
                sscanf(term, "%dx", &coef);
                exp = 1;
            }
        }
        else
        {
            sscanf(term, "%d", &coef);
            exp = 0;
        }
        if (term != polynomial && term[-1] == '-')
        {
            coef = -coef;
        }
        insert_node(&head, coef, exp);
        term = strtok(NULL, "+");
    }
    if (head == NULL)
    {
        insert_node(&head, 0, 0);
    }
    return head;
}

void print(linklist *head)
{
    linklist *curr = head;
    int isFirstTerm = 1;
    while (curr != NULL)
    {
        if (curr->coef != 0)
        {
            if (isFirstTerm)
            {
                if (curr->exp == 0)
                {
                    printf("%d", curr->coef);
                    isFirstTerm = 0;
                }
                else
                {
                    printf("%dx^%d", curr->coef, curr->exp);
                    isFirstTerm = 0;
                }
            }
            else
            {
                if (curr->coef > 0)
                {
                    printf("+");
                }
                else
                {
                    printf("-");
                }
                if (curr->exp == 1)
                {
                    printf("%dx", abs(curr->coef));
                }
                else
                {
                    printf("%dx^%d", abs(curr->coef), curr->exp);
                }
            }
        }
        curr = curr->next;
    }
    printf("\n");
}

void SumofPoly(linklist *ha, linklist *hb)
{
    linklist *tmp1 = ha;
    linklist *tmp2 = hb;
    linklist *tmp3;
    linklist *new_head = ha;
    linklist *current = (linklist *)malloc(sizeof(linklist));
    current->next = tmp1;
    while (tmp1 && tmp2)
    {
        if (tmp1->exp == tmp2->exp)
        {
            tmp1->coef += tmp2->coef;
            tmp2->coef = 0;
            linklist *del = tmp2;
            current = tmp1;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            del->next = NULL;
        }
        else
        {
            current->next = (tmp1->exp < tmp2->exp) ? tmp1 : tmp2;
            tmp1 = (tmp1 == current->next) ? tmp1->next : tmp1;
            tmp2 = (tmp2 == current->next) ? tmp2->next : tmp2;
            current = current->next;
        }
        current->next = tmp2 ? tmp2 : tmp1;
    }
}

/*测试用例：
A(x)=7+3x+9x^8+5x^17+2x^20;
B(x)=8x+22x^7+-9x^8+-4x^18+30x^25+10x^35+19x^55;

结果：
A(x)= 7+11x+22x^7+5x^17-4x^18+2x^20+30x^25+10x^35+19x^55;
B表空


测试用例：
（2）A(x)=19+3x+72x^7+6x^17+2x^28+10x^35+19x^55;
B(x)=8x^4+22x^7+-6x^17+-2x^28

结果：
A(x)=19+3x+8x^4+94x^7+10x^35+19x^55;
B表空


测试用例：
（3）A(x)=23+3x+7x^6+16x^18+2x^23+10x^32;
B(x)=-23+-3x+17x^6+-16x^18-2x^23-10x^32;

结果：
A(x)= 24x^6;
B表空


测试用例：
（4）A(x)=23+3x+7x^6+16x^18+2x^23+10x^32;
 B(x)= 6x^12+16x^38+-2x^42+-10x^62;
结果：
A(x)= 23-3x+7x^6+6x^12+16x^18+2x^23+10x^32+16x^38+2x^42+10x^62;
B表空

7+3x+9x^8+5x^17-2x^20
7+-3x+-9x^8+-5x^17+-2x^20
*/