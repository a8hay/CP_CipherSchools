// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

#include <bits/stdc++.h>
using namespace std;

bool searchInMatrix(vector<vector<int>> matrix, int key)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0, col = cols - 1;
    while (row < rows && cols >= 0)
    {
        if (matrix[row][col] == key)
            return true;
        else if (matrix[row][col] > key)
            col--;
        else
            row++;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix;
    matrix.push_back({10, 20, 30, 40});
    matrix.push_back({15, 25, 35, 45});
    matrix.push_back({27, 29, 37, 48});
    matrix.push_back({32, 33, 39, 50});
    cout << searchInMatrix(matrix, 29) << endl;
    return 0;
}