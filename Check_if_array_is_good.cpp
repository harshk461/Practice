#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int n = *max_element(nums.begin(), nums.end());
        if (nums.size() < n + 1)
            return false;

        vector<int> freq(n + 1, 0);
        freq[0] = 1;
        for (auto i : nums)
            freq[i]++;

        for (int i = 0; i <= n; i++)
        {
            if (freq[i] == 0 || freq[i] > 2)
                return false;

            if (freq[i] == 2 && i != n)
                return false;

            if (freq[n] != 2)
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}