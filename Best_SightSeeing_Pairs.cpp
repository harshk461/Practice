#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &values)
    {
        int n = values.size();

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                ans = max(ans, values[i] + values[j] + i - j);
        }
        return ans;
    }

public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int maxi = values[0];
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, maxi + values[i] - i);
            maxi = max(maxi, values[i] + i);
        }
        return ans;
    }
};

int main()
{

    return 0;
}