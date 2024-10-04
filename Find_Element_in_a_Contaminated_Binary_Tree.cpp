#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements
{
private:
    void buildTree(TreeNode *root, int val)
    {
        if (root == NULL)
            return;

        root->val = val;
        buildTree(root->left, 2 * val + 1);
        buildTree(root->right, 2 * val + 2);
    }

    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

public:
    vector<int> arr;
    FindElements(TreeNode *root)
    {
        buildTree(root, 0);
        inorder(root, arr);
        for (auto it : arr)
            cout << it << " ";
    }

    bool find(int target)
    {
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == target)
                return true;

        return false;
    }
};

int main()
{

    return 0;
}