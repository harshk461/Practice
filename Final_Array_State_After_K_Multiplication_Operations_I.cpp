#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

typedef pair<int, int> pi;
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        while (k--)
        {
            auto top = pq.top();
            pq.pop();

            pq.push({top.first * multiplier, top.second});
        }

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            nums[top.second] = top.first;
        }

        return nums;
    }
};

int main()
{

    return 0;
}