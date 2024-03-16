#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void convertToGraph(TreeNode *curr, int parent, unordered_map<int, set<int>> &graph)
    {
        if (curr == NULL)
            return;

        if (graph.find(curr->val) == graph.end())
            graph[curr->val] = set<int>();

        auto &adjList = graph[curr->val];

        if (parent != 0)
            adjList.insert(parent);
        if (curr->left != NULL)
            adjList.insert(curr->left->val);
        if (curr->right != NULL)
            adjList.insert(curr->left->val);

        convertToGraph(curr->left, curr->val, graph);
        convertToGraph(curr->right, curr->val, graph);
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, set<int>> graph;
        convertToGraph(root, 0, graph);

        for (auto it : graph)
        {
            cout << it.first << "->";
            for (auto i : it.second)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        queue<int> q;
        q.push(start);

        int minute = 0;

        unordered_map<int, bool> visited;
        visited[start] = true;

        // while (!q.empty())
        // {
        //     int size = q.size();
        //     while (size > 0)
        //     {
        //         int top = q.front();
        //         q.pop();

        //         for (auto num : graph[num])
        //         {
        //             if (visited.find(num) == visited.end())
        //             {
        //                 visited[num] = true;
        //                 q.push(num);
        //             }
        //         }
        //         size--;
        //     }
        //     minute++;
        // }

        return minute;
    }
};

int main()
{

    return 0;
}