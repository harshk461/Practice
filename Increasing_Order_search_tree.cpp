#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> sorted;
        inorder(root, sorted);
        TreeNode *head = NULL;
        reverse(sorted.begin(), sorted.end());
        for (auto i : sorted)
        {
            TreeNode *temp = new TreeNode(i);
            temp->right = head;
            head = temp;
        }
        return head;
    }
};

// another soln
class Solution2
{
public:
    TreeNode *increasingBST(TreeNode *root, TreeNode *tail = NULL)
    {
        if (root == NULL)
            return tail;

        TreeNode *ans = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return ans;
    }
};

int main()
{
    stack<int> s;
    s.
    return 0;
}