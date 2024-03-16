#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        int level = 0;
        int a = label;
        while (a > 0)
        {
            a = a / 2;
            level++;
        }
        vector<int> ans;
        for (int i = level - 1; i > 0; i--)
        {
            ans.push_back(label);
            int x = (pow(2, i) + pow(2, i - 1) - 1);
            int y = label / 2;

            label = x - y;
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}