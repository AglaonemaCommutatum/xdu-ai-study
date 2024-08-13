// //多项式求和运算：设单链表 A 和 B 分别存储不同的多项式，要求完成多项式的求和运
// 算，求和结果存放在 A 表中（备注： B 表不变，测试用例至少测 3 组不同情况）。
// 提示：
#include <bits/stdc++.h>
#include <malloc.h>
#include <stdio.h>
using namespace std;
// 多项式单链表结构类型定义
typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} linklist;
linklist *create();
void print(linklist *head);
linklist *SumofPoly(linklist *a, linklist *b);
int main()
{
    linklist *A, *B, *C;
    printf("**************请输入原多项式A链表为*****************\n");
    A = create();
    printf("**************请输入原多项式B链表为*****************\n");
    B = create();
    printf("\n****************显示原多项式A链表为*****************\n");
    print(A);
    printf("\n****************显示原多项式B链表为*****************\n");
    print(B);
    C = SumofPoly(A, B); // 调用多项式求和的函数
    printf("\n**************显示求和运算之后的多项式A链表为*****************\n");
    print(A);
    printf("\n**************显示求和运算之后的多项式B链表为*****************\n");
    print(B);
    printf("\n**************显示求和运算之后的多项式之和C链表为*****************\n");
    print(C);
    system("pause");
    return 0;
}
linklist *create()
{
    linklist *head = (linklist *)malloc(sizeof(linklist));
    head->next = NULL;
    int coef, exp;
    head->coef = 0;
    head->exp = -1;
    linklist *tail = head;
    while (scanf("%d", &coef) != EOF)
    {
        scanf("%d", &exp);
        linklist *newnode = (linklist *)malloc(sizeof(linklist));
        newnode->coef = coef;
        newnode->exp = exp;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    return head;
}
void print(linklist *head)
{
    linklist *current = head->next;
    while (current != NULL)
    {
        if (current->coef == 0)
        {
            current = current->next;
            continue;
        }
        cout << current->coef << "x^" << current->exp << " ";
        current = current->next;
    }
    puts("\n");
}
linklist *SumofPoly(linklist *a, linklist *b)
{
    linklist *new_head = (linklist *)malloc(sizeof(linklist));
    linklist *tail = new_head;
    tail->next = NULL;
    tail->coef = 0;
    tail->exp = -1;
    linklist *current_a = a->next;
    linklist *current_b = b->next;
    // linklist *after = current_a->next;
    while (current_a != NULL && current_b != NULL)
    {
        if (current_a->exp == current_b->exp)
        {
            linklist *newnode = (linklist *)malloc(sizeof(linklist));
            tail->next = newnode;
            newnode->next = NULL;
            newnode->coef = current_b->coef + current_a->coef;
            newnode->exp = current_b->exp;
            tail = newnode;
            current_b = current_b->next;
            current_a = current_a->next;
        }
        else if (current_a->exp < current_b->exp)
        {
            linklist *newnode = (linklist *)malloc(sizeof(linklist));
            tail->next = newnode;
            newnode->next = NULL;
            newnode->coef = current_a->coef;
            newnode->exp = current_a->exp;
            tail = newnode;
            current_a = current_a->next;
        }
        else if (current_a->exp > current_b->exp)
        {
            linklist *newnode = (linklist *)malloc(sizeof(linklist));
            tail->next = newnode;
            newnode->next = current_a;
            newnode->coef = current_b->coef;
            newnode->exp = current_b->exp;
            tail = newnode;
            current_b = current_b->next;
        }
    }
    tail->next = current_a == NULL ? current_b : current_a;
    return new_head;
}

/*
参考类似截屏。
测试用例：
（1） A(x)=7+3x+9x^8+5x^17+2x^20
B(x)=8x+22x^7-9x^8-4x^18+30x^25+10x^35+19x^55;
7 0 3 1 9 8 5 17 2 20
8 1 22 7 -9 8 -4 18 30 25 10 35 19 55
运行结果：
A(x)= 7+11x+22x^7+5x^17-4x^18+2x^20+30x^25+10x^35+19x^55;
B(x)=8x+22x^7-9x^8-4x^18+30x^25+10x^35+19x^55;
测试用例：
（2） A(x)=19+3x+72x^7+6x^17+2x^28+10x^35+19x^55;
B(x)=8x^4+22x^7-6x^17-2x^28
19 0 3 1 72 7 6 17 2 28 10 35 19 55
8 4 22 7 -6 17 -2 28
运行结果：
A(x)= 19+3x+8x^4+94x^7+10x^35+19x^55;
B(x)=8x^4+22x^7-6x^17-2x^28
测试用例：
（3） A(x)=23+3x+7x^6+16x^18+2x^23+10x^32;
B(x)=-23-3x+17x^6-16x^18-2x^23-10x^32;
运行结果：
A(x)= 24x^6;
B(x)=-23-3x+17x^6-16x^18-2x^23-10x^32;
23 0 3 1 7 6 16 18 2 23 10 32
-23 0 -3 1 17 6 -16 18 -2 23 -10 32
测试用例：
（4） A(x)=23+3x+7x^6+16x^18+2x^23+10x^32;
B(x)= 6x^12+16x^38-2x^42-10x^62;
运行结果：
A(x)= 23+3x+7x^6+6x^12+16x^18+2x^23+10x^32+16x^38-2x^42-10x^62;
B(x)= 6x^12+16x^38-2x^42-10x^62;
*/
