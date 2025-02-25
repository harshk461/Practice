#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int magnificentSets(int numNodes, vector<vector<int>> &edgesList)
    {
        // Construct adjacency list for the graph
        vector<vector<int>> adjacencyList(numNodes);
        for (auto &edge : edgesList)
        {
            int node1 = edge[0] - 1, node2 = edge[1] - 1; // Convert 1-based to 0-based indexing
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }

        vector<int> nodeDistances(numNodes); // Stores the maximum group size for each component

        // Perform BFS from each node to determine the largest valid grouping
        for (int startNode = 0; startNode < numNodes; ++startNode)
        {
            queue<int> nodeQueue{{startNode}};
            vector<int> distance(numNodes, 0); // Distance array initialized to 0
            distance[startNode] = 1;           // Mark the start node
            int maxDistance = 1;               // Track the largest depth in this component
            int rootNode = startNode;          // Track the smallest node in the component

            while (!nodeQueue.empty())
            {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();
                rootNode = min(rootNode, currentNode); // Ensure consistent root selection

                for (int neighbor : adjacencyList[currentNode])
                {
                    if (distance[neighbor] == 0)
                    { // If unvisited, update its distance
                        distance[neighbor] = distance[currentNode] + 1;
                        maxDistance = max(maxDistance, distance[neighbor]);
                        nodeQueue.push(neighbor);
                    }
                    // If a cycle with the same parity exists, it's not bipartite
                    else if (abs(distance[neighbor] - distance[currentNode]) != 1)
                    {
                        return -1;
                    }
                }
            }

            // Store the maximum valid group size for the component's root node
            nodeDistances[rootNode] = max(nodeDistances[rootNode], maxDistance);
        }

        // Sum up all maximum distances for connected components
        return accumulate(nodeDistances.begin(), nodeDistances.end(), 0);
    }
};

int main()
{

    return 0;
}