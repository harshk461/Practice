#include <bits/stdc++.h>
using namespace std;

// TC-O(N+E) SC-O(N+E)
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // create adjancey matrix
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // do bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);
    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}