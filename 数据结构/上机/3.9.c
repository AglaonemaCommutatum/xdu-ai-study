// 奇数阶魔方阵
#include <stdio.h>
#include <stdlib.h>
int a[1000][1000];
void init(int n)
{
    int row, col, row0, col0;
    col = 0;
    row = n / 2;
    a[col][row] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        row0 = row;
        col0 = col;
        if (col == 0 && row == n - 1)
        {
            col = n - 1;
            row = 0;
        }
        else if (col == 0)
        {
            col = n - 1;
            row++;
        }
        else if (row == n - 1)
        {
            row = 0;
            col--;
        }
        else
        {
            col--;
            row++;
        }
        if (a[col][row] != 0)
        {
            col = col0 + 1;
            row = row0;
        }
        a[col][row] = i;
    }
}
int main()
{
    int coef;
    puts("请输入阶数:");
    scanf("%d", &coef);
    init(coef);
    for (int i = 0; i < coef; i++)
    {
        for (int j = 0; j < coef; j++)
        {
            printf("%d ", a[i][j]);
        }
        puts("\n");
    }
    system("pause");
    return 0;
}