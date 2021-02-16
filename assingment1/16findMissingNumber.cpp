#include <bits/stdc++.h>
using namespace std;

int findMissing(vector<int> vec)
{
    int a = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        a = a ^ vec[i];
    }
    for (int i = 1; i <= vec.size() + 1; i++)
    {
        a = a ^ i;
    }
    return a;
}

int main()
{
    vector<int> vec = {1, 2, 4, 6, 3, 7, 8};
    cout << findMissing(vec) << endl;
    return 0;
}