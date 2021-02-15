#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> vec, int k)
{
    sort(vec.begin(), vec.end());
    return vec[k]
}

int main()
{
    vector<int> vec = {1, 20, 6, 4, 5};
    int k = 3;
    cout << kthSmallest(vec, k) << endl;
    return 0;
}