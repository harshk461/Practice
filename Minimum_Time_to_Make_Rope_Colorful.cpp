#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        int i;
        for (i = 0; i < colors.length(); i++)
        {
            int start = i;
            while (i + 1 < colors.length() && colors[i] == colors[i + 1])
                i++;
            int end = i + 1;
            if (end - start > 1)
            {
                vector<int> temp(neededTime.begin() + start, neededTime.begin() + end);
                int sum = accumulate(temp.begin(), temp.end(), 0);
                int maxi = *max_element(temp.begin(), temp.end());
                ans += (sum - maxi);
            }
        }
        cout << ans;
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    Solution s;
    s.minCost("abc", arr);
    return 0;
}