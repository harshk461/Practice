#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(vector<int> &parent, int u, int v, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v)
        {
            ans += w;
            unionSet(parent, u, v, rank);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 6}, {2, 3, 2}, {1, 3, 2}, {1, 0, 2}};
    cout << minimumSpanningTree(arr, 4);
    return 0;
}