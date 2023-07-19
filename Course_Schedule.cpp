#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
    {
        visited[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                topoSort(neighbour, visited, s, adj);
            }
        }

        s.push(node);
    }

    bool checkCycle(stack<int> st,int n)
    {
        unordered_map<int, int> pos;
        int index = 0;
        vector<int> tsort;
        while (!st.empty())
        {
            pos[st.top()] = index;
            tsort.push_back(st.top());
            index++;
            st.pop();
        }

        for(int i=0;i<n;i++){
            
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // create adj matrix
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        // call for each component (dfs calls)
        vector<bool> visited(v);
        stack<int> s;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                topoSort(i, visited, s, adj);
            }
        }
    }
};

int main()
{

    return 0;
}