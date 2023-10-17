class Solution
{
public:
    bool findtopo(stack<int> &st, int i, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
    {
        vis[i] = 1;
        dfsvis[i] = 1;
        for (auto node : adj[i])
        {
            if (!vis[node])
            {
                if (findtopo(st, node, adj, vis, dfsvis))
                    return true;
            }
            else if (dfsvis[node])
                return true;
        }
        dfsvis[i] = 0;
        st.push(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        stack<int> st;
        vector<int> adj[numCourses];
        vector<int> vis(numCourses, 0), dfsvis(numCourses, 0), ans;
        for (auto i : prerequisites)
            adj[i[1]].push_back(i[0]);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (findtopo(st, i, adj, vis, dfsvis))
                    return ans;
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};