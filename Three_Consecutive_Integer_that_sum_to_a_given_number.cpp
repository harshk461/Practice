#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        vector<long long> ans;
        if (num % 3 == 0)
        {
            long long a = num / 3;
            ans.push_back(a - 1);
            ans.push_back(a);
            ans.push_back(a + 1);
            return ans;
        }
        return ans;
        accumulate
    }
};

int main()
{
    Solution s;
    vector<long long> arr = s.sumOfThree(4);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}