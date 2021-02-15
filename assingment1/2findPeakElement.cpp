// https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> vec)
{
    int l = 0, r = vec.size(), mid;
    while (l < r)
    {
        mid = (r - l) / 2 + l;
        if (vec[mid] >= vec[mid + 1] && vec[mid] >= vec[mid - 1])
        {
            return mid;
        }
        else if (vec[mid + 1] >= vec[mid])
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {10, 20, 15, 2, 23, 90, 67};
    cout << findPeakElement(vec) << endl;
    return 0;
}