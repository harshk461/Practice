#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> solve(string s, string p)
    {
        int sLen = s.length();
        int pLen = p.length();

        if (sLen < pLen)
            return {};

        vector<int> freq(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < pLen; i++)
        {
            freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        vector<int> ans;
        if (freq == window)
            ans.push_back(0);

        for (int i = pLen; i < sLen; i++)
        {
            window[s[i - pLen] - 'a']--;
            window[s[i] - 'a']++;

            if (freq == window)
                ans.push_back(i - pLen + 1);
        }

        return ans;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.length() > s.length())
            return {};

        vector<int> ans;
        unordered_map<char, int> map;

        // string->{already visited,isAnagram}
        unordered_map<string, pair<bool, bool>> visited;
        for (auto it : p)
            map[it]++;

        for (int i = 0; i <= s.length() - p.length(); i++)
        {
            string temp = s.substr(i, p.length());

            if (visited[temp].second == true && visited[temp].second == true)
                ans.push_back(i);
            else
            {
                unordered_map<char, int> temp_map;

                for (auto it : temp)
                    temp_map[it]++;
                bool okay = true;

                for (auto it : temp_map)
                {
                    // cout << temp << " ";
                    temp_map[it.first] -= map[it.first];
                    // cout << temp_map[it.first] << " " << map[it.first];
                    // cout << endl;
                }

                for (auto it : temp_map)
                    if (it.second != 0)
                        okay = false;

                if (okay)
                {
                    ans.push_back(i);
                    visited[temp] = make_pair(true, true);
                }
                else
                    visited[temp] = make_pair(true, false);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> ans = s.findAnagrams("cbaebabacd", "abc");
    for (auto it : ans)
        cout << it << " ";
    return 0;
}