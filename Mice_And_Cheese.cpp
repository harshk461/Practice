#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        priority_queue<pair<int, int>> pq;
        int n = reward1.size();
        for (int i = 0; i < n; i++)
            pq.push({reward1[i] - reward2[i], i});

        int ans = 0;
        while (k-- && pq.empty())
        {
            ans += reward1[pq.top().second];
            pq.pop();
        }

        while (!pq.empty())
        {
            ans += reward2[pq.top().second];
            pq.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}