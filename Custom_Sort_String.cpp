#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<int, int> freq;
        for (auto it : s)
            freq[it]++;

        queue<char> q;
        set<char> vis;
        int i = 0;
        string ans = "";
        while (i < order.length())
        {
            if (s.find(order[i]) != string::npos)
            {
                vis.insert(order[i]);
                while (freq[order[i]] > 0)
                {
                    ans += order[i];
                    freq[order[i]]--;
                }
            }
            i++;
        }
        for (auto it : s)
        {
            if (vis.find(it) == vis.end())
                q.push(it);
        }

        for (auto it : q)
            cout << q << " ";

        while (!q.empty())
        {
            auto top = q.front();
            ans.push_back(top);
        }
        return ans;
    }
};

int main()
{

    return 0;
}