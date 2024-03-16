#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int start, int n, vector<vector<int>> graph, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : graph[node])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q.push(it);
                }

                // checking if color of adjacent node is same
                else if (color[it] == color[node])
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                if (check(i, n, graph, color) == false)
                    return false;
        }

        return true;
    }
};

class Solution
{
private:
    void dfs(int node, int curr_color, vector<vector<int>> &graph, vector<int> &color)
    {
        color[node] = curr_color;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (!dfs(it, 1 - curr_color, graph, color))
                    return false;
            }
            else if (color[it] == curr_color)
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                if (!dfs(i, 0, graph, , color))
                    return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}