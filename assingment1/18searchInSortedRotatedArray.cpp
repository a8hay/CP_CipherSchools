#include <bits/stdc++.h>
using namespace std;

int search(vector<int> vec, int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (h - l) / 2 + l;
    if (vec[mid] == key)
        return mid;
    if (vec[l] <= vec[mid])
    {
        if (key >= vec[l] && key <= vec[mid])
            return search(vec, l, mid - 1, key);

        return search(vec, mid + l, h, key);
    }
    if (key >= vec[mid] && key <= vec[h])
    {
        return search(vec, mid + 1, h, key);
    }
    return search(vec, l, mid - 1, key);
}

int findInSortedRotated(vector<int> vec, int key)
{
    return search(vec, 0, vec.size() - 1, key);
}

int main()
{
    vector<int> vec = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    cout << findInSortedRotated(vec, key) << endl;
    return 0;
}