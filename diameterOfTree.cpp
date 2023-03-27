#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int height(struct Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }

public:
    // pair-first part represent diameter second part represents height
    pair<int, int> diameterFast(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }

        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + 1 + height(root->right);

        int ans = max(op1, max(op2, op3));
        return ans;
    }
};

// optimised solution
class Solution2
{
private:
    int height(struct Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }

public:
    // pair-first part represent diameter second part represents height
    pair<int, int> diameterFast(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        return diameterFast(root).first;
    }
};

int main()
{

    return 0;
}