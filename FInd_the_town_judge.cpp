#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> count(n + 1);
        for (auto vec : trust)
        {
            --count[vec[0]];
            ++count[vec[1]];
        }

        for (int i = 1; i <= n; i++)
        {
            if (count[i] == n - 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    Solution s;
    cout << s.findJudge(3, trust);
    return 0;
}