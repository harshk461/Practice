#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int ans = 0;
        int i = 0, j = 1;
        int n = costs.size();
        while (i < n)
        {
            vector<int> t = {costs[i][0], costs[i][1], costs[j][0], costs[j][1]};
            sort(t.begin(), t.end());
            ans += (t[0], t[1]);
            i = j + 1;
            j++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}