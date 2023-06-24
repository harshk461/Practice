#include <bits/stdc++.h>
using namespace std;
class Node
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

void inorder(TreeNode<int> *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

TreeNode<int> *inorderToBST(int s, int e, vector<int> arr)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = s + (e - s) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = inorderToBST(s, mid - 1, arr);
    root->right = inorderToBST(mid + 1, e, arr);

    return root;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> arr;
    inorder(root, arr);

    return inorderToBST(0, arr.size() - 1, arr);
}

int main()
{

    return 0;
}