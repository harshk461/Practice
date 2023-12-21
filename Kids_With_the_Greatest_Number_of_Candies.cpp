#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxi = max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> ans(n, false);

        for (int i = 0; i < n; i++)
            if (candies[i] + extraCandies >= maxi)
                ans[i] = true;

        return ans;
    }
};

int main()
{

    return 0;
}