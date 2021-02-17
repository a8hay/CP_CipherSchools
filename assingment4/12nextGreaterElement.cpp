#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> vec)
{
    vector<int> res(vec.size());
    res[vec.size() - 1] = -1;
    stack<int> S;
    S.push(vec[vec.size() - 1]);
    for (int i = vec.size() - 2; i >= 0; i--)
    {
        if (S.top() > vec[i])
        {
            res[i] = S.top();
            S.push(vec[i]);
        }
        else
        {
            while (!S.empty() && S.top() < vec[i])
            {
                S.pop();
            }
            if (S.empty())
            {
                res[i] = -1;
                S.push(vec[i]);
            }
            else
            {
                res[i] = S.top();
                S.push(vec[i]);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> vec = {4, 6, 5, 4, 8, 12};
    vector<int> res = nextGreater(vec);
    for (int a : res)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}