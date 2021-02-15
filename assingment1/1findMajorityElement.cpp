// https://www.geeksforgeeks.org/majority-element/

#include <bits/stdc++.h>
using namespace std;

int getCandidate(vector<int> vec)
{
    int candidate = vec[0], count = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            candidate = vec[i];
        }
    }
    if (count > 0)
        return candidate;
    else
        return -1;
}

int findMajorityElement(vector<int> vec)
{
    int candidate = getCandidate(vec);
    int count = 0;
    for (int a : vec)
    {
        if (a == candidate)
            count++;
    }
    if (count > vec.size() / 2)
        return candidate;
    return -1;
}

int main()
{
    vector<int> vec = {2, 2, 2, 1, 1, 1, 4};
    cout << findMajorityElement(vec) << endl;
    return 0;
}
