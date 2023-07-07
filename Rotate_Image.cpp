#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // first reverse the matrix
        reverse(matrix.begin(), matrix.end());
        // then transpose the matrix
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i; j < matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};
int main()
{

    return 0;
}