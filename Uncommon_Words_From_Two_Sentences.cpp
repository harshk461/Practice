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
private:
    vector<string> split(string s)
    {
        string curr = "";
        vector<string> res;

        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == ' ' || i == s.length())
            {
                res.push_back(curr);
                curr = "";
            }
            else
                curr += s[i];
        }

        return res;
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> arr1 = split(s1);
        vector<string> arr2 = split(s2);
        unordered_map<string, int> map;

        for (auto it : arr1)
            map[it]++;
        for (auto it : arr2)
            map[it]++;

        vector<string> ans;
        for (auto it : map)
        {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};

int main()
{

    return 0;
}