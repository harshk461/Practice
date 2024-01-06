#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums, ll k)
    {
        long long sum = 0;
        set<long long> temp;

        for (int i : nums)
            temp.insert(i);

        for (long long i : temp)
        {
            if (i <= k)
            {
                k++;
                sum -= i;
            }
        }

        if (k % 2 == 0)
            sum = sum + (k / 2) * (k + 1);
        else
            sum = sum + (k) * (k + 1) / 2;

        return sum;
    }

public:
    long long minimalKSum(vector<int> &nums, ll k)
    {
        long long ans = 0;
        int count = 0;
        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;

        int i = 1;
        while (true && count != k)
        {
            if (map.find(i) == map.end() && count < k)
                ans += i, count++;
            ;
            i++;
        }

        return ans;
    }
};

class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int j = 1;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (j < nums[i])
            {
                int t = nums[i] - j;
                if (t <= k)
                {
                    sum += (long)t * (2 * j + (t - 1)) / 2;
                    k -= t;
                }
                else
                {
                    sum += (long)k * (2 * j + (k - 1)) / 2;
                    return sum;
                }
            }
            j = nums[i] + 1;
        }
        if (k > 0)
            sum += (long)k * (2 * j + (k - 1)) / 2;

        return sum;
    }
};

int main()
{

    return 0;
}