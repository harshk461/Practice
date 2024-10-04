#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
            // value,weight
            vec.push_back({arr[i].value, arr[i].weight});

        sort(vec.begin(), vec.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             { return ((double)a.first / a.second) > ((double)b.first / b.second); });

        int ans = 0;
        int curr_weight = 0;

        for (int i = 0; i < n; i++)
        {
            if (curr_weight + vec[i].second <= w)
            {
                curr_weight += vec[i].second;
                ans += vec[i].first;
            }
            else
            {
                int rem = w - curr_weight;
                ans += ((double)rem / vec[i].second) * vec[i].first;
                break;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}