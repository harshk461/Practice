#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> small(n, 1e9);
        vector<int> great(n, -1e9);

        small[0] = nums[0];
        great[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
            small[i] = min(small[i - 1], nums[i]);

        for (int i = n - 2; i >= 0; i--)
            great[i] = max(great[i + 1], nums[i]);

        for (int i = 1; i < n - 1; i++)
            if (nums[i] > small[i - 1] && nums[i] < great[i + 1])
                return true;

        return false;
    }
};

int main()
{

    return 0;
}