#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
BinaryTreeNode<int> *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
    {
        return NULL;
    }

    if (preorder[i] < mini || preorder[i] > maxi)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}
int main()
{

    return 0;
}