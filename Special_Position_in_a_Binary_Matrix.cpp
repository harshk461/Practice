#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkMatrix(int i, int j, vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        for (int k = 0; k < n; k++)
            if (mat[i][k] == 1 && j != k)
                return false;
        for (int k = 0; k < m; k++)
            if (mat[k][j] == 1 && i != k)
                return false;

        return true;
    }

public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1 && checkMatrix(i, j, mat))
                    count++;
        return count;
    }
};

int main()
{

    return 0;
}