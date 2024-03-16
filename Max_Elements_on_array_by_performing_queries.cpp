#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define ll long long

    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        ll sum = 0;b
        int n = nums.size();
        vector<int> vis(n, 0);

        vector<ll> res;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
            sum += nums[i];
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int idx = queries[i][0];
            int m = queries[i][1];
            if (vis[idx] == 0)
            {
                vis[idx] = 1;
                sum -= nums[idx];
            }

            while (m > 0 && !pq.empty())
            {
                int num = pq.top().first;
                int index = pq.top().second;
                pq.pop();

                if (vis[index] == 0)
                {
                    sum -= num;
                    vis[index] = 1;
                    m--;
                }
            }

            res.push_back(sum);
        }

        return res;
    }
};

int main()
{

    return 0;
}