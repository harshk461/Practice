#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
private:
    void solve(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        ans.push_back(root->val);
        for (auto it : root->children)
            solve(it, ans);
    }

public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        solve(root, ans);

        return ans;
    }
};

int main()
{

    return 0;
}