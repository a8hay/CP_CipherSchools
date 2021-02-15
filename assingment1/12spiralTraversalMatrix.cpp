#include <bits/stdc++.h>
using namespace std;

void spiralTraverse(vector<vector<int>> matrix)
{
    int rs = 0, re = matrix.size() - 1, cs = 0, ce = matrix[0].size() - 1;

    while (rs < re && cs < ce)
    {
        for (int j = cs; j <= ce; j++)
            cout << matrix[rs][j];
        rs++;

        for (int i = rs; i <= re; i++)
            cout << matrix[i][ce];
        ce--;

        for (int j = ce; j >= cs; j++)
            cout << matrix[re][j];
        re--;

        for (int i = re; i >= rs; i++)
            cout << matrix[i][cs];
        cs++;
    }
}

int main()
{
    vector<vector<int>> matrix;
    matrix.push_back({1, 2, 3, 4});
    matrix.push_back({5, 6, 7, 8});
    matrix.push_back({9, 10, 11, 12});
    matrix.push_back({12, 14, 15, 16});
    spiralTraverse(matrix);
    return 0;
}