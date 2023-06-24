#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> ans;
        vector<int> pos;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                pos.push_back(i);
            }
        }

        for (int j = 0; j < s.length(); j++)
        {
            int mn = INT_MAX;
            for (int i = 0; i < pos.size(); i++)
            {
                mn = min(mn, abs(pos[i] - j));
            }
            ans.push_back(mn);
        }
        return ans;
    }
};

int main()
{

    return 0;
}