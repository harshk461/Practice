#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans = "";
        for (const string &str : strs)
        {
            ans += to_string(str.size()) + "#" + str;
        }

        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        int i = 0;
        while (i < s.size())
        {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            ans.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return ans;
    }
};

int main()
{

    return 0;
}