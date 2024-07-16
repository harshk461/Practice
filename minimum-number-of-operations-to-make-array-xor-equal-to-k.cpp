#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int finalXor = 0;

        for (auto it : nums)
            finalXor = finalXor ^ it;

        int count = 0;

        while (k > 0 || finalXor)
        {
            if ((k % 2) != (finalXor % 2))
                count++;

            k /= 2;
            finalXor /= 2;
        }

        return count;
    }
};

int main()
{
    return 0;
}