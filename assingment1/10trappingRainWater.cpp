#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> vec)
{
    vector<int> left(vec.size());
    vector<int> right(vec.size());
    left[0] = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        left[i] = max(vec[i], left[i - 1]);
    }
    right[vec.size() - 1] = vec[vec.size() - 1];
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        right[i] = max(vec[i], right[i + 1]);
    }
    int water = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        water += (min(left[i], right[i]) - vec[i]);
    }
    return water;
}

int main()
{
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trappingRainWater(vec) << endl;
    return 0;
}