#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        int count = 0; // new added coins;
        int maxReach = 0;

        for (auto coin : coins)
        {
            while (coin < maxReach + 1)
            {
                maxReach += maxReach + 1;
                count++;
                if (maxReach >= target)
                    return count;
            }
            maxReach += coin;
            if (maxReach >= target)
                return count;
        }

        while (maxReach < target)
        {
            maxReach += maxReach + 1;
            count++;
        }

        return count;
    }

public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        int curr_max = 0;
        int count = 0;
        int i = 0;
        while (curr_max < target)
        {
            if (i < coins.size() && coins[i] <= curr_max + 1)
            {
                curr_max += coins[i];
                i++;
            }
            else
            {
                curr_max += curr_max + 1;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 4, 10};
    s.minimumAddedCoins(arr, 19);
    return 0;
}