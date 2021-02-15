#include <bits/stdc++.h>
using namespace std;

void sortZeroOneTwo(vector<int> &vec)
{
    int low = 0, mid = 0, high = vec.size() - 1;
    while (mid <= high)
    {
        if (vec[mid] == 0)
        {
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        }
        else if (vec[mid] == 1)
        {
            mid++;
        }
        else if (vec[mid] == 2)
        {
            swap(vec[mid], vec[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> vec = {2, 0, 2, 1, 1, 0, 2, 1, 2, 1};
    sortZeroOneTwo(vec);
    for (int a : vec)
        cout << a << " ";
    cout << endl;
    return 0;
}