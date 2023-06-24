#include <bits/stdc++.h>
using namespace std;

bool isCycle(int i, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;
    parent[i] = -1;
    visited[i] = true;
    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neigbhour : adj[node])
    {
        if (!visited[neigbhour])
        {
            bool ans = isCycleDFS(neigbhour, node, visited, adj);
            if (ans)
                return true;
        }
        else if (neigbhour != parent)
        {
            // cycle present
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adjancey Matrix
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected graphs
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycle(i, visited, adj);
            if (ans == 1)
                return "YES";
        }
    }
    return "NO";
}

int main()
{

    return 0;
}