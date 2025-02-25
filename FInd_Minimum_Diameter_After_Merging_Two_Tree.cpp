#include <bits/stdc++.h>
using namespace std;

// Optimize input/output operations for competitive programming
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization between C and C++ standard streams
    cin.tie(0);                  // Untie cin from cout for faster I/O
    cout.tie(0);                 // Tie cout only to itself for faster output
    return 'c';
}();

// Class to solve the problem of finding the minimum diameter after merging two trees
class Solution
{
private:
    // Helper function to perform Depth-First Search (DFS) and calculate the diameter and depth
    pair<int, int> dfs(int node, int parent, unordered_map<int, vector<int>> &adj)
    {
        int max_depth1 = 0; // Tracks the maximum depth from the current node
        int max_depth2 = 0; // Tracks the second maximum depth from the current node
        int dia = 0;        // Tracks the diameter of the subtree rooted at this node

        // Traverse all neighbors of the current node
        for (auto nbr : adj[node])
        {
            if (nbr == parent)
                continue; // Skip the parent node to avoid revisiting it

            // Recursive call to DFS for the child node
            auto [child_dia, depth] = dfs(nbr, node, adj);

            // Update the diameter to include the largest diameter from child subtrees
            dia = max(dia, child_dia);

            // Increment the depth for the edge connecting the current node and the child
            depth++;

            // Update the two largest depths from this node
            if (depth > max_depth1)
            {
                max_depth2 = max_depth1; // Update second largest depth
                max_depth1 = depth;      // Update largest depth
            }
            else if (depth > max_depth2)
            {
                max_depth2 = depth; // Update second largest depth
            }
        }

        // Update the diameter to consider paths passing through this node
        dia = max(dia, max_depth1 + max_depth2);

        // Return the diameter of the subtree and the maximum depth
        return {dia, max_depth1};
    }

public:
    // Function to calculate the minimum diameter after merging two trees
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        unordered_map<int, vector<int>> adj1; // Adjacency list for Tree 1
        unordered_map<int, vector<int>> adj2; // Adjacency list for Tree 2

        // Build adjacency list for Tree 1
        for (auto it : edges1)
        {
            int u = it[0]; // Start of the edge
            int v = it[1]; // End of the edge

            adj1[u].push_back(v); // Add the edge to adjacency list
            adj1[v].push_back(u); // Add reverse edge for undirected graph
        }

        // Build adjacency list for Tree 2
        for (auto it : edges2)
        {
            int u = it[0];
            int v = it[1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        // Calculate the diameter of Tree 1
        int dia1 = dfs(0, -1, adj1).first;

        // Calculate the diameter of Tree 2
        int dia2 = dfs(0, -1, adj2).first;

        // Calculate the combined diameter after merging the two trees
        int comb_dia = ceil(dia1 / 2.0) + ceil(dia2 / 2.0) + 1;

        // Return the maximum diameter among Tree 1, Tree 2, and the combined tree
        return max({dia1, dia2, comb_dia});
    }
};

int main()
{

    return 0;
}