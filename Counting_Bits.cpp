#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int generateBit(int n)
    {
        // string ans = "";
        int count = 0;
        while (n > 0)
        {
            int temp = n % 2;
            if (temp == 1)
                count++;
            // ans += to_string(temp);
            n /= 2;
        }
        return count;
    }

public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);

        for (int i = 1; i <= n; i++)
            ans[i] = ans[i / 2] + (i & 1);

        return ans;
    }
};

int main()
{
    Solution s;
    s.countBits(8);
    return 0;
}