#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<int, int> freq_map;
        for (auto it : word)
            freq_map[it]++;

        priority_queue<int> pq;
        // insert all frequencies
        for (auto it : freq_map)
            pq.push(it.second);

        int ans = 0;
        int i = 0;
        while (!pq.empty())
        {
            ans += (1 + (i / 8)) * pq.top();
            pq.pop();
            i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}