#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, int> cost;
        unordered_map<int, vector<int>> sub;
        for (auto it : employees)
        {
            cost[it->id] = it->importance;
            sub[it->id] = it->subordinates;
        }

        unordered_map<int, bool> vis;
        queue<int> q;
        q.push(id);
        vis[id] = true;

        int ans = 0;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            ans += cost[top];

            for (auto nbr : sub[top])
            {
                if (!vis[nbr])
                    q.push(nbr);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}