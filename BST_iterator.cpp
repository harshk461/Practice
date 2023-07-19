#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    void Pushall(TreeNode *node)
    {
        for (; node != NULL; st.push(node), node = node->left)
            ;
    }

public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        Pushall(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        Pushall(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{

    return 0;
}