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
    vector<vector<int>> solve(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode *node = temp.first;
            int hd = temp.second.first; // hd = horizontal distance
            int level = temp.second.second;

            mp[hd][level].insert(node->val);

            if (node->left != NULL)
                q.push(make_pair(node->left, make_pair(hd - 1, level + 1)));
            if (node->right != NULL)
                q.push(make_pair(node->right, make_pair(hd + 1, level + 1)));
        }

        for (auto i : mp)
        {
            vector<int> res;
            for (auto j : i.second)
            {
                res.insert(res.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(res);
        }

        return ans;
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<pair<int, int>, vector<int>, hash_pair> mp;
        mp[{0, 0}].push_back(root->val);
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto top = q.front();
            TreeNode *node = top.first;
            pair<int, int> val = top.second;
            q.pop();
            mp[{val.first, val.second}].insert(node->val);
            if (node->left)
            {
                q.push({node->left, {val.first + 1, val.second - 1}});
            }
            if (node->right)
            {
                q.push({node->right, {val.first + 1, val.second + 1}});
            }
        }

        vector<vector<int>> ans;
        // for (auto it : mp)
        // {
        //     ans.push_back(it.second);
        // }
        return solve(root);
    }
};

int main()
{

    return 0;
}