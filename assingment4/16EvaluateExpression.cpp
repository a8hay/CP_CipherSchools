#include <bits/stdc++.h>
using namespace std;

int evaluatePostFixExpression(const string &expression)
{
    stack<int> S;
    for (char x : expression)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
        {
            int a, b;
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            if (x == '+')
            {
                S.push(b + a);
            }
            else if (x == '-')
            {
                S.push(b - a);
            }
            else if (x == '*')
            {
                S.push(b * a);
            }
            else if (x == '/')
            {
                S.push(b / a);
            }
        }
        else
        {
            S.push(x - '0');
        }
    }
    return S.top();
}

int main()
{
    string expression = "231*+9-";
    cout << evaluatePostFixExpression(expression) << endl;
    return 0;
}