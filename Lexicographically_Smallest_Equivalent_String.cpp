#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        unordered_map<int, set<int>> map;
        unordered_map<int, set<int>> map2;
        int n = s1.length();

        // initial mapping
        for (int i = 0; i < n; i++)
        {
            auto a1 = s1[i];
            auto a2 = s2[i];

            map[a1].insert(a2);
            map[a2].insert(a1);

            map[a1].insert(a1);
            map[a2].insert(a2);

            map2[a1].insert(a2);
            map2[a2].insert(a1);
        }

        // mapping children
        for (auto it : map)
        {
            char key = it.first;
            for (auto child : map2[key])
            {
                if (child != key)
                {
                    for (auto i : map2[child])
                    {
                        map[i].insert(child);
                        map[child].insert(i);
                    }
                }
            }
        }

        for (auto it : map)
        {
            cout << (char)it.first << "->";
            for (auto i : it.second)
                cout << (char)i << " ";
            cout << endl;
        }

        for (int i = 0; i < baseStr.length(); i++)
        {
            if (map.find(baseStr[i]) != map.end())
                baseStr[i] = (char)*map[baseStr[i]].begin();
        }
        return baseStr;
    }
};

class Solution
{
public:
    char dfs(unordered_map<char, vector<char>> &mapping, char input, unordered_set<char> &visited)
    {
        if (visited.count(input) > 0)
        {
            return input;
        }
        visited.insert(input);
        char ret = input;
        for (const auto ch : mapping[input])
        {
            ret = min(ret, dfs(mapping, ch, visited));
        }
        return ret;
    }

public:
    string smallestEquivalentString(string A, string B, string S)
    {
        unordered_map<char, vector<char>> mapping;
        for (int i = 0; i < A.size(); ++i)
        {
            mapping[A[i]].push_back(B[i]);
            mapping[B[i]].push_back(A[i]);
        }
        string ret;
        unordered_map<char, char> memo;
        for (const auto s : S)
        {
            if (memo.count(s) > 0)
            {
                ret += memo[s];
                continue;
            }
            unordered_set<char> visited;
            const auto min_char = dfs(mapping, s, visited);
            for (const auto ch : visited)
            {
                memo[ch] = min_char;
            }
            ret += min_char;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    s.smallestEquivalentString("parker", "morris", "parser");
    return 0;
}