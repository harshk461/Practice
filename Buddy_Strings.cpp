#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        if (s == goal && set<char>(s.begin(), s.end()).size() < s.length())
            return true;

        vector<int> diff;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
                diff.push_back(i);
        }
        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] &&
               s[diff[1]] == goal[diff[0]];
    }
};

int main()
{
    Solution s;
    cout << s.buddyStrings("ba", "ab");
    return 0;
}