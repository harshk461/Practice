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

class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        set<int> children;
        unordered_map<int, pair<int, int>> mapping;
        for (auto it : descriptions)
            children.insert(it[1]);

        int parent = -1;
        for (auto it : descriptions)
        {
            if (children.find(it[0]) == children.end())
            {
                parent = it[0];
                break;
            }
        }
        // cout << parent;

        for (auto it : descriptions)
        {
            int p = it[0];
            int c = it[1];
            int iL = it[2];

            if (iL)
                mapping[p].first = c;
            else
                mapping[p].second = c;
        }

        // for (auto it : mapping)
        //     cout << it.first << "->" << it.second.first << " " << it.second.second << endl;

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(parent);
        q.push(root);

        while (!q.empty())
        {

            for (int i = 0; i < q.size(); i++)
            {
                auto top = q.front();
                q.pop();

                pair<int, int> mp = mapping[top->val];
                if (mp.first != 0)
                {
                    TreeNode *temp = new TreeNode(mp.first);
                    top->left = temp;
                    q.push(temp);
                }

                if (mp.second != 0)
                {
                    TreeNode *temp = new TreeNode(mp.second);
                    top->right = temp;
                    q.push(temp);
                }
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}