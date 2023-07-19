#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int ans = 0;
        int maxi = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); r++)
        {
            maxi = max(maxi, ++count[s[r]]);
            cout << maxi << " ";
            while (maxi + k < r - l + 1)
                --count[s[l++]];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.characterReplacement("AABABBA", 1);
    return 0;
}