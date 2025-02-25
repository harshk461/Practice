#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();

        // A vector to store queries grouped by the maximum index of the pair (a, b)
        vector<vector<vector<int>>> qrs(heights.size());

        // A priority queue to efficiently find the smallest height that satisfies a query
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Result vector to store the answers for each query
        vector<int> ans(queries.size(), -1);

        // Preprocess each query
        for (int i = 0; i < queries.size(); i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];

            // Direct cases where the result can be determined without further checks:
            if (a < b && heights[a] < heights[b])
                ans[i] = b; // Moving right and b is taller
            else if (a > b && heights[a] > heights[b])
                ans[i] = a; // Moving left and a is taller
            else if (a == b)
                ans[i] = a; // Same building, directly return the building
            else
                // Otherwise, store the query for processing later
                qrs[max(a, b)].push_back({max(heights[a], heights[b]), i});
        }

        // Iterate through all buildings
        for (int i = 0; i < n; i++)
        {
            // Process queries in the priority queue where the current building is taller
            while (!pq.empty() && pq.top()[0] < heights[i])
            {
                ans[pq.top()[1]] = i; // Assign the current building index as the answer
                pq.pop();             // Remove processed query
            }

            // Add pending queries for the current building
            for (auto ele : qrs[i])
                pq.push(ele);
        }

        return ans;
    }
};

int main()
{

    return 0;
}