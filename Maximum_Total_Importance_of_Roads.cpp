#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second > b.second)
            return false;
        else if (a.second == b.second)
            return a.first < b.first;

        return true;
    }
};

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, int> degree;
        for (auto it : roads)
        {
            int u = it[0];
            int v = it[1];

            degree[u]++;
            degree[v]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto dg : degree)
            pq.push(dg);

        int rank = n;
        unordered_map<int, int> node_to_rank;

        while (!pq.empty())
        {
            int node = pq.top().first;
            node_to_rank[node] = rank;
            rank--;
            pq.pop();
        }

        for (auto it : node_to_rank)
            cout << it.first << " " << it.second << endl;

        long long ans = 0;
        for (auto it : roads)
        {
            int u = it[0];
            int v = it[1];

            ans += node_to_rank[u] + node_to_rank[v];
        }

        return ans;
    }
};

int main()
{

    return 0;
}