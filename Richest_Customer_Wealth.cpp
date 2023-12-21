#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int ans = 0;
        for (auto it : accounts)
            ans = max(ans, accumulate(it.begin(), it.end(), 0));
        return ans;
    }
};

int main()
{

    return 0;
}