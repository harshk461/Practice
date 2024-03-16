#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<int, vector<int>> prime_index;
    unordered_map<int, vector<int>> index_prime;

    void dfs(int i, vector<int> &vis, unordered_map<int, bool> &vis_prime)
    {
        if (vis[i])
            return;

        vis[i] = true;

        for (auto it : index_prime[index])
        {
            if (vis_prime[it])
                continue;

            vis_prime[it] = true;
            for (auto i : prime_index[it])
            {
                if (vis[i])
                    continue;
                dfs(i, vis, vis_prime);
            }
        }
    }

public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            for (int j = 2; j * j <= nums[i]; j++)
            {
                if (temp % j == 0)
                {
                    prime_index[j].push_back(i);
                    index_prime[i].push_back(j);

                    while (temp % j == 0)
                        temp /= j;
                }
            }

            if (temp > 1)
            {
                prime_index[temp].push_back(i);
                index_prime[i].push_back(temp);
            }
        }

        vector<int> vis(n, 0);
        unordered_map<int, bool> vis_prime;

        for (int i = 0; i < vis.size(); i++)
            if (!vis[i])
                return false;

        return true;
    }
};

int main()
{

    return 0;
}