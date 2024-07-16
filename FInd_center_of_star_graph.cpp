#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &edges)
    {
        int n = edges.size();
        unordered_map<int, int> degree;
        for (auto it : edges)
        {
            map[it[0]]++;
            map[it[1]]++;
        }

        for (auto node : degree)
        {
            if (node.second == n)
                return node.first;
        }

        return -1;
    }

public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> map;
        for (auto vec : edges)
        {
            map[vec[0]]++;
            map[vec[1]]++;
        }
        for (auto it : map)
        {
            if (it.second > 2)
                return it.first;
        }
        return -1;
    }

    int findCenter(vector<vector<int>> &edges)
    {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};

int main()
{

    return 0;
}