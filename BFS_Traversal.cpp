#include <bits/stdc++.h>
using namespace std;

void prepareAdj(unordered_map<int, set<int>> &adjMat, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjMat[u].insert(v);
        adjMat[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjMat, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);

    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store in ans
        ans.push_back(frontNode);

        // traverse all member of frontnode
        for (auto i : adjMat[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjMat;
    unordered_map<int, bool> visited;
    vector<int> ans;

    // prepare adjacency matrix
    prepareAdj(adjMat, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjMat, visited, ans, i);
        }
    }
    return ans;
}

int main()
{

    return 0;
}