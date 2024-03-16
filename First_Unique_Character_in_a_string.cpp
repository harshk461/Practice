#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        // q will be of size 3 ->(character,first index,count)
        vector<pair<int, int>> q(26, {-1, 0});

        q[s[0] - 'a'] = {0, 1};
        for (int i = 1; i < s.length(); i++)
        {
            if (q[s[i] - 'a'].first == -1)
            {
                q[s[i] - 'a'].first = i;
                q[s[i] - 'a'].second++;
            }
            else
                q[s[i] - 'a'].second++;
        }

        // sort(q.begin(), q.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
        //      {
        //     if(a.second==b.second)
        //         return a.first<b.first;
        //     else
        //         return a.second<b.second; });

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++)
            if (q[i].second == 1)
                ans = min(ans, q[i].first);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    Solution s;
    s.firstUniqChar("loveleetcode");
    return 0;
}