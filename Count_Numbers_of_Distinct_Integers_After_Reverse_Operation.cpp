#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int reverseNumber(int n)
    {
        if (n < 10)
            return n;
        int ans = 0;
        while (n > 0)
        {
            int rem = n % 10;
            ans = ans * 10 + rem;
            n /= 10;
        }
        return ans;
    }

public:
    int countDistinctIntegers(vector<int> &nums)
    {
        set<int> s;
        for (auto it : nums)
            s.insert(it);

        for (int i = 0; i < nums.size(); i++)
        {
            cout << reverseNumber(nums[i]) << " ";
            s.insert(reverseNumber(nums[i]));
        }

        return s.size();
    }
};

int main()
{

    return 0;
}