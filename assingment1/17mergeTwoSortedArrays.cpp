#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArray(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> res(vec1.size() + vec2.size());
    int i = 0, j = 0, k = 0;
    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] < vec2[j])
        {
            res[k] = vec1[i];
            i++;
        }
        else if (vec1[i] > vec2[j])
        {
            res[k] = vec2[j];
            j++;
        }
        else
        {
            res[k] = vec1[i];
            i++;
            j++;
        }
        k++;
    }

    if (i >= vec1.size())
    {
        while (j < vec2.size())
        {
            res[k] = vec2[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i < vec1.size())
        {
            res[k] = vec1[i];
            i++;
            k++;
        }
    }
    return res;
}

int main()
{
    vector<int> vec1 = {1, 2, 13, 8};
    vector<int> vec2 = {6, 14, 16};
    vector<int> res = mergeSortedArray(vec1, vec2);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    return 0;
}