#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        vector<int> ans({area, 1});
        for (int i = 1; i * i <= area; i++)
        {
            // area/i->length
            // i->width
            if (area % i == 0 && (area / i - i) < (ans[0] - ans[1]))
                ans[0] = area / i, ans[1] = i;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.constructRectangle(122122);
    return 0;
}