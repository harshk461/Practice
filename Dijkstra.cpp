#include <bits/stdc++.h>
using namespace std;

// TC-O(ELogV) SC-O(N+E);
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // create adjacency matrix
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top node
        auto top = *(st.begin());
        st.erase(st.begin());

        int topNode = top.second;
        int nodeDistance = top.first;

        for (auto neigbour : adj[topNode])
        {
            if (nodeDistance + neigbour.second < dist[neigbour.first])
            {
                auto record = st.find(make_pair(dist[neigbour.first], neigbour.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                // update distance
                dist[neigbour.first] = nodeDistance + neigbour.second;
                // push record
                st.insert(make_pair(dist[neigbour.first], neigbour.first));
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}