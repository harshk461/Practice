#include <bits/stdc++.h>
using namespace std;

// TC-O(N)
// SC-O(N)

class Solution
{

public:
    int countNode(struct Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int ans = 1 + countNode(root->left) + countNode(root->right);
        return ans;
    }

    bool isCBT(struct Node *root, int i, int n)
    {
        if (root == NULL)
        {
            return true;
        }
        if (i >= n)
        {
            return false;
        }

        bool left = isCBT(root->left, 2 * i + 1, n);
        bool right = isCBT(root->right, 2 * i + 2, n);
        return (left && right);
    }

    bool isMaxHeap(struct Node *root)
    {
        // leaf node is always a heap
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        // only left side exists
        if (root->right == NULL)
        {
            return root->data > root->left->data;
        }

        // both side exists
        else
        {
            return ((root->data > root->left->data) && (root->data > root->right->data) && isMaxHeap(root->left) && isMaxHeap(root->right));
        }
    }
    bool isHeap(struct Node *tree)
    {
        int i = 0;
        int n = countNode(tree);
        if (isCBT(tree, i, n) && isMaxHeap(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    return 0;
}