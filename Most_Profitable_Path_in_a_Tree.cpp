#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &rewards)
    {
        int nodes = rewards.size(), maxProfit = INT_MIN;
        graph.resize(nodes);
        visited.assign(nodes, false);
        queue<vector<int>> q;
        q.push({0, 0, 0});

        for (vector<int> edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        findBobRoute(bob, 0);

        visited.assign(nodes, false);
        while (!q.empty())
        {
            int currentNode = q.front()[0], time = q.front()[1], profit = q.front()[2];

            if (bobArrival.find(currentNode) == bobArrival.end() || time < bobArrival[currentNode])
            {
                profit += rewards[currentNode];
            }
            else if (time == bobArrival[currentNode])
            {
                profit += (rewards[currentNode] / 2);
            }

            if (graph[currentNode].size() == 1 && currentNode != 0)
            {
                maxProfit = max(maxProfit, profit);
            }

            for (int neighbor : graph[currentNode])
            {
                if (!visited[neighbor])
                {
                    q.push({neighbor, time + 1, profit});
                }
            }

            visited[currentNode] = true;
            q.pop();
        }
        return maxProfit;
    }

private:
    unordered_map<int, int> bobArrival;
    vector<bool> visited;
    vector<vector<int>> graph;

    bool findBobRoute(int currentNode, int time)
    {
        bobArrival[currentNode] = time;
        visited[currentNode] = true;

        if (currentNode == 0)
            return true;

        for (int neighbor : graph[currentNode])
        {
            if (!visited[neighbor] && findBobRoute(neighbor, time + 1))
            {
                return true;
            }
        }

        bobArrival.erase(currentNode);
        return false;
    }
};

int main()
{

    return 0;
}