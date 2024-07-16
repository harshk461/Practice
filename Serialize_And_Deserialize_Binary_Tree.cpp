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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "#,";

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode *helper(queue<string> &q)
    {
        string s = q.front();
        q.pop();

        if (s == "#")
            return NULL;

        // we serialized data in a preorder format
        // so we have to deserialize it in a preorder format
        TreeNode *node = new TreeNode(stoi(s));
        node->left = helper(q);
        node->right = helper(q);

        return node;
    }

    TreeNode *deserialize(string data)
    {
        queue<string> q;
        string s = "";
        for (int i = 0; i < n; i++)
        {
            if (data[i] == ',')
            {
                q.push(s);
                s = "";
                continue;
            }
            s += data[i];
        }

        if (s.length() != 0)
            q.push(s);

        return help(q);
    }
};

int main()
{

    return 0;
}