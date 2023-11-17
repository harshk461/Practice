#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j && nums[i][j] % 2 != 0)
                    ans = max(ans, mat[i][j]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((i + j) == (n - 1) && nums[i][j] % 2 != 0)
                    ans = max(ans, mat[i][j]);
        return ans;
    }
};

int main()
{

    return 0;
}