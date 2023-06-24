#include <bits/stdc++.h>
using namespace std;

// naive approach gave TLE
long long sumMatrix(vector<vector<int>> arr, int n)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += arr[i][j];
        }
    }
    return ans;
}

// long long matrixSumQueries(int n, vector<vector<int>> &queries)
// {
//     vector<vector<int>> matrix(n, vector<int>(n, 0));
//     for (vector<int> arr : queries)
//     {
//         if (arr[0] == 0)
//         {
//             for (int i = 0; i < n; i++)
//             {

//                 matrix[arr[1]][i] = arr[2];
//             }
//         }
//         if (arr[0] == 1)
//         {
//             for (int i = 0; i < n; i++)
//             {

//                 matrix[i][arr[1]] = arr[2];
//             }
//         }
//     }
//     return sumMatrix(matrix, n);
// }

long long matrixSumQueries(int n, vector<vector<int>> &queries)
{
    long long ans = 0;

    // it stores which row and column is seen or not
    // seen[0]->row
    // seen[1]->col
    vector<vector<bool>> seen(2, vector<bool>(n));

    // notset[0]->row
    // notset[1]->col
    vector<int> notSet(2, n);

    for (int i = queries.size() - 1; i >= 0; --i)
    {
        int type = queries[i][0];
        int index = queries[i][1];
        int val = queries[i][2];

        if (!seen[type][index])
        {
            cout << notSet[type ^ 1] << " ";
            ans += val * notSet[type ^ 1];
            seen[type][index] = true;
            --notSet[type];
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0, 1},
        {1, 2, 2},
        {0, 2, 3},
        {1, 0, 4}};
    cout << matrixSumQueries(3, arr);
    return 0;
}