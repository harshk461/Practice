#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;
        unordered_set<int> freq;
        int ans = 0;
        for (auto it : map)
        {
            int f = it.second;
            while (f > 0 && freq.find(f) != freq.end())
            {
                f--;
                ans++;
            }
            freq.insert(f);
        }
        return ans;
    }
};

int main()
{

    return 0;
}