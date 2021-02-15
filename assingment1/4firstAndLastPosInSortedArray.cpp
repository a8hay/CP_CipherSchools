// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findFirstAndLast(vector<int> vec, int key)
{
    int low = 0, high = vec.size(), mid;
    int first, last;
    while (low < high)
    {
        mid = (high - low) / 2 + low;
        if (vec[mid] == key)
        {
            first = mid;
            high = mid;
        }
        else if (vec[mid] < key)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    low = 0;
    high = vec.size();
    while (low < high)
    {
        mid = (high - low) / 2 + low;
        if (vec[mid] == key)
        {
            last = mid;
            low = mid;
        }
        else if (vec[mid] < key)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return {first, last};
}

int main()
{
    vector<int> vec = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    pair<int, int> res = findFirstAndLast(vec, 5);
    cout << res.first << " " << res.second << " " << endl;
    return 0;
}