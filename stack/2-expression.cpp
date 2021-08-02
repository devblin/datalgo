#include <bits/stdc++.h>
using namespace std;

int outpre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    return 8;
}

int inpre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    return 6;
}

bool isOperator(char x)
{
    if (x >= 33 && x <= 47 || x == '^')
        return true;
    return false;
}

int evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    }
    return 0;
}

int EvaluatePostfix(string s)
{
    int i, n = s.size(), a, b, solve;
    stack<char> eval;
    for (i = 0; i < n; i++)
    {
        if (!isOperator(s[i]))
            eval.push(s[i]);
        else
        {
            if (!eval.empty())
            {
                b = eval.top() - 48;
                eval.pop();
                a = eval.top() - 48;
                eval.pop();
                solve = evaluate(a, b, s[i]) + 48;
                eval.push(solve);
            }
        }
    }
    a = eval.top() - 48;
    return a;
}

string InfixPostfix(string s)
{
    stack<char> operators;
    string ans = "";
    int i = 0, n = s.size();
    for (i = 0; i < n; i++)
    {
        if (!isOperator(s[i]))
            ans.push_back(s[i]);
        else
        {
            if (!operators.empty())
            {
                while (!(outpre(s[i]) > inpre(operators.top())))
                {
                    if (operators.top() != '(')
                        ans.push_back(operators.top());
                    operators.pop();
                    if (operators.empty())
                        break;
                }
                if (s[i] != ')')
                    operators.push(s[i]);
            }
            else
                operators.push(s[i]);
        }
    }
    while (!operators.empty())
    {
        ans.push_back(operators.top());
        operators.pop();
    }
    return ans;
}

string InfixPrefix(string s)
{
    return "";
}

int main()
{
    string s, postfix;
    cout << "Enter expression: ";
    cin >> s;
    postfix = InfixPostfix(s);
    cout << postfix << "\n";
    cout << EvaluatePostfix(postfix);
    return 0;
}