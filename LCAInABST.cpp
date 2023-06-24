#include <bits/stdc++.h>
using namespace std;

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    /* Recursive way
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < P->data && root->data < Q->data)
    {
        return LCAinaBST(root->right, P, Q);
    }

    if (root->data > P->data && root->data > Q->data)
    {
        return LCAinaBST(root->left, P, Q);
    }

    return root;
    */
    // Iterative Way
    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
            root = root->right;
        else if (root->data > P->data && root->data > Q->data)
            root = root->left;
        else
            return root;
    }
}

int main()
{

    return 0;
}