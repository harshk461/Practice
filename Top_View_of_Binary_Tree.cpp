#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if (root == NULL)
            return {};

        map<int, vector<int>> mp;
        queue<pair<Node *, int>> q;
        vector<int> ans;
        q.push({root, 0});

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            Node *node = top.first;
            int hd = top.second;

            mp[hd].push_back(node->data);

            if (node->left != NULL)
                q.push({node->left, hd - 1});
            if (node->right != NULL)
                q.push({node->right, hd + 1});
        }

        for (auto it : mp)
            ans.push_back(it.second[0]);

        return ans;
    }
};

int main()
{

    return 0;
}