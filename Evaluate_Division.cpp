#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    double divide(unordered_map<string, unordered_map<string, double>> &graph,
                  string &a, string &b, unordered_set<string> &seen)
    {
        if (a == b)
            return 1.0;

        seen.insert(a);

        for (auto& [B, value] : graph.at(a))
        {
            if (seen.count(B))
                continue;

            double res = divide(graph, B, b, move(seen));
            if (res > 0)
                return value * res;
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        vector<double> ans;
        // A->{B:cost} cost=A/B
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            // Graph[A]=X->unordered map of connected node value of X is unordered map
            graph[a][b] = values[i];
            graph[b][a] = 1/values[i];
        }

        for (auto query : queries)
        {
            string a = query[0];
            string b = query[1];
            if (!graph.count(b) || !graph.count(b))
                ans.push_back(-1);
            else
                ans.push_back(divide(graph, a, b, unordered_set<string>()));
        }
        return ans;
    }
};

int main()
{

    return 0;
}