#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long brute(vector<vector<int>> &arr)
    {

        int m = arr.size();
        int n = arr[0].size();

        vector<long long> curr(n, 0);
        vector<long long> next(n, 0);

        for (int j = 0; j < n; j++)
            curr[j] = arr[0][j];

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                next[j] = LLONG_MIN;

                for (int k = 0; k < n; k++)
                {
                    long long points = arr[i][j] + curr[k] - abs(j - k);
                    next[j] = max(next[j], points);
                }
            }

            curr = next;
        }

        return *max_element(curr.begin(), curr.end());
    }

    long long solve(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();

        vector<long long> curr;
        for (int i = 0; i < n; i++)
            curr.push_back(arr[0][i]);

        for (int i = 1; i < m; i++)
        {
            vector<long long> next;
            for (int j = 0; j < n; j++)
                next.push_back(arr[i][j]);

            vector<long long> left(n, 0);
            vector<long long> right(n, 0);

            left[0] = curr[0];
            right[n - 1] = curr[n - 1];

            for (int j = 1; j < n; j++)
                left[j] = max(curr[j], left[j - 1] - 1);

            for (int j = n - 2; j >= 0; j--)
                right[j] = max(right[j + 1] - 1, curr[j]);

            for (int j = 0; j < n; j++)
                next[j] += max(left[j], right[j]);

            curr = next;
        }

        return *max_element(curr.begin(), curr.end());
    }

public:
    long long maxPoints(vector<vector<int>> &points)
    {
        return solve(points);
    }
};

int main()
{

    return 0;
}