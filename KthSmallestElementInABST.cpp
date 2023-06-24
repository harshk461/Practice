#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int solve(BinaryTreeNode<int> *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    // L
    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    // N
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int main()
{

    return 0;
}