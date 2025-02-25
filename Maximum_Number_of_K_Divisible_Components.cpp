#include <bits/stdc++.h>
using namespace std;

// Optimize I/O operations for faster execution
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization between C++ and C standard streams
    cin.tie(0);                  // Untie cin from cout to avoid flushing cout before cin
    cout.tie(0);                 // Untie cout from other output streams
    return 'c';                  // A dummy return value to make this a lambda expression
}();

// Define the solution class
class Solution
{
private:
    // Depth First Search (DFS) function to calculate the sum of values for each subtree
    // Parameters:
    // - curr: Current node being visited
    // - parent: Parent node of the current node
    // - adj: Adjacency list representing the graph
    // - values: Node values vector
    // - k: The divisor to check divisibility
    // - components: Reference to the count of k-divisible components
    int dfs(int curr, int parent, unordered_map<int, vector<int>> &adj, vector<int> &values, int k, int &components)
    {
        int sum = 0; // Initialize the sum of the current subtree

        // Traverse all neighbors of the current node
        for (auto nbr : adj[curr])
        {
            // Avoid revisiting the parent node
            if (nbr != parent)
            {
                // Recursively calculate the sum of the subtree rooted at the neighbor
                sum += dfs(nbr, curr, adj, values, k, components);
                sum %= k; // Keep the sum modulo k to prevent overflow
            }
        }

        // Add the current node's value to the subtree sum
        sum += values[curr];
        sum %= k; // Again, take modulo k to ensure the sum doesn't grow unnecessarily large

        // If the subtree sum is divisible by k, it forms a valid k-divisible component
        if (sum == 0)
            components++;

        // Return the subtree sum modulo k for the parent to use
        return sum;
    }

public:
    // Function to calculate the maximum number of k-divisible components
    // Parameters:
    // - n: Number of nodes in the graph
    // - edges: List of edges representing the graph
    // - values: Node values vector
    // - k: The divisor to check divisibility
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;
        for (auto it : edges)
        {
            int u = it[0]; // Start node of the edge
            int v = it[1]; // End node of the edge

            // Add the edge to the adjacency list
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components = 0; // Initialize the count of k-divisible components

        // Perform DFS starting from node 0 (assuming the tree is rooted at 0)
        dfs(0, -1, adj, values, k, components);

        // Return the total count of k-divisible components
        return components;
    }
};

int main()
{

    return 0;
}