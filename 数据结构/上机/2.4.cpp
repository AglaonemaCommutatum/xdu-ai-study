// 朴素的模式匹配追踪算法（BF）测试

// 测试用例 1：
// 输入:
// T:abcababcabc
// P:abcabc
// 输出:
// 匹配成功！ 比较次数为： 18
// 返回第一次匹配成功的位置(首字母位序)： 6
// 测试用例 2：
// 输入:
// T:abcababcabckka
// P:abcabc
// 输出:
// 匹配成功！ 比较次数为： 18
// 返回第一次匹配成功的位置(首字母位序)： 6
// 测试用例 3：
// 输入:
// T:abcababcabckka
// P:abcabd
// 输出:
// 匹配失败！ 比较次数为： 29
// 测试用例 4：
// 输入:
// T:aaaaaaaaaaaaaaaaaaakuu
// P: aaaaak
// 输出:
// 匹配成功！ 比较次数为： 90
// 返回第一次匹配成功的位置(首字母位序)： 15
// 测试用例 5：输入:
// T:aaaaaaaaaaaaaaaaaaak
// P:aaaaau
// 输出:
// 匹配失败！ 比较次数为： 105
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int main()
{
    string t = "";
    string p = "";
    cin >> t >> p;
    int cnt = 0;
    for (int i = 0, j = 0; i < t.size();)
    {
        if (t[i] != p[j])
        {
            cnt++;
            i = i + 1 - j;
            j = 0;
        }

        else
        {
            cnt++;
            j++;
            i++;

            if (j == p.size())
            {
                printf("匹配成功！比较次数为：%d\n返回第一次匹配成功的位置(首字母位序):%d\n", cnt, i - j + 1);
                system("pause");
                return 0;
            }
        }
    }
    printf("匹配失败！比较次数为:%d", cnt);
    system("pause");
    return 0;
}
