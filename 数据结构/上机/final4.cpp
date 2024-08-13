#include <bits/stdc++.h>
using namespace std;

int priority(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isValid(string expression)
{
    stack<char> s;
    for (char c : expression)
    {
        if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                cout << "Error: Mismatched parentheses" << endl;
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
        {
            cout << "Error: Invalid character " << c << endl;
            return false;
        }
    }
    if (!s.empty())
    {
        cout << "Error: Mismatched parentheses" << endl;
        return false;
    }
    return true;
}

int evaluate_expression(string expression)
{
    stack<int> nums;
    stack<char> ops;
    for (int i = expression.size() - 1; i >= 0; i--)
    {
        char c = expression[i];
        if (isdigit(c))
        {
            int num = 0, j = i;
            while (j >= 0 && isdigit(expression[j]))
            {
                num += (expression[j] - '0') * pow(10, i - j);
                j--;
            }
            nums.push(num);
            i = j + 1;
        }
        else if (c == ')')
        {
            ops.push(c);
        }
        else if (c == '(')
        {
            while (!ops.empty() && ops.top() != ')')
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                if (op == '+')
                    nums.push(num1 + num2);
                else if (op == '-')
                    nums.push(num1 - num2);
                else if (op == '*')
                    nums.push(num1 * num2);
                else
                    nums.push(num1 / num2);
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty() && priority(c) < priority(ops.top()))
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                if (op == '+')
                    nums.push(num1 + num2);
                else if (op == '-')
                    nums.push(num1 - num2);
                else if (op == '*')
                    nums.push(num1 * num2);
                else
                    nums.push(num1 / num2);
            }
            ops.push(c);
        }
    }
    while (!ops.empty())
    {
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        if (op == '+')
            nums.push(num1 + num2);
        else if (op == '-')
            nums.push(num1 - num2);
        else if (op == '*')
            nums.push(num1 * num2);
        else
            nums.push(num1 / num2);
    }
    return nums.top();
}

int main()
{
    string expression;
    getline(cin, expression);
    if (expression[0] != '#' || expression.back() != '#')
    {
        cout << "Error: Invalid format" << endl;
        system("pause");
        return 0;
    }
    expression = expression.substr(1, expression.size() - 2);
    if (!isValid(expression))
    {
        system("pause");
        return 0;
    }
    int result = evaluate_expression(expression);
    cout << "Result: " << result << endl;
    system("pause");
    return 0;
}
// 1、#6+3*(9-7)-8/2#
// 2、#(8-2)/(3-1)*(9-6)#
// 3、#5+a*(8-4)/2#
// 4、#5+(7-3)*6#
// 1+2*(3+4)/2-5*2+(10/5)#
