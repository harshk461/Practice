#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;

        // cout<<k;
        deque<pair<int, int>> dq;
        for (int i = 0; i < chalk.size(); i++)
            dq.push_back({chalk[i], i});

        while (true)
        {
            auto top = dq.front();
            // cout<<top.second<<" ";
            dq.pop_front();
            dq.push_back(top);
            if (top.first > k)
                return top.second;

            k -= top.first;
        }
        return -1;
    }
};

int main()
{

    return 0;
}