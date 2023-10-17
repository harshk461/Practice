#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
private:
    int dfs(Node *node)
    {
        if (node == NULL)
            return 0;

        int height = 0;
        for (auto nbr : node->children)
        {
            height = max(height, 1 + dfs(nbr));
        }
        return height;
    }

public:
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;
        int height = dfs(root);
        return height;
    }
};

int main()
{

    return 0;
}