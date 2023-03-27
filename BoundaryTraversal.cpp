#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void traverseLeft(Node *root, vector<int> &ans)
    {
        // base case
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        ans.push_back(root->data);
        if (root->left)
        {
            traverseLeft(root->left, ans);
        }
        else
        {
            traverseLeft(root->right, ans);
        }
    }

    void traverseLeaf(Node *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node *root, vector<int> &ans)
    {
        // base case
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        if (root->right)
        {
            traverseRight(root->right, ans);
        }
        else
        {
            traverseRight(root->left, ans);
        }

        // wapas aate time store karna h
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        ans.push_back(root->data);

        // left part and store
        traverseLeft(root->left, ans);

        // leaf node

        // left subtree
        traverseLeaf(root->left, ans);

        // right subtree
        traverseLeaf(root->right, ans);

        // traverse right part
        traverseRight(root->right, ans);

        return ans;
    }
};

int main()
{

    return 0;
}