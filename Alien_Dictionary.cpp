#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
            for (auto it : adj[i])
                indegree[it]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;
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

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.length(), s2.length());
            for (int it = 0; it < len; it++)
            {
                if (s1[it] != s2[it])
                {
                    adj[s1[it] - 'a'].push_back(s2[it] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for (auto it : topo)
            ans += it + 'a';
        return ans;
    }
};

int main()
{
    string arr[5] = {"baa", "abcd", "abca", "cab", "cad"};
    Solution s;

    s.findOrder(arr, 5, 4);
    return 0;
}