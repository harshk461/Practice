#include <bits/stdc++.h>
using namespace std;

// Optimization for faster I/O operations
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization between C++ and C I/O
    cin.tie(0);                  // Untie cin from cout
    cout.tie(0);                 // Untie cout from cin
    return 'c';
}();

// Class to solve the problem
class Solution
{
private:
    /**
     * Depth First Search (DFS) function
     * @param node - Current node being visited
     * @param adj - Adjacency list representing the graph
     * @param vis - Vector to keep track of visited nodes
     * @param st - Stack to store nodes in their finishing order
     */
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &vis, stack<int> &st)
    {
        vis[node] = true; // Mark the current node as visited

        // Traverse all neighbors of the current node
        for (auto nbr : adj[node])
        {
            if (!vis[nbr]) // If the neighbor is not visited, call DFS recursively
                dfs(nbr, adj, vis, st);
        }

        // After exploring all neighbors, push the node into the stack
        st.push(node);
    }

public:
    /**
     * Function to find the "champion" node in the graph
     * A champion node is defined as a node from which all other nodes are reachable
     * @param n - Number of nodes in the graph (0-indexed)
     * @param edges - List of directed edges in the graph
     * @return - Champion node if exists, otherwise -1
     */
    int findChampion(int n, vector<vector<int>> &edges)
    {
        // Create an adjacency list for the graph
        unordered_map<int, vector<int>> adj;
        for (auto it : edges)
        {
            int u = it[0];       // Start node of the edge
            int v = it[1];       // End node of the edge
            adj[u].push_back(v); // Add edge to the adjacency list
        }

        // Check each node to see if it can be a champion
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(n, false); // Visited vector to track visited nodes
            stack<int> st;              // Stack to hold nodes in their DFS finishing order

            // Perform DFS from the current node
            dfs(i, adj, vis, st);

            // If all nodes are reachable from the current node, it is the champion
            if (st.size() == n)
                return i;
        }

        // If no champion is found, return -1
        return -1;
    }
};

class Solution
{
public:
    /**
     * Function to find the "champion" node in a graph
     * A champion node is defined as a node with zero in-degree, i.e., no incoming edges.
     * If there is more than one node with zero in-degree, or if no such node exists, the function returns -1.
     *
     * @param n - Number of nodes in the graph (0-indexed)
     * @param edges - List of directed edges in the graph
     * @return - Champion node index if there is exactly one node with zero in-degree, otherwise -1
     */
    int findChampion(int n, vector<vector<int>> &edges)
    {
        // Initialize an in-degree array to keep track of incoming edges for each node
        vector<int> indegree(n, 0);

        // Iterate through the edges to calculate in-degree for each node
        for (auto it : edges)
        {
            int u = it[0]; // Start node of the edge
            int v = it[1]; // End node of the edge
            indegree[v]++; // Increment in-degree of the destination node
        }

        // Variables to track the potential champion and the number of nodes with zero in-degree
        int champ = 0; // Store the potential champion node
        int count = 0; // Counter for nodes with zero in-degree

        // Check each node to identify nodes with zero in-degree
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {              // If the node has zero in-degree
                champ = i; // Update the potential champion node
                count++;   // Increment the count of nodes with zero in-degree
            }
        }

        // If there is more than one node with zero in-degree, or no such node exists, return -1
        return count > 1 ? -1 : champ;
    }
};

int main()
{

    return 0;
}