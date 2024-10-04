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

class CBTInserter
{
private:
    void levelOrder(TreeNode *root, queue<TreeNode *> &ans)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q({root});
        while (!q.empty())
        {
            vector<TreeNode *> currLevel;
            for (int i = q.size(); i > 0; --i)
            {
                TreeNode *node = q.front();
                q.pop();
                currLevel.push_back(node);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            for (auto it : currLevel)
            {
                // cout<<it->val<<" ";
                ans.push(it);
            }
        }
    }

public:
    queue<TreeNode *> q;
    TreeNode *root;
    CBTInserter(TreeNode *root)
    {
        levelOrder(root, q);

        this->root = root;
    }

    int insert(int val)
    {
        while (q.front()->left != NULL && q.front()->right != NULL)
        {
            // cout<<q.front()->val<<" ";
            q.pop();
        }
        auto top = q.front();
        // cout<<top->val<<" ";
        TreeNode *temp = new TreeNode(val);
        if (top->left == NULL && top->right == NULL)
        {
            top->left = temp;
            q.push(temp);
        }
        else if (top->left != NULL)
        {
            top->right = temp;
            q.push(temp);
            q.pop();
        }

        else if (top->right != NULL)
        {
            top->left = temp;
            q.push(temp);
            // q.pop();
        }

        return top->val;
    }

    TreeNode *get_root()
    {
        return root;
    }
};

int main()
{

    return 0;
}