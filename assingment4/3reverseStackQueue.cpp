#include <bits/stdc++.h>
using namespace std;

void insertToBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
    }
    else
    {
        int top = s.top();
        s.pop();
        insertToBottom(s, top);
        s.push(x);
    }
}

void reverseStack(stack<int> &s)
{

    if (!s.empty())
    {
        int top = s.top();
        s.pop();
        reverseStack(s);
        insertToBottom(s, top);
    }
}

int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }
    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
