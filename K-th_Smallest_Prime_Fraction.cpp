#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> brute(vector<int> &arr, int k)
    {
        vector<float> v;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                float x = float(arr[i]);
                float y = float(arr[j]);
                // cout << x / y << " ";
                v.push_back(x / y);
            }

        sort(v.begin(), v.end());
        float ans = v[k - 1];
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                float x = float(arr[i]);
                float y = float(arr[j]);
                if (ans == x / y)
                    return {x, y};
            }

        return {};
    }

    vector<int> solve(vector<int> &arr, int k)
    {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double x = arr[i] / (arr[j] * 1.0);
                B if (pq.size() == k)
                {
                    if (x < pq.top().first)
                    {
                        pq.pop();
                        pq.push({x, {arr[i], arr[j]}});
                    }
                }
                else
                {
                    pq.push({x, {arr[i], arr[j]}});
                }
            }
        }

        return {pq.top().second.first, pq.top().second.second};
    }

public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        return brute(arr, k);
    }
};

int main()
{

    return 0;
}