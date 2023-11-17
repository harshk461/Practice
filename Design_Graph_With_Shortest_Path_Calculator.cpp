#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (auto it : edges)
            adj[it[0]].push_back(make_pair(it[1], it[2]));
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }

    int shortestPath(int node1, int node2)
    {
        int n = adj.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> cost(n, INT_MAX);
        cost[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty())
        {
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();

            if (currCost > cost[currNode])
                continue;

            if (currNode == node2)
                return currCost;

            for (auto nbr : adj[currNode])
            {
                int nbrNode = nbr.first;
                int nbrCost = nbr.second;

                int newCost = currCost + nbrCost;

                if (newCost < cost[nbrNode])
                {
                    cost[nbrNode] = newCost;
                    pq.push({newCost, nbrNode});
                }
            }
        }

        return -1;
    }
};

class Graph
{
public:
    vector<vector<int>> adjMatrix;
    Graph(int n, vector<vector<int>> &edges)
    {
        adjMatrix = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto &e : edges)
            adjMatrix[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            adjMatrix[i][i] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    adjMatrix[j][k] = min(adjMatrix[j][k],
                                          adjMatrix[j][i] + adjMatrix[i][k]);
    }

    void addEdge(vector<int> edge)
    {
        int n = adjMatrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = min(adjMatrix[i][j],
                                      adjMatrix[i][edge[0]] +
                                          adjMatrix[edge[1]][j] +
                                          edge[2]);
    }

    int shortestPath(int node1, int node2)
    {
        if (adjMatrix[node1][node2] == 1e9)
            return -1;
        return adjMatrix[node1][node2];
    }
};

int main()
{

    return 0;
}