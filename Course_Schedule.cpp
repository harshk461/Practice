#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for (auto vec : prerequisites)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indegree[u]++;
        }

        queue<int> q;
        // push all node with 0 indegree
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        int nodeVis = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            nodeVis++;
            for (auto nbr : adj[node])
            {
                // delete edge from neighbour
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // when indegree is more than 0 after delete it then there's a cycle present in the graph
        return nodeVis == numCourses;
    }
};

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto it : prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        queue<int> q;

        vector<int> topo;
        for (auto it : indegree)
            if (it == 0)
                q.push(it);

        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            topo.push_back(top);
            for (auto it : adj[top])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return q.size() == numCourses;
    }
};

int main()
{

    return 0;
}