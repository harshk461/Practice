#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> solve(int n, int target, vector<int> &rolls)
    {
        if (n == 0 && target == 0)
            return rolls;

        if (n == 0 || target == 0)
            return {};

        for (int i = 1; i <= 6; i++)
        {
            rolls.push_back(i);
            vector<int> rem = solve(n - 1, target - i, rolls);
            if (!rem.empty())
                return rolls;
            rolls.pop_back();
        }
        return {};
    }

public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int targetSum = mean * (n + rolls.size()) - sum;

        if (targetSum > n * 6)
            return {};

        vector<int> temp = rolls;

        solve(n, targetSum, rolls);

        unordered_map<int, int> map;
        for (auto it : rolls)
            map[it]++;

        for (auto it : temp)
            map[it]--;

        vector<int> ans;
        for (auto it : map)
        {
            if (it.second > 0)
            {
                while (map[it.first] > 0)
                {
                    ans.push_back(it.first);
                    map[it.first]--;
                }
            }
        }
        return !ans.empty() ? ans : vector<int>();
    }
};

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = (mean * (rolls.size() + n)) - sum;
        if (missingSum < n || missingSum > n * 6)
            return {};

        int part = missingSum / n;
        int rem = missingRolls % n;

        // first distrubute each part to each member of array
        // and after that divide the remaining parts one by one
        vector<int> ans(n, part);
        for (int i = 0; i < rem; i++)
            ++ans[i];

        return ans;
    }
};

int main()
{
    vector<int> arr = {3, 2, 4, 3};
    Solution s;
    s.missingRolls(arr, 4, 2);
    return 0;
}