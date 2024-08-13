// 改进的模式匹配追踪算法（KMP）测试
/* 以类似下图的形式展示结果：
测试用例 1：
输入:
abcababcabc
abcabc
输出:
匹配成功！ 比较次数为： 13
返回第一次匹配成功的位置(首字母位序)： 5
*********next 数组内容： -1,0,0,0,1,2
测试用例 2：
输入:
abcababcabckka
abcabc
输出:
匹配成功！ 比较次数为： 13
返回第一次匹配成功的位置(首字母位序)： 5
*********next 数组内容： -1,0,0,0,1,2
测试用例 3：
输入:
abcababcabckka
abcabd
输出:
匹配失败！ 比较次数为： 20
*********next 数组内容： -1,0,0,0,1,27
测试用例 4：
输入:
aaaaaaaaaaaaaaaaaaakuu
aaaaak
输出:
匹配成功！ 比较次数为： 34
返回第一次匹配成功的位置(首字母位序)： 14
*********next 数组内容： -1,0,1,2,3,4
测试用例 5：
aaaaaaaaaaaaaaaaaaak
aaaaau
输出:
匹配失败！ 比较次数为： 40
*********next 数组内容： -1,0,1,2,3,48
*/
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetNext(vector<int> &next, const string &subStr, int n)
{
    next.push_back(-1);
    next.push_back(0);
    int i = 2;
    int k = 0; // 表示i的前一个元素的next数组元素值

    while (i < n)
    {
        // 可能回退至首元素了,说明主串需要向后走，子串从首元素开始，所以也是k = k + 1
        if (k == -1 || subStr[i - 1] == subStr[k]) // P[i - 1] == P[k]
        {
            k = k + 1;
            next.push_back(k);

            i++;
        }
        else // 不匹配则回退
        {
            k = next[k];
        }
    }
}
int KMP(string &str, string &subStr)
{
    int i = 0;
    int j = 0;

    int len1 = str.length();
    int len2 = subStr.length();

    vector<int> Next;
    GetNext(Next, subStr, len2);

    if (len1 == 0 && len2 == 0 || len2 == 0)
        return 0;

    else if (len1 == 0 || len2 > len1)
        return 0;

    while (i < len1 && j < len2)
    {
        if (str[i] == subStr[j] || j == -1)
        {
            i++;
            j++;
        }
        else
        {
            j = Next[j];
        }
        if (j >= len2)
            return 1;
    }
    return 0;
}

int main()
{
    vector<int> next;
    string str;
    string subStr;
    cin >> str >> subStr;
    int n = subStr.size();
    GetNext(next, subStr, n);
    if (KMP(str, subStr) == 1)
        cout << "匹配成功" << endl;
    else
    {
        cout << "匹配失败" << endl;
    }
    cout << "next数组为：" << endl;
    for_each(next.begin(), next.end(), [](int i)
             { cout << i << " "; });
    system("pause");
    return 0;
}