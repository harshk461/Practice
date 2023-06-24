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
    // store inorder value in a array
    arr.push_back(root->data);
    inorder(root->right, arr);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> arr;
    inorder(root, arr);

    TreeNode<int> *newRoot = new TreeNode<int>(arr[0]);
    TreeNode<int> *curr = newRoot;
    // 2nd step is to create a temp node then point it's left to null and right to next node
    for (int i = 1; i < arr.size(); i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(arr[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // 3rd step is to point last element's left and right to null
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

int main()
{

    return 0;
}