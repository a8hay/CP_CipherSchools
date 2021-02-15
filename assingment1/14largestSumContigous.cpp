#include <bits/stdc++.h>
using namespace std;

int largestContigousSum(vector<int> vec)
{
    int curr_sum = vec[0], max_sum = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        curr_sum = max(vec[i], curr_sum + vec[i]);
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

void findIdxLargestContigousSum(vector<int> vec)
{
    int curr_sum = vec[0], max_sum = vec[0];
    int start_idx = 0, end_idx = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] + curr_sum < vec[i])
        {
            curr_sum = vec[i];
            start_idx = i;
            end_idx = i;
        }
        else
        {
            curr_sum = vec[i] + curr_sum;
        }
        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
            end_idx = i;
        }
    }

    cout << start_idx << " " << end_idx << " " << endl;
}

int main()
{
    vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
    findIdxLargestContigousSum(vec);
    return 0;
}