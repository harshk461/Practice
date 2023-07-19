#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> image)
    {
        vector<vector<int>> matrix(image.begin(), image.end());
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        int n = image.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }
        return matrix;
    }
};
int main()
{

    return 0;
}