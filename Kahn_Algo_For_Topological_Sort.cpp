#include <bits/stdc++.h>
using namespace std;

// TC-O(N+E) SC-O(N)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create adj matrix
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // create indegree vector
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    // push element with 0 indegree
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // store ans
        ans.push_back(front);

        // check for neighbour
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}