#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string solve(string s)
    {
        unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto it : map)
            pq.push({it.second, it.first});

        string res;
        while (!pq.empty())
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            res += top1.second;
            res += top2.second;
            if (--top1.first > 0)
                pq.push({top1.first, top1.second});
            if (--top2.first > 0)
                pq.push({top2.first, top2.second});
        }

        if (!pq.empty())
        {
            auto top = pq.top();
            if (top.first > 1)
                return "";
            res += top.second;
        }
        return res;
    }

public:
    string reorganizeString(string s)
    {
        vector<int> charCounts(26, 0);
        for (char c : s)
        {
            charCounts[c - 'a'] = charCounts[c - 'a'] + 1;
        }

        // Max heap ordered by character counts
        priority_queue<vector<int>> pq;
        for (int i = 0; i < 26; i++)
        {
            if (charCounts[i] > 0)
            {
                pq.push(vector<int>{charCounts[i], i + 'a'});
            }
        }

        string result;
        while (!pq.empty())
        {
            auto first = pq.top();
            pq.pop();
            if (result.empty() || first[1] != result.back())
            {
                result += char(first[1]);
                if (--first[0] > 0)
                {
                    pq.push(first);
                }
            }
            else
            {
                if (pq.empty())
                {
                    return "";
                }
                auto second = pq.top();
                pq.pop();
                result += char(second[1]);
                if (--second[0] > 0)
                {
                    pq.push(second);
                }
                pq.push(first);
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}