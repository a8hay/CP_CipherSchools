#include <bits/stdc++.h>
using namespace std;

void getMaxInQueue(queue<int> &q)
{
    int curr_max = 0;
    while (!q.empty())
    {
        curr_max = max(q.front(), curr_max);
        q.pop();
    }
    cout << curr_max << endl;
}

void slidingWindowMax(vector<int> &vec, int k)
{
    queue<int> q;
    for (int i = 0; i < vec.size(); i++)
    {
        if ((i + 1 % k) == 0)
        {
            q.push(vec[i]);
        }
        else
        {
            getMaxInQueue(q);
            q.pop();
            q.push(vec[i]);
        }
    }
    getMaxInQueue(q);
}

int main()
{
    return 0;
}