#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int ans = 0;
        for (auto it : left)
            ans = max(ans, it);

        for (auto it : right)
            ans = max(ans, n - it);

        return ans;
    }
};

int main()
{

    return 0;
}