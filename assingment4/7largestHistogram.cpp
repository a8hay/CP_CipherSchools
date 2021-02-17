#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallestToLeft(vector<int> vec)
{
    vector<int> res(vec.size());
    res[0] = -1;
    stack<int> S;
    S.push(0);
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[S.top()] < vec[i])
        {
            res[i] = vec[S.top()];
            S.push(i);
        }
        else
        {
            while (!S.empty() && vec[S.top()] > vec[i])
            {
                S.pop();
            }
            if (S.empty())
            {
                res[i] = -1;
                S.push(i);
            }
            else
            {
                res[i] = vec[S.top()];
                S.push(i);
            }
        }
    }
    return res;
}

vector<int> nearestSmallestToRight(vector<int> vec)
{
    vector<int> res(vec.size());
    res[vec.size() - 1] = -1;
    stack<int> S;
    S.push(vec.size() - 1);
    for (int i = vec.size() - 2; i >= 0; i--)
    {
        if (vec[S.top()] < vec[i])
        {
            res[i] = vec[S.top()];
            S.push(i);
        }
        else
        {
            while (!S.empty() && vec[S.top()] > vec[i])
            {
                S.pop();
            }
            if (S.empty())
            {
                res[i] = -1;
                S.push(i);
            }
            else
            {
                res[i] = vec[S.top()];
                S.push(i);
            }
        }
    }
    return res;
}

int largestArea(vector<int> vec)
{
    int max_area = 0, curr_area;
    vector<int> left = nearestSmallestToLeft(vec);
    vector<int> right = nearestSmallestToRight(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        int width = abs(vec[i] - left[i]) + abs(vec[i] - right[i]) - 1;
        curr_area = width * vec[i];
        max_area = max(max_area, curr_area);
    }
    return max_area;
}

int main()
{
    vector<int> vec = {6, 1, 5, 4, 5, 2, 6};
    cout << largestArea(vec) << endl;
    return 0;
}