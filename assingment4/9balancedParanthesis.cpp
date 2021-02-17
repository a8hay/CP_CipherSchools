#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string input)
{
    stack<char> S;
    for (char c : input)
    {
        if (c == '[' || c == '(' || c == '{')
        {
            S.push(c);
        }
        else
        {
            if (S.empty())
            {
                return false;
            }
            char open = S.top();
            S.pop();
            if (open == '(')
            {
                if (c != ')')
                    return false;
            }

            if (open == '{')
            {
                if (c != '}')
                    return false;
            }

            if (open == '[')
            {
                if (c != ']')
                    return false;
            }
        }
    }
    return S.empty();
}

int main()
{
    string input1 = "[()]{}{[()()]()}";
    string input2 = "[(])";
    cout << isBalanced(input1) << endl;
    cout << isBalanced(input2) << endl;
    return 0;
}