#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<string> modififed;
        for (auto it : bank)
        {
            if (count(it.begin(), it.end(), '1') > 0)
                modififed.push_back(it);
        }

        if (modififed.empty())
            return 0;

        int ans = 0;

        for (int i = 0; i < modififed.size() - 1; i++)
        {
            int one_in_row_1 = count(modififed[i].begin(), modififed[i].end(), '1');
            int one_in_row_2 = count(modififed[i + 1].begin(), modififed[i + 1].end(), '1');

            ans += one_in_row_1 * one_in_row_2;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> arr = {"000", "111", "000"};
    s.numberOfBeams(arr);
    return 0;
}