#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int s, int d, vector<bool> &visited, unordered_map<int, list<int>> &adj)
    {
        if (s == d)
        {
            return true;
        }

        visited[s] = true;

        for (auto neighbour : adj[s])
        {
            if (!visited[neighbour])
            {
                bool ans = dfs(neighbour, d, visited, adj);
                if (ans)
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
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

        vector<bool> visited(n);
        return dfs(source, destination, visited, adj);
    }
};

class Solution
{
public:
    bool DFS(int n, vector<vector<int>> graph, int source, int destination, bool *visited)
    {
        if (source == destination)
        {
            return true;
        }
        visited[source] = true;
        for (int i = 0; i < graph[source].size(); i++)
        {
            if (!visited[graph[source][i]])
            {
                bool smallans = DFS(n, graph, graph[source][i], destination, visited);
                if (smallans)
                {
                    return smallans;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {

            int firstvertex = edges[i][0], secondvertex = edges[i][1];

            graph[firstvertex].push_back(secondvertex);
            graph[secondvertex].push_back(firstvertex);
        }
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        bool ans = DFS(n, graph, source, destination, visited);
        return ans;
    }
};

int main()
{

    return 0;
}