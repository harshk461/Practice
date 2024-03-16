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
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> curr;
            for (int i = q.size(); i > 0; i--)
            {
                Node *top = q.front();
                q.pop();

                for (auto it : top->children)
                    q.push(it);
                curr.push_back(top->val);
            }
            ans.push_back(curr);
        }

        return ans;
    }
};

int main()
{

    return 0;
}