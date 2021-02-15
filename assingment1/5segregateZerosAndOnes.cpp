#include <bits/stdc++.h>
using namespace std;

void segregateZerosOnes(vector<int> &vec)
{
    int last_zero_idx = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0)
        {
            swap(vec[i], vec[last_zero_idx]);
            last_zero_idx++;
        }
    }
}

int main()
{
    vector<int> vec = {1, 1, 0, 0, 1, 0};
    segregateZerosOnes(vec);
    for (int a : vec)
        cout << a << " ";
    cout << endl;
    return 0;
}